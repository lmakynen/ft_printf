/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:10:59 by lmakynen          #+#    #+#             */
/*   Updated: 2020/10/13 16:55:58 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

/*
** Macros of conversions, flags, modifiers and all of them combined.
*/

# define CONV "cspdiouxXf%"
# define MOD "#-+ .*0123456789hlLz"
# define FLAGS "-+ #0"
# define ALL "cspdiouxXf#-+ .*0123456789hLljz"
# define CURR_POS s->input[s->pos]
# define NEXT_POS s->input[s->pos + 1]

/*
** Struct for the %[flags][width][.precision][length][conversion specifier].
** h = 1, hh = 2, l = 3, ll = 4, L = 5
*/

typedef struct	s_struct
{
	int		pos;
	int		minus;
	int		plus;
	int		space;
	int		hash;
	int		zero;
	int		width;
	int		precision;
	int		length;
	int		printed;
	int		empty;
	char	*input;
}				t_struct;

void			set_struct(t_struct *s);
void			check_all(t_struct *s, const char *format, va_list ap);
void			check_format(t_struct *s, const char *format, va_list ap);

void			flags(t_struct *s, const char *format);
void			length(t_struct *s, const char *format);
void			width(t_struct *s, const char *format, va_list ap);
void			precision(t_struct *s, const char *format, va_list ap);
void			modifier(t_struct *s, const char *format, va_list ap);

void			conversion(t_struct *s, const char *format, va_list ap);
void			char_conv(t_struct *s, va_list ap);
void			str_conv(t_struct *s, va_list ap);
void			int_conv(t_struct *s, va_list ap);

int				check_input(const char *format, t_struct *s, va_list ap);
int				ft_printf(const char *format, ...);

#endif
