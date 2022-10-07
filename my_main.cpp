#include <iostream>
#include <string>
#include <deque>
#if 1 //CREATE A REAL STL EXAMPLE
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
    // namespace ft = std;
#else
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#endif

#include <stdlib.h>

int main()
{
    ft::vector<int> ve(10, 42);

    ft::vector<int>::iterator it = ve.end();
    *it--;
    it = it + 1;
    std::cout << *it << std::endl;
    it = it - 1;
    std::cout << *it << std::endl;

    ft::vector<int>::iterator s = it;
    std::cout << *s << std::endl;

    std::cout << (s == it) << std::endl;

    std::cout << (s < it) << std::endl;

    it += 2;

    std::cout << *it << std::endl;

    ft::vector<int>::reverse_iterator hh = ve.rbegin();

    std::cout << *hh << std::endl;

    ft::vector<std::string> st(5, "hello");

    ft::vector<std::string>::iterator itt;

    for (itt = st.begin(); itt != st.end(); itt++)
        std::cout << *itt << std::endl;

    std::cout << "********" << std::endl;

    ft::vector<std::string>::reverse_iterator rev_itt;   //////////////// !!!!!!!!!!!!!!!!!!!!!!
    ft::vector<std::string>::reverse_iterator rrev_itt; //////////////// !!!!!!!!!!!!!!!!!!!!!!

    std::cout << (rev_itt == rrev_itt) << std::endl;     //////////////// !!!!!!!!!!!!!!!!!!!!!!

    for (rev_itt = st.rbegin(); rev_itt != st.rend(); rev_itt++){
        std::cout << *rev_itt << std::endl;
    }

    std::cout << ve[2] << " is in the third position" << std::endl;

    std::cout << "assign test << std::endl";

    ve.assign(4, 1337);

    for (ft::vector<int>::iterator ve_it = ve.begin(); ve_it != ve.end(); ve_it++)
        std::cout << *ve_it << std::endl;

    ve.at(2) = 42;
    std::cout << "at test : " << ve.at(2) << std::endl; // test the out of range

    std::cout << "front test :" << ve.front() << std::endl;

    std::cout << "datatest : " << ve.data() << std::endl;

    std::cout << "empty test : " << ve.empty() << std::endl;
    ft::vector<int> ve_test(0);
    std::cout << "empty test : " << ve_test.empty() << std::endl;
    ve_test.assign(1, 1);
    std::cout << "empty assign test : " << ve_test.empty() << std::endl;

    std::cout << "size test :" << ve.size() << std::endl;

    std::cout << "max size test :" << ve.max_size() << std::endl;

    ve.reserve(50);
    std::cout << "reserve test :" << "new capacity is : " << ve.capacity() << " but size is still : " << ve.size() << std::endl;
    std::cout << ve.at(ve.size() - 1) << std::endl; // test out of range

    std::cout << "insert test :" << std::endl;
    ve.insert((ve.begin() + 1), 4, 666);
    for (ft::vector<int>::iterator ve_it = ve.begin(); ve_it != ve.end(); ve_it++)
        std::cout << ">" << *ve_it << std::endl;

    std::cout << "erase test :" << std::endl;
    ve.erase(ve.end() - 2); //delete 42
    for (ft::vector<int>::iterator ve_it = ve.begin(); ve_it != ve.end(); ve_it++)
        std::cout << ">" << *ve_it << std::endl;

    std::cout << "push_back test :" << std::endl;
    ve.push_back(42);
    for (ft::vector<int>::iterator ve_it = ve.begin(); ve_it != ve.end(); ve_it++)
        std::cout << ">" << *ve_it << std::endl;

    std::cout << "pop_back test :" << std::endl;
    ve.pop_back();
    for (ft::vector<int>::iterator ve_it = ve.begin(); ve_it != ve.end(); ve_it++)
        std::cout << ">" << *ve_it << std::endl;

    std::cout << "resize less test :" << std::endl;
    ve.resize(3);
    for (ft::vector<int>::iterator ve_it = ve.begin(); ve_it != ve.end(); ve_it++)
        std::cout << ">" << *ve_it << std::endl;
    
    std::cout << "resize more test :" << std::endl;
    ve.resize(10);
    for (ft::vector<int>::iterator ve_it = ve.begin(); ve_it != ve.end(); ve_it++)
        std::cout << ">" << *ve_it << std::endl;


    ft::vector<int> v1(10, 42);
    ft::vector<int> v2(10, 1337);


    std::cout << "swap test :" << std::endl;
    // swap();
    for (int i = 0; i < 10; i++)
        std::cout << ">" << v2[i] << std::endl;
    //////////////////////////////////////////////

    // std::vector<std::string> lol(2, "taha");
    // lol.assign(lol.begin(), lol.end() + 10);
    // std::cout << lol[1] << std::endl;
    // lol.insert(lol.begin() + 1, "namir");
    // std::cout << lol[2] << std::endl;

    // system("leaks a.out");


    // int i = it - ls;
    // std::vector<int>::reverse_iterator itt = ls.rbegin();


    // std::cout << *--itt << std::endl;
    // for (int i = 0; i < 10; i++)


    // std::vector<int> v;

    // for (int i =0; i < 11; i++)
    // {
    //     std::cout << v.size()  << "......" << v.capacity() << std::endl ;
    //     v.push_back(i);
    // }
    // std::cout << v.size()  << "......" << v.capacity() << std::endl ;
    // v.assign(50, 42);
    // std::cout << v.size()  << "......" << v.capacity() << std::endl ;
    // v.push_back(5);
    // std::cout << v.size()  << "......" << v.capacity() << std::endl ;
    // return 0;
}