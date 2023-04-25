#ifndef TESTER_H
# define TESTER_H

# include "nlibc.h"

# define NL write(STDOUT_FILENO, &"\n", sizeof(char));
# define IND write(STDOUT_FILENO, &"\t", sizeof(char));

void tester_strings(void);
void tester_lists(void);
void tester_tree(void);

#endif // TESTER_H
