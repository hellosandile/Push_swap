#include "push_swap.h"

int	main(int ac , char **av)
{
	char **data = NULL;
	stack_a *list;
	stack_b *listb;
	list = (stack_a *)malloc(sizeof(stack_a));
	listb = NULL;
	char *str;
	char *temp;
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
				temp = ft_strjoin(str, " ");
				if (i > 2)
					free(str);
				str = ft_strjoin(temp, av[i]);
				free(temp);
				i++;
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
		if (ft_listsize(list) <= 100 && ft_listsize(list) > 50 && ft_stacksorted(list) == 0)
			ft_sort_100(&list, &listb);
		if (ft_listsize(list) > 100 && ft_stacksorted(list) == 0)
			ft_sort_more_than_100(&list, &listb);
    }
	ft_free_linkedlist(list);
	ft_free_linkedlist(listb);
	return 0;
}