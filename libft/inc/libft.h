/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:22:15 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 04:41:41 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BASE_BIN "01"
# define BASE_OCT "01234567"
# define BASE_DEC "0123456789"
# define BASE_HEX "0123456789abcdef"
# define BASE_HEX_M "0123456789ABCDEF"

# include <string.h>
# include <inttypes.h>
# include <stdlib.h>
# include <stdarg.h>

int					ft_printf(const char *str, ...);
int					ft_printf_valist(const char *str, va_list *args);
int					ft_printf_buf(char *buffer, const char *str, ...);
int					ft_printf_buf_valist(char *buffer, const char *str,
						va_list *args);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);

void				ft_putstr(const char *str);
void				ft_putstr_fd(const char *str, int fd);

void				ft_putnbr(int nbr);
void				ft_putnbr_fd(int nbr, int fd);

void				ft_putendl(char const *str);
void				ft_putendl_fd(char const *str, int fd);

int					ft_nbrmin(int nbr1, int nbr2);
int					ft_nbrmax(int nbr1, int nbr2);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

void				*ft_memset(void *to_fill, int value, size_t len);
void				ft_bzero(void *to_fill, size_t len);

void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int value,
								size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memchr(const void *to_search, int value, size_t len);
int					ft_memcmp(const void *mem1, const void *mem2, size_t len);

char				*ft_memadr(const void *mem);

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);

char				*ft_strdup(const char *src);

char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);

char				*ft_strcat(char *str1, const char *str2);
char				*ft_strncat(char *str1, const char *str2, size_t len);

size_t				ft_strlcat(char *str1, const char *str2, size_t size);

size_t				ft_strlen(const char *str);

void				ft_strclr(char *str);

char				*ft_strchr(const char *str, int value);
char				*ft_strrchr(const char *str, int value);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to_find,
								size_t len);

int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t n);

int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

int					ft_toupper(int c);
int					ft_tolower(int c);

void				ft_striter(char *str, void (*f)(char *));
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *str, char (*f)(char));
char				*ft_strmapi(const char *str,
								char (*f)(unsigned int, char));
char				*ft_strmapif(const char *str, const void *data,
								int (*f_condition)(char, const void *),
								char (*f)(char));

int					ft_strequ(const char *str1, const char *str2);
int					ft_strnequ(const char *str1, const char *str2,
							size_t len);

char				*ft_strsub(const char *str, unsigned int start,
							size_t len);
char				*ft_strjoin(const char *str1, const char *str2);
char				*ft_strfjoin(char *str1, char *str2);

char				*ft_strtrim(const char *str);

char				**ft_strsplit(const char *str, char c);

int					ft_atoi(const char *str);
char				*ft_itoa(int nbr);
char				*ft_ctoabase(char nbr, const char *base);
char				*ft_uctoabase(unsigned char nbr, const char *base);
char				*ft_stoabase(short nbr, const char *base);
char				*ft_ustoabase(unsigned short nbr, const char *base);
char				*ft_itoabase(int nbr, const char *base);
char				*ft_uitoabase(unsigned int nbr, const char *base);
char				*ft_ltoabase(long nbr, const char *base);
char				*ft_ultoabase(unsigned long nbr, const char *base);
char				*ft_lltoabase(long long nbr, const char *base);
char				*ft_ulltoabase(unsigned long long nbr, const char *base);
char				*ft_imtoabase(intmax_t nbr, const char *base);
char				*ft_uimtoabase(uintmax_t nbr, const char *base);
char				*ft_ssitoabase(ssize_t nbr, const char *base);
char				*ft_sitoabase(size_t nbr, const char *base);

void				ft_ctoabase_buf(char nbr, const char *base, char *buf);
void				ft_uctoabase_buf(unsigned char nbr, const char *base,
						char *buf);
void				ft_stoabase_buf(short nbr, const char *base, char *buf);
void				ft_ustoabase_buf(unsigned short nbr, const char *base,
						char *buf);
void				ft_itoabase_buf(int nbr, const char *base, char *buf);
void				ft_uitoabase_buf(unsigned int nbr, const char *base,
						char *buf);
void				ft_ltoabase_buf(long nbr, const char *base, char *buf);
void				ft_ultoabase_buf(unsigned long nbr, const char *base,
						char *buf);
void				ft_lltoabase_buf(long long nbr, const char *base,
						char *buf);
void				ft_ulltoabase_buf(unsigned long long nbr, const char *base,
						char *buf);
void				ft_imtoabase_buf(intmax_t nbr, const char *base,
						char *buf);
void				ft_uimtoabase_buf(uintmax_t nbr, const char *base,
						char *buf);
void				ft_ssitoabase_buf(ssize_t nbr, const char *base,
						char *buf);
void				ft_sitoabase_buf(size_t nbr, const char *base, char *buf);

int					ft_gnl(const int fd, char **line);

int					ft_chartablen(char **tab);
void				ft_chartabfree(char **tab);

/*
** Args manager
*/

# define ARG_DEFAULT -1

typedef struct		s_arg
{
	int				idx;
	char			**data;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_refarg
{
	int				idx;
	char			*name;
	char			short_name;
	int				data_len;
	struct s_refarg	*next;
}					t_refarg;

typedef struct		s_args
{
	t_refarg		*ref_args;
	t_arg			*args;
}					t_args;

void				register_arg_ref(char *name, char short_name,
						int data_len, int idx);
int					parse_args(int argc, char **argv);
t_args				**get_args(void);
void				destroy_args(void);
t_arg				*get_arg(int idx);

/*
** Simple linked lists (llist)
*/

typedef struct		s_llist
{
	void			*data;
	struct s_llist	*next;
}					t_llist;

t_llist				*ft_llist_new(void *data);
void				ft_llist_rem(t_llist **head, t_llist *elem,
						void (*del_data)(void *));
void				ft_llist_del(t_llist **head, void (*del_data)(void *));
void				ft_llist_front(t_llist **head, t_llist *new);
void				ft_llist_back(t_llist **head, t_llist *new);
int					ft_llist_has_data(t_llist *head, void *data);

#endif
