// Formatted Read Support
//
// Project: Objexx Fortran-C++ Library (ObjexxFCL)
//
// Version: 4.3.0
//
// Language: C++
//
// Copyright (c) 2000-2020 Objexx Engineering, Inc. All Rights Reserved.
// Use of this source code or any derivative of it is restricted by license.
// Licensing is available from Objexx Engineering, Inc.: https://objexx.com

// ObjexxFCL Headers
#include <ObjexxFCL/Read.hh>

namespace ObjexxFCL {

// Static Data Member Definitions
#ifndef OBJEXXFCL_THREADS
std::istringstream ReadStream::internal_stream_; // Internal stream
#endif

} // ObjexxFCL
