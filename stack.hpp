#pragma once

#include "vector.hpp"

namespace ft
{
	template< class T, class Container = ft::vector<T> >
	class stack{

		public :

			typedef Container                           container_type;
			typedef typename Container::value_type      value_type;
			typedef typename Container::size_type       size_type;
			typedef typename Container::reference       reference;
			typedef typename Container::const_reference const_reference;

		protected:

			container_type c;

		public :

			
			//******************************* constructors **************************************//

			explicit stack( const Container& cont = Container() ) : c(cont) {}

			stack( const stack& other ) : c(other.c) {}

			// ~stack();

			//******************************* element access **************************************//

			reference 		top(){ return c.back(); }

			const_reference top() const { return c.back(); }

			//******************************* capacity **************************************//

			bool		empty() { return c.empty(); }

			size_type	size() { return c.size(); }

			//******************************* modifiers **************************************//

			void push( const value_type& value ) { c.push_back(value); }

			void pop() { c.pop_back(); }

			//******************************* operators **************************************//

			stack& operator = ( const stack& other ) { c = other.c ; return *this;};

			template< class Tp, class container > friend bool operator == ( const stack<Tp,container>& lhs, const stack<Tp,container>& rhs );
			template< class Tp, class container > friend bool operator <  ( const stack<Tp,container>& lhs, const stack<Tp,container>& rhs );
	};

	template< class T, class Container >
	bool operator == ( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){ return (lhs.c == rhs.c); }

	template< class T, class Container >
	bool operator != ( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){ return !(lhs == rhs); }

	template< class T, class Container >
	bool operator <  ( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){ return  (lhs.c < rhs.c); }

	template< class T, class Container >
	bool operator >  ( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){ return  (rhs < lhs); }

	template< class T, class Container >
	bool operator <= ( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){ return !(rhs < lhs); }

	template< class T, class Container >
	bool operator >= ( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){ return !(lhs < rhs); }
}