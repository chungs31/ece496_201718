# 1 "C:/hls-starter-1.0/coprocess/example/.autopilot/db/main.pragma.1.c"
# 1 "C:/hls-starter-1.0/coprocess/example/.autopilot/db/main.pragma.1.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 148 "<built-in>" 3
# 1 "<command line>" 1





# 1 "C:/Xilinx/Vivado_HLS/2017.2/common/technology/autopilot\\etc/autopilot_ssdm_op.h" 1
/* autopilot_ssdm_op.h*/
/*
#-  (c) Copyright 2011-2017 Xilinx, Inc. All rights reserved.
#-
#-  This file contains confidential and proprietary information
#-  of Xilinx, Inc. and is protected under U.S. and
#-  international copyright and other intellectual property
#-  laws.
#-
#-  DISCLAIMER
#-  This disclaimer is not a license and does not grant any
#-  rights to the materials distributed herewith. Except as
#-  otherwise provided in a valid license issued to you by
#-  Xilinx, and to the maximum extent permitted by applicable
#-  law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
#-  WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
#-  AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
#-  BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
#-  INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
#-  (2) Xilinx shall not be liable (whether in contract or tort,
#-  including negligence, or under any other theory of
#-  liability) for any loss or damage of any kind or nature
#-  related to, arising under or in connection with these
#-  materials, including for any direct, or any indirect,
#-  special, incidental, or consequential loss or damage
#-  (including loss of data, profits, goodwill, or any type of
#-  loss or damage suffered as a result of any action brought
#-  by a third party) even if such damage or loss was
#-  reasonably foreseeable or Xilinx had been advised of the
#-  possibility of the same.
#-
#-  CRITICAL APPLICATIONS
#-  Xilinx products are not designed or intended to be fail-
#-  safe, or for use in any application requiring fail-safe
#-  performance, such as life-support or safety devices or
#-  systems, Class III medical devices, nuclear facilities,
#-  applications related to the deployment of airbags, or any
#-  other applications that could lead to death, personal
#-  injury, or severe property or environmental damage
#-  (individually and collectively, "Critical
#-  Applications"). Customer assumes the sole risk and
#-  liability of any use of Xilinx products in Critical
#-  Applications, subject only to applicable laws and
#-  regulations governing limitations on product liability.
#-
#-  THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
#-  PART OF THIS FILE AT ALL TIMES. 
#- ************************************************************************

 *
 * $Id$
 */
# 289 "C:/Xilinx/Vivado_HLS/2017.2/common/technology/autopilot\\etc/autopilot_ssdm_op.h"
/*#define AP_SPEC_ATTR __attribute__ ((pure))*/



    /****** SSDM Intrinsics: OPERATIONS ***/
    // Interface operations
    //typedef unsigned int __attribute__ ((bitwidth(1))) _uint1_;
    void _ssdm_op_IfRead() __attribute__ ((nothrow));
    void _ssdm_op_IfWrite() __attribute__ ((nothrow));
    //_uint1_ _ssdm_op_IfNbRead() SSDM_OP_ATTR;
    //_uint1_ _ssdm_op_IfNbWrite() SSDM_OP_ATTR;
    //_uint1_ _ssdm_op_IfCanRead() SSDM_OP_ATTR;
    //_uint1_ _ssdm_op_IfCanWrite() SSDM_OP_ATTR;

    // Stream Intrinsics
    void _ssdm_StreamRead() __attribute__ ((nothrow));
    void _ssdm_StreamWrite() __attribute__ ((nothrow));
    //_uint1_  _ssdm_StreamNbRead() SSDM_OP_ATTR;
    //_uint1_  _ssdm_StreamNbWrite() SSDM_OP_ATTR;
    //_uint1_  _ssdm_StreamCanRead() SSDM_OP_ATTR;
    //_uint1_  _ssdm_StreamCanWrite() SSDM_OP_ATTR;

    // Misc
    void _ssdm_op_MemShiftRead() __attribute__ ((nothrow));

    void _ssdm_op_Wait() __attribute__ ((nothrow));
    void _ssdm_op_Poll() __attribute__ ((nothrow));

    void _ssdm_op_Return() __attribute__ ((nothrow));

    /* SSDM Intrinsics: SPECIFICATIONS */
    void _ssdm_op_SpecSynModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecTopModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDecl() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDef() __attribute__ ((nothrow));
    void _ssdm_op_SpecPort() __attribute__ ((nothrow));
    void _ssdm_op_SpecConnection() __attribute__ ((nothrow));
    void _ssdm_op_SpecChannel() __attribute__ ((nothrow));
    void _ssdm_op_SpecSensitive() __attribute__ ((nothrow));
    void _ssdm_op_SpecModuleInst() __attribute__ ((nothrow));
    void _ssdm_op_SpecPortMap() __attribute__ ((nothrow));

    void _ssdm_op_SpecReset() __attribute__ ((nothrow));

    void _ssdm_op_SpecPlatform() __attribute__ ((nothrow));
    void _ssdm_op_SpecClockDomain() __attribute__ ((nothrow));
    void _ssdm_op_SpecPowerDomain() __attribute__ ((nothrow));

    int _ssdm_op_SpecRegionBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecRegionEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopName() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopTripCount() __attribute__ ((nothrow));

    int _ssdm_op_SpecStateBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecStateEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecInterface() __attribute__ ((nothrow));

    void _ssdm_op_SpecPipeline() __attribute__ ((nothrow));
    void _ssdm_op_SpecDataflowPipeline() __attribute__ ((nothrow));


    void _ssdm_op_SpecLatency() __attribute__ ((nothrow));
    void _ssdm_op_SpecParallel() __attribute__ ((nothrow));
    void _ssdm_op_SpecProtocol() __attribute__ ((nothrow));
    void _ssdm_op_SpecOccurrence() __attribute__ ((nothrow));

    void _ssdm_op_SpecResource() __attribute__ ((nothrow));
    void _ssdm_op_SpecResourceLimit() __attribute__ ((nothrow));
    void _ssdm_op_SpecCHCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecFUCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIFCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIPCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecKeepValue() __attribute__ ((nothrow));
    void _ssdm_op_SpecMemCore() __attribute__ ((nothrow));

    void _ssdm_op_SpecExt() __attribute__ ((nothrow));
    /*void* _ssdm_op_SpecProcess() SSDM_SPEC_ATTR;
    void* _ssdm_op_SpecEdge() SSDM_SPEC_ATTR; */

    /* Presynthesis directive functions */
    void _ssdm_SpecArrayDimSize() __attribute__ ((nothrow));

    void _ssdm_RegionBegin() __attribute__ ((nothrow));
    void _ssdm_RegionEnd() __attribute__ ((nothrow));

    void _ssdm_Unroll() __attribute__ ((nothrow));
    void _ssdm_UnrollRegion() __attribute__ ((nothrow));

    void _ssdm_InlineAll() __attribute__ ((nothrow));
    void _ssdm_InlineLoop() __attribute__ ((nothrow));
    void _ssdm_Inline() __attribute__ ((nothrow));
    void _ssdm_InlineSelf() __attribute__ ((nothrow));
    void _ssdm_InlineRegion() __attribute__ ((nothrow));

    void _ssdm_SpecArrayMap() __attribute__ ((nothrow));
    void _ssdm_SpecArrayPartition() __attribute__ ((nothrow));
    void _ssdm_SpecArrayReshape() __attribute__ ((nothrow));

    void _ssdm_SpecStream() __attribute__ ((nothrow));

    void _ssdm_SpecExpr() __attribute__ ((nothrow));
    void _ssdm_SpecExprBalance() __attribute__ ((nothrow));

    void _ssdm_SpecDependence() __attribute__ ((nothrow));

    void _ssdm_SpecLoopMerge() __attribute__ ((nothrow));
    void _ssdm_SpecLoopFlatten() __attribute__ ((nothrow));
    void _ssdm_SpecLoopRewind() __attribute__ ((nothrow));

    void _ssdm_SpecFuncInstantiation() __attribute__ ((nothrow));
    void _ssdm_SpecFuncBuffer() __attribute__ ((nothrow));
    void _ssdm_SpecFuncExtract() __attribute__ ((nothrow));
    void _ssdm_SpecConstant() __attribute__ ((nothrow));

    void _ssdm_DataPack() __attribute__ ((nothrow));
    void _ssdm_SpecDataPack() __attribute__ ((nothrow));

    void _ssdm_op_SpecBitsMap() __attribute__ ((nothrow));
    void _ssdm_op_SpecLicense() __attribute__ ((nothrow));


/*#define _ssdm_op_WaitUntil(X) while (!(X)) _ssdm_op_Wait(1);
#define _ssdm_op_Delayed(X) X */
# 427 "C:/Xilinx/Vivado_HLS/2017.2/common/technology/autopilot\\etc/autopilot_ssdm_op.h"
// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
# 7 "<command line>" 2
# 1 "<built-in>" 2
# 1 "C:/hls-starter-1.0/coprocess/example/.autopilot/db/main.pragma.1.c" 2
# 1 "coprocess/example/src/main.c"
# 1 "coprocess/example/src/main.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 148 "<built-in>" 3
# 1 "<command line>" 1





# 1 "C:/Xilinx/Vivado_HLS/2017.2/common/technology/autopilot\\etc/autopilot_ssdm_op.h" 1
/* autopilot_ssdm_op.h*/
/*
#-  (c) Copyright 2011-2017 Xilinx, Inc. All rights reserved.
#-
#-  This file contains confidential and proprietary information
#-  of Xilinx, Inc. and is protected under U.S. and
#-  international copyright and other intellectual property
#-  laws.
#-
#-  DISCLAIMER
#-  This disclaimer is not a license and does not grant any
#-  rights to the materials distributed herewith. Except as
#-  otherwise provided in a valid license issued to you by
#-  Xilinx, and to the maximum extent permitted by applicable
#-  law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
#-  WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
#-  AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
#-  BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
#-  INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
#-  (2) Xilinx shall not be liable (whether in contract or tort,
#-  including negligence, or under any other theory of
#-  liability) for any loss or damage of any kind or nature
#-  related to, arising under or in connection with these
#-  materials, including for any direct, or any indirect,
#-  special, incidental, or consequential loss or damage
#-  (including loss of data, profits, goodwill, or any type of
#-  loss or damage suffered as a result of any action brought
#-  by a third party) even if such damage or loss was
#-  reasonably foreseeable or Xilinx had been advised of the
#-  possibility of the same.
#-
#-  CRITICAL APPLICATIONS
#-  Xilinx products are not designed or intended to be fail-
#-  safe, or for use in any application requiring fail-safe
#-  performance, such as life-support or safety devices or
#-  systems, Class III medical devices, nuclear facilities,
#-  applications related to the deployment of airbags, or any
#-  other applications that could lead to death, personal
#-  injury, or severe property or environmental damage
#-  (individually and collectively, "Critical
#-  Applications"). Customer assumes the sole risk and
#-  liability of any use of Xilinx products in Critical
#-  Applications, subject only to applicable laws and
#-  regulations governing limitations on product liability.
#-
#-  THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
#-  PART OF THIS FILE AT ALL TIMES. 
#- ************************************************************************

 *
 * $Id$
 */
# 289 "C:/Xilinx/Vivado_HLS/2017.2/common/technology/autopilot\\etc/autopilot_ssdm_op.h"
/*#define AP_SPEC_ATTR __attribute__ ((pure))*/



    /****** SSDM Intrinsics: OPERATIONS ***/
    // Interface operations
    //typedef unsigned int __attribute__ ((bitwidth(1))) _uint1_;
    void _ssdm_op_IfRead() __attribute__ ((nothrow));
    void _ssdm_op_IfWrite() __attribute__ ((nothrow));
    //_uint1_ _ssdm_op_IfNbRead() SSDM_OP_ATTR;
    //_uint1_ _ssdm_op_IfNbWrite() SSDM_OP_ATTR;
    //_uint1_ _ssdm_op_IfCanRead() SSDM_OP_ATTR;
    //_uint1_ _ssdm_op_IfCanWrite() SSDM_OP_ATTR;

    // Stream Intrinsics
    void _ssdm_StreamRead() __attribute__ ((nothrow));
    void _ssdm_StreamWrite() __attribute__ ((nothrow));
    //_uint1_  _ssdm_StreamNbRead() SSDM_OP_ATTR;
    //_uint1_  _ssdm_StreamNbWrite() SSDM_OP_ATTR;
    //_uint1_  _ssdm_StreamCanRead() SSDM_OP_ATTR;
    //_uint1_  _ssdm_StreamCanWrite() SSDM_OP_ATTR;

    // Misc
    void _ssdm_op_MemShiftRead() __attribute__ ((nothrow));

    void _ssdm_op_Wait() __attribute__ ((nothrow));
    void _ssdm_op_Poll() __attribute__ ((nothrow));

    void _ssdm_op_Return() __attribute__ ((nothrow));

    /* SSDM Intrinsics: SPECIFICATIONS */
    void _ssdm_op_SpecSynModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecTopModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDecl() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDef() __attribute__ ((nothrow));
    void _ssdm_op_SpecPort() __attribute__ ((nothrow));
    void _ssdm_op_SpecConnection() __attribute__ ((nothrow));
    void _ssdm_op_SpecChannel() __attribute__ ((nothrow));
    void _ssdm_op_SpecSensitive() __attribute__ ((nothrow));
    void _ssdm_op_SpecModuleInst() __attribute__ ((nothrow));
    void _ssdm_op_SpecPortMap() __attribute__ ((nothrow));

    void _ssdm_op_SpecReset() __attribute__ ((nothrow));

    void _ssdm_op_SpecPlatform() __attribute__ ((nothrow));
    void _ssdm_op_SpecClockDomain() __attribute__ ((nothrow));
    void _ssdm_op_SpecPowerDomain() __attribute__ ((nothrow));

    int _ssdm_op_SpecRegionBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecRegionEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopName() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopTripCount() __attribute__ ((nothrow));

    int _ssdm_op_SpecStateBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecStateEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecInterface() __attribute__ ((nothrow));

    void _ssdm_op_SpecPipeline() __attribute__ ((nothrow));
    void _ssdm_op_SpecDataflowPipeline() __attribute__ ((nothrow));


    void _ssdm_op_SpecLatency() __attribute__ ((nothrow));
    void _ssdm_op_SpecParallel() __attribute__ ((nothrow));
    void _ssdm_op_SpecProtocol() __attribute__ ((nothrow));
    void _ssdm_op_SpecOccurrence() __attribute__ ((nothrow));

    void _ssdm_op_SpecResource() __attribute__ ((nothrow));
    void _ssdm_op_SpecResourceLimit() __attribute__ ((nothrow));
    void _ssdm_op_SpecCHCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecFUCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIFCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIPCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecKeepValue() __attribute__ ((nothrow));
    void _ssdm_op_SpecMemCore() __attribute__ ((nothrow));

    void _ssdm_op_SpecExt() __attribute__ ((nothrow));
    /*void* _ssdm_op_SpecProcess() SSDM_SPEC_ATTR;
    void* _ssdm_op_SpecEdge() SSDM_SPEC_ATTR; */

    /* Presynthesis directive functions */
    void _ssdm_SpecArrayDimSize() __attribute__ ((nothrow));

    void _ssdm_RegionBegin() __attribute__ ((nothrow));
    void _ssdm_RegionEnd() __attribute__ ((nothrow));

    void _ssdm_Unroll() __attribute__ ((nothrow));
    void _ssdm_UnrollRegion() __attribute__ ((nothrow));

    void _ssdm_InlineAll() __attribute__ ((nothrow));
    void _ssdm_InlineLoop() __attribute__ ((nothrow));
    void _ssdm_Inline() __attribute__ ((nothrow));
    void _ssdm_InlineSelf() __attribute__ ((nothrow));
    void _ssdm_InlineRegion() __attribute__ ((nothrow));

    void _ssdm_SpecArrayMap() __attribute__ ((nothrow));
    void _ssdm_SpecArrayPartition() __attribute__ ((nothrow));
    void _ssdm_SpecArrayReshape() __attribute__ ((nothrow));

    void _ssdm_SpecStream() __attribute__ ((nothrow));

    void _ssdm_SpecExpr() __attribute__ ((nothrow));
    void _ssdm_SpecExprBalance() __attribute__ ((nothrow));

    void _ssdm_SpecDependence() __attribute__ ((nothrow));

    void _ssdm_SpecLoopMerge() __attribute__ ((nothrow));
    void _ssdm_SpecLoopFlatten() __attribute__ ((nothrow));
    void _ssdm_SpecLoopRewind() __attribute__ ((nothrow));

    void _ssdm_SpecFuncInstantiation() __attribute__ ((nothrow));
    void _ssdm_SpecFuncBuffer() __attribute__ ((nothrow));
    void _ssdm_SpecFuncExtract() __attribute__ ((nothrow));
    void _ssdm_SpecConstant() __attribute__ ((nothrow));

    void _ssdm_DataPack() __attribute__ ((nothrow));
    void _ssdm_SpecDataPack() __attribute__ ((nothrow));

    void _ssdm_op_SpecBitsMap() __attribute__ ((nothrow));
    void _ssdm_op_SpecLicense() __attribute__ ((nothrow));


/*#define _ssdm_op_WaitUntil(X) while (!(X)) _ssdm_op_Wait(1);
#define _ssdm_op_Delayed(X) X */
# 427 "C:/Xilinx/Vivado_HLS/2017.2/common/technology/autopilot\\etc/autopilot_ssdm_op.h"
// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
# 7 "<command line>" 2
# 1 "<built-in>" 2
# 1 "coprocess/example/src/main.c" 2
# 1 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 1 3
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
# 10 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3


# 1 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */






# 1 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/_mingw_mac.h" 1 3
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
# 18 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/_mingw_mac.h" 3
/* mingw.org's version macros: these make gcc to define
   MINGW32_SUPPORTS_MT_EH and to use the _CRT_MT global
   and the __mingwthr_key_dtor() function from the MinGW
   CRT in its private gthr-win32.h header. */
# 47 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/_mingw_mac.h" 3
/* For 32-bits we have always to prefix by underscore.  */
# 62 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/_mingw_mac.h" 3
/* Use alias for msvcr80 export of get/set_output_format.  */




/* Set VC specific compiler target macros.  */
# 79 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/_mingw_mac.h" 3
/* This gives wrong (600 instead of 300) value if -march=i386 is specified
   but we cannot check for__i386__ as it is defined for all 32-bit CPUs. */
# 10 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3


/* C/C++ specific language defines.  */
# 32 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
/* Note the extern. This is needed to work around GCC's
limitations in handling dllimport attribute.  */
# 147 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
/* Attribute `nonnull' was valid as of gcc 3.3.  We don't use GCC's
   variadiac macro facility, because variadic macros cause syntax
   errors with  --traditional-cpp.  */
# 225 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
/*  High byte is the major version, low byte is the minor. */
# 277 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
# 1 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 1 3
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
# 14 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 3
# 1 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
# 674 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
# 1 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/sdks/_mingw_directx.h" 1 3
# 674 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3

# 1 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/sdks/_mingw_ddk.h" 1 3
# 675 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3
# 13 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 2 3


#pragma pack(push,_CRT_PACKING)








 typedef __builtin_va_list __gnuc_va_list;






  typedef __gnuc_va_list va_list;
# 46 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 3
/* Use GCC builtins */
# 102 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 3
#pragma pack(pop)
# 277 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3


#pragma pack(push,_CRT_PACKING)
# 316 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
/* We have to define _DLL for gcc based mingw version. This define is set
   by VC, when DLL-based runtime is used. So, gcc based runtime just have
   DLL-base runtime, therefore this define has to be set.
   As our headers are possibly used by windows compiler having a static
   C-runtime, we make this definition gnu compiler specific here.  */
# 372 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
typedef unsigned int size_t;
# 382 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
typedef int ssize_t;
# 394 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
typedef int intptr_t;
# 407 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
typedef unsigned int uintptr_t;
# 420 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
typedef int ptrdiff_t;







typedef unsigned short wchar_t;







typedef unsigned short wint_t;
typedef unsigned short wctype_t;
# 456 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
typedef int errno_t;




typedef long __time32_t;




__extension__ typedef long long __time64_t;





typedef __time32_t time_t;
# 518 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
/* _dowildcard is an int that controls the globbing of the command line.
 * The MinGW32 (mingw.org) runtime calls it _CRT_glob, so we are adding
 * a compatibility definition here:  you can use either of _CRT_glob or
 * _dowildcard .
 * If _dowildcard is non-zero, the command line will be globbed:  *.*
 * will be expanded to be all files in the startup directory.
 * In the mingw-w64 library a _dowildcard variable is defined as being
 * 0, therefore command line globbing is DISABLED by default. To turn it
 * on and to leave wildcard command line processing MS's globbing code,
 * include a line in one of your source modules defining _dowildcard and
 * setting it to -1, like so:
 * int _dowildcard = -1;
 */
# 605 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
/* MSVC-isms: */

struct threadlocaleinfostruct;
struct threadmbcinfostruct;
typedef struct threadlocaleinfostruct *pthreadlocinfo;
typedef struct threadmbcinfostruct *pthreadmbcinfo;
struct __lc_time_data;

typedef struct localeinfo_struct {
  pthreadlocinfo locinfo;
  pthreadmbcinfo mbcinfo;
} _locale_tstruct,*_locale_t;



typedef struct tagLC_ID {
  unsigned short wLanguage;
  unsigned short wCountry;
  unsigned short wCodePage;
} LC_ID,*LPLC_ID;




typedef struct threadlocaleinfostruct {
  int refcount;
  unsigned int lc_codepage;
  unsigned int lc_collate_cp;
  unsigned long lc_handle[6];
  LC_ID lc_id[6];
  struct {
    char *locale;
    wchar_t *wlocale;
    int *refcount;
    int *wrefcount;
  } lc_category[6];
  int lc_clike;
  int mb_cur_max;
  int *lconv_intl_refcount;
  int *lconv_num_refcount;
  int *lconv_mon_refcount;
  struct lconv *lconv;
  int *ctype1_refcount;
  unsigned short *ctype1;
  const unsigned short *pctype;
  const unsigned char *pclmap;
  const unsigned char *pcumap;
  struct __lc_time_data *lc_time_curr;
} threadlocinfo;






/* mingw-w64 specific functions: */
const char *__mingw_get_crt_info (void);





#pragma pack(pop)
# 12 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 2 3


struct _exception;

#pragma pack(push,_CRT_PACKING)
# 55 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
/* See also float.h  */


/* IEEE 754 classication */
# 79 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
 extern double * _imp___HUGE;
# 91 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
 struct _exception {
    int type;
    const char *name;
    double arg1;
    double arg2;
    double retval;
  };

  void __mingw_raise_matherr (int typ, const char *name, double a1, double a2,
         double rslt);
  void __mingw_setusermatherr (int ( *)(struct _exception *));
  __attribute__ ((__dllimport__)) void __setusermatherr(int ( *)(struct _exception *));



  double sin(double _X);
  double cos(double _X);
  double tan(double _X);
  double sinh(double _X);
  double cosh(double _X);
  double tanh(double _X);
  double asin(double _X);
  double acos(double _X);
  double atan(double _X);
  double atan2(double _Y,double _X);
  double exp(double _X);
  double log(double _X);
  double log10(double _X);
  double pow(double _X,double _Y);
  double sqrt(double _X);
  double ceil(double _X);
  double floor(double _X);
  double fabs(double _X);
# 135 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
 double ldexp(double _X,int _Y);
  double frexp(double _X,int *_Y);
  double modf(double _X,double *_Y);
  double fmod(double _X,double _Y);

  void sincos (double __x, double *p_sin, double *p_cos);
  void sincosl (long double __x, long double *p_sin, long double *p_cos);
  void sincosf (float __x, float *p_sin, float *p_cos);



  int abs(int _X);
  long labs(long _X);



  double atof(const char *_String);
  double _atof_l(const char *_String,_locale_t _Locale);
# 162 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
 struct _complex {
    double x;
    double y;
  };


  __attribute__ ((__dllimport__)) double _cabs(struct _complex _ComplexA);
  double _hypot(double _X,double _Y);
  __attribute__ ((__dllimport__)) double _j0(double _X);
  __attribute__ ((__dllimport__)) double _j1(double _X);
  __attribute__ ((__dllimport__)) double _jn(int _X,double _Y);
  __attribute__ ((__dllimport__)) double _y0(double _X);
  __attribute__ ((__dllimport__)) double _y1(double _X);
  __attribute__ ((__dllimport__)) double _yn(int _X,double _Y);


  __attribute__ ((__dllimport__)) int _matherr (struct _exception *);


/* These are also declared in Mingw float.h; needed here as well to work 
   around GCC build issues.  */
/* BEGIN FLOAT.H COPY */
/*
 * IEEE recommended functions
 */


  __attribute__ ((__dllimport__)) double _chgsign (double _X);
  __attribute__ ((__dllimport__)) double _copysign (double _Number,double _Sign);
  __attribute__ ((__dllimport__)) double _logb (double);
  __attribute__ ((__dllimport__)) double _nextafter (double, double);
  __attribute__ ((__dllimport__)) double _scalb (double, long);
  __attribute__ ((__dllimport__)) int _finite (double);
  __attribute__ ((__dllimport__)) int _fpclass (double);
  __attribute__ ((__dllimport__)) int _isnan (double);


/* END FLOAT.H COPY */



__attribute__ ((__dllimport__)) double j0 (double) ;
__attribute__ ((__dllimport__)) double j1 (double) ;
__attribute__ ((__dllimport__)) double jn (int, double) ;
__attribute__ ((__dllimport__)) double y0 (double) ;
__attribute__ ((__dllimport__)) double y1 (double) ;
__attribute__ ((__dllimport__)) double yn (int, double) ;

__attribute__ ((__dllimport__)) double chgsign (double);
/*
 * scalb() is a GCC built-in.
 * Exclude this _scalb() stub; the semantics are incompatible
 * with the built-in implementation.
 *
_CRTIMP double __cdecl scalb (double, long);
 *
 */
  __attribute__ ((__dllimport__)) int finite (double);
  __attribute__ ((__dllimport__)) int fpclass (double);
# 236 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
 __attribute__ ((__dllimport__)) int _set_SSE2_enable(int _Flag);
# 260 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
/* Use the compiler's builtin define for FLT_EVAL_METHOD to
   set float_t and double_t.  */


typedef float float_t;
typedef double double_t;
# 278 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
/* 7.12.3.1 */
/*
   Return values for fpclassify.
   These are based on Intel x87 fpu condition codes
   in the high byte of status word and differ from
   the return values for MS IEEE 754 extension _fpclass()
*/





/* 0x0200 is signbit mask */

/*
  We can't inline float or double, because we want to ensure truncation
  to semantic type before classification. 
  (A normal long double value might become subnormal when 
  converted to double, and zero when converted to float.)
*/

  extern int __fpclassifyl (long double);
  extern int __fpclassifyf (float);
  extern int __fpclassify (double);
# 325 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
/* 7.12.3.2 */


/* 7.12.3.3 */


/* 7.12.3.4 */
/* We don't need to worry about truncation here:
   A NaN stays a NaN. */

  extern int __isnan (double);
  extern int __isnanf (float);
  extern int __isnanl (long double);
# 372 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
/* 7.12.3.5 */


/* 7.12.3.6 The signbit macro */
  extern int __signbit (double);
  extern int __signbitf (float);
  extern int __signbitl (long double);
# 403 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
/* 7.12.4 Trigonometric functions: Double in C89 */
  extern float sinf(float _X);
  extern long double sinl(long double);

  extern float cosf(float _X);
  extern long double cosl(long double);

  extern float tanf(float _X);
  extern long double tanl(long double);
  extern float asinf(float _X);
  extern long double asinl(long double);

  extern float acosf (float);
  extern long double acosl (long double);

  extern float atanf (float);
  extern long double atanl (long double);

  extern float atan2f (float, float);
  extern long double atan2l (long double, long double);

/* 7.12.5 Hyperbolic functions: Double in C89  */
  extern float sinhf(float _X);



  extern long double sinhl(long double);

  extern float coshf(float _X);



  extern long double coshl(long double);

  extern float tanhf(float _X);



  extern long double tanhl(long double);

/* Inverse hyperbolic trig functions  */
/* 7.12.5.1 */
  extern double acosh (double);
  extern float acoshf (float);
  extern long double acoshl (long double);

/* 7.12.5.2 */
  extern double asinh (double);
  extern float asinhf (float);
  extern long double asinhl (long double);

/* 7.12.5.3 */
  extern double atanh (double);
  extern float atanhf (float);
  extern long double atanhl (long double);

/* Exponentials and logarithms  */
/* 7.12.6.1 Double in C89 */
  extern float expf(float _X);



  extern long double expl(long double);

/* 7.12.6.2 */
  extern double exp2(double);
  extern float exp2f(float);
  extern long double exp2l(long double);

/* 7.12.6.3 The expm1 functions */
/* TODO: These could be inlined */
  extern double expm1(double);
  extern float expm1f(float);
  extern long double expm1l(long double);

/* 7.12.6.4 Double in C89 */
  extern float frexpf(float _X,int *_Y);



  extern long double frexpl(long double,int *);

/* 7.12.6.5 */


  extern int ilogb (double);
  extern int ilogbf (float);
  extern int ilogbl (long double);

/* 7.12.6.6  Double in C89 */
  extern float ldexpf(float _X,int _Y);



  extern long double ldexpl (long double, int);

/* 7.12.6.7 Double in C89 */
  extern float logf (float);
  extern long double logl(long double);

/* 7.12.6.8 Double in C89 */
  extern float log10f (float);
  extern long double log10l(long double);

/* 7.12.6.9 */
  extern double log1p(double);
  extern float log1pf(float);
  extern long double log1pl(long double);

/* 7.12.6.10 */
  extern double log2 (double);
  extern float log2f (float);
  extern long double log2l (long double);

/* 7.12.6.11 */
  extern double logb (double);
  extern float logbf (float);
  extern long double logbl (long double);

/* Inline versions.  GCC-4.0+ can do a better fast-math optimization
   with __builtins. */
# 552 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
/* 7.12.6.12  Double in C89 */
  extern float modff (float, float*);
  extern long double modfl (long double, long double*);

/* 7.12.6.13 */
  extern double scalbn (double, int);
  extern float scalbnf (float, int);
  extern long double scalbnl (long double, int);

  extern double scalbln (double, long);
  extern float scalblnf (float, long);
  extern long double scalblnl (long double, long);

/* 7.12.7.1 */
/* Implementations adapted from Cephes versions */
  extern double cbrt (double);
  extern float cbrtf (float);
  extern long double cbrtl (long double);

/* 7.12.7.2 The fabs functions: Double in C89 */
  extern float fabsf (float x);
# 583 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
 extern long double fabsl (long double);
# 594 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
/* 7.12.7.3  */
  extern double hypot (double, double) ; /* in libmoldname.a */
  extern float hypotf (float x, float y);



  extern long double hypotl (long double, long double);

/* 7.12.7.4 The pow functions. Double in C89 */
  extern float powf(float _X,float _Y);



  extern long double powl (long double, long double);

/* 7.12.7.5 The sqrt functions. Double in C89. */
  extern float sqrtf (float);
  extern long double sqrtl(long double);

/* 7.12.8.1 The erf functions  */
  extern double erf (double);
  extern float erff (float);
  extern long double erfl (long double);

/* 7.12.8.2 The erfc functions  */
  extern double erfc (double);
  extern float erfcf (float);
  extern long double erfcl (long double);

/* 7.12.8.3 The lgamma functions */
  extern double lgamma (double);
  extern float lgammaf (float);
  extern long double lgammal (long double);

/* 7.12.8.4 The tgamma functions */
  extern double tgamma (double);
  extern float tgammaf (float);
  extern long double tgammal (long double);

/* 7.12.9.1 Double in C89 */
  extern float ceilf (float);
  extern long double ceill (long double);

/* 7.12.9.2 Double in C89 */
  extern float floorf (float);
  extern long double floorl (long double);

/* 7.12.9.3 */
  extern double nearbyint ( double);
  extern float nearbyintf (float);
  extern long double nearbyintl (long double);

/* 7.12.9.4 */
/* round, using fpu control word settings */
extern double rint (double);
extern float rintf (float);
extern long double rintl (long double);

/* 7.12.9.5 */
extern long lrint (double);
extern long lrintf (float);
extern long lrintl (long double);

__extension__ long long llrint (double);
__extension__ long long llrintf (float);
__extension__ long long llrintl (long double);

/* Inline versions of above. 
   GCC 4.0+ can do a better fast-math job with __builtins. */
# 737 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
/* 7.12.9.6 */
/* round away from zero, regardless of fpu control word settings */
  extern double round (double);
  extern float roundf (float);
  extern long double roundl (long double);

/* 7.12.9.7  */
  extern long lround (double);
  extern long lroundf (float);
  extern long lroundl (long double);
  __extension__ long long llround (double);
  __extension__ long long llroundf (float);
  __extension__ long long llroundl (long double);

/* 7.12.9.8 */
/* round towards zero, regardless of fpu control word settings */
  extern double trunc (double);
  extern float truncf (float);
  extern long double truncl (long double);

/* 7.12.10.1 Double in C89 */
  extern float fmodf (float, float);
  extern long double fmodl (long double, long double);

/* 7.12.10.2 */
  extern double remainder (double, double);
  extern float remainderf (float, float);
  extern long double remainderl (long double, long double);

/* 7.12.10.3 */
  extern double remquo(double, double, int *);
  extern float remquof(float, float, int *);
  extern long double remquol(long double, long double, int *);

/* 7.12.11.1 */
  extern double copysign (double, double); /* in libmoldname.a */
  extern float copysignf (float, float);
  extern long double copysignl (long double, long double);

/* 7.12.11.2 Return a NaN */
  extern double nan(const char *tagp);
  extern float nanf(const char *tagp);
  extern long double nanl(const char *tagp);







/* 7.12.11.3 */
  extern double nextafter (double, double); /* in libmoldname.a */
  extern float nextafterf (float, float);
  extern long double nextafterl (long double, long double);

/* 7.12.11.4 The nexttoward functions */
  extern double nexttoward (double, long double);
  extern float nexttowardf (float, long double);
  extern long double nexttowardl (long double, long double);

/* 7.12.12.1 */
/*  x > y ? (x - y) : 0.0  */
  extern double fdim (double x, double y);
  extern float fdimf (float x, float y);
  extern long double fdiml (long double x, long double y);

/* fmax and fmin.
   NaN arguments are treated as missing data: if one argument is a NaN
   and the other numeric, then these functions choose the numeric
   value. */

/* 7.12.12.2 */
  extern double fmax (double, double);
  extern float fmaxf (float, float);
  extern long double fmaxl (long double, long double);

/* 7.12.12.3 */
  extern double fmin (double, double);
  extern float fminf (float, float);
  extern long double fminl (long double, long double);

/* 7.12.13.1 */
/* return x * y + z as a ternary op */
  extern double fma (double, double, double);
  extern float fmaf (float, float, float);
  extern long double fmal (long double, long double, long double);

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */
# 867 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
 __attribute__ ((__dllimport__)) float _hypotf(float _X,float _Y);



   __attribute__ ((__dllimport__)) float _copysignf (float _Number,float _Sign);
   __attribute__ ((__dllimport__)) float _chgsignf (float _X);
   __attribute__ ((__dllimport__)) float _logbf(float _X);
   __attribute__ ((__dllimport__)) float _nextafterf(float _X,float _Y);
   __attribute__ ((__dllimport__)) int _finitef(float _X);
   __attribute__ ((__dllimport__)) int _isnanf(float _X);
   __attribute__ ((__dllimport__)) int _fpclassf(float _X);



   extern long double _chgsignl (long double);
# 898 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\math.h" 3
#pragma pack(pop)
# 2 "coprocess/example/src/main.c" 2
# 1 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/include\\stdint.h" 1 3 4
/*===---- stdint.h - Standard header for sized integer types --------------===*\
 *
 * Copyright (c) 2009 Chris Lattner
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
\*===----------------------------------------------------------------------===*/




/* If we're hosted, fall back to the system's stdint.h, which might have
 * additional definitions.
 */




# 1 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdint.h" 1 3 4
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
/* ISO C9x  7.18  Integer types <stdint.h>
 * Based on ISO/IEC SC22/WG14 9899 Committee draft (SC22 N2794)
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  Contributor: Danny Smith <danny_r_smith_2001@yahoo.co.nz>
 *
 *  This source code is offered for use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *  Date: 2000-12-02
 */







# 1 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3 4
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
# 28 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdint.h" 2 3 4




# 1 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/include\\stddef.h" 1 3 4
/*===---- stddef.h - Basic type definitions --------------------------------===
 *
 * Copyright (c) 2008 Eli Friedman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *===-----------------------------------------------------------------------===
 */






typedef __typeof__(((int*)0)-((int*)0)) ptrdiff_t;



typedef __typeof__(sizeof(int)) size_t;




typedef unsigned short wchar_t;
# 56 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/include\\stddef.h" 3 4
/* Some C libraries expect to see a wint_t here. Others (notably MinGW) will use
__WINT_TYPE__ directly; accommodate both by requiring __need_wint_t */
# 32 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdint.h" 2 3 4


/* 7.18.1.1  Exact-width integer types */
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned uint32_t;
__extension__ typedef long long int64_t;
__extension__ typedef unsigned long long uint64_t;

/* 7.18.1.2  Minimum-width integer types */
typedef signed char int_least8_t;
typedef unsigned char uint_least8_t;
typedef short int_least16_t;
typedef unsigned short uint_least16_t;
typedef int int_least32_t;
typedef unsigned uint_least32_t;
__extension__ typedef long long int_least64_t;
__extension__ typedef unsigned long long uint_least64_t;

/*  7.18.1.3  Fastest minimum-width integer types
 *  Not actually guaranteed to be fastest for all purposes
 *  Here we use the exact-width types for 8 and 16-bit ints.
 */
typedef signed char int_fast8_t;
typedef unsigned char uint_fast8_t;
typedef short int_fast16_t;
typedef unsigned short uint_fast16_t;
typedef int int_fast32_t;
typedef unsigned int uint_fast32_t;
__extension__ typedef long long int_fast64_t;
__extension__ typedef unsigned long long uint_fast64_t;

/* 7.18.1.5  Greatest-width integer types */
__extension__ typedef long long intmax_t;
__extension__ typedef unsigned long long uintmax_t;

/* 7.18.2  Limits of specified-width integer types */


/* 7.18.2.1  Limits of exact-width integer types */
# 90 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdint.h" 3 4
/* 7.18.2.2  Limits of minimum-width integer types */
# 106 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdint.h" 3 4
/* 7.18.2.3  Limits of fastest minimum-width integer types */
# 122 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdint.h" 3 4
/* 7.18.2.4  Limits of integer types capable of holding
    object pointers */
# 134 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdint.h" 3 4
/* 7.18.2.5  Limits of greatest-width integer types */




/* 7.18.3  Limits of other integer types */
# 164 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdint.h" 3 4
/*
 * wint_t is unsigned short for compatibility with MS runtime
 */






/* 7.18.4  Macros for integer constants */


/* 7.18.4.1  Macros for minimum-width integer constants

    Accoding to Douglas Gwyn <gwyn@arl.mil>:
	"This spec was changed in ISO/IEC 9899:1999 TC1; in ISO/IEC
	9899:1999 as initially published, the expansion was required
	to be an integer constant of precisely matching type, which
	is impossible to accomplish for the shorter types on most
	platforms, because C99 provides no standard way to designate
	an integer constant with width less than that of type int.
	TC1 changed this to require just an integer constant
	*expression* with *promoted* type."

	The trick used here is from Clive D W Feather.
*/




/*  The 'trick' doesn't work in C89 for long long because, without
    suffix, (val) will be evaluated as int, not intmax_t */







/* 7.18.4.2  Macros for greatest-width integer constants */
# 33 "C:/Xilinx/Vivado_HLS/2017.2/win64/tools/clang/bin/../lib/clang/3.1/include\\stdint.h" 2 3 4
# 3 "coprocess/example/src/main.c" 2
# 1 "coprocess/example/src/xilly_debug.h" 1





void xilly_puts(const char *);
void xilly_hexprint(const uint32_t, const int);
void xilly_decprint(const uint32_t, const int);
# 4 "coprocess/example/src/main.c" 2

extern float sinf(float);

int mycalc(int a, float *x2) {
  *x2 = sinf(*x2);
  return a + 1;
}

void xillybus_wrapper(int *in, int *out) {
_ssdm_op_SpecInterface(in, "ap_fifo", 0, 0, "", 0, 0, "", "", "", 0, 0, 0, 0, "", "");
_ssdm_op_SpecInterface(out, "ap_fifo", 0, 0, "", 0, 0, "", "", "", 0, 0, 0, 0, "", "");
_ssdm_op_SpecInterface(0, "ap_ctrl_none", 0, 0, "", 0, 0, "", "", "", 0, 0, 0, 0, "", "");

 uint32_t x1, tmp, y1;
  float x2, y2;

  xilly_puts("Hello, world\n");

  // Handle input data
  x1 = *in++;
  tmp = *in++;
  x2 = *((float *) &tmp); // Convert uint32_t to float

  // Debug output
  xilly_puts("x1=");
  xilly_decprint(x1, 1);
  xilly_puts("\n");

  // Run the calculations
  y1 = mycalc(x1, &x2);
  y2 = x2; // This helps HLS in the conversion below

  // Handle output data
  tmp = *((uint32_t *) &y2); // Convert float to uint32_t
  *out++ = y1;
  *out++ = tmp;
}
