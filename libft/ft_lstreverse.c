#include "libft.h"

void ft_lstreverse(t_list **lst)
{
	t_list* prev   = NULL;
	t_list* current = *lst;
	t_list* next;
	while (current != NULL) {
		next  = current->next; 
		current->next = prev;  
		prev = current;
		current = next;
	}
	*lst = prev;
}
