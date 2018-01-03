# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:51:03 by hbouillo          #+#    #+#              #
#    Updated: 2018/01/03 04:56:09 by hbouillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SHELL
ZSH = /bin/zsh
ifneq ("$(wildcard $(ZSH))","")
SHELL = /bin/zsh
endif

# MAKING MODE
ifneq ($(MODE),DEBUG)
override MODE = NORMAL
endif
export MODE

# CC VARIABLES
CC = gcc
ifeq ($(MODE),DEBUG)
CFLAGS = -fsanitize=address
LFLAGS = -fsanitize=address
else
CFLAGS = -Wall -Werror -Wextra
LFLAGS =
endif

# TARGET VARIABLES
NAME = lem-in

LIBFT = libft
LIBS = $(LIBFT)/$(LIBFT).a

INCS_DIR = inc

DMAIN = src/

SMAIN = lemin.c parser.c rooms.c network_builder.c

OMAIN = $(addprefix $(DMAIN), $(SMAIN:.c=.o))


# STYLE VARIABLES
STL_BOLD = \x1b[1m

RGB_YELLOW = \x1b[38;2;239;196;23m
RGB_LGREEN = \x1b[38;2;93;239;183m
RGB_CYAN = \x1b[38;2;112;225;232m
RGB_BLUE = \x1b[38;2;83;154;252m
RGB_LBLUE = \x1b[38;2;147;204;252m
RGB_LRED = \x1b[38;2;255;100;100m
RGB_RESET = \x1b[0m

ifeq ($(MODE),DEBUG)
BGN_MSG = "$(STL_BOLD)$(RGB_YELLOW)⚠  Compiling $(RGB_LRED)$(NAME)\
$(RGB_YELLOW)in $(RGB_LRED)$(MODE)$(RGB_YELLOW) mode. ⚠ $(RGB_RESET)"
else
BGN_MSG = "$(STL_BOLD)$(RGB_BLUE)⧖  Compiling $(RGB_CYAN)$(NAME)\
$(RGB_BLUE)in $(RGB_CYAN)$(MODE)$(RGB_BLUE) mode. ⧖ $(RGB_RESET)"
endif

NOTHING_DONE = "$(STL_BOLD)$(RGB_LRED)✗  Nothing to be done for$(RGB_CYAN)\
$(NAME)$(RGB_LRED). ✗$(RGB_RESET)"
SOMETHING_DONE = "$(STL_BOLD)$(RGB_BLUE)✓  Compiled $(RGB_CYAN)$(NAME)\
$(RGB_BLUE)successfully. ✓$(RGB_RESET)"


END_MSG = $(NOTHING_DONE)

all: $(NAME)-precompil $(NAME) $(NAME)-endcompil
	@echo > /dev/null

$(NAME)-precompil:
	@echo $(BGN_MSG)

$(NAME)-endcompil:
	@echo $(END_MSG)

$(NAME): $(OMAIN)
	@$(MAKE) -C $(LIBFT)
ifeq ($(MODE),DEBUG)
	@echo "\tLinking $(STL_BOLD)$(RGB_LRED)$@$(RGB_RESET)..."
endif
	@$(CC) $(CFLAGS) -o $(NAME) $(OMAIN) $(LIBS)

%.o: %.c
ifeq ($(MODE),DEBUG)
	@echo "\tCompiling $(STL_BOLD)$(RGB_LBLUE)$<$(RGB_RESET)..."
endif
	@$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@
	@$(eval END_MSG = $(SOMETHING_DONE))

clean:
	@$(MAKE) -C $(LIBFT) clean
	@echo "$(STL_BOLD)$(RGB_BLUE)⧖  Cleaning $(RGB_CYAN)$(NAME)\
	$(RGB_BLUE) objs... ⧖$(RGB_RESET)"
ifeq ($(MODE),DEBUG)
	@echo "\tCleaning $(STL_BOLD)$(RGB_LBLUE)main$(RGB_RESET)..."
endif
	@/bin/rm -f $(OMAIN)
	@echo "$(STL_BOLD)$(RGB_BLUE)✓  Cleaned $(RGB_CYAN)$(NAME)\
	$(RGB_BLUE) objs successfully. ✓$(RGB_RESET)"

fclean:
	@$(MAKE) -C $(LIBFT) fclean
	@echo "$(STL_BOLD)$(RGB_BLUE)⧖  Cleaning $(RGB_CYAN)$(NAME)\
	$(RGB_BLUE) objs... ⧖$(RGB_RESET)"
ifeq ($(MODE),DEBUG)
	@echo "\tCleaning $(STL_BOLD)$(RGB_LBLUE)main$(RGB_RESET)..."
endif
	@/bin/rm -f $(OMAIN)
	@echo "$(STL_BOLD)$(RGB_BLUE)✓  Cleaned $(RGB_CYAN)$(NAME)\
	$(RGB_BLUE) objs successfully. ✓$(RGB_RESET)"
	@echo "$(STL_BOLD)$(RGB_BLUE)⧖  Cleaning $(RGB_CYAN)$(NAME)\
	$(RGB_BLUE) executable... ⧖$(RGB_RESET)"
ifeq ($(MODE),DEBUG)
	@echo "\tCleaning $(STL_BOLD)$(RGB_LRED)$(NAME)$(RGB_RESET)..."
endif
	@/bin/rm -f $(NAME)
	@echo "$(STL_BOLD)$(RGB_BLUE)✓  Cleaned $(RGB_CYAN)$(NAME)\
	$(RGB_BLUE) executable successfully. ✓$(RGB_RESET)"

re: fclean all

.PHONY: all clean fclean $(NAME)-precompil $(NAME)-endcompil
