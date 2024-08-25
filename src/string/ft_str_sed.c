/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:43:01 by cdahlhof          #+#    #+#             */
/*   Updated: 2023/01/02 18:57:10 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * @brief replace every instance of ind in base with add
 * @param base char* base string to search through
 * @param ind indicator to be replaced
 * @param add inserted string
 */
void	str_sed(char **base, char *ind, char *add)
{
	char	*scour;
	int		n;
	int		len[2];

	len[0] = ft_strlen(ind);
	len[1] = ft_strlen(add);
	scour = *base;
	n = -1;
	while (scour - 1 != 0)
	{
		scour = ft_strnstr(scour, ind, ft_strlen(scour)) + 1;
		n++;
	}
	*base = ft_realloc(*base, ft_strlen(*base), n * (len[1] - len[0]));
	scour = *base;
	while (1)
	{
		scour = ft_strnstr(scour, ind, ft_strlen(scour));
		if (!scour)
			break ;
		ft_memmove(scour + len[1], scour + len[0], ft_strlen(scour));
		ft_memcpy(scour, add, len[1]);
		scour += len[1];
	}
}

// int main()
// {
// 	char	*frame = {"\
// 		~~~~~~~~~~~~~~~^!&@@@@@&!^~~~~~~~~~~~~~~~~~~~~~~~\n\
// 		~~~~~~~~~~~~~7PPPGGGGGGGJPP7~~~~~~~~~~~~~~~~~~~~~\n\
// 		~~~~~~~~~~~~^P@@&.     .&@@P^~~~~~~~~~~~~~~~~~~~~\n\
// 		~~~~~~~~~!PPPYPP7:::::::Y555PPPP77!~~~~~~~~~~~~~~\n\
// 		~~~~~~~~~7@@@7   ^^^^^^^!!~5@@@YPP7~~~~~~~~~~~~~~\n\
// 		~~~~~~~~^7@@@P   :::::::!7!5@@@YPPPPPP!~~~~~~~~~~\n\
// 		~~~~~~7PPJGGG!......^7!!!!~J#BB5Y5YPPP!~~~~~~~~~~\n\
// 		~~~~~~G@@B   :^^^   J@@@!^^~!!!#@@BPPP!~~~~~~~~~~\n\
// 		~~~~~~G@@B   :^^^   J@@&!^^~!!!#@@BPPP!~~~~~~~~~~\n\
// 		~~~~~~G@@B   :^^^   J@@&!^^~!!!#@@BPPP!~~~~~~~~~~\n\
// 		~~~~~~G@@B   :^^^   J@@&!^^~!!!#@@BPPPPPP7~~~~~~~\n\
// 		~~~~~~G@@B   :^^^   J@@&!^^~!!!#@@BPPPPPP7~~~~~~~\n\
// 		~~~~~~G@@B   :^^^   J@@&!^^~!!!#@@BPPPPPP7~~~~~~~\n\
// 		~~~~~~G@@B   :^^^   J@@&!^^~!!!#@@BPPPPPP7~~~~~~~\n\
// 		~~~~~~G@@B   :^^^   J@@&!^^~!!!#@@BPPPPPP7~~~~~~~\n\
// 		~~~~~~G@@B   :^^^   J@@&!^^~!!!#@@BPPPPPP7~~~~~~~\n\
// 		~~~~~~G@@B   :^^^   J@@&!^^~!!!#@@BPPPPPP7~~~~~~~\n\
// 		~~~~~~G@@B   :^^^   J@@&!^^~!!!#@@BPPPPPP7~~~~~~~\n\
// 		~~~~~~G@@B   :^^^   J@@@!^^~!!!#@@BPPPPPP7~~~~~~~\n\
// 		~~~~~~G@@B...:^^^   J@&&!^^~777#@@BPPPPPP7~~~~~~~\n\
// 		~~~~~~!!!P##&J^^^:..:^^^!!!Y&&&YJJJPPPPPP7~~~~~~~\n\
// 		~~~~~~~~~7@@@Y^^^:::::::!!!5@@@YPPPPPPPPP7~~~~~~~\n\
// 		~~~~~~~~~7@@@J:^^^^^^^^^!!!5@@@YPPPPPPPPP7~~~~~~~\n\
// 		~~~~~~~~~!JJJ5GGP!~~~~~!PGGG555JPPPPPP7!!!~~~~~~~\n\
// 		~~~~~~~~~~~~^P@@&P77777P&@@G7PPPPPPPPP!~~~~~~~~~~\n\
// 		~~~~~~~~~~~~~!!!7&@&&&&&YJJJPPPPPPPPPP!~~~~~~~~~~\n\
// 		~~~~~~~~~~~~~~~~!GGGBBBBJPPPPPPPPPP777!~~~~~~~~~~\n\
// 		~~~~~~~~~~~~~~~~~~~^!PPPPPPPPPPPPP7~~~~~~~~~~~~~~\n\
// 		~~~~~~~~~~~~~~~~~~~~!!!!PPPPPPP!!!!~~~~~~~~~~~~~~\n\
// 		~~~~~~~~~~~~~~~~~~~~~~~~PPPPPPP~~~~~~~~~~~~~~~~~~\n"
// 	};

// 	char *str = ft_strdup(frame);

// 	printf("before\n%s", str);
// 	str_sed(&str, "\t\t", "\e[38;2;255;42;42m");
// 	str_sed(&str, "\n", "\e[0m\n");
// 	printf("after\n%s", str);
// }
