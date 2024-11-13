/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:30:07 by toferrei          #+#    #+#             */
/*   Updated: 2024/11/13 14:10:39 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# define _DEFAULT_SOURCE

# include "Libft/libft.h"
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		l;		//	length of string
	int		l_b;	//	"length bit (or quantity of bits received)"
	int		str_p;	//	string position
	char	*str;	//	final string
	int		s_b;	//	string bytes
}			t_data;

#endif