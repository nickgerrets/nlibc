#ifndef TESTER_H
# define TESTER_H

# include <unistd.h>
# include <stdio.h>

# include "nlibc.h"

# define NL write(STDOUT_FILENO, &"\n", sizeof(char));
# define IND write(STDOUT_FILENO, &"\t", sizeof(char));

void tester_strings(void);
void tester_lists(void);
void tester_tree(void);
void tester_tokenizer(void);
void tester_stack(void);

#endif // TESTER_H
