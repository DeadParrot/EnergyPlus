// ObjexxFCL::Array6S Unit Tests
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

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4244) // Suppress conversion warnings: Intentional narrowing assignments present
#endif

// Google Test Headers
#include <gtest/gtest.h>

// ObjexxFCL Headers
#include <ObjexxFCL/Array6S.hh>
#include <ObjexxFCL/Array6D.hh>
#include <ObjexxFCL/ArrayS.functions.hh>
#include "ObjexxFCL.unit.hh"

#ifdef _MSC_VER
#pragma warning(pop)
#endif

using namespace ObjexxFCL;

TEST( Array6STest, FunctionMerge )
{
	{
		Array6D_int const A( 2, 2, 2, 2, 2, 2, 1 );
		Array6D_int const B( 2, 2, 2, 2, 2, 2, 2 );
		Array6S_int a( A( {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2} ) );
		Array6S_int b( B( {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2} ) );
		EXPECT_TRUE( eq( A, merge( a, b, true ) ) );
		EXPECT_TRUE( eq( B, merge( a, b, false ) ) );
	}

	{
		Array6D_int const A( 2, 2, 2, 2, 2, 2, 1 );
		int const b( 2 );
		Array6D_int const B( 2, 2, 2, 2, 2, 2, 2 );
		Array6S_int a( A( {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2} ) );
		EXPECT_TRUE( eq( A, merge( a, b, true ) ) );
		EXPECT_TRUE( eq( B, merge( a, b, false ) ) );
	}

	{
		int const a( 1 );
		Array6D_int const B( 2, 2, 2, 2, 2, 2, 2 );
		Array6D_int const A( 2, 2, 2, 2, 2, 2, 1 );
		Array6S_int b( B( {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2} ) );
		EXPECT_TRUE( eq( A, merge( a, b, true ) ) );
		EXPECT_TRUE( eq( B, merge( a, b, false ) ) );
	}

	{
		Array6D_int const A( 2, 2, 2, 2, 2, 2, 1 );
		Array6D_int const B( 2, 2, 2, 2, 2, 2, 2 );
		Array6S_int a( A( {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2} ) );
		Array6S_int b( B( {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2} ) );
		Array6D_bool const mask( 2, 2, 2, 2, 2, 2, { true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true } );
		Array6D_int const m( 2, 2, 2, 2, 2, 2, { 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1 } );
		EXPECT_TRUE( eq( m, merge( a, b, mask ) ) );
	}

	{
		Array6D_int const A( 2, 2, 2, 2, 2, 2, 1 );
		int const b( 2 );
		Array6S_int a( A( {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2} ) );
		Array6D_bool const mask( 2, 2, 2, 2, 2, 2, { true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true } );
		Array6D_int const m( 2, 2, 2, 2, 2, 2, { 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1 } );
		EXPECT_TRUE( eq( m, merge( a, b, mask ) ) );
	}

	{
		int const a( 1 );
		Array6D_int const B( 2, 2, 2, 2, 2, 2, 2 );
		Array6S_int b( B( {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2} ) );
		Array6D_bool const mask( 2, 2, 2, 2, 2, 2, { true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true, true, false, false, true } );
		Array6D_int const m( 2, 2, 2, 2, 2, 2, { 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1 } );
		EXPECT_TRUE( eq( m, merge( a, b, mask ) ) );
	}
}
