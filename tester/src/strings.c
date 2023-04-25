#include "tester.h"

static void	put_strarr(char** arr)
{
	n_putstr("[ ");
	while (*arr)
	{
		n_putstr(*arr);
		if (*(arr + 1))
			n_putstr(", ");
		arr++;
	}
	n_putstr(" ]");
}

void tester_strings(void)
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
		const char* string = "This is \t a     string   ";
		const char* delimitors = " \t";

		n_putstr_endl("Splitting a string into a strarr (string array):");
		n_putstr_endl("n_split()");
		IND; n_putstr("String: "); n_putstr_endl(string);
		IND; n_putstr("Delimitors: "); n_putstr(delimitors); n_putstr_endl(" (SPACE & TAB)");
		char** arr = n_protect( n_split(string, delimitors) );
		IND; n_putstr("Array: "); put_strarr(arr); NL;
		IND; n_putstr_endl("Freeing with n_free_array()");
		n_free_array(arr, n_strarr_size(arr));
		//	n_strarr_free(arr);
	}

	NL; {
		const char* string1 = "This is a string that's going to be added to a buffer.";
		const char* string2 = " Paste this string behind there, will ya.";

		t_buffer buffer = n_buffer_new(1024);

		n_putstr_endl("Creating a buffer and adding strings to it:");
		IND; n_putstr("String1: "); n_putstr_endl(string1);
		IND; n_putstr("String2: "); n_putstr_endl(string2);

		n_buffer_add(&buffer, string1, n_strlen(string1) * sizeof(char));
		n_buffer_add(&buffer, string2, n_strlen(string2) * sizeof(char));

		n_putstr_endl("n_buffer_write()");
		IND; n_putchar('{'); n_buffer_write(buffer, STDOUT_FILENO); n_putchar('}'); NL;

		n_putstr_endl("n_buffer_free()");
		n_buffer_free(&buffer);
	}

	NL; {
		n_putstr_endl("Creating a dynamic string");
		t_string string = n_string_new_cstr("Hello there how are you?");
		n_string_add_cstr(&string, " I am doing very well!");
		n_string_add_cstr(&string, " WOW this is so cool!");

		n_putstr_endl("n_string_cstr():");
		IND; n_putstr_endl(n_string_cstr(&string));

		n_putstr_endl("n_string_write() to STDOUT:");
		IND; n_string_write(&string, STDOUT_FILENO); NL;

		n_string_free(&string);
	}
}