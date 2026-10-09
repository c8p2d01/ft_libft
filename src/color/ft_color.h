#ifndef FT_COLOR_H
# define FT_COLOR_H

# include "../../inc/libft.h"

#include "ft_color_struct.h"

/*
	Basic Color Macros
*/

# define RED		"\e[38;2;255;0;0m"
# define MAGENTA	"\e[38;2;255;255;0m"
# define BLUE		"\e[38;2;0;255;0m"
# define GREEN		"\e[38;2;0;0;255m"
# define YELLOW		"\e[38;2;255;0;255m"
# define ORANGE		"\e[38;2;128;0;128m"

# define RESET		"\e[0m"
# define TERM_CLEAR	"\e[1;1H\e[2J"

//# define STTY_RESET"\e[?1000;1006h"

/*
	Color Functionality
*/

t_color	new_color(int r, int g, int b);

t_color	create_gradient_color(float fraction, t_color a, t_color b);

t_color	create_multi_gradient(float fraction, int nColor, ...);

int		create_rgb(int r, int g, int b);
int		color_to_rgb(t_color a);
int		color_to_rgbt(t_color a, int alpha);
int		color_to_trgb(t_color a, int alpha);

/*
	Uses
*/

int		terminal_rgb(char r, char b, char g, bool background);
int		terminal_color(t_color a, bool background);
void	color_range(int num, int low, int high, char c);


#endif