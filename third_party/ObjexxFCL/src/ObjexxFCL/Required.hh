#ifndef ObjexxFCL_Required_hh_INCLUDED
#define ObjexxFCL_Required_hh_INCLUDED

// Required Argument Wrapper
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

// ObjexxFCL Headers
#include <ObjexxFCL/Required.fwd.hh>
#include <ObjexxFCL/noexcept.hh>
#include <ObjexxFCL/Omit.hh>

// C++ Headers
#include <cassert>
#include <type_traits>

namespace ObjexxFCL {

// Required Argument Wrapper
template< typename T, typename Enable >
class Required;

// Required Argument Wrapper: Concrete Type Specialization
template< typename T >
class Required< T, typename std::enable_if< ! std::is_abstract< T >::value >::type >
{

private: // Friend

	template< typename, typename > friend class Required;

public: // Types

	using Value = T;
	using EnableType = typename std::enable_if< ! std::is_abstract< T >::value >::type;
	using Tc = typename std::conditional< std::is_scalar< T >::value, T const, T const & >::type;
	using Tr = typename std::conditional< std::is_scalar< T >::value, typename std::remove_const< T >::type, T const & >::type;

public: // Creation

	// Default Constructor
	Required()
	{
		assert( false ); // Required object not present
	}

	// Copy Constructor
	Required( Required const & r ) :
	 ptr_( r.own_ ? new T( r() ) : r.ptr_ ),
	 own_( r.own_ )
	{
		assert( ptr_ != nullptr ); // Required object must be present
	}

	// Copy Constructor Template
	template< typename U, class = typename std::enable_if< std::is_const< T >::value && std::is_same< U, typename std::remove_const< T >::type >::value >::type >
	Required( Required< U, EnableType > const & o ) :
	 ptr_( o.own_ ? new T( o() ) : o.ptr_ ),
	 own_( o.own_ )
	{
		assert( ptr_ != nullptr ); // Required object must be present
	}

	// Move Constructor
	Required( Required && ) NOEXCEPT = default;

	// Value Constructor
	Required( T const & val ) :
	 ptr_( const_cast< T * >( &val ) )
	{}

	// Value Constructor Template
	template< typename U, class = typename std::enable_if< std::is_constructible< T, U >::value >::type >
	Required( U const & val ) :
	 ptr_( new T( val ) ), // Requires Value( U ) constructor
	 own_( true )
	{}

	// rvalue Constructor
	Required( T && val ) :
	 ptr_( new T( val ) ), // Requires Value copy constructor
	 own_( true )
	{}

	// Omit Constructor
	Required( Omit )
	{
		assert( false ); // Required object not present
	}

	// Destructor
	~Required()
	{
		if ( own_ ) delete ptr_;
	}

public: // Assignment

	// Copy Assignment
	Required &
	operator =( Required const & r )
	{
		if ( this != &r ) {
			if ( own_ ) delete ptr_;
			ptr_ = r.own_ ? new T( r() ) : r.ptr_;
			assert( ptr_ != nullptr ); // Required object must be present
			own_ = r.own_;
		}
		return *this;
	}

	// Move Assignment
	Required &
	operator =( Required && ) NOEXCEPT = default;

	// Value Assignment
	Required &
	operator =( T const & val )
	{
		assert( ptr_ != nullptr );
		*ptr_ = val;
		return *this;
	}

	// Value Assignment Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	Required &
	operator =( U const & val )
	{
		assert( ptr_ != nullptr );
		*ptr_ = T( val );
		return *this;
	}

	// rvalue Assignment
	Required &
	operator =( T && val )
	{
		assert( ptr_ != nullptr );
		*ptr_ = val;
		return *this;
	}

public: // Conversion

	// Value Conversion
	operator Tr() const
	{
		assert( ptr_ != nullptr );
		return *ptr_;
	}

	// Value Conversion
	operator T &()
	{
		assert( ptr_ != nullptr );
		return *ptr_;
	}

public: // Operators

	// Value
	Tr
	operator ()() const
	{
		assert( ptr_ != nullptr );
		return *ptr_;
	}

	// Value
	T &
	operator ()()
	{
		assert( ptr_ != nullptr );
		return *ptr_;
	}

public: // Property

	// Present?
	bool
	present() const
	{
		return ( ptr_ != nullptr );
	}

	// Own?
	bool
	own() const
	{
		return own_;
	}

public: // Modifier

	// Clear
	void
	clear()
	{
		if ( own_ ) delete ptr_;
		ptr_ = nullptr;
		own_ = false;
	}

public: // Comparison

	// Required == Required
	friend
	bool
	operator ==( Required const & a, Required const & b )
	{
		return ( ( a.ptr_ != nullptr ) && ( b.ptr_ != nullptr ) ? ( *a.ptr_ == *b.ptr_ ) : ( a.ptr_ == b.ptr_ ) );
	}

	// Required != Required
	friend
	bool
	operator !=( Required const & a, Required const & b )
	{
		return !( a == b );
	}

	// Required == Value
	friend
	bool
	operator ==( Required const & a, Tc b )
	{
		return ( ( a.ptr_ != nullptr ) && ( *a.ptr_ == b ) );
	}

	// Required != Value
	friend
	bool
	operator !=( Required const & a, Tc b )
	{
		return !( a == b );
	}

	// Value == Required
	friend
	bool
	operator ==( Tc a, Required const & b )
	{
		return ( ( b.ptr_ != nullptr ) && ( a == *b.ptr_ ) );
	}

	// Value != Required
	friend
	bool
	operator !=( Tc a, Required const & b )
	{
		return !( a == b );
	}

private: // Data

	T * ptr_{ nullptr }; // Pointer to object
	bool own_{ false }; // Own the object?

}; // Required

// Required Argument Wrapper: Abstract Type Specialization
template< typename T >
class Required< T, typename std::enable_if< std::is_abstract< T >::value >::type >
{

private: // Friend

	template< typename, typename > friend class Required;

public: // Types

	using Value = T;
	using EnableType = typename std::enable_if< std::is_abstract< T >::value >::type;
	using Tc = typename std::conditional< std::is_scalar< T >::value, T const, T const & >::type;
	using Tr = typename std::conditional< std::is_scalar< T >::value, typename std::remove_const< T >::type, T const & >::type;

public: // Creation

	// Default Constructor
	Required()
	{
		assert( false ); // Required object not present
	}

	// Copy Constructor
	Required( Required const & r ) :
	 ptr_( r.ptr_ )
	{
		assert( ptr_ != nullptr ); // Required object must be present
	}

	// Copy Constructor Template
	template< typename U, class = typename std::enable_if< std::is_const< T >::value && std::is_same< U, typename std::remove_const< T >::type >::value >::type >
	Required( Required< U, EnableType > const & o ) :
	 ptr_( o.ptr_ )
	{
		assert( ptr_ != nullptr ); // Required object must be present
	}

	// Value Constructor
	Required( T const & val ) :
	 ptr_( const_cast< T * >( &val ) )
	{}

	// Omit Constructor
	Required( Omit )
	{
		assert( false ); // Required object not present
	}

public: // Assignment

	// Copy Assignment
	Required &
	operator =( Required const & r )
	{
		ptr_ = r.ptr_;
		assert( ptr_ != nullptr ); // Required object must be present
		return *this;
	}

	// Value Assignment
	Required &
	operator =( T const & val )
	{
		assert( ptr_ != nullptr );
		*ptr_ = val;
		return *this;
	}

	// Value Assignment Template
	template< typename U, class = typename std::enable_if< std::is_assignable< T&, U >::value >::type >
	Required &
	operator =( U const & val )
	{
		assert( ptr_ != nullptr );
		*ptr_ = val;
		return *this;
	}

	// rvalue Assignment
	Required &
	operator =( T && val )
	{
		assert( ptr_ != nullptr );
		*ptr_ = val;
		return *this;
	}

public: // Conversion

	// Value Conversion
	operator Tr() const
	{
		assert( ptr_ != nullptr );
		return *ptr_;
	}

	// Value Conversion
	operator T &()
	{
		assert( ptr_ != nullptr );
		return *ptr_;
	}

public: // Operators

	// Value
	Tr
	operator ()() const
	{
		assert( ptr_ != nullptr );
		return *ptr_;
	}

	// Value
	T &
	operator ()()
	{
		assert( ptr_ != nullptr );
		return *ptr_;
	}

public: // Property

	// Present?
	bool
	present() const
	{
		return ( ptr_ != nullptr );
	}

public: // Modifier

	// Clear
	void
	clear()
	{
		ptr_ = nullptr;
	}

public: // Comparison

	// Required == Required
	friend
	bool
	operator ==( Required const & a, Required const & b )
	{
		return ( ( a.ptr_ != nullptr ) && ( b.ptr_ != nullptr ) ? ( *a.ptr_ == *b.ptr_ ) : ( a.ptr_ == b.ptr_ ) );
	}

	// Required != Required
	friend
	bool
	operator !=( Required const & a, Required const & b )
	{
		return !( a == b );
	}

	// Required == Value
	friend
	bool
	operator ==( Required const & a, Tc b )
	{
		return ( ( a.ptr_ != nullptr ) && ( *a.ptr_ == b ) );
	}

	// Required != Value
	friend
	bool
	operator !=( Required const & a, Tc b )
	{
		return !( a == b );
	}

	// Value == Required
	friend
	bool
	operator ==( Tc a, Required const & b )
	{
		return ( ( b.ptr_ != nullptr ) && ( a == *b.ptr_ ) );
	}

	// Value != Required
	friend
	bool
	operator !=( Tc a, Required const & b )
	{
		return !( a == b );
	}

private: // Data

	T * ptr_{ nullptr }; // Pointer

}; // Required

// Argument Present?
template< typename T >
inline
bool
present( Required< T > const & r )
{
	return r.present();
}

// Argument Present?
template< typename T >
inline
bool
PRESENT( Required< T > const & r )
{
	return r.present();
}

// Required Maker
template< typename T >
inline
Required< T >
make_Required( T const & val )
{
	return Required< T >( val );
}

} // ObjexxFCL

#endif // ObjexxFCL_Required_hh_INCLUDED
