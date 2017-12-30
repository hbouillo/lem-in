# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:51:03 by hbouillo          #+#    #+#              #
#    Updated: 2017/12/04 22:11:15 by hbouillo         ###   ########.fr        #
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
CFLAGS =
else
CFLAGS = -Wall -Werror -Wextra
endif

# TARGET VARIABLES
NAME = libft.a

INCS_DIR = inc

DMEM = src/mem/
DOUT = src/out/
DSTR = src/str/
DUTIL = src/util/
DXTOABASE = src/util/xtoabase/

SMEM =  ft_bzero.c ft_memadr.c ft_memalloc.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		ft_memmove.c ft_memset.c \

SOUT =  ft_putchar.c ft_putchar_fd.c ft_putendl.c \
		ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
		ft_putstr_fd.c \
		printf/convert.c printf/convseq.c printf/ft_printf.c \
		printf/handlers_helper.c \
		printf/handlers/handle_b.c printf/handlers/handle_c.c \
		printf/handlers/handle_d.c printf/handlers/handle_m_c.c \
		printf/handlers/handle_m_d.c printf/handlers/handle_m_o.c \
		printf/handlers/handle_m_s.c printf/handlers/handle_m_u.c \
		printf/handlers/handle_m_x.c printf/handlers/handle_o.c \
		printf/handlers/handle_p.c printf/handlers/handle_percent.c \
		printf/handlers/handle_rgb.c printf/handlers/handle_s.c \
		printf/handlers/handle_u.c printf/handlers/handle_x.c \

SSTR =  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
		ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
		ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		ft_strlen.c ft_strmap.c ft_strmapi.c ft_strmapif.c \
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
		ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
		ft_strssplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \

SUTIL =	ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_islower.c ft_isprint.c \
		ft_isupper.c ft_itoa.c ft_nbrmax.c ft_nbrmin.c ft_tolower.c \
		ft_toupper.c \

SXTOABASE = ft_itoabase.c ft_uitoabase.c ft_ctoabase.c ft_uctoabase.c \
		ft_stoabase.c ft_ustoabase.c ft_ltoabase.c ft_ultoabase.c \
		ft_lltoabase.c ft_ulltoabase.c ft_imtoabase.c ft_uimtoabase.c \
		ft_sitoabase.c ft_ssitoabase.c

OMEM = $(addprefix $(DMEM), $(SMEM:.c=.o))
OSTR = $(addprefix $(DSTR), $(SSTR:.c=.o))
OOUT = $(addprefix $(DOUT), $(SOUT:.c=.o))
OUTIL = $(addprefix $(DUTIL), $(SUTIL:.c=.o))
OXTOABASE = $(addprefix $(DXTOABASE), $(SXTOABASE:.c=.o))


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
BGN_MSG = "$(STL_BOLD)$(RGB_YELLOW)⚠  Compiling library $(RGB_LRED)$(NAME)\
$(RGB_YELLOW)in $(RGB_LRED)$(MODE)$(RGB_YELLOW) mode. ⚠ $(RGB_RESET)"
else
BGN_MSG = "$(STL_BOLD)$(RGB_BLUE)⧖  Compiling library $(RGB_CYAN)$(NAME)\
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

$(NAME): $(OMEM) $(OSTR) $(OOUT) $(OUTIL) $(OXTOABASE)
ifeq ($(MODE),DEBUG)
	@echo "\tArchiving $(STL_BOLD)$(RGB_LRED)$@$(RGB_RESET)..."
endif
	@ar rc $(NAME) $(OMEM) $(OSTR) $(OOUT) $(OUTIL) $(OXTOABASE)
ifeq ($(MODE),DEBUG)
	@echo "\tIndexing  $(STL_BOLD)$(RGB_LRED)$@$(RGB_RESET)..."
endif
	@ranlib $(NAME)

%.o: %.c
ifeq ($(MODE),DEBUG)
	@echo "\tCompiling $(STL_BOLD)$(RGB_LBLUE)$<$(RGB_RESET)..."
endif
	@$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@
	@$(eval END_MSG = $(SOMETHING_DONE))

clean:
	@echo "$(STL_BOLD)$(RGB_BLUE)⧖  Cleaning $(RGB_CYAN)$(NAME)\
	$(RGB_BLUE) objs... ⧖$(RGB_RESET)"
ifeq ($(MODE),DEBUG)
	@echo "\tCleaning $(STL_BOLD)$(RGB_LBLUE)mem$(RGB_RESET)..."
endif
	@/bin/rm -f $(OMEM)
ifeq ($(MODE),DEBUG)
	@echo "\tCleaning $(STL_BOLD)$(RGB_LBLUE)str$(RGB_RESET)..."
endif
	@/bin/rm -f $(OSTR)
ifeq ($(MODE),DEBUG)
	@echo "\tCleaning $(STL_BOLD)$(RGB_LBLUE)out$(RGB_RESET)..."
endif
	@/bin/rm -f $(OOUT)
ifeq ($(MODE),DEBUG)
	@echo "\tCleaning $(STL_BOLD)$(RGB_LBLUE)util$(RGB_RESET)..."
endif
	@/bin/rm -f $(OUTIL)
ifeq ($(MODE),DEBUG)
	@echo "\tCleaning $(STL_BOLD)$(RGB_LBLUE)util/xtoabase$(RGB_RESET)..."
endif
	@/bin/rm -f $(OXTOABASE)
	@echo "$(STL_BOLD)$(RGB_BLUE)✓  Cleaned $(RGB_CYAN)$(NAME)\
	$(RGB_BLUE) objs successfully. ✓$(RGB_RESET)"

fclean: clean
	@echo "$(STL_BOLD)$(RGB_BLUE)⧖  Cleaning $(RGB_CYAN)$(NAME)\
	$(RGB_BLUE) archive... ⧖$(RGB_RESET)"
ifeq ($(MODE),DEBUG)
	@echo "\tCleaning $(STL_BOLD)$(RGB_LRED)$(NAME)$(RGB_RESET)..."
endif
	@/bin/rm -f $(NAME)
	@echo "$(STL_BOLD)$(RGB_BLUE)✓  Cleaned $(RGB_CYAN)$(NAME)\
	$(RGB_BLUE) archive successfully. ✓$(RGB_RESET)"

re: fclean all

.PHONY: all clean fclean $(NAME)-precompil $(NAME)-endcompil
