#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include "./utils/iterators.hpp"
#include "./utils/algorithm.hpp"
#include "./utils/bst.hpp"

namespace ft
{
	template< class Key, class T, class Compare = ft::less<Key>,
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

			typedef ft::bst_iterator<value_type>			iterator;
			typedef ft::bst_const_iterator<value_type>		const_iterator;
			// typedef ft::bst_const_reverse_iterator<iterator>               reverse_iterator;
			// typedef ft::bst_const_reverse_iterator<const_iterator>         const_reverse_iterator;

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

				bst<value_type, Compare, Allocator>		_bst;
				Compare									_comp;
				allocator_type							_alloc;

			public :

			/********************************* constructors ****************************************/

			map() {
				_bst._node = _bst.insert(_bst._node, ft::make_pair(5,6));
				_bst._node = _bst.insert(_bst._node, ft::make_pair(8,9));
				std::cout << _bst._node->value << std::endl;
				_bst._node = _bst.delete_node(_bst._node, ft::make_pair(8,9));
				std::cout << _bst._node->right << std::endl;
			}

			explicit map( const Compare& comp, const Allocator& alloc = Allocator() ) {}

			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) {
				while (first != last){
					_bst._node = _bst.insert(_bst._node, *first);
					first++;
				}
			}

			map( const map& other ){ this = other; }

			map& operator = (const map& obj){
				this->_bst = obj._bst;
				this->_comp = obj._comp;
				this->_alloc = obj._alloc;
			}

			allocator_type get_allocator() const{
				return (_alloc);
			}

			T& at( const Key& key ){
				// for (iterator it = begin(); it != end(); it++)
				// 	if (*it == key)
				// 		return *it;
				throw (std::out_of_range("out of range !"));
			}
			const T& at( const Key& key ) const{
				// for (const_iterator it = begin(); it != end(); it++)
				// 	if (*it == key)
				// 		return *it;
				throw (std::out_of_range("out of range !"));
			}

			T& operator[]( const Key& key ){
				// for (iterator it = begin(); it != end(); it++)
				// 	if (*it._node->value.first == key)
				// 		return *it;
				// _bst._node = _bst.insert(_bst._node, *first);
			}

			// iterator begin() 			{ return (iterator(_bst.min_node())); }
			// iterator end()   			{ return (iterator(_bst._node)); }
			// reverse_iterator rbegin() 	{ return (reverse_iterator(_bst._node)); }
			// reverse_iterator rend() 	{ return (reverse_iterator(_bst.min_node())); }

			bool empty() const{ return (_bst._node == nullptr); }

			size_type size() const{
				size_type size;
				// for (iterator it = begin(); it != end(); it++;)
				// 	size++;
				return size;
			}

			iterator erase( iterator pos ){
				// for (iterator it = begin(); it != end(); it++;)
				// 	if (*it == pos)
				// 		*it.delete();
			}
			iterator erase( iterator first, iterator last ){
				// while (first != last){
				// 	if (*it == pos)
				// 		*it.delete();
				// 	first++;
				// }
			}
			size_type erase( const Key& key ){
				// for (iterator it = begin(); it != end(); it++;)
				// 	if (*it == key)
				// 		*it.delete();
			}
	};
}