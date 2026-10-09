#include "../ft_print.h"

/**
 * @brief empty the files used for debugging
 */
void	reset_files(void)
{
	FILE	*file;
	char	*string;
	char	*files[3];
	int		i;

	if (!(*persist_env()))
		return ;
	files[0] = "/me.txt";
	files[1] = "/original.txt";
	files[2] = "/debug.txt";
	i = 0;
	while (i < 3)
	{
		string = ft_strjoin(get_value("PWD"), files[i]);
		if (string)
		{
			file = fopen(string, "w+");
			fclose(file);
			ft_free(string);
			string = NULL;
		}
		i++;
	}
}

/**
 * @brief execute the original function and our function for comparison
 */
void	print_to_file(char *fmt, va_list va, bool original)
{
	FILE	*file;
	int		result;
	char	*string;

	if (original)
	{
		string = ft_strjoin(get_value("PWD"), "/original.txt");
		if (!string)
			return ;
		file = fopen(string, "a+");
		result = vfprintf(file, fmt, va);
	}
	else
	{
		string = ft_strjoin(get_value("PWD"), "/me.txt");
		if (!string)
			return ;
		file = fopen(string, "a+");
		result = ft_vfprintf(file, fmt, va);
	}
	fprintf(file, "\nreturn value = %i\n\n", result);
	fclose(file);
	ft_free(string);
}

/**
 * @brief debug print behaviour against original
 * empty call empties output files
 * other calls append to them
 */
void	compare(char *fmt, ...)
{
	va_list	va;

	if (!fmt)
		reset_files();
	if (!fmt)
		return ;
	va_start(va, fmt);
	print_to_file(fmt, va, true);
	va_end(va);
	va_start(va, fmt);
	print_to_file(fmt, va, false);
	va_end(va);
}
