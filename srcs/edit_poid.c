#include "lem-in.h"


int ft_check(int z)
{
	int i;
	int bol;
	static int leng = 1;
	static int tab[255];

	bol = 0;
	i = 0;
	tab[0] = 0;
	while(i < leng)
	{
		if(tab[i] == z)
			return(0);
		i++;
	}
	tab[leng] = z;
	leng++;
	return(1);
}

void edit_poid(t_env *e)
{
	int i;
	int y;
	int z;
	int x;
	int a;
	int chr[255];
	int bol;

	bol = 0;
	i = 0;
	y = 0;
	z = 0;
	a = 0;
	while(e->s[i].end != 1)
		i++;
	e->s[i].poid = 0;

	printf("-------->%d\n", e->leng_salle);




	while(a < e->leng_salle)
	{
		if(bol == 0)
		{
			z = 0;
			while(z < e->leng_salle)
			{
				y = 0;
				while(y < e->s[z].size_bridg)
				{
					if(e->s[z].bridg[y] == e->s[i].nb_salle)
					{
						e->s[z].poid = 1;
					}
					y++;
				}
				z++;
			}
		}
		else
		{
			i = 0;
			while(i < e->leng_salle)
			{
				if(e->s[i].poid == a)
				{
					z = 0;
					while(z < e->leng_salle)
					{
						y = 0;
						while(y < e->s[z].size_bridg)
						{
							if(e->s[z].bridg[y] == e->s[i].nb_salle && a < e->s[z].poid && ft_check(z))
							{
								e->poid_max = a + 1;
								e->s[z].poid = a + 1;
							}
							y++;
						}
						z++;
					}
				}
				i++;
			}

		}





		bol = 1;
		a++;
	}
	i = 0;




}






/*
	while(z < e->leng_salle)
	{
		y = 0;
		while(y < e->s[z].size_bridg)
		{
			if(e->s[z].bridg[y] == e->s[i].nb_salle)              //edit salle adja de i
				e->s[z] = 1;
			y++;
		}
		z++;
	}*/