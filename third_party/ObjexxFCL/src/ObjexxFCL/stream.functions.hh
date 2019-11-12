#ifndef ObjexxFCL_stream_functions_hh_INCLUDED
#define ObjexxFCL_stream_functions_hh_INCLUDED

// Stream Functions
//
// Project: Objexx Fortran-C++ Library (ObjexxFCL)
//
// Version: 4.3.0
//
// Language: C++
//
// Copyright (c) 2000-2019 Objexx Engineering, Inc. All Rights Reserved.
// Use of this source code or any derivative of it is restricted by license.
// Licensing is available from Objexx Engineering, Inc.: https://objexx.com

// C++ Headers
#include <istream>
#include <string>

namespace ObjexxFCL {

// Is an Input Stream a File Stream?
bool
is_fstream( std::istream const & stream );

// Is an Output Stream a File Stream?
bool
is_fstream( std::ostream const & stream );

// Is an Input/Output Stream a File Stream?
bool
is_fstream( std::iostream const & stream );

// Is an Input Stream a String Stream?
bool
is_stringstream( std::istream const & stream );

// Is an Output Stream a String Stream?
bool
is_stringstream( std::ostream const & stream );

// Is an Input/Output Stream a String Stream?
bool
is_stringstream( std::iostream const & stream );

// Read a Line from a Text Input Stream: Cross-Platform: Linux (\n) or Windows (\r\n)
std::istream &
cross_platform_get_line( std::istream & stream, std::string & line );

// Read a Line from a Text Input Stream with an Extra Delimiter: Cross-Platform: Linux (\n) or Windows (\r\n)
std::istream &
cross_platform_get_line( std::istream & stream, std::string & line, char const delim );

// Auto-Detected Line Terminator from a Text Input Stream: Cross-Platform: Linux (\n) or Windows (\r\n)
std::string
line_terminator( std::istream & stream );

} // ObjexxFCL

#endif // ObjexxFCL_stream_functions_hh_INCLUDED
