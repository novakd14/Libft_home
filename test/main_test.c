/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:44:28 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/27 14:29:41 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

int	main(void)
{
	int	count;
	int	max;

	max = 0;
	count = 0;
	count += ft_isalpha_test();
	max++;
	count += ft_isdigit_test();
	max++;
	count += ft_isalnum_test();
	max++;
	count += ft_isascii_test();
	max++;
	count += ft_isprint_test();
	max++;
	count += ft_strlen_test();
	max++;
	count += ft_memset_test();
	max++;
	count += ft_bzero_test();
	max++;
	count += ft_memcpy_test();
	max++;
	count += ft_memmove_test();
	max++;
	count += ft_strlcpy_test();
	max++;
	count += ft_strlcat_test();
	max++;
	count += ft_toupper_test();
	max++;
	count += ft_tolower_test();
	max++;
	count += ft_strchr_test();
	max++;
	count += ft_strrchr_test();
	max++;
	count += ft_strncmp_test();
	max++;
	count += ft_memchr_test();
	max++;
	count += ft_memcmp_test();
	max++;
	count += ft_strnstr_test();
	max++;
	count += ft_atoi_test();
	max++;
	count += ft_calloc_test();
	max++;
	count += ft_strdup_test();
	max++;
	count += ft_substr_test();
	max++;
	count += ft_strjoin_test();
	max++;
	count += ft_strtrim_test();
	max++;
	count += ft_split_test();
	max++;
	count += ft_itoa_test();
	max++;
	count += ft_strmapi_test();
	max++;
	count += ft_striteri_test();
	max++;
	count += ft_putchar_fd_test();
	max++;
	count += ft_putstr_fd_test();
	max++;
	count += ft_putendl_fd_test();
	max++;
	count += ft_putnbr_fd_test();
	max++;
	ft_print_rate(count, max, 34);
}
