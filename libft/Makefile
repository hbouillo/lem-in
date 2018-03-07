# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:51:03 by hbouillo          #+#    #+#              #
#    Updated: 2018/03/03 04:41:56 by hbouillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile.inc

# COMPILATION VARIABLES
CC = clang
CFLAGS = $(DEBUG_FLAGS) \
	-I./inc
LFLAGS = $(DEBUG_FLAGS)

# TARGETS
TARGET_1 = lib/libft.dylib
SRC_1 =  mem/ft_bzero.c mem/ft_memadr.c mem/ft_memalloc.c mem/ft_memccpy.c \
	mem/ft_memchr.c mem/ft_memcmp.c mem/ft_memcpy.c mem/ft_memdel.c \
	mem/ft_memmove.c mem/ft_memset.c \
	in/ft_gnl.c \
	out/ft_putchar.c out/ft_putchar_fd.c out/ft_putendl.c \
	out/ft_putendl_fd.c out/ft_putnbr.c out/ft_putnbr_fd.c out/ft_putstr.c \
	out/ft_putstr_fd.c \
	out/printf/convert.c out/printf/convseq.c out/printf/ft_printf.c \
	out/printf/ft_printf_ellipsis.c out/printf/handlers_helper.c \
	out/printf/handlers/handle_b.c out/printf/handlers/handle_c.c \
	out/printf/handlers/handle_d.c out/printf/handlers/handle_m_c.c \
	out/printf/handlers/handle_m_d.c out/printf/handlers/handle_m_o.c \
	out/printf/handlers/handle_m_s.c out/printf/handlers/handle_m_u.c \
	out/printf/handlers/handle_m_x.c out/printf/handlers/handle_o.c \
	out/printf/handlers/handle_p.c out/printf/handlers/handle_percent.c \
	out/printf/handlers/handle_rgb.c out/printf/handlers/handle_s.c \
	out/printf/handlers/handle_u.c out/printf/handlers/handle_x.c \
	str/ft_strcat.c str/ft_strchr.c str/ft_strclr.c str/ft_strcmp.c \
	str/ft_strcpy.c str/ft_strdel.c str/ft_strdup.c str/ft_strequ.c \
	str/ft_striter.c str/ft_striteri.c str/ft_strjoin.c str/ft_strlcat.c \
	str/ft_strlen.c str/ft_strmap.c str/ft_strmapi.c str/ft_strmapif.c \
	str/ft_strncat.c str/ft_strncmp.c str/ft_strncpy.c str/ft_strnequ.c \
	str/ft_strnew.c str/ft_strnstr.c str/ft_strrchr.c str/ft_strsplit.c \
	str/ft_strssplit.c str/ft_strstr.c str/ft_strsub.c str/ft_strtrim.c \
	str/ft_strfjoin.c \
	util/ft_atoi.c util/ft_isalnum.c util/ft_isalpha.c util/ft_isascii.c \
	util/ft_isdigit.c util/ft_islower.c util/ft_isprint.c \
	util/ft_isupper.c util/ft_itoa.c util/ft_nbrmax.c util/ft_nbrmin.c \
	util/ft_tolower.c util/ft_toupper.c util/ft_chartablen.c \
	util/ft_chartabfree.c util/args/args.c util/args/args_destroy.c \
	util/args/args_access.c \
	util/xtoabase/ft_itoabase.c util/xtoabase/ft_uitoabase.c \
	util/xtoabase/ft_ctoabase.c util/xtoabase/ft_uctoabase.c \
	util/xtoabase/ft_stoabase.c util/xtoabase/ft_ustoabase.c \
	util/xtoabase/ft_ltoabase.c util/xtoabase/ft_ultoabase.c \
	util/xtoabase/ft_lltoabase.c util/xtoabase/ft_ulltoabase.c \
	util/xtoabase/ft_imtoabase.c util/xtoabase/ft_uimtoabase.c \
	util/xtoabase/ft_sitoabase.c util/xtoabase/ft_ssitoabase.c \
	util/llist/ft_llist_new.c util/llist/ft_llist_front.c \
	util/llist/ft_llist_back.c util/llist/ft_llist_rem.c \
	util/llist/ft_llist_del.c util/llist/ft_llist_has_data.c
OBJ_1 = $(addprefix obj/src/,$(SRC_1:.c=.o))

TARGET_2 = lib/libft.a
SRC_2 = $(SRC_1)
OBJ_2 = $(OBJ_1)

all: prebuild.$(TARGET_1) $(TARGET_1) postbuild.$(TARGET_1) \
	prebuild.$(TARGET_2) $(TARGET_2) postbuild.$(TARGET_2)
	@echo > /dev/null

prebuild.$(TARGET_1):
	$(call bgn_msg,$(TARGET_1))

$(TARGET_1): $(OBJ_1)
	$(call link_dylib, $(LFLAGS))

$(OBJ_1): ./obj/%.o: %.c
	$(call compile, $(CFLAGS))

postbuild.$(TARGET_1):
	$(call $(END_MSG),$(TARGET_1))

prebuild.$(TARGET_2):
	$(call bgn_msg,$(TARGET_2))

$(TARGET_2): $(OBJ_2)
	$(call link_lib)

postbuild.$(TARGET_2):
	$(call $(END_MSG),$(TARGET_2))

clean:
	$(call clean,$(TARGET_1),$(OBJ_1))
	$(call clean,$(TARGET_2),$(OBJ_2))

fclean:
	$(call lib_fclean,$(TARGET_1),$(OBJ_1))
	$(call lib_fclean,$(TARGET_2),$(OBJ_2))

libclean:
	@rm -rf ./lib

re: fclean all

.PHONY: all clean fclean \
	prebuild.$(TARGET_1) postbuild.$(TARGET_1) \
	prebuild.$(TARGET_1) postbuild.$(TARGET_1)
