/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:44:28 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/27 19:49:31 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

int	main(int argc, char **argv)
{
	int full;
	int	count;
	int	max;
	(void) argv;
	ft_test_header("Test for the 42cursus libft project.");
	if (argc != 2)
		full = 0;
	else
		full = 1;

	max = 0;
	count = 0;
	count += ft_isalpha_test(full);
	max++;
	count += ft_isdigit_test(full);
	max++;
	count += ft_isalnum_test(full);
	max++;
	count += ft_isascii_test(full);
	max++;
	count += ft_isprint_test(full);
	max++;
	count += ft_strlen_test(full);
	max++;
	count += ft_memset_test(full);
	max++;
	count += ft_bzero_test(full);
	max++;
	count += ft_memcpy_test(full);
	max++;
	count += ft_memmove_test(full);
	max++;
	count += ft_strlcpy_test(full);
	max++;
	count += ft_strlcat_test(full);
	max++;
	count += ft_toupper_test(full);
	max++;
	count += ft_tolower_test(full);
	max++;
	count += ft_strchr_test(full);
	max++;
	count += ft_strrchr_test(full);
	max++;
	count += ft_strncmp_test(full);
	max++;
	count += ft_memchr_test(full);
	max++;
	count += ft_memcmp_test(full);
	max++;
	count += ft_strnstr_test(full);
	max++;
	count += ft_atoi_test(full);
	max++;
	count += ft_calloc_test(full);
	max++;
	count += ft_strdup_test(full);
	max++;
	count += ft_substr_test(full);
	max++;
	count += ft_strjoin_test(full);
	max++;
	count += ft_strtrim_test(full);
	max++;
	count += ft_split_test(full);
	max++;
	count += ft_itoa_test(full);
	max++;
	count += ft_strmapi_test(full);
	max++;
	count += ft_striteri_test(full);
	max++;
	count += ft_putchar_fd_test(full);
	max++;
	count += ft_putstr_fd_test(full);
	max++;
	count += ft_putendl_fd_test(full);
	max++;
	count += ft_putnbr_fd_test(full);
	max++;
	ft_print_rate(count, max, 34 + 9);

	int	array[] = {1000000,2000000,3000000,400};

	ft_putnbytes(array, 10);
	printf("\n");
}
