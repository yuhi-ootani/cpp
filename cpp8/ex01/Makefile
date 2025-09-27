
NAME      := ex01

CPP       := c++
CPPFLAGS  := -Wall -Wextra -Werror -std=c++98 #-pedantic

SRCS      := main.cpp \
			Span.cpp

OBJS      := $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)


%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJS)


fclean: clean
	$(RM) $(NAME)


re: fclean all
