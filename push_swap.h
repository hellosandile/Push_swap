/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samkhize <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:39:38 by samkhize          #+#    #+#             */
/*   Updated: 2019/09/06 10:32:19 by samkhize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./get_next_line/get_next_line.h"
#include <stdio.h>

typedef struct	node
{
	int			data;
	int			ptr;
	struct node	*next;
}				stack_a, stack_b;

void		ft_print(struct node **head, int size);
void		ft_swap_a(stack_a **a, int s);
void		ft_swap_b(stack_b **b, int s);
void		ft_push_a(stack_a **a, stack_b **b);
void		ft_push_b(stack_a **a, stack_b **b);
void		ft_shift_a(stack_a **a, int s);
void		ft_shift_b(stack_b **b, int s);
void		ft_reverse_a(stack_a **a, int s);
void		ft_reverse_b(stack_b **b, int s);
void		ft_shift_both(stack_a **a, stack_b **b, int s);
void		ft_reverse_both(stack_a **a, stack_b **b, int s);
void		ft_push_both(stack_a **a, stack_b **b, int *s);
void		ft_swap_both(stack_a *a, stack_b *b);
int			ft_exist(char *str);
void		ft_populate(stack_a *head, char **stack, int *size);
int			ft_parse_int(char *value);
int			ft_range(char *value);
int			ft_dup(stack_a *head);
int			ft_check(char **stack);
int			ft_handle(stack_a *head, char **stack, int *size);
int			ft_handle_instr(char *instr);
void		ft_follow(stack_a **a, stack_b **b, char *instr, int *s);
void		ft_remove_first(struct node **head);
char		*ft_instr(char *str);
void		ft_remove_last(struct node **head);
void		ft_add_first(struct node **head, int value);
int			stack_b_size(char *oper);
void		stack_a_size(int *size, char *oper);
int			ft_sorted(stack_a *head);
void		ft_generate_b(stack_a *a, stack_b *b, int *size);
int			ft_is_less(struct node **head);
int			ft_first_state(struct node *head);
int			ft_is_bigger(struct node **head, int s);
int			ft_sorted_desc(stack_b *head);

void		ft_printlist(stack_a *head);
void		ft_initialize(struct node **head, char **data);
int 		ft_head_g_last(struct node **head);
int			ft_last_g_middle(struct node **head);
int			ft_middle_g_last(struct node **head);
int			ft_head_g_middle(struct node **head);
int			ft_stack_sorted(struct node **head);
int			ft_last(struct node **head);
int			ft_min(struct node **head);
int			ft_max(struct node **head);
int			ft_listsize(struct node *head);
int			ft_stacksorted(struct node *head);

void		ft_sort_100(stack_a **a, stack_b **b);
void		ft_sort_more_than_100(stack_a **a, stack_b **b);
int			*ft_create_range(int min, int max, int size);
int			ft_mid(int size);
void		ft_get_biggest(struct node **head);
void		ft_sort_three(stack_a **a);
void		ft_sort_five(stack_a **a, stack_b **b);
int 		ft_median_value(stack_a **head);
int			ft_big_value(stack_a *head);
int			ft_first_sec_value(stack_a *head, int size);
int			ft_less_value(stack_a *head, int size);
void	ft_free_linkedlist(struct node *head);

#endif
