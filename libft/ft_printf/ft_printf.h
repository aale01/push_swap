/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebe <abecucci@student.42roma.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:09:43 by alebe             #+#    #+#             */
/*   Updated: 2025/04/03 20:07:57 by abecucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_arg_print(const char **format, va_list args);
int		ft_arg_char(const char *format, size_t size, char c);
int		ft_arg_int(const char *format, size_t size, int nbr);
int		ft_arg_uint(const char *format, size_t size, unsigned int nbr);
int		ft_arg_str(const char *format, size_t size, const char *str);
int		ft_arg_hexa(const char *format, size_t size, unsigned int nbr);
int		ft_arg_ptr(const char *format, size_t size, unsigned long nbr);
char	*ft_strnchr(const char *s, size_t size, int c);
int		ft_search_precision_format(const char *format, size_t size);
int		ft_search_width(const char *format, size_t size);
int		ft_search_width_format(const char *format, size_t size);
int		ft_atoi_size(const char *str, size_t size);
int		ft_max(const int n, ...);
void	ft_putposnbr(unsigned long long n);
int		ft_putnchar(char c, int num);
void	ft_hexa(unsigned long nbr, char c);
long	ft_abs(long nbr);

#endif
