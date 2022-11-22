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

		pair() : first(0), second(0) {}

		pair( const T_first& x, const T_second& y ) : first(x), second(y) {}

		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) {}

		pair( const pair& p ) : first(p.first), second(p.second) {}

		pair& operator = ( const pair& other ){
			this->first = other.first;
			this->second = other.second;
			return *this;
		}

		template< class T1, class T2 >
		friend std::ostream & operator << (std::ostream &out, const pair &obj);

		template< class T1, class T2 >
		friend bool operator == ( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs );

		template< class T1, class T2 >
		friend bool operator != ( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs );

		template< class T1, class T2 >
		friend bool operator < ( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs );

		template< class T1, class T2 >
		friend bool operator <= ( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs );

		template< class T1, class T2 >
		friend bool operator > ( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs );

		template< class T1, class T2 >
		friend bool operator >= ( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs );
	};

	template< class t1, class t2 >
	ft::pair<t1, t2> make_pair( t1 t, t2 u ){
		ft::pair<t1, t2> paiir(t, u);
		return paiir;
	}

	template< class T1, class T2 >
	bool operator == ( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template< class T1, class T2 >
	bool operator != ( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return (!(lhs == rhs));
	}

	template< class T1, class T2 >
	bool operator < ( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		if (lhs.first < rhs.first) { return true; }
		else if (rhs.first < lhs.first) { return false; }
		else if (lhs.second < rhs.second) { return true; }
		else { return false; }
	}

	template< class T1, class T2 >
	bool operator <= ( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return (!(rhs < lhs));
	}

	template< class T1, class T2 >
	bool operator > ( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return (rhs < lhs);
	}

	template< class T1, class T2 >
	bool operator >= ( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return (!(lhs < rhs));
	}

	template< class T1, class T2 >
	std::ostream	&operator << (std::ostream &out, const ft::pair<T1,T2>& obj)
	{
		out << "{" << obj.first << ", " << obj.second << "}" << std::endl;
		return out;
	}

	template <class T>
	struct less {
		bool operator() (const T& x, const T& y) const { return (x < y); }
	};

	template< class T >
	struct is_integral{
		template <class _Tp> struct __libcpp_is_integral                     : public std::false_type {};
		template <>          struct __libcpp_is_integral<bool>               : public std::true_type {};
		template <>          struct __libcpp_is_integral<char>               : public std::true_type {};
		template <>          struct __libcpp_is_integral<signed char>        : public std::true_type {};
		template <>          struct __libcpp_is_integral<unsigned char>      : public std::true_type {};
		template <>          struct __libcpp_is_integral<wchar_t>            : public std::true_type {};
		template <>          struct __libcpp_is_integral<char16_t>           : public std::true_type {};
		template <>          struct __libcpp_is_integral<char32_t>           : public std::true_type {};
		template <>          struct __libcpp_is_integral<short>              : public std::true_type {};
		template <>          struct __libcpp_is_integral<unsigned short>     : public std::true_type {};
		template <>          struct __libcpp_is_integral<int>                : public std::true_type {};
		template <>          struct __libcpp_is_integral<unsigned int>       : public std::true_type {};
		template <>          struct __libcpp_is_integral<long>               : public std::true_type {};
		template <>          struct __libcpp_is_integral<unsigned long>      : public std::true_type {};
		template <>          struct __libcpp_is_integral<long long>          : public std::true_type {};
		template <>          struct __libcpp_is_integral<unsigned long long> : public std::true_type {};
		template <>          struct __libcpp_is_integral<__int128_t>         : public std::true_type {};
		template <>          struct __libcpp_is_integral<__uint128_t>        : public std::true_type {};
	};
}