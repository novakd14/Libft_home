/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:44:22 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/27 19:39:25 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H
# include "../libft.h"	// library
# include <stdio.h>		// printf
# include <ctype.h>		// isalpha, isdigit, isalnum, isprint
# include <string.h>	// strlen, memset, memcmp, strncmp
# include <stdlib.h>	// atoi
# include <strings.h>	// bzero

int		ft_isalpha_test(int full);
int		ft_isdigit_test(int full);
int		ft_isalnum_test(int full);
int		ft_isascii_test(int full);
int		ft_isprint_test(int full);
int		ft_strlen_test(int full);
int		ft_strlcpy_test(int full);
int		ft_strlcat_test(int full);
int		ft_toupper_test(int full);
int		ft_tolower_test(int full);
int		ft_strchr_test(int full);
int		ft_strrchr_test(int full);
int		ft_strncmp_test(int full);
int		ft_strnstr_test(int full);
int		ft_atoi_test(int full);
int		ft_memset_test(int full);
int		ft_bzero_test(int full);
int		ft_memcpy_test(int full);
int		ft_memmove_test(int full);
int		ft_memchr_test(int full);
int		ft_memcmp_test(int full);
int		ft_calloc_test(int full);
int		ft_strdup_test(int full);
int		ft_substr_test(int full);
int		ft_strjoin_test(int full);
int		ft_strtrim_test(int full);
int		ft_split_test(int full);
int		ft_itoa_test(int full);
int		ft_strmapi_test(int full);
int		ft_striteri_test(int full);
int		ft_putchar_fd_test(int full);
int		ft_putstr_fd_test(int full);
int		ft_putendl_fd_test(int full);
int		ft_putnbr_fd_test(int full);

//Print functions
void	ft_print_success_short(int count);
void	ft_print_fail(int index, char itype, void *input, char type, void *test, void *ref);
void	ft_print_success(int index, char itype, void *input, char type, void *test, void *ref);
void	ft_print_bold(char *msg);
void	ft_print_rate(int success, int max, int all);
int		ft_print_tmp(void);
void	ft_putnbytes(void *start, size_t n);

//Visual fucntions
void	ft_test_header(char *msg);

#endif //LIBFT_TEST_H
