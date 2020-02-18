#include "push_swap.h"
#include <stdio.h>


void	sortFive(struct node **head)
{
	stack_a *list;
	stack_b *listb;
	list = *head;
	listb = NULL;

	while (listsize(list) > 3 && stacksorted(list) == 0)
		{
			if (last(&list) == min(&list))
			{
				ft_reverse_a(&list, listsize(list));
				//ft_printlist(list);
				//printf("%s", "-");
				//sleep(5);
				ft_putendl("rra");
			}
			 if (list->data != min(&list))
			{
				ft_shift_a(&list, 2);
				ft_putendl("ra");
			}
			if (list->data == min(&list))
			{
				ft_push_b(&list, &listb);
				ft_putendl("pb");
			}
		}
		while (stacksorted(list) != 1)
		{
			if (last_g_middle(&list) == 0 && head_g_middle(&list) == 0 && head_g_last(&list) == 1)
			{
				ft_reverse_a(&list, 3);
				ft_putendl("rra");
				
			}
			if (last_g_middle(&list) == 0 && head_g_middle(&list) == 1)
			{
				ft_shift_a(&list, 2);
				ft_putendl("ra");
			}
			if (last_g_middle(&list) == 1 && head_g_last(&list) == 1)
			{
				ft_shift_a(&list, 2);
				ft_putendl("ra");
			}
			if (head_g_middle(&list) == 1)
			{
				ft_swap_a(&list, 2);
				ft_putendl("sa");
			}
			if (head_g_middle(&list) == 0 && last_g_middle(&list) == 0)
			{
				ft_swap_a(&list, 2);
				ft_putendl("sa");
			}
		}
		while (listsize(listb) > 0)
		{
			ft_push_a(&list, &listb);
			ft_putendl("pa");
			printf("%p\n", (void *) list->next);
		}
}



int	main(int ac , char **av)
{
	char **data;
	stack_a *list;
	stack_b *listb;

	list = (stack_a *)malloc(sizeof(stack_a));
	listb = (stack_b *)malloc(sizeof(stack_b));
	listb = NULL;

    if (ac ==2)
    {
		data = ft_strsplit(av[1], ' ');
		initialize(&list, data);
        if (listsize(list) == 5  && stacksorted(list) == 0)
			sortFive(&list);	
    }
ft_printlist(list);
//ft_printlist(listb);
return 0;
}
