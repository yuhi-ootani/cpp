
<<<<<<< HEAD
NAME      := ex02

CPP       := c++
CPPFLAGS  := -Wall -Wextra -Werror -std=c++98 #-pedantic

SRCS      := main.cpp 

OBJS      := $(SRCS:.cpp=.o)


=======

# Executable name
NAME      := ex01

# Compiler settings
CPP       := c++
CPPFLAGS  := -Wall -Wextra -Werror -std=c++98 -pedantic

# Source and object files (explicit — no wildcards)
SRCS      := main.cpp \
			Span.cpp


OBJS      := $(SRCS:.cpp=.o)

# Clean utility
RM        := rm -f

# Mandatory targets
>>>>>>> f50f495 (adfa)
.PHONY: all clean fclean re

all: $(NAME)

<<<<<<< HEAD
$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

=======
# Link the binary only when needed
$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)

# Compile each .cpp into its .o
%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

# Remove object files
clean:
	$(RM) $(OBJS)

# Remove objects and executable
fclean: clean
	$(RM) $(NAME)

# Rebuild from scratch
>>>>>>> f50f495 (adfa)
re: fclean all
