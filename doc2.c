void		ft_sb(stack_b **b)

{

	if (ft_how_big(*b) && stack_b_size("") > 1)

	{

		if (!ft_sorted_desc(*b))

			return ;

		ft_putendl("sb");

		ft_swap_b(b);

	}

}

​

void		ft_normal_sa(stack_a **a, int *size)

{

	if (ft_first_state(*a, *size))

	{

		ft_ra(a, size);

		ft_rra(a, size);

		ft_swap_a(a, *size);

		ft_putendl("sa");

	}

}

​

int			ft_get_mid(int size) // listsize

{

	if ((size % 2) == 0) // this working with the list size

		return (size / 2);

	else

		return ((size / 2) + 1);

}

​

void        ft_get_biggest(stack_b **a)

{

    stack_b    *ptr;

    int         back;

    int         front;

    int         v;


    ptr = *a;

    front = 0;

    back = 0;

	if (stack_b_size("") == 0)

		return ;

    v = ptr->v;

    while (ptr->next != NULL)

    {

        if (v < ptr->next->v)

            v = ptr->next->v;

        ptr = ptr->next;

    }

    ptr = *a;

    while (ptr->next && ptr->v != v)

    {

        front++;

        ptr = ptr->next;

    }

	ptr = ptr->next;

    while (ptr)

    {

        back++;

        ptr = ptr->next;

    }

    if (front > back || back == 0)

    {

        while (back-- > -1)

        {

            if (!ft_sorted_desc(*a))

                return ;

            ft_reverse_b(a, stack_b_size(""));

            ft_putendl("rrb");

        }

    }

	else

    {

        while (front-- > 0)

        {

            if (!ft_sorted_desc(*a))

                return ;

            ft_shift_b(a, stack_b_size(""));

            ft_putendl("rb");

        }

    }

}
