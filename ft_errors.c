#include "push_swap.h"

//Checking if it is a number and is in the integer range

int			ft_check(char **stack)
{
	int		i;

	i = 0;
	while (stack[i])
	{
		if (ft_range(stack[i]) == 0 || ft_parse_int(stack[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

//Checking if it is a number and it is called in the above function
//If the return value is 0 then the function is true which means there is an error.

int			ft_parse_int(char *value)
{
	if (ft_atoi(value) || ft_atoi(value) == 0)
		return (1);
	return (0);
}

//Checking the integer range and is called on the top function
// Just refresh my atoi to see how it checks for max & min int values
// Check ft_strequ 
int			ft_range(char *value)
{
	int		num;

	num = ft_atoi(value);
	if (ft_strequ(value, ft_itoa(num)))
		return (1);
	return (0);
}

//Checks for duplicates
int			ft_dup(stack_a *head)
{
	stack_a *c; // means current 
	stack_a	*ptr;
	int		val;

	ptr = head;
	val = ptr->v;
	while (ptr->next != NULL)
	{
		c = ptr;
		while (c->next != NULL)
		{
			if (c->next->v == val)
				return (1);
			c = c->next;
		}
		ptr = ptr->next; //This is how you incrememnt with lists
		val = ptr->v;
	}
	return (0);
}

int			ft_exist(char *str)
{
	if (ft_strequ(str, "sa"))
		return (1);
	else if (ft_strequ(str, "sb"))
		return (1);
	else if (ft_strequ(str, "ss"))
		return (1);
	else if (ft_strequ(str, "pa"))
		return (1);
	else if (ft_strequ(str, "pb"))
		return (1);
	else if (ft_strequ(str, "ra"))
		return (1);
	else if (ft_strequ(str, "rb"))
		return (1);
	else if (ft_strequ(str, "rr"))
		return (1);
	else if (ft_strequ(str, "rra"))
		return (1);
	else if (ft_strequ(str, "rrb"))
		return (1);
	else if (ft_strequ(str, "rrr"))
		return (1);
	return (0);
}
