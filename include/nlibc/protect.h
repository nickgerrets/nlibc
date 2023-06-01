/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   protect.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 14:31:13 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/09/02 14:31:30 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTECT_H
# define PROTECT_H

typedef void (*protect_func_t)(void);
# define PROTECT_F_DEFAULT error_and_exit

void		error_and_exit(void);
protect_func_t	protect_setf(protect_func_t func);
void		*protect(void *ptr);

#endif // PROTECT_H
