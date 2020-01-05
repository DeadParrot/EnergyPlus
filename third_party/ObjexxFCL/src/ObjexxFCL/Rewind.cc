// Rewind Support
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
#include <ObjexxFCL/Rewind.hh>
#include <ObjexxFCL/IOFlags.hh>

// C++ Headers
#include <cassert>
#include <istream>
#include <ostream>

namespace ObjexxFCL {

// Rewind Input Stream
void
Rewind( std::istream & stream )
{
	stream.clear();
	assert( stream.tellg() != std::streampos( -1 ) ); // Non-seekable stream
	if ( stream.tellg() == std::streampos( -1 ) ) return; // Non-seekable stream
	stream.seekg( 0, std::ios::beg );
}

// Rewind Input Stream and Set Status Flags
void
Rewind( std::istream & stream, IOFlags & flags )
{
	flags.clear_status();
	Rewind( stream );
	flags.set_status( stream );
}

// Rewind Output Stream
void
Rewind( std::ostream & stream )
{
	stream.clear();
	assert( stream.tellp() != std::streampos( -1 ) ); // Non-seekable stream
	if ( stream.tellp() == std::streampos( -1 ) ) return; // Non-seekable stream
	stream.seekp( 0, std::ios::beg );
}

// Rewind Output Stream and Set Status Flags
void
Rewind( std::ostream & stream, IOFlags & flags )
{
	flags.clear_status();
	Rewind( stream );
	flags.set_status( stream );
}

// Rewind Input/Output Stream
void
Rewind( std::iostream & stream )
{
	stream.clear();
	assert( stream.tellg() != std::streampos( -1 ) ); // Non-seekable stream
	assert( stream.tellp() != std::streampos( -1 ) ); // Non-seekable stream
	if ( stream.tellg() == std::streampos( -1 ) ) return; // Non-seekable stream
	if ( stream.tellp() == std::streampos( -1 ) ) return; // Non-seekable stream
	stream.seekg( 0, std::ios::beg );
	stream.seekp( 0, std::ios::beg );
}

// Rewind Input/Output Stream and Set Status Flags
void
Rewind( std::iostream & stream, IOFlags & flags )
{
	flags.clear_status();
	Rewind( stream );
	flags.set_status( stream );
}

} // ObjexxFCL
