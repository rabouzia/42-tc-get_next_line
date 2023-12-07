/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:14:43 by rabouzia          #+#    #+#             */
/*   Updated: 2023/12/07 16:54:28 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen_tren(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while(str[i] != '\n')
        i++;
    return (i);
}
char substr(); // pour return tt la ligne
char *strjoin(); // pour coller
read(); // 


char *get_next_line(int fd)
{
    
}