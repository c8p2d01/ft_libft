#include "../ft_graph.h"

static int	print_indent(size_t indent)
{
	int		res;
	size_t	i = 0;

	i = 0;
	while (i < indent)
	{
		res += printf("   ");
		i++;
	}
	return (res);
}

int	qt_print_node(t_graph *node, size_t indent, int q_num)
{
	int res;

	res = 0;
	res += print_indent(indent);
	res += printf("%i\tx: %.2f\n", q_num, node->pos.x);

	res += print_indent(indent);
	res += printf("\ty: %.2f\n", node->pos.y);
	return (res);
}

int	qt_print(t_qt_node *root, size_t indent, int q_num)
{
	int res;
	int	q;

	res = 0;
	if (root->node)
		res += qt_print_node(root->node, indent, q_num);
	res += print_indent(indent);
	res += printf("mass: %.0lf\n", root->total_mass);
	q = 0;
	while (q < 4)
	{
		//printf("q%i: %p\n", q, root->children[q]);
		if (root->children[q])
			res += qt_print(root->children[q], indent + 1, q + 1);
		q++;
	}
	return (res);
}
