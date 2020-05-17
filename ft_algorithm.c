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
	m  = medianValue(&list);
	printf("%d\n", m);

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

int getMiddle(struct node *head) 
{ 
    int count = 0; 
    struct node *mid = head; 
  
    while (head != NULL) 
    { 
        if (count & 1) 
            mid = mid->next; 
  
        ++count; 
        head = head->next; 
    } 
    if (mid != NULL) 
        return(mid->data);
	return(mid->data); 
} 

int medianValue(stack_a **head) 
{ 
    stack_a *slow_ptr = *head;  
    stack_a *fast_ptr = *head;  
  
    if (head!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }    
    }
	return(slow_ptr->data);
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
	//int m = getMiddle(&list);
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

		testMedian(list);
		
		//sort100(&list, &listb);
		/*
		if (listsize(list) < 4 && stacksorted(list) == 0)
			sortThree(&list);
        if (listsize(list) <= 50  && listsize(list) > 3 && stacksorted(list) == 0)
			sortFive(&list, &listb);
		if (listsize(list) >50 && stacksorted(list) == 0)
			sort100(&list, &listb);
		
		*/
    }
	//TestEndDisplay(&list);
	printf("Final list contents of stack_a: ");
	ft_printlist(list);
	printf("\n");
	printf("Final list contents of stack_b: ");
	ft_printlist(listb);
	printf("\n");
	printf("The median value is: ");
	/*
	printf("%d", m);
	printf("\n");
	*/
	return 0;
}




//About to work with a sorted list of 1 2 3 4 5 but not when things are mixed up
// get some help and sort this out asap
