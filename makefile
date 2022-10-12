SRCS = main.cpp my_main.cpp
HEADERS = iterators.hpp algorithm.hpp map.hpp stack.hpp


all : ft stl dif

ft : $(SRC) $(HEADERS)
	@c++ my_main.cpp -std=c++98 -D STL=1 -o ft_test_my_main

# @c++ my_main.cpp -std=c++98 -D STL=1 -o ft_test_their_main

stl : $(SRC) $(HEADERS)
	@c++ my_main.cpp -std=c++98 -D STL=0 -o stl_test_my_main

# @c++ main.cpp -std=c++98 -D STL=0 -o stl_test_their_main

out :
	@./ft_test_my_main > ft_me_out
	@./stl_test_my_main > stl_me_out

# @./ft_test_their_main > ft_them_out
# @./stl_test_their_main > stl_them_out

dif : 
	@diff ft_me_out stl_me_out

# @diff ft_them_out stl_them_out

clean :
	@rm -f ft_test_my_main ft_test_their_main stl_test_my_main stl_test_their_main

fclean : clean
	@rm -f ft_me_out ft_them_out stl_me_out stl_them_out

re : fclean all

