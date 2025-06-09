#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

# define NULL_PTR "(nil)"

char	*ft_itoa_mod(int n);
char	*ft_utoa(unsigned int n);
int		ft_printf(const char *format, ...);
int		ft_printchar(int c);
int		ft_printnum(int c);
int		ft_printstr(char *s);
int		ft_print_unsigned(unsigned int c);
int		ft_printptr(void *ptr);
int		ft_printhex(unsigned long num, const char c);
int		ft_printpercent(void);
void	ft_to_hex(unsigned long num, char *s, int *i);
void	ft_to_bighex(unsigned long num, char *s, int *i);

#endif