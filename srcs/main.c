#include "lem-in.h"

/*	if(start == 1)
		e->s[i].start = 1;
	else
		e->s[i].start = 0;

	if(end == 1)
		e->s[i].end = 1;
	else
		e->s[i].end = 0;*/

int ft_strlen_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}



int main()
{
	t_env e;
	int i;

	i = 0;
	if(ft_pars(&e) == -1)
		return(-1);
	ft_resolv(&e);















	return(0);
}