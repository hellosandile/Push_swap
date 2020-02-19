#include "push_swap.h"
#include <stdio.h>

void	sortFive(stack_a **a, stack_b **b)
{
	stack_a *list;
	stack_b *listb;
	list = *a;
	listb = *b;
	
	while (listsize(list) > 3 && stacksorted(list) == 0)
		{
			if (last(&list) == min(&list))
			{
				ft_reverse_a(&list, listsize(list));
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
			sortThree(&list);
		while (listsize(listb) > 0)
		{
			ft_push_a(&list, &listb);
			ft_putendl("pa");
		}
		if (listsize(listb) == 0)
			listb = NULL;
		*a = list;
}

void	sortThree(stack_a **a)
{
	stack_a *list;
	list = *a;

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
		}
		*a = list;
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
		if (listsize(list) < 4 && stacksorted(list) == 0)
			sortThree(&list);
        if (listsize(list) < 6  && listsize(list) > 3 && stacksorted(list) == 0)
			sortFive(&list, &listb);	
    }
printf("Final list contents of stack_a: ");
ft_printlist(list);
printf("\nCurrent list size of stack_a: ");
printf("%i\n", listsize(list));
return 0;
}