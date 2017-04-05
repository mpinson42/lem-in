#include "lem-in.h"

void ft_resolv(t_env *e)
{
	t_resolv r;

	r.test = 0;
	r.fin = 0;
	r.nb_fourmi = 1;
	while (e->s[r.fin].end != 1)
		r.fin++;
	while (e->s[r.fin].is_full != e->nb_fourmi)       //tant que la parti est pas fini
	{
		printf("\n");
		r.poid = 0;
		ft_memset(r.fourmi, -1 ,255);
		r.fourmiz = 0;
		while (++r.poid <= e->poid_max)                 //tant que tout les poid sont pas check
		{
			r.i = -1;
			while (++r.i < e->leng_salle) //check poid
			{
				if (e->s[r.i].poid == r.poid && e->s[r.i].is_full) // si un poid corespond
				{
					while (e->s[r.i].start == 1 && e->s[r.i].is_full && r.save_one != -2)
					{
						r.y = -1;
						r.save_one = -1;
						while (++r.y < e->s[r.i].size_bridg)   //check les tunelle
						{
							r.z = -1;
							r.save = 255;
							while (++r.z < e->leng_salle) //cherche la sorti des tunelle
							{
								if (e->s[r.i].bridg[r.y] == e->s[r.z].nb_salle && e->s[r.z].poid < e->s[r.i].poid && e->s[r.z].poid < r.save && (e->s[r.z].is_full == 0 || e->s[r.z].end == 1))
								{
									r.save_one = e->s[r.z].nb_salle;
									r.save = e->s[r.z].poid;
								}
							}
						}
						if (r.save_one != -1)
						{
							r.z = -1;
							while (++r.z < e->leng_salle)
							{
								if (e->s[r.z].nb_salle == r.save_one)
								{
									e->s[r.z].is_full++;
									e->s[r.i].is_full--;
									e->s[r.z].num_fourmi = r.nb_fourmi;
										printf("L%d-%d ", r.nb_fourmi, e->s[r.z].nb_salle);
									r.nb_fourmi++;
								}
							}
						}
						else
							r.save_one = -2;
					}
					r.y = -1;
					r.save_one = -1;
					r.save = 255;
					while (++r.y < e->s[r.i].size_bridg && e->s[r.i].start == 0 && r.save_one != -2)   //check les tunelle
					{
						r.z = -1;
						
						while (++r.z < e->leng_salle) //cherche la sorti des tunelle
						{
							if (e->s[r.i].bridg[r.y] == e->s[r.z].nb_salle && e->s[r.z].poid <= e->s[r.i].poid && e->s[r.z].poid < r.save && (e->s[r.z].is_full == 0 || e->s[r.z].end == 1))
							{
								r.save_one = e->s[r.z].nb_salle;
								r.save = e->s[r.z].poid;
							}
						}
					}

					if (r.save_one != -1)
					{
						r.z = -1;
						while (++r.z < e->leng_salle)
						{
							if (e->s[r.z].nb_salle == r.save_one)
							{
								e->s[r.z].is_full++;
								e->s[r.i].is_full--;
								e->s[r.z].num_fourmi = e->s[r.i].num_fourmi;
								e->s[r.i].num_fourmi = 0;
								printf("L%d-%d ", e->s[r.z].num_fourmi, e->s[r.z].nb_salle);
							}
						}
					}
					else
						r.save_one = -2;
				}
			}	
		}
	}	
}
