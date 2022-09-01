#include "nlibc.h"

#define NL write(STDOUT_FILENO, &"\n", sizeof(char))
#define IND write(STDOUT_FILENO, &"\t", sizeof(char))

void	custom_protect_func(void)
{
	n_putstr_fd("ERROR!", STDERR_FILENO);
}

int	main(void)
{

	//	Finding a substring within a string:
	NL; {
		const char*	string = "This is a string!";
		const char* substring = "a";

		n_putstr_endl("Finding a substring within a string:");
		n_putstr_endl("n_strfind()");
		IND; n_putstr("String: "); n_putstr_endl(string);
		IND; n_putstr("Substring: "); n_putstr_endl(substring);

		char* found = n_strfind(string, substring);
		IND; n_putstr("Found: ");
		if (found)
		{
			n_putstr("true ("); n_putstr(found); n_putstr_endl(")");
		}
		else
			n_putstr_endl("false");
	}

	//	Checking if a string is equal to another
	NL; {
		const char* string1 = "Hello!";
		const char* string2 = "Hey!";
		const char* string3 = "Hello!";

		n_putstr_endl("Checking if a string is equal to another:");
		n_putstr_endl("n_strequal()");
		IND; n_putstr("String1: "); n_putstr_endl(string1);
		IND; n_putstr("String2: "); n_putstr_endl(string2);
		IND; n_putstr("String3: "); n_putstr_endl(string3);
		
		IND; n_putstr("1 == 2: "); n_putint(n_strequals(string1, string2)); NL;
		IND; n_putstr("1 == 3: "); n_putint(n_strequals(string1, string3)); NL;

		n_putstr_endl("n_strcmp()");
		IND; n_putstr("(1, 2): "); n_putint(n_strcmp(string1, string2)); NL;
		IND; n_putstr("(1, 3): "); n_putint(n_strcmp(string1, string3)); NL;
	}

	NL; {

		
	}
	
	n_putint(n_str_count_words("    This string has 5 words.   ", " ")); NL;

	n_putint(n_str_count_words("        ", " ")); NL;

	n_putint(n_str_count_words("    This    string   \t\t\t\t  \n\n\n\n\n   has 6 wor\nds.   da   ", " \t\n")); NL;

	char	**arr;

	arr = n_split("This is \t\t\t\n\n\n a string", " \n\t");
	n_strarr_exec(arr, (t_str_f)n_putstr_endl);

	return (0);
}