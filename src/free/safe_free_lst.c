#include "../../minirt.h"


void	ft_safe_lstdelone(t_list *lst, void (*del)(void **))
{
	del(&(lst->content));
	free(lst);
	lst = NULL;
}

void	ft_safe_lstclear(t_list **lst, void (*del)(void **))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_safe_lstdelone(*(lst), del);
		*(lst) = tmp;
	}
	lst = NULL;
}