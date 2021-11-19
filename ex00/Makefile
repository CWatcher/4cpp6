SRC			=	Converter.cpp \
				main.cpp
OBJ			=	$(SRC:.cpp=.o)
NAME		=	convert
CXX			= 	clang++
CXXFLAGS	= 	-Wextra -Wall -Wpedantic -Werror -std=c++98 -g #-fsanitize=address

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
