SRCS = main.cpp my_main.cpp
HEADERS = ./utils/iterators.hpp ./utils/algorithm.hpp ./utils/bst.hpp map.hpp stack.hpp vector.hpp
FLAGS = -Wall -Wextra -Werror

all : ft stl

ft : my_main.cpp $(HEADERS)
	@c++ my_main.cpp -std=c++98 -D STL=1 $(FLAGS) && ./a.out > ft_my_main_out
	@c++ main.cpp -std=c++98 -D STL=1 $(FLAGS) && ./a.out 0 > ft_them_out

stl : $(SRC) $(HEADERS)
	@c++ my_main.cpp -std=c++98 -D STL=0 $(FLAGS) && ./a.out > stl_my_main_out
	@c++ main.cpp -std=c++98 -D STL=0 $(FLAGS) && ./a.out 0 > stl_them_out

# @./ft_test_their_main 
# @./stl_test_their_main 

dif : 
	@diff ft_my_main_out stl_my_main_out
	@diff ft_them_out stl_them_out

clean :
	@rm -f a.out

fclean : clean
	@rm -f ft_my_main_out ft_them_out stl_my_main_out stl_them_out

re : fclean all

