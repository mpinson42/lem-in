#include "lem-in.h"

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

int ft_check_patch(t_env *e)
{
	int i;
	int j;
	int y;

	y = 0;
	j = -1;
	i = -1;
	while (++i < e->leng_salle && e->s[i].start != 1)
		;
	if (e->s[i].size_bridg == 0)
	{
		ft_putstr("ERROR PATH");
		return (-1);
	}
	while (++j < e->s[i].size_bridg)
	{
		y = -1;
		while (++y < e->leng_salle)
		{
			if (e->s[i].bridg[j] == e->s[y].nb_salle && e->s[y].poid != 255)
				return (0);
		}
	}
	ft_putstr("ERROR PATH");
	return(-1);
}

int main()
{
	t_env e;
	int i;

	i = 0;
	if (ft_pars(&e) == -1)
		return (-1);
	if(ft_check_patch(&e) == -1)
		return (-1);
	ft_resolv(&e);
	return (0);
}