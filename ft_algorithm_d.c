#include "push_swap.h"
#include <stdio.h>

void	sortNumbers(stack_a **a, stack_b **b)
{
	stack_a *list;
	stack_b *listb;
	list = *a;
	listb = *b;
	int len = listsize(list) / 2;
	int m;
	m  = medianValue(list);

	while(listsize(list) > len)
	{
		if (list->data > m)
		{
		ft_reverse_a(&list, listsize(list));
		}
		if (list->data < m)
			ft_push_b(&list, &listb);
		if (list->data == m)
			break;
	}
	*a = list;
	*b = listb;
}

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
		return; 
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

void	TestEndDisplay(stack_a ** a)
{
	stack_a *list;
	list = *a;
	printf("Final list contents of stack_a: ");
	ft_printlist(list);
	printf("Final list contents of stack_b: ");
	printf("\nCurrent list size of stack_a: ");
	printf("%i\n", listsize(list));
}

int medianValue(struct node *head) 
{ 
	int i = 0; 
    stack_a *mid = head;
	stack_b *listb = NULL;
	if (listsize(mid) % 2 == 0)
	{
		ft_remove_last(&mid);
		sortFive(&mid, &listb);
	}
	else
		sortFive(&mid, &listb);
    while (head != NULL) 
    { 
        if (i & 1) 
            mid = mid->next; 
        i++; 
        head = head->next; 
    } 
    if (mid != NULL) 
    	return (mid->data);
	return (mid->data);
} 

int	main(int ac , char **av)
{
	char **data;
	stack_a *list;
	stack_b *listb;
	list = (stack_a *)malloc(sizeof(stack_a));
	listb = (stack_b *)malloc(sizeof(stack_b));
	listb = NULL;
	char *str = NULL;
	char *avConcatStr = NULL;
	int i;
	
	if (ac >= 2)
	{
		if (ac == 2)
			data = ft_strsplit(av[1], ' ');
		else
		{
			str = av[1];
			i = 2;
			while (i < ac)
			{
				str = ft_strjoin(str, " ");
				avConcatStr = ft_strjoin(str, av[i]);
				str	= avConcatStr;
				i++;
			}
			data = ft_strsplit(str, ' ');
		}
		initialize(&list, data);
		if (ft_dup(list))
		{
			ft_putendl("Error");
			return 0;
		}
		sortNumbers(&list, &listb);
		/*
		if (listsize(list) < 4 && stacksorted(list) == 0)
			sortThree(&list);
        if (listsize(list) < 50  && listsize(list) > 3 && stacksorted(list) == 0)
			sortFive(&list, &listb);
		if (listsize(list) > 5 && stacksorted(list) == 0)
			sort100(&list, &listb);
			*/
    }
	//TestEndDisplay(&list);
	printf("Final list contents of stack_a: ");
	ft_printlist(list);
	printf("\n");
	printf("Final list contents of stack_b: ");
	ft_printlist(listb);
	return 0;
}


//About to work with a sorted list of 1 2 3 4 5 but not when things are mixed up
// get some help and sort this out asap
