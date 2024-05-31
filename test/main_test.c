/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:44:28 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/31 20:17:25 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

int	main(int argc, char **argv)
{
	int	full = 0;
	int	count_pass = 0;
	int	count = 0;
	int	max = 34 + 9;

	// Check if user wants full information
	if (argc > 1 && strcmp(argv[1], "full") == 0)
		full = 1;
	// Print test header
	ft_test_header("Test for the 42cursus libft project.");
	// Run tests for functions
	count_pass += ft_atoi_test(full);
	count++;
	count_pass += ft_bzero_test(full);
	count++;
	count_pass += ft_calloc_test(full);
	count++;
	count_pass += ft_isalnum_test(full);
	count++;
	count_pass += ft_isalpha_test(full);
	count++;
	count_pass += ft_isascii_test(full);
	count++;
	count_pass += ft_isdigit_test(full);
	count++;
	count_pass += ft_isprint_test(full);
	count++;
	count_pass += ft_itoa_test(full);
	count++;
	count_pass += ft_memchr_test(full);
	count++;
	count_pass += ft_memcmp_test(full);
	count++;
	count_pass += ft_memcpy_test(full);
	count++;
	count_pass += ft_memmove_test(full);
	count++;
	count_pass += ft_memset_test(full);
	count++;
	count_pass += ft_putchar_fd_test(full);
	count++;
	count_pass += ft_putendl_fd_test(full);
	count++;
	count_pass += ft_putnbr_fd_test(full);
	count++;
	count_pass += ft_putstr_fd_test(full);
	count++;
	count_pass += ft_split_test(full);
	count++;
	count_pass += ft_strchr_test(full);
	count++;
	count_pass += ft_strdup_test(full);
	count++;
	count_pass += ft_striteri_test(full);
	count++;
	count_pass += ft_strjoin_test(full);
	count++;
	count_pass += ft_strlcat_test(full);
	count++;
	count_pass += ft_strlcpy_test(full);
	count++;
	count_pass += ft_strlen_test(full);
	count++;
	count_pass += ft_strmapi_test(full);
	count++;
	count_pass += ft_strncmp_test(full);
	count++;
	count_pass += ft_strnstr_test(full);
	count++;
	count_pass += ft_strrchr_test(full);
	count++;
	count_pass += ft_strtrim_test(full);
	count++;
	count_pass += ft_substr_test(full);
	count++;
	count_pass += ft_tolower_test(full);
	count++;
	count_pass += ft_toupper_test(full);
	count++;
	count_pass += ft_lstnew_test(full);
	count++;
	count_pass += ft_lstlast_test(full);
	count++;
	count_pass += ft_lstadd_back_test(full);
	count++;
	count_pass += ft_lstadd_front_test(full);
	count++;
	count_pass += ft_lstdelone_test(full);
	count++;
	count_pass += ft_lstclear_test(full);
	count++;
	count_pass += ft_lstiter_test(full);
	count++;
	count_pass += ft_lstsize_test(full);
	count++;
	count_pass += ft_lstmap_test(full);
	count++;
	// Print summary
	ft_print_rate(count_pass, count, max);
}
