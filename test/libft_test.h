/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:44:22 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/27 14:20:06 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H
# include "../libft.h" //library
# include <stdio.h> //printf
# include <ctype.h> //isalpha, isdigit, isalnum, isprint
# include <string.h> //strlen, memset

int		ft_isalpha_test(void);
int		ft_isdigit_test(void);
int		ft_isalnum_test(void);
int		ft_isascii_test(void);
int		ft_isprint_test(void);
int		ft_strlen_test(void);
int		ft_strlcpy_test(void);
int		ft_strlcat_test(void);
int		ft_toupper_test(void);
int		ft_tolower_test(void);
int		ft_strchr_test(void);
int		ft_strrchr_test(void);
int		ft_strncmp_test(void);
int		ft_strnstr_test(void);
int		ft_atoi_test(void);
int		ft_memset_test(void);
int		ft_bzero_test(void);
int		ft_memcpy_test(void);
int		ft_memmove_test(void);
int		ft_memchr_test(void);
int		ft_memcmp_test(void);
int		ft_calloc_test(void);
int		ft_strdup_test(void);
int		ft_substr_test(void);
int		ft_strjoin_test(void);
int		ft_strtrim_test(void);
int		ft_split_test(void);
int		ft_itoa_test(void);
int		ft_strmapi_test(void);
int		ft_striteri_test(void);
int		ft_putchar_fd_test(void);
int		ft_putstr_fd_test(void);
int		ft_putendl_fd_test(void);
int		ft_putnbr_fd_test(void);

//Print functions
void	ft_print_success(void);
void	ft_print_fail(int index, char type, void *test, void *ref);
void	ft_print_bold(char *msg);
void	ft_print_rate(int success, int max, int all);
int		ft_print_tmp(void);

#endif //LIBFT_TEST_H
