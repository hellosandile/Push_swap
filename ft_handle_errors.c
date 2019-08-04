#include "push_swap.h"
//The error is print on the fd because of the instruction on the PDF
int			ft_handle(stack_a *head, char **stack, int *size)
{
	if (ft_check(stack))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	ft_populate(head, stack, size);
	if (ft_dup(head))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	return (0);
}
// This is how we took out the error for the first instrunction however double check if the length is 2  and you understand then this function is not needed.
char		*ft_instr(char *str)
{
	return (ft_strsub(str, 1, ft_strlen(str)));
}

//Here we are checking if the instrunction exists which are stated in the ft_errors.c

int			ft_handle_instr(char *instr)
{
	if (ft_exist(instr))
		return (0);
	return (1);
}
