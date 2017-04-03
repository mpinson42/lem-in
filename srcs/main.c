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

int ft_get_bridg(t_env *e, char *str)
{
	char **tab;
	t_bridg *tmp;
	int i;

	i = 0;
	tmp = e->b;
	tab = ft_strsplit(str, '-');
	if(ft_strlen_tab(tab) != 2 || tab[1][0] == '\n')
		return(-1);
	e->b = (t_bridg *)malloc(sizeof(t_bridg) * (e->leng_bridg + 1));
	while(i < e->leng_bridg)
	{
		e->b[i] = tmp[i];
		i++;
	}
	e->b[i].bridg_1 = ft_atoi(tab[0]);
	e->b[i].bridg_2 = ft_atoi(tab[1]);
	e->leng_bridg++;
	return(0);
}

int ft_get_salle(t_env *e, char *str, int *start, int *end)
{
	char **tab;
	t_salle *tmp;
	int i;

	i = 0;
	tmp = e->s;
	tab = ft_strsplit(str, ' ');

	if(ft_strlen_tab(tab) != 3 || tab[2][0] == '\n')
		return(-1);

	e->s = (t_salle *)malloc(sizeof(t_salle) * (e->leng_salle + 1));
	while(i < e->leng_salle)
	{
		e->s[i] = tmp[i];
		i++;
	}
	e->s[i].nb_salle = ft_atoi(tab[0]);
	e->s[i].x = ft_atoi(tab[1]);
	e->s[i].y = ft_atoi(tab[2]);
	e->s[i].size_bridg = 0;
	e->leng_salle++;
	if(start[0] == 1)
		e->s[i].start = 1;
	else
		e->s[i].start = 0;
	if(end[0] == 1)
		e->s[i].end = 1;
	else
		e->s[i].end = 0;
	return(0);
}

void ft_bridg(t_env *e, int bridg, int i)
{
	int *tmp;
	int y;

	y = 0;
	while(y < e->s[i].size_bridg)
	{
		if(e->s[i].bridg[y] == bridg)
			return;
		y++;
	}
	tmp = e->s[i].bridg;
	e->s[i].bridg = (int *)malloc(sizeof(int) * (e->s[i].size_bridg + 1));
	//ft_bzero(e->s[i].bridg, e->s[i].size_bridg + 42);
	y = 0;
	while(y < e->s[i].size_bridg)
	{
		e->s[i].bridg[y] = tmp[y];
		y++; 
	}
	e->s[i].bridg[y] = bridg;
	e->s[i].size_bridg++;
	//printf("%d\n", e->s[i].size_bridg);
}

int ft_pars(t_env *e)
{
	int status;
	char *str;
	int  end;
	int start;
	int i;
	int count;
	char **tab;
	int stop;
	int count_sapce;

	end = 0;
	start = 0;
	status = -1;
	e->leng_bridg = 0;
	e->leng_salle = 0;
	stop = 0;
	while(get_next_line(0, &str))
	{
		count_sapce = 0;
		i = 0;
		count = 0;
		if(str[0] == 0)
			break;
		if(str[0] == '#' && ft_strcmp(str, "##end") != 0 && ft_strcmp(str, "##start") != 0)
			continue;
		if(status == -1)
		{
			while(str[i])
			{
				if((ft_isdigit(str[i]) == 0 && str[i] != '\n') || str[0] == '\n')
					stop = 1;
				i++;
			}
			if(stop == 1)
				break;
			e->nb_fourmi = ft_atoi(str);
			status = 0;
			ft_putstr(str);
			ft_putstr("\n");
			continue;
		}
		if(ft_strcmp(str, "##start") == 0 && start == 0)
		{
			start++;
			ft_putstr(str);
			ft_putstr("\n");
			continue;
		}
		if(ft_strcmp(str, "##start") == 0)
			break;
		if(ft_strcmp(str, "##end") == 0 && end == 0)
		{
			end++;
			ft_putstr(str);
			ft_putstr("\n");
			continue;
		}
		if(ft_strcmp(str, "##end\n") == 0)
			break;

		i = 0;
		while(str[i])
		{
			if((ft_isdigit(str[i]) == 0 && str[i] != '-' && str[i] != ' ' && str[i] != '\n') || count >= 2)
				stop = 1;
			if(str[i] == ' ')
				count_sapce++;
			if(str[i] == '-' && str[i] + 1 == '\n')
				stop = 1;
			if(str[i] == '-')
			{
				status = 1;
				count++;
			}
			i++;
		}
		if(stop == 1)
			break;
		if(status == 0)
		{
			if(count_sapce != 2)
				break;
			if(ft_get_salle(e, str, &start, &end) == -1)
				break;
			ft_putstr(str);
			ft_putstr("\n");
		}
		if(status == 1)
		{
			i = 0;
			while(str[i])
			{
				if(str[i] == ' ')
					stop = 1;
				i++;
			}
			if(stop == 1)
				break;
			if(ft_get_bridg(e, str) == -1)
				break;
			if(count != 1)
				break;
			ft_putstr(str);
			ft_putstr("\n");
		}


		if(start == 1)
			start++;
		if(end == 1)
			end++;

	}
	if(start != 2 || end != 2 || e->leng_salle < 2 || e->leng_bridg < e->leng_salle -1 || e->nb_fourmi <= 0)
	{
		ft_putstr("ERROR");
		//return(-1);
	}
	


	e->s[e->leng_salle].size_bridg = 0;


	i = 0;
	stop = 0;
	while(i < e->leng_salle)
	{
		stop = 0;
		while(stop < e->leng_bridg)
		{

			if(e->s[i].nb_salle == e->b[stop].bridg_1)
				ft_bridg(e, e->b[stop].bridg_2, i);
			if(e->s[i].nb_salle == e->b[stop].bridg_2)
				ft_bridg(e, e->b[stop].bridg_1, i);


			stop++;
		}
		i++;
	}

	printf("%d\n", e->s[0].bridg[0]);



	ft_putstr("\n\n\n\n\n");
		i = 0;
		printf("nbfourmi : %d\nsalle :\n", e->nb_fourmi);
		while(i < e->leng_salle)
		{
			printf("-> %d %d %d      %d    %d", e->s[i].nb_salle, e->s[i].x, e->s[i].y , e->s[i].start, e->s[i].end);
			stop = 0;
		
      		while(stop < e->s[i].size_bridg)
      		{
      		//	printf("      %d\n", e->s[i].size_bridg);
				printf("         %d ", e->s[i].bridg[stop]);
				stop++;
			}
			printf("\n");
			i++;
		}
		i = 0;
		while(i < e->leng_bridg)
		{
			printf("->%d-%d\n", e->b[i].bridg_1, e->b[i].bridg_2);
			i++;
		}
	return(0);
}

int main()
{
	t_env e;
	int i;

	i = 0;
	return(ft_pars(&e) == -1);
		return(-1);















	return(0);
}