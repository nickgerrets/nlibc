#ifndef TESTER_H
# define TESTER_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>

# include "nlibc.h"

# define NL write(STDOUT_FILENO, &"\n", sizeof(char));
# define IND write(STDOUT_FILENO, &"\t", sizeof(char));

# define LOG(msg) printf(msg"\n");

# define TEST(msg, expression) \
	{ \
		if (expression) \
			printf("[\033[0;32m OK \033[0m]\t%s\n", msg); \
		else \
			printf("[\033[0;31mFAIL\033[0m]\t%s\n", msg); \
	};

# define DREF(T, ptr) (*(T *)(ptr))
# define CAST(T, val) ((T)(val))


void test_vector(void);
void test_hashmap(void);
void test_lists(void);
void test_macrovector(void);

#endif // TESTER_H
