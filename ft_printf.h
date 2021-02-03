/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:16:41 by iouali            #+#    #+#             */
/*   Updated: 2021/02/03 13:33:24 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_handle_all(char *str, va_list params);
int		ft_handle_str(char *str, char *flags);
int		ft_handle_char(int c, char *flags);
int		ft_handle_int(long long nb, char *flags);
void	ft_putnbr(long long c, int precision);
void	ft_putstr(char *str);
int		ft_printf(const char *str, ...);
int		ft_handle_hexa(long long nb, char *flags, char op);
void	write_to_hexa(long long c, char op);
int		is_op(char c);
char	get_op(char *str);
char	*parse_flags(char *str, va_list params);
int		ft_handle_flags_int(char *flags, int len, int after, long long nb);
int		print_spaces(int width, int precision, int len, long long nb);
int		print_zeros(int len, long long nb, int precision, char *flags);
int		get_precision(char *flags);
int		get_width(char *flags);
int		get_zeros(char *flags, int precision);
int		get_print_after(char *flags, int zeros, int len, int precision);
char	*replace_with_star(char *orig, int n, int len);
int		ft_handle_flags_str(char *flags, int len, int after);
int		print_spaces_str(int width, int len);
int		print_str_len(char *str, int max);
int		ft_handle_flags_char(char *flags, int after);
int		print_zeros_hexa(char *flags, int *tab, long long nb, int zeros);
int		print_spaces_hexa(int width, int precision, int len, long long nb);
int		ft_handle_flags_hexa(char *flags, int *tab, int after, long long nb);
int		ft_handle_pointers(unsigned long long nb, char *flags);
int		size_of_hex(unsigned long long nb);
int		ft_handle_percent(char *flags);
int		print_spaces_percent(int width);
int		print_zeros_percent(int width);
int		ft_check_if_zeros(char *flags, int len, long long nb);
int		ft_handle_flags_hexa_extension(char *flags, int *tab, int after,
										long long nb);
void	print_zeros_hexa_extension(long long nb, int precision, char op);
int		ft_handle_hexa_extension(long long nb, char *flags, int len, int *tab);
int		ft_printf_extension(int len, const char *str, va_list params);
int		check_nb_len(long long nb);
int		ft_handle_flags_int_ext(char *flags, int len, int after, long long nb);
void	print_zeros_int_ext(long long nb, int precision);
int		ft_handle_pointers_extension(unsigned long long nb, char *flags,
									int len, int *tab);
int		ft_handle_pointers_bis(unsigned long long nb, char *flags,
										char op);
int		ft_handle_flags_pointers_extension(char *flags, int *tab, int after,
								unsigned long long nb);
int		ft_handle_flags_pointers(char *flags, int *tab, int after,
									unsigned long long nb);
int		print_spaces_pointers(int width, int precision, int len,
								unsigned long long nb);
int		print_zeros_pointers(char *flags, int *tab, unsigned long long nb,
								int zeros);
void	write_to_hexa_pointers(unsigned long long c, char op);
void	print_zeros_pointers_extension(unsigned long long nb, int precision,
										char op);
int		size_until_op(char *str);

#endif
