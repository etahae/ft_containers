#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include "./iterators.hpp"

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

	//FIX THAT ASAAAAAAP

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
				for (size_type i; i < count; i++)
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

			void	assign( size_type count, const T& value ){
				if (count > _capacity)
					reserve(count);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_vector[i]);
				_size 		= count;
				_capacity 	= count;
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_vector[i], value);
			}

			template< class iterator > void assign( iterator first, iterator last ){
				size_type i = 0;
				for (iterator it = first ; it != last ; it++)
					i++;
				_size = i;
				for ( size_type x = 0; x < _size; x++)
					_alloc.destroy(&_vector[x]);
				for (size_type x = 0; x < _size; x++)
				{_alloc.construct(&_vector[x], first);
					first++;}
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
					_capacity = new_cap;
					pointer tmp_vector = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&tmp_vector[i], _vector[i]);
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(&_vector[i]);
					_vector = tmp_vector;
				}
			}

			size_type capacity() const{ return _capacity; }

			// ******************		modifiers		******************

			void clear(){
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_vector[i]);
				_size = 0;
			}

			iterator insert( const_iterator pos, const T& value ){
				size_type	int_pos = pos - this->begin();
				std::cout << std::distance(begin(), end()) << std::endl;

				return begin();
			}

			// constexpr iterator insert( const_iterator pos, size_type count, const T& value );

			// template< class InputIt > iterator insert( const_iterator pos, InputIt first, InputIt last );
	};
}