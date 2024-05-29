/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:44:22 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/29 12:43:19 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H
# include "../libft.h"	// library
# include <stdio.h>		// printf
# include <ctype.h>		// isalpha, isdigit, isalnum, isprint, tolower
# include <string.h>	// strlen, strncmp, memset, memcmp, memcpy
# include <stdlib.h>	// atoi, calloc, malloc, free
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
void	ft_print_success(int index);
void	ft_print_fail(int index);
void	ft_print_colored(char *msg, char *color_code, int bold);
void	ft_print_rate(int success, int max, int all);
int		ft_print_tmp(void);
void	ft_print_mem(void *start, size_t n);
void	ft_print_memchar(void *mem, size_t size);
void	ft_print_memint(void *mem, size_t size);

//Print input functions
void	ft_print_input_int(int num);
void	ft_print_input_intint(int num1, int num2);
void	ft_print_input_str(char *str);
void	ft_print_input_strstr(char *str1, char *str2);
void	ft_print_input_strint(char *str, int num);
void	ft_print_input_strchar(char *str, char c);
void	ft_print_input_charint(char c, int num);
void	ft_print_input_strstrsize(char *str1, char *str2, size_t size);
void	ft_print_input_struintsize(char *str, unsigned int num, size_t size);
void	ft_print_input_sizesize(size_t size1, size_t size2);
void	ft_print_input_voidsize(void *ptr, size_t n, size_t num);
void	ft_print_input_voidintsize(void *ptr, size_t n, int num1, size_t num2);
void	ft_print_input_voidvoidsize(void *ptr1, size_t n1, void *ptr2, size_t n2, size_t num);

//Print output functions
void	ft_print_test_int(int test, int ref);
void	ft_print_test_size(size_t test, size_t ref);
void	ft_print_test_str(char *test, char *ref);
void	ft_print_test_strarr(char **test, char **ref);
void	ft_print_test_void(void *test, void *ref, size_t size);

//Visual fucntions
void	ft_test_header(char *msg);

#endif //LIBFT_TEST_H
