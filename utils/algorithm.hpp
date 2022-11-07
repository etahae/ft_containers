#pragma once

#include <iostream>

namespace ft {

	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 ){
		for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
		{
			if (comp(*first1, *first2))
				return true;
			if (comp(*first2, *first1))
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template< class T >
	void swap( T& a, T& b ){
		T tmp;
		tmp = a;
		a = b;
		b = tmp;
	}

	template< class InputIt1, class InputIt2 >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 ){
		for (; (first1 != last1) ; ++first1, ++first2){
			if (*first1 != *first2)
				return false;
		}
		return true;
	}

	template< bool B, class T = void >
	struct enable_if{};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template< class T_first, class T_second >
	struct pair{
		
		typedef T_first		first_type;
		typedef T_second	second_type;

		first_type  first;
		second_type second;

		pair(){}

		pair( const T_first& x, const T_second& y ) : first(x), second(y) {}

		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) {}

		pair( const pair& p ) : first(p.first), second(p.second) {}

		pair& operator = ( const pair& other ){
			this->first = other.first;
			this->second = other.second;
		}
	};

	template< class t1, class t2 >
	ft::pair<t1, t2> make_pair( t1 t, t2 u ){
		ft::pair<t1, t2> paiir(t, u);
		return paiir;
	}

	template< class T1, class T2 >
	bool operator == ( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ){
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template< class T1, class T2 >
	bool operator != ( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ){
		return (!(lhs == rhs));
	}

	template< class T1, class T2 >
	bool operator < ( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ){
		if (lhs.first < rhs.first) { return true; }
		else if (rhs.first < lhs.first) { return false; }
		else if (lhs.second < rhs.second) { return true; }
		else { return false; }
	}

	template< class T1, class T2 >
	bool operator <= ( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ){
		return (!(rhs < lhs));
	}

	template< class T1, class T2 >
	bool operator > ( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ){
		return (rhs < lhs);
	}

	template< class T1, class T2 >
	bool operator >= ( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs ){
		return (!(lhs < rhs));
	}
}