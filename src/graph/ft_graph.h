#ifndef FT_GRAPH_H
# define FT_GRAPH_H

# include "../../inc/libft.h"

# define K_THETA   0.5
# define K_REPULSE 48
# define K_SPRING  12

typedef struct s_graph
{
	struct s_list	*links;
	char			*name;
	t_vec2d			pos;
	t_vec2d			force;
	t_vec2d			velocity;
	void			*content;
}	t_graph;

typedef struct s_link
{
	struct s_graph	*from;
	struct s_graph	*to;
	bool			active;
	int				direction;
}	t_link;

typedef struct s_net
{
	t_list	*graph_nodes;
	t_list	*graph_links;
	void	*content;
}	t_net;

typedef struct s_qt_node
{
	t_vec2d	bound_x;
	t_vec2d	bound_y;
	t_vec2d	center;
	double	total_mass;
	bool	is_leaf;
	t_graph	*node;
	struct	s_qt_node *children[4];
	double	min_width;
} t_qt_node;

// graph setup

t_net	**catch();
t_net	*ft_new_net();
t_graph	*ft_new_graph(char *name, int x, int y);
t_link	*ft_new_link(t_graph *in, t_graph *out);

// graph utils

t_link	*ft_link_graphs(t_graph *a, t_graph *b);
t_link	*ft_are_linked(t_graph *a, t_graph *b);
void	ft_unlink_graphs(t_graph *a, t_graph *b);
size_t	n_links(t_graph *a);
t_graph	*ft_linked_to(t_graph *a, t_link *link);
t_graph	*ft_node_exist(char *name);

// graph preperation

void		velocity_reset();
t_qt_node	*new_qt_root(t_vec2d x, t_vec2d y, size_t n);
t_qt_node	*new_qt_node(t_qt_node *parent, int quartile);
int			determine_quadrant(t_qt_node *root, t_graph *node);

void		force_reset();
t_vec2d		apply_forces();
void		link_force(t_link *link);

void		qt_plot(t_qt_node *root, bool nodes, bool center);
int			qt_print_node(t_graph *node, size_t indent, int q_num);
int			qt_print(t_qt_node *root, size_t indent, int q_num);

// parsing utils

void	input_parser(char *file);
void	input_check();
int8_t	determine_input_type(char *line);
t_graph	*create_node(char *raw_line, t_graph **node_destination);
t_link	*create_link(char *raw_line);
void	comment_parsing(char *raw_line);

int		interrupt(char *format, ...);

#endif
