#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
		tmp = lst;
		lst = tmp->next;
	}
	return (tmp);
}
