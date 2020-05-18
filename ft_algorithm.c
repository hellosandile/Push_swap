#include "push_swap.h"

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
		ft_initialize(&list, data);
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
	free(list);
	free(listb);
	free(str);
	return 0;
}