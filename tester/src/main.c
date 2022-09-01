#include "nlibc.h"

#define NL write(STDOUT_FILENO, &"\n", sizeof(char))

void	custom_protect_func(void)
{
	n_putstr_fd("ERROR!", STDERR_FILENO);
}

int	main(void)
{

	{
		int *arr;
		arr = n_protect(n_zalloc(0));
		free(arr);
	}


	n_putstr( n_protect( n_strfind("this is a string", "is") ) );

	NL;

	n_putint( n_strcmp("string", "trin"));

	NL;

	if (n_strequals("string", "string"))
		n_putstr("strings are equal\n");
	else
		n_putstr("strings are not equal\n");
	
	n_putint(n_str_count_words("    This string has 5 words.   ", " ")); NL;

	n_putint(n_str_count_words("        ", " ")); NL;

	n_putint(n_str_count_words("    This    string   \t\t\t\t  \n\n\n\n\n   has 6 wor\nds.   da   ", " \t\n")); NL;

	char	**arr;

	arr = n_split("This is \t\t\t\n\n\n a string", " \n\t");
	n_strarr_exec(arr, n_putstr_endl);

	return (0);
}