/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:20:31 by samkhize          #+#    #+#             */
/*   Updated: 2019/08/12 15:52:10 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


create a main that will take in the ints on the stack


/* sorting algorithm for 3 numbers
 *
 * if tail is smallest & head is the biggest
 * 		rotate
 *
 * if head > tail & tail  > middle
 * 		rotate
 *
 * if head > middle
 * 		swap
 *
 * if head is small & tail < middle
 * 		rotate
