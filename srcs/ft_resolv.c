#include "lem-in.h"

void ft_resolv(t_env *e)
{
	int fin;
	int i;
	int poid;
	int save;
	int save_one;
	int bridg;
	int y;
	int z;

	fin = 0;
	while(e->s[fin].end != 1)
		fin++;
	while(e->s[fin].is_full != e->nb_fourmi)       //tant que la parti est pas fini
	{
		poid = 1;
		while(poid <= e->poid_max)                 //tant que tout les poid sont pas check
		{
			i = 0;
			while(i < e->leng_salle) //check poid
			{
				if(e->s[i].poid == poid && e->s[i].is_full ) // si un poid corespond
				{
					y = 0;
					
					while(y < e->s[i].size_bridg)   //check les tunelle
					{




						z = 0;
						save_one = -1;
						save = 255;
						while(z < e->leng_salle) //cherche la sorti des tunelle
						{
							if(e->s[i].bridg[y] == e->s[z].nb_salle && e->s[z].poid < e->s[i].poid && (e->s[z].is_full != 1 || e->s[z].end == 1) && e->s[z].poid < save)
							{
								ft_putstr("oui");
								save_one = e->s[z].nb_salle;
								save = e->s[z].poid;
							}
							z++;
						}

						y++;
					}




					if(save_one != -1)
					{
							printf("----->%d\n", save_one);
					}








				}
				i++;
			}		
			poid++;
		}




		

	}	
}