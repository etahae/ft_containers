#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include "./iterators.hpp"
#include "./algorithm.hpp"

namespace ft
{
	//******************************* map_iterator ***********************************//

	

	template< class Key, class T, class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {

		public :

			typedef Key                     			key_type;
			typedef T                       			mapped_type;
			typedef ft::pair<const Key, T>  			value_type;
			typedef	typename std::size_t				size_type;
			typedef typename std::ptrdiff_t				difference_type;
			typedef	Compare								key_compare;
			typedef	Allocator							allocator_type;
			typedef	value_type&							reference;
			typedef	const value_type					const_reference;
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			// typedef	iterator
			// typedef const_iterator
			// typedef	reverse_iterator
			// typedef const_reverse_iterator

			class value_compare{
				public :

					typedef bool		result_type;
					typedef	value_type	first_argument_type;
					typedef	value_type	second_argument_type;
				
				protected :

					Compare comp;

					value_compare( Compare c ) : comp(c) {}

				public :

					value_compare& operator () ( const value_type& lhs, const value_type& rhs ) const{
						return ( comp(lhs.first, rhs.first) );
					}
			
			};

			/********************************* constructors ****************************************/

			map(){}

			explicit map( const Compare& comp, const Allocator& alloc = Allocator() ){}

			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ){}

			map( const map& other ){}
	};
}