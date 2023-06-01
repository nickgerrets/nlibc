#ifndef COMMON_H
# define COMMON_H

# include <stddef.h>

// A byte is 8 bits (unsigned int of size 1)
typedef __UINT8_TYPE__	byte_t;

typedef void (*data_func_t)(void *);

#endif // COMMON_H
