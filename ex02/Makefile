SRC			=	main.cpp
OBJ			=	$(SRC:.cpp=.o)
NAME		=	aa
CXX			= 	c++
CXXFLAGS	= 	-Wextra -Wall -Werror -Wpedantic --std=c++98 -g -fsanitize=address

all		: $(NAME)

-include  $(SRC:.cpp=.d)

%.o		: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -MMD -c $<

$(NAME)	: $(OBJ) Makefile
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

clean	:
	$(RM) $(OBJ)
	$(RM) $(SRC:.cpp=.d)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
