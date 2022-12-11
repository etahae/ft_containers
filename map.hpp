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

			typedef Key                     							key_type;
			typedef T                       							mapped_type;
			typedef ft::pair<Key, T>  									value_type;
			typedef	typename std::size_t								size_type;
			typedef typename std::ptrdiff_t								difference_type;
			typedef	Compare												key_compare;
			typedef	Allocator											allocator_type;
			typedef	value_type&											reference;
			typedef	const value_type									const_reference;
			typedef typename Allocator::pointer							pointer;
			typedef typename Allocator::const_pointer					const_pointer;
			typedef ft::bst_iterator<value_type>						iterator;
			typedef ft::bst_const_iterator<value_type>					const_iterator;
			typedef ft::bst_reverse_iterator<iterator>               	reverse_iterator;
			typedef ft::bst_const_reverse_iterator<const_iterator>      const_reverse_iterator;

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
				ft::Node<value_type> 					*_root_node;
				key_compare								_comp;
				allocator_type							_alloc;
				size_type								_size;

				void set_root_node(){
					if (_bst._node != nullptr)
						_root_node = _bst._node;
				}

			public :

			/********************************* constructors ****************************************/

			map() : _size(0) {}

			explicit map( const Compare& comp, const Allocator& alloc = Allocator() ) : _comp(comp), _alloc(alloc) {}

			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) {
				_size = 0;
				while (first != last){
					_bst._node = _bst.insert(_bst._node, *first);
					first++;
					_size++;
				}
				(void)alloc;
				(void)comp;
			}

			map( const map& other ){ this = other; }

			map& operator = (const map& obj){
				this->_bst = obj._bst;
				this->_comp = obj._comp;
				this->_alloc = obj._alloc;
				this->_size = obj._size;
			}

			allocator_type get_allocator() const{ return (_alloc); }

			ft::pair<iterator, bool> insert( const value_type& value ){
				ft::Node<value_type> tmpp = ft::Node<value_type>(value);
				iterator tmp = iterator(&tmpp);
				if (this->count(value.first)){
					return (ft::make_pair<iterator, bool>(tmp, false));
				}
				else{
					_bst._node = _bst.insert(_bst._node, value);
					_size++;
					if (_size == 1)
						set_root_node();
					return (ft::make_pair<iterator, bool>(tmp, true));
				}
			}
			iterator insert( iterator pos, const value_type& value ){
				(void)pos;
				return (insert(value));
			}
			template< class InputIt >
			void insert( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = 0){
				while (first != last){
					_bst._node = _bst.insert(_bst._node, *first);
					first++;
					_size++;
					if (_size == 1)
						set_root_node();
				}
			}

			T& at( const Key& key ){
				for (iterator it = begin(); it != end(); it++)
					if ((*it).first == key)
						return *it;
				throw (std::out_of_range("out of range !"));
			}
			const T& at( const Key& key ) const{
				for (const_iterator it = begin(); it != end(); it++)
					if ((*it).first == key)
						return *it;
				throw (std::out_of_range("out of range !"));
			}

			T& operator[]( const Key& key ){
				iterator tmp = this->find(key);
				if (tmp == end()){
					_bst._node = _bst.insert(_bst.node, make_pair(key, mapped_type()));
					_size++;
					if (_size == 1)
						set_root_node();
				}
				tmp = this->find(key);
				return ((*tmp).second);
			}

			iterator begin() 			{ return (iterator(_bst.min_node(_bst._node), _root_node)); }
			iterator end()   			{ return (iterator(nullptr, _root_node)); }
			reverse_iterator rbegin() 	{ return (reverse_iterator(nullptr, _root_node)); }
			reverse_iterator rend() 	{ return (reverse_iterator(_bst.min_node(_bst.node), _root_node)); }

			bool empty() { return (_bst._node == nullptr); }

			size_type size() const{ return _size; }

			size_type max_size() const{ return _alloc.max_size(); }

			void clear(){
				_bst.delete_tree(_bst._node);
				_bst._node = nullptr;
				_size = 0;
			}

			iterator erase( iterator pos ){
				this->erase((*pos).first);
			}
			iterator erase( iterator first, iterator last ){
				while (first != last){
					_bst.delete_node(_bst._node, *first);
					first++;
					_size--;
				}
			}
			size_type erase( const Key& key ){
				for (iterator it = begin(); it != end(); it++){
					if ((*it).first == key){
						_bst.delete_node(_bst._node, *it);
						_size--;
					}
				}
				return _size;
			}

			void swap( map& obj ){
				ft::swap(this->_size, obj._size);
				ft::swap(this->_alloc, obj._alloc);
				ft::swap(this->_bst, obj._bst);
				ft::swap(this->_comp, obj._comp);
			}

			size_type count( const Key& key ){
				size_type count = 0;
				for (iterator it = begin(); it != end(); it++)
					if (it->first == key)
						count++;
				return count;
			}

			iterator find( const Key& key ){
				return (iterator(_bst.search(_bst._node, ft::make_pair(key, mapped_type()))));
			}
			const_iterator find( const Key& key ) const{
				return (const_iterator(_bst.search(_bst._node, ft::make_pair(key, mapped_type()))));
			}

			ft::pair<iterator,iterator> equal_range( const Key& key ){
				return (ft::make_pair(lower_bound(key), upper_bound(key)));
			}
			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const{
				return (ft::make_pair(lower_bound(key), upper_bound(key)));
			}

			iterator lower_bound( const Key& key ){
				iterator it;
				for (it = begin(); it != end() ;it++)
					if ((*it).first >= key)
						return (it);
				return it;
			}
			const_iterator lower_bound( const Key& key ) const{
				const_iterator it;
				for (it = begin(); it != end() ;it++)
					if ((*it).first >= key)
						return (it);
				return it;
			}

			iterator upper_bound( const Key& key ){
				iterator it;
				for (it = begin(); it != end() ;it++)
					if ((*it).first == key)
						return (++it);
				return it;
			}
			const_iterator upper_bound( const Key& key ) const{
				const_iterator it;
				for (it = begin(); it != end() ;it++)
					if ((*it).first == key)
						return (++it);
				return it;
			}

			key_compare key_comp() const{ return _comp; }

			typename ft::map<key_type, mapped_type>::value_compare value_comp() const{ return new value_compare(); }
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs ){
					return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
				 }

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs ){
					return (!(lhs == rhs));
				 }

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
                const ft::map<Key,T,Compare,Alloc>& rhs ){
					return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
				}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs ){
					return (!(rhs < lhs));
				 }

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
                const ft::map<Key,T,Compare,Alloc>& rhs ){
					return (rhs < lhs);
				}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs ){
					return (!(lhs < rhs));
				 }
}