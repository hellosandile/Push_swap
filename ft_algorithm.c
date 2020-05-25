#include "push_swap.h"
#include <stdio.h>

void	ft_free_linkedlist(struct node *head)
{
	struct node *temp;
	temp = head;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	ft_printlist(struct node *head)
{
	struct node *stack;

	stack = head;
	while (stack != NULL)
	{
		printf("%d", stack->data);
		printf(" ");
		stack = stack->next;
	}
}

int	main(int ac , char **av)
{
	char **data;
	stack_a *list;
	stack_b *listb;
	list = (stack_a *)malloc(sizeof(stack_a));
//	listb = (stack_b *)malloc(sizeof(stack_b));
	listb = NULL;
	char *str;
	char *temp;
	//char *avConcatStr;
	int i;
	if (ac >= 2)
	{
		if (ac == 2)
			{
				data = ft_strsplit(av[1], ' ');
				i = 0;
			while(data[i])
			{
			//	free(data[i]);
				i++;
			}
		//free(data);
			}
		else
		{
			str = av[1];
			i = 2;
			while (i < ac)
			{
				temp = ft_strjoin(str, " ");
				if (i > 2)
					free(str);
				str = ft_strjoin(temp, av[i]);
				free(temp);
				//temp = str;
				//free(str);
				//free(str);
				i++;
				//free(strTemp);
				//free(avConcatStr);
			}
			data = ft_strsplit(str, ' ');
			free(str);
		}
		ft_initialize(&list, data);
		i = 0;
		while(data[i])
			{
				free(data[i]);
				i++;
			}
		free(data);
		if (ft_dup(list))
		{
			ft_putendl("Error");
			return 0;
		}
		if (ft_listsize(list) < 4 && ft_stacksorted(list) == 0)
			ft_sort_three(&list);
        if (ft_listsize(list) <= 50  && ft_listsize(list) > 3 && ft_stacksorted(list) == 0)
			ft_sort_five(&list, &listb);
		if (ft_listsize(list) > 50 && ft_listsize(list) <= 100 && ft_stacksorted(list) == 0)
			ft_sort_100(&list, &listb);
		if (ft_listsize(list) > 100 && ft_stacksorted(list) == 0)
			ft_sort_more_than_100(&list, &listb);
    }
	//printf("Final list contents of stack_a: ");
	//ft_printlist(list);
	//printf("\n");
//	printf("Final list contents of stack_b: ");
	//ft_printlist(listb);
	//printf("\n");
	ft_free_linkedlist(list);
	ft_free_linkedlist(listb);
	
	return 0;
}

//when you free linked list needs to free everthing in the list not just first node