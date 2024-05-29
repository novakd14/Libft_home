/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fnc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 03:05:44 by dnovak            #+#    #+#             */
/*   Updated: 2024/05/29 12:18:37 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	ft_print_success_short(int count)
{
	printf("\033[0;32m");
	printf(" All tests passed (%i)\n", count);
	printf("\033[0m");
}

void	ft_print_success(int index)
{
	printf(" Test %i: ", index);
	printf("\033[0;32m");
	printf("PASSED");
	printf("\033[0m");
}

void	ft_print_fail(int index)
{
	printf(" Test %i: ", index);
	printf("\033[0;31m");
	printf("FAILED");
	printf("\033[0m");
}

void	ft_print_input_int(int num)
{
	printf(" input >>>");
	printf("\033[0;34m%i\033[0m", num);
	printf("<<< ->");
}

void	ft_print_input_intint(int num1, int num2)
{
	printf(" input >>>");
	printf("\033[0;34m%i\033[0m", num1);
	printf("|");
	printf("\033[0;34m%i\033[0m", num2);
	printf("<<< ->");
}

void	ft_print_input_str(char *str)
{
	printf(" input >>>");
	printf("\033[0;34m%s\033[0m", str);
	printf("<<< ->");
}

void	ft_print_input_strstr(char *str1, char *str2)
{
	printf(" input >>>");
	printf("\033[0;34m%s\033[0m", str1);
	printf("|");
	printf("\033[0;34m%s\033[0m", str2);
	printf("<<< ->");
}

void	ft_print_input_strint(char *str, int num)
{
	printf(" input >>>");
	printf("\033[0;34m%s\033[0m", str);
	printf("|");
	printf("\033[0;34m%i\033[0m", num);
	printf("<<< ->");
}

void	ft_print_input_strchar(char *str, char c)
{
	printf(" input >>>");
	printf("\033[0;34m%s\033[0m", str);
	printf("|");
	printf("\033[0;34m%c\033[0m", c);
	printf("<<< ->");
}

void	ft_print_input_charint(char c, int num)
{
	printf(" input >>>");
	printf("\033[0;34m%c\033[0m", c);
	printf("|");
	printf("\033[0;34m%i\033[0m", num);
	printf("<<< ->");
}

void	ft_print_input_strstrsize(char *str1, char *str2, size_t size)
{
	printf(" input >>>");
	printf("\033[0;34m%s\033[0m", str1);
	printf("|");
	printf("\033[0;34m%s\033[0m", str2);
	printf("|");
	printf("\033[0;34m%li\033[0m", size);
	printf("<<< ->");
}

void	ft_print_input_struintsize(char *str, unsigned int num, size_t size)
{
	printf(" input >>>");
	printf("\033[0;34m%s\033[0m", str);
	printf("|");
	printf("\033[0;34m%i\033[0m", num);
	printf("|");
	printf("\033[0;34m%li\033[0m", size);
	printf("<<< ->");
}

void	ft_print_input_sizesize(size_t size1, size_t size2)
{
	printf(" input >>>");
	printf("\033[0;34m%li\033[0m", size1);
	printf("|");
	printf("\033[0;34m%li\033[0m", size2);
	printf("<<< ->");
}

void	ft_print_input_voidsize(void *ptr, size_t n, size_t size)
{
	size_t			i;
	unsigned char	*ptr_tmp;

	ptr_tmp = (unsigned char *) ptr;
	printf(" input >>>");
	printf("\033[0;34m");
	i = 0;
	while (i < n)
	{
		printf("%x", *(ptr_tmp + i++));
		if (i % 4 == 0 && i != n)
			printf(" ");
		else if (i != n)
			printf(":");
	}
	printf("\033[0m");
	printf("|");
	printf("\033[0;34m%li\033[0m", size);
	printf("<<< ->");
}

void	ft_print_input_voidintsize(void *ptr, size_t n, int num, size_t size)
{
	size_t			i;
	unsigned char	*ptr_tmp;

	ptr_tmp = (unsigned char *) ptr;
	printf(" input >>>");
	printf("\033[0;34m");
	i = 0;
	while (i < n)
	{
		printf("%x", *(ptr_tmp + i++));
		if (i % 4 == 0 && i != n)
			printf(" ");
		else if (i != n)
			printf(":");
	}
	printf("\033[0m");
	printf("|");
	printf("\033[0;34m%i\033[0m", num);
	printf("|");
	printf("\033[0;34m%li\033[0m", size);
	printf("<<< ->");
}

void	ft_print_input_voidvoidsize(void *ptr1, size_t n1, void *ptr2, size_t n2, size_t size)
{
	size_t			i;
	unsigned char	*ptr_tmp;

	printf(" input >>>");
	printf("\033[0;34m");
	ptr_tmp = (unsigned char *) ptr1;
	i = 0;
	while (i < n1)
	{
		printf("%x", *(ptr_tmp + i++));
		if (i % 4 == 0 && i != n1)
			printf(" ");
		else if (i != n1)
			printf(":");
	}
	printf("\033[0m");
	printf("|");
	printf("\033[0;34m");
	ptr_tmp = (unsigned char *) ptr2;
	i = 0;
	while (i < n2)
	{
		printf("%x", *(ptr_tmp + i++));
		if (i % 4 == 0 && i != n2)
			printf(" ");
		else if (i != n2)
			printf(":");
	}
	printf("\033[0m");
	printf("|");
	printf("\033[0;34m%li\033[0m", size);
	printf("<<< ->");
}

void	ft_print_test_int(int test, int ref)
{
	printf(" test >>>%i<<< || ref >>>%i<<<\n", test, ref);
}

void	ft_print_test_size(size_t test, size_t ref)
{
	printf(" test >>>%li<<< || ref >>>%li<<<\n", test, ref);
}

void	ft_print_test_str(char *test, char *ref)
{
	printf(" test >>>%s<<< || ref >>>%s<<<\n", test, ref);
}

void	ft_print_test_strarr(char **test, char **ref)
{
	int	i;

	printf(" test >>>");
	i = 0;
	while (*(test + i) != NULL)
	{
		printf("%s", *(test + i++));
		if (*(test + i) != NULL)
			printf(":::");
	}
	printf("<<< | ref >>>");
	i = 0;
	while (*(ref + i) != NULL)
	{
		printf("%s", *(ref + i++));
		if (*(ref + i) != NULL)
			printf(":::");
	}
	printf("<<<\n");
}

void	ft_print_test_void(void *test, void *ref, size_t size)
{
	size_t			i;
	unsigned char	*ptr_tmp;

	printf(" test >>>");
	ptr_tmp = (unsigned char *) test;
	i = 0;
	while (i < size)
	{
		printf("%x", *(ptr_tmp + i++));
		if (i % 4 == 0 && i != size)
			printf(" ");
		else if (i != size)
			printf(":");
	}
	printf("<<< || ref >>>");
	ptr_tmp = (unsigned char *) ref;
	i = 0;
	while (i < size)
	{
		printf("%x", *(ptr_tmp + i++));
		if (i % 4 == 0 && i != size)
			printf(" ");
		else if (i != size)
			printf(":");
	}
	printf("<<<\n");
}

void	ft_print_bold(char *msg)
{
	printf("\033[1m");
	printf("%s", msg);
	printf("\033[0m");
}

void	ft_print_colored(char *msg, char *color_code, int bold)
{
	if (bold)
		printf("\033[1m");
	if (strncmp(color_code, "red", 3) == 0)
		printf("\033[31m");
	else if (strncmp(color_code, "green", 5) == 0)
		printf("\033[32m");
	else if (strncmp(color_code, "yellow", 6) == 0)
		printf("\033[33m");
	else if (strncmp(color_code, "orange", 6) == 0)
		printf("\033[34m");
	else if (strncmp(color_code, "cyan", 4) == 0)
		printf("\033[36m");
	else if (strncmp(color_code, "white", 5) == 0)
		printf("\033[37m");
	printf("%s", msg);
	printf("\033[0m");
}

void	ft_print_rate(int success, int max, int all)
{
	printf("==================================\n");
	if (success == max)
		printf("\033[0;32m");
	else
		printf("\033[0;31m");
	printf("%i of %i (%i) functions succesful.\n", success, max, all);
	printf("\033[0m");
}

int	ft_print_tmp(void)
{
	printf("\033[0;31m");
	printf(" Create a test!!!\n");
	printf("\033[0m");
	return (0);
}

void	ft_print_mem(void *mem, size_t size)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *) mem;
	i = 0;
	while (i < size)
	{
		printf("%x", *(ptr + i++));
		if (i % 2 == 0 && i < size)
			printf(" ");
	}
}

void	ft_print_memchar(void *mem, size_t size)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *) mem;
	i = 0;
	while (i < size)
	{
		if (isprint(*(ptr + i)))
			printf("%c", *(ptr + i));
		else
			printf(".");
		i++;
	}
}

void	ft_print_memint(void *mem, size_t size)
{
	size_t	i;
	int		*ptr;

	ptr = (int *) mem;
	i = 0;
	while (i < size)
	{
		if (i + 4 < size)
		{
			printf("%i", *(ptr + i / 4));
			printf(" ");
		}
		else
		{
			printf("\033[34m");
			printf("%i", *(ptr + i / 4));
			printf("\033[0m");
		}
		i += 4;
	}
}
