#include "push_swap.h"


int		ft_get_max(stack_a *a)

{

	stack_a *	ptr;

	int		v;

	ptr = a;

	v = ptr->v;

	while (ptr)

	{

		if (v < ptr->v)

			v = ptr->v;

		ptr = ptr->next;

	}

	return (v);

}


int		ft_get_min(stack_a *a)

{

	stack_a *ptr;

	int		v;

	ptr = a;

	v = ptr->v;

	while (ptr)

	{

		if (v > ptr->v)

			v = ptr->v;

		ptr = ptr->next;

	}

	return (v);

}

// START HERE
int		*ft_create_range(int min, int max, int size)

{

	int		i;

	int		r;

	int		max_f;

	int		*range = NULL;


	if (size >= 100)

	{

		i = 0;

		if (size == 100) //listsize

		{

			range = (int *)malloc(sizeof(int) * 5); //Allcating memory for the five chucks

			r = (max - min) / 5; // range of numbers in the chuck

			r += (max-min % 5 == 0) ? 0 : 1; // Brush up on this syntax

			max_f = r + (min - 1); // This calcuation gives you last number of the chunck

			range[i] = max_f;

			if (max_f < 0)
				max_f = -1 * max_f; // this deals with the negtives
			
			//This is to make sure is continues in the specified chunk
			while (++i < 4)

			{

				range[i] = range[i - 1] + max_f;

			}

			range[i] = max;

		}

		else if (size > 100) //call the listsize

		{

			range = (int *)malloc(sizeof(int) * 11); // We got it from the artical and this is the most optinal. Maybe see if you can make it better

			r = (max - min) / 11;

			max_f = r + (min - 1);

			range[i] = max_f;

			while (++i < 10)

				range[i] = range[i - 1] + max_f;

			range[i] = max;

		}

	}

	return (range);

}

//sort both 100 and 500
void	ft_sort_100(stack_a **a, stack_b **b, int *size)

{

	int		max;

	int		min;

	int		*range;

	int		i;	

	stack_a *ptr;

	stack_b *p;


	i = 0;

	p = *b;

	ptr = *a;

	min = ft_get_min(*a);

	max = ft_get_max(*a);

	range = ft_create_range(min, max, *size);

	while (*size > 1)

	{

		ptr = *a;

		i = 0;

		while (ptr)

		{

			i++;

			if (ptr->v >= min && ptr->v < *range)

			{

				if (ft_get_mid(*size) >= i)

				{

					while (i-- > 1)

					{

						ft_shift_a(a, *size);

						ft_putendl("ra");

					}

					i = 0;

				}

				else

				{

					while (i-- > 0)

					{

						ft_reverse_a(a, *size);

						ft_putendl("rra");

					}

					i = 0;

				}

				ft_get_biggest(b);

				ft_push_b(a, b, size);

				ft_putendl("pb");

				ptr = *a; // remember that ptr is list

			}

			else	

				ptr = ptr->next;

		}

		min = *range;

		range++;

	}

	i = stack_b_size("");

	while (i > 0)

	{

		ft_get_biggest(b);

    		ft_push_a(a, b, size);

		ft_putendl("pa");

		//ft_another_processes(a, b, size); -- but check what is good

		i--;

	}

}
