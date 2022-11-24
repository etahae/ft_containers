#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include "./utils/iterators.hpp"
#include "./utils/algorithm.hpp"

namespace ft
{
	//*********************			vector_iterator			*******************//

	template <typename T>
	class vector_iterator{

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

			vector_iterator() : _it(nullptr){}

			vector_iterator(pointer ptr) : _it(ptr){}

			vector_iterator(const vector_iterator& obj) { *this = obj; }

			~vector_iterator() {}

			//**************        operators overloads         ***********//

			vector_iterator& operator = (const vector_iterator& obj){
				_it = obj.base();
				return *this;
			}

			vector_iterator& operator++(){ _it++ ; return *this; }

			vector_iterator operator++(int){
				vector_iterator it = *this;
				++(*this);
				return it;
			}

			vector_iterator& operator--(){ _it-- ; return *this; }

			vector_iterator operator--(int){
				vector_iterator it = *this;
				--(*this);
				return it;
			}

			reference   operator [] (int index) { return _it[index]; }

			pointer	operator -> () { return _it; }

			reference	operator * () {return *_it; }

			pointer operator + (int n){
				_it += n;
				return _it;
			}

			pointer operator - (int n){
				_it -= n;
				return _it;
			}

			vector_iterator operator+ (difference_type n) { _it += n; return _it;}

			difference_type operator- (const vector_iterator& obj) const { return _it - obj.base(); }

			bool	operator <  ( const vector_iterator& obj ) { return _it < obj.base();  }
			bool	operator >  ( const vector_iterator& obj ) { return _it > obj.base();  }
			bool	operator <= ( const vector_iterator& obj ) { return _it <= obj.base(); }
			bool	operator >= ( const vector_iterator& obj ) { return _it >= obj.base(); }
			bool	operator == ( const vector_iterator& obj ) { return _it == obj.base(); }
			bool	operator != ( const vector_iterator& obj ) { return _it != obj.base(); }

			reference operator += (int n){
				_it += n;
				return *_it;
			}

			reference operator -= (int n){
				_it -= n;
				return *_it;
			}
	};

	//*********************			rev_vector_iterator			*******************//

	template <typename T>
	class rev_vector_iterator : public iterator<random_access_iterator_tag, T> {

		public :

			typedef T																	iterator_type;
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

			rev_vector_iterator() : _it(nullptr){}

			explicit rev_vector_iterator(pointer ptr) : _it(ptr){}

			template <typename iter>  rev_vector_iterator (const rev_vector_iterator<iter>& rev_it){
				rev_it = *this;
			}

			~rev_vector_iterator() {}

			reference	operator * () {return *_it; }

			rev_vector_iterator& operator = (const rev_vector_iterator& obj){
				_it = obj.base();
				return *this;
			}

			rev_vector_iterator& operator++(){ _it-- ; return *this; }

			rev_vector_iterator operator++(int){
				rev_vector_iterator it = *this;
				++(*this);
				return it;
			}

			rev_vector_iterator& operator--(){ _it++ ; return *this; }

			rev_vector_iterator operator--(int){
				rev_vector_iterator it = *this;
				--(*this);
				return it;
			}

			reference   operator [] (int index) { return _it[index]; }

			pointer	operator -> () { return _it; }

			pointer operator - (int n){
				_it -= n;
				return _it;
			}

			pointer operator + (int n){
				_it += n;
				return _it;
			}

			reference operator += (int n){
				_it += n;
				return *_it;
			}

			reference operator -= (int n){
				_it -= n;
				return *_it;
			}
	};

	template <class Iterator>  bool operator <  (const rev_vector_iterator<Iterator>& obj1, const rev_vector_iterator<Iterator>& obj2) { return obj1.base() <  obj2.base(); }
	template <class Iterator>  bool operator >  (const rev_vector_iterator<Iterator>& obj1, const rev_vector_iterator<Iterator>& obj2) { return obj1.base() >  obj2.base(); }
	template <class Iterator>  bool operator <= (const rev_vector_iterator<Iterator>& obj1, const rev_vector_iterator<Iterator>& obj2) { return obj1.base() <= obj2.base(); }
	template <class Iterator>  bool operator >= (const rev_vector_iterator<Iterator>& obj1, const rev_vector_iterator<Iterator>& obj2) { return obj1.base() >= obj2.base(); }
	template <class Iterator>  bool operator == (const rev_vector_iterator<Iterator>& obj1, const rev_vector_iterator<Iterator>& obj2) { return obj1.base() == obj2.base(); }
	template <class Iterator>  bool operator != (const rev_vector_iterator<Iterator>& obj1, const rev_vector_iterator<Iterator>& obj2) { return obj1.base() != obj2.base(); }
	template <class Iterator>  rev_vector_iterator<Iterator> operator+ (typename rev_vector_iterator<Iterator>::difference_type n, const rev_vector_iterator<Iterator>& obj){
		obj.base() += n;
		return obj.base();}
	template <class Iterator>  typename rev_vector_iterator<Iterator>::difference_type operator- (const rev_vector_iterator<Iterator>& obj1, const rev_vector_iterator<Iterator>& obj2){
		return (obj2.base() + obj1.base());}

	//*************************			vector			**************************//

	template <class T, class Allocator = std::allocator<T> >
	class vector{

		public :

			typedef std::size_t												size_type;
			typedef std::ptrdiff_t											difference_type;

			typedef T														value_type;
			typedef value_type&												reference;
			typedef const value_type&										const_reference;

			typedef T*														pointer;
			typedef const pointer											const_pointer;

			typedef Allocator 												allocator_type;
	
			typedef typename ft::vector_iterator<value_type> 				iterator;
			typedef const typename ft::vector_iterator<value_type> 			const_iterator;

			typedef typename ft::rev_vector_iterator<iterator> 				reverse_iterator;
			typedef const typename ft::rev_vector_iterator<const_iterator> 	const_reverse_iterator;

		protected :

			size_type		_size;
			size_type 		_capacity;
			allocator_type 	_alloc;
			pointer			_vector;

		public :

			// ******************      CONSTRUCTORS      ******************

			vector() : _size(0), _capacity(0){
				_vector = _alloc.allocate(0);
			}

			explicit vector( const Allocator& alloc ) : _size(0), _capacity(0), _alloc(alloc){
				_vector = _alloc.allocate(0);
			}

			explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator() ):
					_size(count), _capacity(count) ,_alloc(alloc){
				_vector = _alloc.allocate(count);
				for (size_type i = 0; i < count; i++)
					_alloc.construct(&_vector[i], value);
				return ;
			}

			vector( const vector& obj) : _size(obj._size), _capacity(obj._capacity), _alloc(obj._alloc){
				_vector = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_vector[i], obj._vector[i]);
			}

			~vector(){
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_vector[i]);
				_alloc.deallocate(_vector, _capacity);
			}

			// ******************      	operators     		 ******************

			vector&	operator = ( const vector& obj ){
				_size = obj._size;
				_capacity = obj._capacity;
				_alloc = obj._alloc;
				_vector = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_vector[i], obj._vector[i]);
				return (*this);
			}

			reference operator [] ( size_type pos ) {
				return _vector[pos];
			}

			// ******************          ITERATORS      	*********************

			iterator			begin() {return iterator(_vector);}
			const_iterator		begin() const {return const_iterator(_vector);}

			iterator			end() {return iterator(_vector + _size);}
			const_iterator		end() const {return const_iterator(_vector + _size);}

			reverse_iterator		rbegin() {return reverse_iterator(_vector + _size - 1);}
			const_reverse_iterator	rbegin() const {return const_reverse_iterator(_vector + _size - 1);}

			reverse_iterator		rend() {return reverse_iterator(_vector - 1);}
			const_reverse_iterator	rend() const {return const_reverse_iterator(_vector - 1);}

			// ******************		member functions	******************

			template< class iterator > void assign( iterator first, iterator last, typename ft::enable_if<!ft::is_integral<iterator>::value >::type* = 0){
				size_type i = 0;
				for (iterator it = first ; it != last ; it++)
					i++;
				_size = i;
				for ( size_type x = 0; x < _size; x++)
					_alloc.destroy(&_vector[x]);
				for (size_type x = 0; x < _size; x++){
					_alloc.construct(&_vector[x], first);
					first++;
				}
			}

			void	assign( size_type count, const T& value ){
				if (count < _capacity)
					reserve(count);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_vector[i]);
				for (size_type i = 0; i < count; i++)
					_alloc.construct(&_vector[i], value);
				_size = count;
			}


			allocator_type get_allocator() const{ return _alloc; };

			// ******************		element_access		******************

			reference 		at( size_type pos ){
				if (pos >= _size) { throw std::out_of_range("index out of range"); }
				return _vector[pos];
			}
			const_reference at( size_type pos ) const{
				if (pos >= _size) { throw std::out_of_range("index out of range"); }
				return _vector[pos];
			}

			reference 		front(){ return _vector[0]; }
			const_reference front() const{ return _vector[0]; }

			reference 		back(){ return _vector[_size - 1]; }
			const_reference back() const{ return _vector[_size - 1]; }

			T* 			data(){ return _vector; }
			const T* 	data() const{ return _vector; }

			// ******************		capacity		******************

			bool empty() const{ return _size == 0; }

			size_type	size() const{ return _size; }

			size_type max_size() const{ return _alloc.max_size(); }

			void reserve( size_type new_cap ){
				if (new_cap > max_size()) { throw std::length_error("value of capacity exceeded the max size"); }
				if (new_cap > _capacity){
					pointer tmp_vector = _alloc.allocate(new_cap);
					for (size_type i = 0; i < _size; i++){
						_alloc.construct(&tmp_vector[i], _vector[i]);
						_alloc.destroy(&_vector[i]);
					}
					_alloc.deallocate(_vector, _capacity);
					_vector = tmp_vector;
					_capacity = new_cap;
				}
			}

			size_type capacity() const{ return _capacity; }

			// ******************		modifiers		******************

			void clear(){
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_vector[i]);
				_size = 0;
			}

			iterator insert( const_iterator it_pos, const T& value ){
				size_type	pos = it_pos - begin();
				insert(it_pos, 1, value);
				return _vector + pos;
			}

			iterator insert( const_iterator it_pos, size_type count, const T& value ){
				size_type	pos = it_pos - begin();
				if (_size + count > _capacity)
					reserve(_size + count);
				for (size_type x = 0; x < pos; x++)
					_alloc.construct(&_vector[_size + x], value);
				for (size_type x = _size - 1; x >= 0 && x >= pos; x--)
					_alloc.construct(&_vector[x + count], _vector[x]);
				for (size_type x = pos; x < pos + count; x++)
					_vector[x] = value;
				_size += count;
				return _vector + pos;
			}

			template< class InputIt > iterator insert( const_iterator it_pos, InputIt first, InputIt last,
				typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0){   /////USE ENABLE IF
				size_type	pos = it_pos - begin();
				size_type 	count = 0;
				for (InputIt it = first; it != last && count <= max_size(); it++) {count++;}
				if (_size + count > _capacity)
					reserve(_size + count);
				for (size_type x = 0; x < pos; x++)
					_alloc.construct(&_vector[_size + x], first);
				for (size_type x = _size - 1; x >= 0 && x >= pos; x--)
					_alloc.construct(&_vector[x + count], _vector[x]);
				for (size_type x = pos; x < pos + count; x++)
					{_vector[x] = first; first++;}
				return _vector + pos;
			}

			iterator erase( iterator it_pos ){
				size_type	pos = it_pos - begin();
				size_type x = pos;
				for (x = pos; x < _size - 1; x++)
					_vector[x] = _vector[x + 1];
				_alloc.destroy(&_vector[x]);
				_size -= 1;
				return it_pos + 1;
			}

			iterator erase( iterator first, iterator last ){
				size_type	pos = 0;
				for (iterator it = first; it != last && pos <= max_size(); it++) {pos++;}
				size_type x;
				for (x = pos; x < _size - 1; x++)
					_vector[x] = _vector[x + 1];
				_alloc.destroy(&_vector[x]);
				_size -= 1;
				return _vector + pos + 1;
			}

			void push_back( const T& value ){
				size_type old_capacity = _capacity;
				if (_size + 1 > _capacity)
					reserve(_capacity * 2);
				pointer tmp = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++){
					_alloc.construct(&tmp[i], _vector[i]);
					_alloc.destroy(&_vector[i]);
				}
				_size += 1;
				_alloc.construct(&tmp[_size - 1], value);
				_alloc.deallocate(_vector, old_capacity);
				_vector = tmp;
			}

			void pop_back(){
				_alloc.destroy(&_vector[_size - 1]);
				_size -= 1;
			}

			void resize( size_type count, T value = T()){
				if (_size > count){
					for (size_type x = _size ; x >= count && x >= 0 ; x--)
						_alloc.destroy(&_vector[x]);
					_size = count;
				}
				else {
					size_type old_capacity = _capacity;
					if (count > _capacity)
						reserve(count * 2);
					pointer tmp = _alloc.allocate(_capacity);
					size_type i;
					for (i = 0; i < _size; i++){
						_alloc.construct(&tmp[i], _vector[i]);
						_alloc.destroy(&_vector[i]);
					}
					_alloc.deallocate(_vector, old_capacity);
					_size = count;
					for (; i < _size; i++)
						_alloc.construct(&tmp[i], value);
					_vector = tmp;
				}
			}

			void swap( vector& obj ){
				ft::swap(_capacity, obj._capacity);
				ft::swap(_size, obj._size);
				ft::swap(_alloc, obj._alloc);
				ft::swap(_vector, obj._vector);
			}
	};

	template< class T, class Alloc >
	bool operator == ( const ft::vector<T,Alloc>& lhs,  const ft::vector<T,Alloc>& rhs ){
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class T, class Alloc >
	bool operator != ( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){
		return (!(lhs == rhs));
	}

	template< class T, class Alloc >
	bool operator <  ( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class T, class Alloc >
	bool operator <= ( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){
		return (!(rhs < lhs));
	}

	template< class T, class Alloc >
	bool operator >  ( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){
		return (rhs < lhs);
	}

	template< class T, class Alloc >
	bool operator >= ( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){
		return (!(lhs < rhs));
	}
}