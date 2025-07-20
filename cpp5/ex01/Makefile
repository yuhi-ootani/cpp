

# Executable name
NAME      := ex00

# Compiler settings
CPP       := c++
CPPFLAGS  := -Wall -Wextra -Werror -std=c++98

# Source and object files (explicit — no wildcards)
SRCS      := main.cpp \
			Bureaucrat.cpp

OBJS      := $(SRCS:.cpp=.o)

# Clean utility
RM        := rm -f

# Mandatory targets
.PHONY: all clean fclean re

all: $(NAME)

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
re: fclean all
