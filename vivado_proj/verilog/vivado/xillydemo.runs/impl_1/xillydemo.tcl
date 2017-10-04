proc start_step { step } {
  set stopFile ".stop.rst"
  if {[file isfile .stop.rst]} {
    puts ""
    puts "*** Halting run - EA reset detected ***"
    puts ""
    puts ""
    return -code error
  }
  set beginFile ".$step.begin.rst"
  set platform "$::tcl_platform(platform)"
  set user "$::tcl_platform(user)"
  set pid [pid]
  set host ""
  if { [string equal $platform unix] } {
    if { [info exist ::env(HOSTNAME)] } {
      set host $::env(HOSTNAME)
    }
  } else {
    if { [info exist ::env(COMPUTERNAME)] } {
      set host $::env(COMPUTERNAME)
    }
  }
  set ch [open $beginFile w]
  puts $ch "<?xml version=\"1.0\"?>"
  puts $ch "<ProcessHandle Version=\"1\" Minor=\"0\">"
  puts $ch "    <Process Command=\".planAhead.\" Owner=\"$user\" Host=\"$host\" Pid=\"$pid\">"
  puts $ch "    </Process>"
  puts $ch "</ProcessHandle>"
  close $ch
}

proc end_step { step } {
  set endFile ".$step.end.rst"
  set ch [open $endFile w]
  close $ch
}

proc step_failed { step } {
  set endFile ".$step.error.rst"
  set ch [open $endFile w]
  close $ch
}

set_msg_config  -ruleid {1}  -id {BD 41-968}  -string {{xillybus_S_AXI}}  -new_severity {INFO} 
set_msg_config  -ruleid {2}  -id {BD 41-967}  -string {{xillybus_ip_0/xillybus_M_AXI}}  -new_severity {INFO} 
set_msg_config  -ruleid {3}  -id {BD 41-967}  -string {{xillybus_ip_0/xillybus_S_AXI}}  -new_severity {INFO} 
set_msg_config  -ruleid {4}  -id {BD 41-678}  -string {{xillybus_S_AXI/Reg}}  -new_severity {INFO} 
set_msg_config  -ruleid {5}  -id {BD 41-1356}  -string {{xillybus_S_AXI/Reg}}  -new_severity {INFO} 
set_msg_config  -ruleid {7}  -id {BD 41-759}  -string {{xlconcat_0/In}}  -new_severity {INFO} 
set_msg_config  -ruleid {8}  -id {Netlist 29-160}  -string {{vivado_system_processing_system7}}  -new_severity {INFO} 

start_step init_design
set ACTIVE_STEP init_design
set rc [catch {
  create_msg_db init_design.pb
  create_project -in_memory -part xc7z020clg484-1
  set_property design_mode GateLvl [current_fileset]
  set_param project.singleFileAddWarning.threshold 0
  set_property webtalk.parent_dir C:/xillinux-eval-zedboard-2.0a/verilog/vivado/xillydemo.cache/wt [current_project]
  set_property parent.project_path C:/xillinux-eval-zedboard-2.0a/verilog/vivado/xillydemo.xpr [current_project]
  set_property ip_repo_paths C:/xillinux-eval-zedboard-2.0a/vivado-essentials/vivado-ip [current_project]
  set_property ip_output_repo C:/xillinux-eval-zedboard-2.0a/verilog/vivado/xillydemo.cache/ip [current_project]
  set_property ip_cache_permissions {read write} [current_project]
  set_property XPM_LIBRARIES {XPM_CDC XPM_MEMORY} [current_project]
  add_files -quiet C:/xillinux-eval-zedboard-2.0a/verilog/vivado/xillydemo.runs/synth_1/xillydemo.dcp
  set_msg_config -source 4 -id {BD 41-1661} -suppress
  set_param project.isImplRun true
  add_files C:/xillinux-eval-zedboard-2.0a/vivado-essentials/vivado_system/vivado_system.bd
  set_property is_locked true [get_files C:/xillinux-eval-zedboard-2.0a/vivado-essentials/vivado_system/vivado_system.bd]
  read_ip -quiet C:/xillinux-eval-zedboard-2.0a/vivado-essentials/vga_fifo/vga_fifo.xci
  set_property is_locked true [get_files C:/xillinux-eval-zedboard-2.0a/vivado-essentials/vga_fifo/vga_fifo.xci]
  read_ip -quiet C:/xillinux-eval-zedboard-2.0a/vivado-essentials/fifo_8x2048/fifo_8x2048.xci
  set_property is_locked true [get_files C:/xillinux-eval-zedboard-2.0a/vivado-essentials/fifo_8x2048/fifo_8x2048.xci]
  read_ip -quiet C:/xillinux-eval-zedboard-2.0a/vivado-essentials/fifo_32x512/fifo_32x512.xci
  set_property is_locked true [get_files C:/xillinux-eval-zedboard-2.0a/vivado-essentials/fifo_32x512/fifo_32x512.xci]
  set_param project.isImplRun false
  set_property edif_extra_search_paths C:/xillinux-eval-zedboard-2.0a/cores [current_fileset]
  read_edif c:/xillinux-eval-zedboard-2.0a/vivado-essentials/vivado_system/system/pcores/xillybus_lite_v1_00_a/netlist/xillybus_lite.ngc
  add_files -quiet C:/hls-starter-1.0/coprocess/example/impl/ip/xillybus_wrapper.dcp
  read_xdc C:/xillinux-eval-zedboard-2.0a/vivado-essentials/xillydemo.xdc
  set_param project.isImplRun true
  link_design -top xillydemo -part xc7z020clg484-1
  set_param project.isImplRun false
  write_hwdef -force -file xillydemo.hwdef
  close_msg_db -file init_design.pb
} RESULT]
if {$rc} {
  step_failed init_design
  return -code error $RESULT
} else {
  end_step init_design
  unset ACTIVE_STEP 
}

start_step opt_design
set ACTIVE_STEP opt_design
set rc [catch {
  create_msg_db opt_design.pb
  opt_design 
  write_checkpoint -force xillydemo_opt.dcp
  catch { report_drc -file xillydemo_drc_opted.rpt }
  close_msg_db -file opt_design.pb
} RESULT]
if {$rc} {
  step_failed opt_design
  return -code error $RESULT
} else {
  end_step opt_design
  unset ACTIVE_STEP 
}

start_step place_design
set ACTIVE_STEP place_design
set rc [catch {
  create_msg_db place_design.pb
  implement_debug_core 
  place_design 
  write_checkpoint -force xillydemo_placed.dcp
  catch { report_io -file xillydemo_io_placed.rpt }
  catch { report_utilization -file xillydemo_utilization_placed.rpt -pb xillydemo_utilization_placed.pb }
  catch { report_control_sets -verbose -file xillydemo_control_sets_placed.rpt }
  close_msg_db -file place_design.pb
} RESULT]
if {$rc} {
  step_failed place_design
  return -code error $RESULT
} else {
  end_step place_design
  unset ACTIVE_STEP 
}

start_step route_design
set ACTIVE_STEP route_design
set rc [catch {
  create_msg_db route_design.pb
  route_design 
  set src_rc [catch { 
    puts "source C:/xillinux-eval-zedboard-2.0a/vivado-essentials/showstopper.tcl"
    source C:/xillinux-eval-zedboard-2.0a/vivado-essentials/showstopper.tcl
  } _RESULT] 
  if {$src_rc} { 
    send_msg_id runtcl-1 error "$_RESULT"
    send_msg_id runtcl-2 error "sourcing script C:/xillinux-eval-zedboard-2.0a/vivado-essentials/showstopper.tcl failed"
    return -code error
  }
  write_checkpoint -force xillydemo_routed.dcp
  catch { report_drc -file xillydemo_drc_routed.rpt -pb xillydemo_drc_routed.pb -rpx xillydemo_drc_routed.rpx }
  catch { report_methodology -file xillydemo_methodology_drc_routed.rpt -rpx xillydemo_methodology_drc_routed.rpx }
  catch { report_power -file xillydemo_power_routed.rpt -pb xillydemo_power_summary_routed.pb -rpx xillydemo_power_routed.rpx }
  catch { report_route_status -file xillydemo_route_status.rpt -pb xillydemo_route_status.pb }
  catch { report_clock_utilization -file xillydemo_clock_utilization_routed.rpt }
  catch { report_timing_summary -warn_on_violation -max_paths 10 -file xillydemo_timing_summary_routed.rpt -rpx xillydemo_timing_summary_routed.rpx }
  close_msg_db -file route_design.pb
} RESULT]
if {$rc} {
  write_checkpoint -force xillydemo_routed_error.dcp
  step_failed route_design
  return -code error $RESULT
} else {
  end_step route_design
  unset ACTIVE_STEP 
}

start_step write_bitstream
set ACTIVE_STEP write_bitstream
set rc [catch {
  create_msg_db write_bitstream.pb
  set_property XPM_LIBRARIES {XPM_CDC XPM_MEMORY} [current_project]
  catch { write_mem_info -force xillydemo.mmi }
  write_bitstream -force xillydemo.bit 
  catch { write_sysdef -hwdef xillydemo.hwdef -bitfile xillydemo.bit -meminfo xillydemo.mmi -file xillydemo.sysdef }
  catch {write_debug_probes -no_partial_ltxfile -quiet -force debug_nets}
  catch {file copy -force debug_nets.ltx xillydemo.ltx}
  close_msg_db -file write_bitstream.pb
} RESULT]
if {$rc} {
  step_failed write_bitstream
  return -code error $RESULT
} else {
  end_step write_bitstream
  unset ACTIVE_STEP 
}

