#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include "./utils/iterators.hpp"
#include "./utils/algorithm.hpp"
#include "./utils/bst.hpp"

namespace ft
{
	//******************************* map_iterator ***********************************//

	template<typename T>
	class  map_iterator{

		public :

			typedef T*																	iterator_type;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category 		iterator_category;
			typedef typename ft::iterator_traits<iterator_type>::value_type				value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type		difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer				pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference				reference;

		protected :
		
			iterator_type _it;
		
		public :

			iterator_type	base() const{
				return _it;
			}

			//**************        constructor                 ***********//

			map_iterator(){}

			map_iterator(pointer ptr) : _it(ptr){}

			map_iterator(const map_iterator& obj) { *this = obj; }

			~map_iterator() {}

			//**************        operators overloads         ***********//

			map_iterator& operator = (const map_iterator& obj){
				_it = obj.base();
				return *this;
			}

			map_iterator& operator++(){ _it++ ; return *this; }

		// 	map_iterator operator++(int){
		// 		map_iterator it = *this;
		// 		++(*this);
		// 		return it;
		// 	}

		// 	map_iterator& operator--(){ _it-- ; return *this; }

		// 	map_iterator operator--(int){
		// 		map_iterator it = *this;
		// 		--(*this);
		// 		return it;
		// 	}

		// 	pointer	operator -> () { return _it; }

		// 	reference	operator * () {return *_it; }

		// 	bool	operator == ( const map_iterator& obj ) { return _it == obj.base(); }
		// 	bool	operator != ( const map_iterator& obj ) { return _it != obj.base(); }
	};

	//******************************* map ***********************************//

	template< class Key, class T, class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {

		public :

			typedef Key                     				key_type;
			typedef T                       				mapped_type;
			typedef ft::pair<Key, T>  						value_type;
			typedef	typename std::size_t					size_type;
			typedef typename std::ptrdiff_t					difference_type;
			typedef	Compare									key_compare;
			typedef	Allocator								allocator_type;
			typedef	value_type&								reference;
			typedef	const value_type						const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef	bst<value_type, Compare, Allocator>		tree;

			typedef ft::map_iterator<value_type>			iterator;
			// typedef __map_const_iterator<typename __base::const_iterator> const_iterator;
			// typedef _VSTD::reverse_iterator<iterator>               reverse_iterator;
			// typedef _VSTD::reverse_iterator<const_iterator>         const_reverse_iterator;

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

			private :

				tree					_bst;

			public :

			/********************************* constructors ****************************************/

			map() { }

			explicit map( const Compare& comp, const Allocator& alloc = Allocator() ) {  }

			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ){}

			map( const map& other ){}
	};
}