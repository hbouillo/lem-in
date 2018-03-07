/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:28:33 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 02:14:29 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FT_PRINTF_BUFF_SIZE 4096

# define FT_PRINTF_SEQ_INIT '%'

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

# define FT_PRINTF_FLAG_SHARP 0x01
# define FT_PRINTF_FLAG_ZERO 0x02
# define FT_PRINTF_FLAG_MINUS 0x04
# define FT_PRINTF_FLAG_PLUS 0x08
# define FT_PRINTF_FLAG_SPACE 0x10

# define FT_PRINTF_FLAGS_STR "#0-+ "

typedef char		t_flag;

typedef int			t_wid;

# define FT_PRINTF_PREC_MAX 0x7fffffff

typedef int			t_prec;

typedef enum		e_len
{
	no_len,
	hh,
	h,
	ll,
	l,
	j,
	z
}					t_len;

# define PRINTF_CONV_STR "\1s\1S\1p\1i\1d\1D\1o\1O\1u\1U\1x\1X\1c\1C\1%\1b\3rgb"
# define PRINTF_LEN_STR "\2hh\1h\2ll\1l\1j\1z"

typedef enum		e_conv
{
	no_conv,
	s,
	m_s,
	p,
	i,
	d,
	m_d,
	o,
	m_o,
	u,
	m_u,
	x,
	m_x,
	c,
	m_c,
	percent,
	b,
	rgb
}					t_conv;

typedef enum		e_status
{
	begin,
	arg_no,
	flags,
	width,
	precision,
	length,
	conversion
}					t_status;

typedef struct		s_convseq
{
	t_flag			flags;
	t_wid			wid;
	t_prec			prec;
	t_len			len;
	t_conv			conv;
	t_status		status;
}					t_convseq;

int					ft_printf(const char *str, ...);
int					ft_printf_valist(const char *str, va_list *args);
int					ft_printf_buf(char *buffer, const char *str, ...);
int					ft_printf_buf_valist(char *buffer, const char *str,
						va_list *args);

int					set_flags(const char **str, t_convseq *convseq);
int					set_width(const char **str, t_convseq *convseq);
int					set_precision(const char **str, t_convseq *convseq);
int					set_length(const char **str, t_convseq *convseq);
int					set_conversion(const char **str, t_convseq *convseq);

int					apply_conv(va_list *arg, t_convseq *convseq, char **buf);

void				argtoabase(va_list *arg, t_len len, char *base, char *buf);
void				uargtoabase(va_list *arg, t_len len, char *base, char *buf);

int					handle_s(va_list *arg, t_convseq *convseq, char **buf);
int					handle_m_s(va_list *arg, t_convseq *convseq, char **buf);
int					handle_p(va_list *arg, t_convseq *convseq, char **buf);
int					handle_d(va_list *arg, t_convseq *convseq, char **buf);
int					handle_m_d(va_list *arg, t_convseq *convseq, char **buf);
int					handle_o(va_list *arg, t_convseq *convseq, char **buf);
int					handle_m_o(va_list *arg, t_convseq *convseq, char **buf);
int					handle_u(va_list *arg, t_convseq *convseq, char **buf);
int					handle_m_u(va_list *arg, t_convseq *convseq, char **buf);
int					handle_x(va_list *arg, t_convseq *convseq, char **buf);
int					handle_m_x(va_list *arg, t_convseq *convseq, char **buf);
int					handle_c(va_list *arg, t_convseq *convseq, char **buf);
int					handle_m_c(va_list *arg, t_convseq *convseq, char **buf);
int					handle_percent(va_list *arg, t_convseq *convseq,
						char **buf);
int					handle_b(va_list *arg, t_convseq *convseq, char **buf);

/*
** {%rgb}
** Colors are handled in ARGB format (int). Alpha not used. Flag '0' can be used
** to reset the color, in which case no argument is required.
*/
int					handle_rgb(va_list *arg, t_convseq *convseq, char **buf);

/*
** RGB
*/
# define FT_PRINTF_RGB_ESC "\x1b[38;2;"
# define FT_PRINTF_RGB_RESET "\x1b[38;0m"

/*
** UNICODE
*/
# define FT_PRINTF_UTF8_1B 0x7F
# define FT_PRINTF_UTF8_2B 0x7FF
# define FT_PRINTF_UTF8_3B 0xFFFF
# define FT_PRINTF_UTF8_4B 0x10FFFF

# define FT_PRINTF_UTF8_WFIRST_2B 0xC0
# define FT_PRINTF_UTF8_WFIRST_3B 0xE0
# define FT_PRINTF_UTF8_WFIRST_4B 0xF0
# define FT_PRINTF_UTF8_WNEXT 0x80

int					write_utf8_seq(wchar_t uni, char **buf);
int					utf8_len(wchar_t uni);

#endif
