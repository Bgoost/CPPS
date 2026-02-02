# Standard
NAME				= Intern

# Directories
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= c++
# CFLAGS				= -Wall -Werror -Wextra -MMD -fsanitize=address -std=c++98
CFLAGS				= -Wall -Werror -Wextra -MMD -std=c++98
RM					= rm -f
INCLUDES			= Bureaucrat.h Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp Intern.hpp
SRCS 				= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp Intern.cpp

OBJ = $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRCS))
DEP = $(SRCS:.cpp=.d)

# Build rules
start:
					@make all

all: 				$(NAME)

$(NAME): 			$(OBJ)
					@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
					@echo "\033[32mAll "$(NAME) "done!!✅\033[1;97m"

# Compile object files from source files
$(OBJ_DIR)%.o:		%.cpp Makefile $(INCLUDES)
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@
					@echo "\033[32mCompiling...\033[1;97m "$< "✅"

clean:
					@$(RM) -rf $(OBJ_DIR)
					@echo "\033[1;32mAll cleaned 💩🗑\33[1;97m"

fclean: 			clean
					@$(RM) $(NAME)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re
-include $(DEP)
