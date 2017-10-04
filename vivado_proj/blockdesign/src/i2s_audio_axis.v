module i2s_audio_axis
  (
   input             ap_clk,
   input             clk_100,
   
   output reg	     audio_mclk,
   output reg	     audio_dac,
   input 	     audio_adc,
   input 	     audio_bclk,
   input 	     audio_lrclk,

   input [31:0]      from_host_audio_tdata,
   output reg        from_host_audio_tready,
   input             from_host_audio_tvalid, // Ignored

   output reg [31:0] to_host_audio_tdata,
   input             to_host_audio_tready, // Ignored
   output reg        to_host_audio_tvalid
   );
   
   reg 		     audio_adc_reg;
   reg 		     audio_bclk_reg;
   reg 		     audio_lrclk_reg;
   reg 		     audio_lrclk_reg_d;
   
   reg [1:0] 	     clk_div;
   reg [15:0] 	     play_shreg;
   reg [1:0] 	     bclk_d;
   wire 	     bclk_rising, bclk_falling;

   reg [31:0] 	     record_shreg;
   reg [4:0] 	     record_count;
   reg 		     write_when_done;

   // synthesis attribute IOB of audio_mclk is TRUE
   // synthesis attribute IOB of audio_dac is TRUE   
   // synthesis attribute IOB of audio_adc_reg is TRUE   
   // synthesis attribute IOB of audio_bclk_reg is TRUE   
   // synthesis attribute IOB of audio_lrclk_reg is TRUE   

   assign 	     user_r_audio_eof = 0;
      
   // Produce a 25 MHz clock for MCLK
   
   always @(posedge clk_100)
     begin
	clk_div <= clk_div + 1;
	audio_mclk <= clk_div[1];
     end

   assign bclk_rising = (bclk_d == 2'b01);
   assign bclk_falling = (bclk_d == 2'b10);

   // BCLK runs at 3.072 MHz, so the signals are sampled and handled
   // synchronously, with an obvious delay, which is negligble compared
   // with a BCLK clock cycle.
   
   always @(posedge ap_clk)
     begin
	audio_adc_reg <= audio_adc;
    	audio_bclk_reg <= audio_bclk;
    	audio_lrclk_reg <= audio_lrclk;

	bclk_d <= { bclk_d, audio_bclk_reg };

	if (bclk_rising)
	  audio_lrclk_reg_d <= audio_lrclk_reg;

	// Playback

	// from_host_audio_tvalid is assumed to be asserted all the time.
	// If it's not, it's an underrun, and there's nothing to do about
	// it anyhow.
	
	from_host_audio_tready <= 0; // Possibly overridden below
	
	if (bclk_rising && !audio_lrclk_reg && audio_lrclk_reg_d)
	  play_shreg <= from_host_audio_tdata[31:16]; // Left channel
	else if (bclk_rising && audio_lrclk_reg && !audio_lrclk_reg_d)
	  begin
	     play_shreg <= from_host_audio_tdata[15:0]; // Right channel
	     from_host_audio_tready <= 1;
	  end
	else if (bclk_falling)
	  begin
	     audio_dac <= play_shreg[15];
	     play_shreg <= { play_shreg, 1'b0 };
	  end

	// Recording

	// Same is with playback, to_host_audio_tvalid is asserted for
	// one clock cycle when the data is valid, and if the AXI-S receiver
	// wasn't ready, it's an overrun, and there's not much to do.

	to_host_audio_tvalid <= 0; // Possibly overridden below	
	
	if (bclk_rising && (record_count != 0))
	  begin
	     to_host_audio_tdata <= { to_host_audio_tdata, audio_adc_reg };
	     record_count <= record_count - 1;

	     if (record_count == 1)
	       begin
		  to_host_audio_tvalid <= write_when_done;
		  write_when_done <= 0;
	       end	       
	  end
		
	if (bclk_rising && !audio_lrclk_reg && audio_lrclk_reg_d)
	  begin
	     record_count <= 16;
	     write_when_done <= 0;
	  end	
	else if (bclk_rising && audio_lrclk_reg && !audio_lrclk_reg_d)
	  begin
	     record_count <= 16;
	     write_when_done <= 1;
	  end
     end   
endmodule 
