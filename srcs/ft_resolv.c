#include "lem-in.h"

void ft_print(t_env *e)
{
	int i;

	i = 0;
	while(i < e->leng_salle)
	{
		if(e->s[i].is_full && e->s[i].end != 1 && e->s[i].start != 1)
			printf("L%d-%d ", e->s[i].num_fourmi, e->s[i].nb_salle);

		i++;
	}
	
}

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
	int test = 0;
	int nb_fourmi;
	int fourmi[255];
	int fourmiz;

	fin = 0;
	nb_fourmi = 1;
	while(e->s[fin].end != 1)
		fin++;
	while(e->s[fin].is_full != e->nb_fourmi)       //tant que la parti est pas fini
	{
		//printf("-------TOUR--------------\n");
		printf("\n");
		poid = 1;
		ft_memset(fourmi, -1 ,255);
		fourmiz = 0;
		while(poid <= e->poid_max)                 //tant que tout les poid sont pas check
		{
			i = 0;
			while(i < e->leng_salle) //check poid
			{
				if(e->s[i].poid == poid && e->s[i].is_full) // si un poid corespond
				{
					while(e->s[i].start == 1 && e->s[i].is_full && save_one != -2)
					{
						y = 0;
						save_one = -1;
						while(y < e->s[i].size_bridg)   //check les tunelle
						{
							z = 0;
							save = 255;
							while(z < e->leng_salle) //cherche la sorti des tunelle
							{
								if(e->s[i].bridg[y] == e->s[z].nb_salle && e->s[z].poid < e->s[i].poid && e->s[z].poid < save && (e->s[z].is_full == 0 || e->s[z].end == 1))
								{
									save_one = e->s[z].nb_salle;
									save = e->s[z].poid;

								}
								z++;
							}

							y++;
						}
						if(save_one != -1)
						{
							z = 0;
							while(z < e->leng_salle)
							{
									
								if(e->s[z].nb_salle == save_one)
								{

							//		printf("----->");
									e->s[z].is_full++;
									e->s[i].is_full--;
									e->s[z].num_fourmi = nb_fourmi;
								//	if(e->s[z].end == 1)
										printf("L%d-%d ", nb_fourmi, e->s[z].nb_salle);
									nb_fourmi++;
								}
								z++;
							}
						}
						else
							save_one = -2;
				/*		sleep(1);
						test = 0;
						while(test < e->leng_salle)
						{
							printf("-> %d %d %d		%d %d	->%d _>%d\n", e->s[test].nb_salle, e->s[test].x, e->s[test].y , e->s[test].start, e->s[test].end, e->s[test].poid, e->s[test].is_full);
							test++;
						}
						printf("\n\n\n\n");*/
					}
					y = 0;
					save_one = -1;
					while(y < e->s[i].size_bridg && e->s[i].start == 0 && save_one != -2)   //check les tunelle
					{
						z = 0;
						save = 255;
						while(z < e->leng_salle) //cherche la sorti des tunelle
						{
							if(e->s[i].bridg[y] == e->s[z].nb_salle && e->s[z].poid < e->s[i].poid && e->s[z].poid < save && (e->s[z].is_full == 0 || e->s[z].end == 1))
							{
								save_one = e->s[z].nb_salle;
								save = e->s[z].poid;

							}
							z++;
						}

						y++;
					}

					if(save_one != -1)
					{
						z = 0;
						while(z < e->leng_salle)
						{
							//	printf("%d\n", save_one);
							if(e->s[z].nb_salle == save_one)
							{
								e->s[z].is_full++;
								e->s[i].is_full--;
								e->s[z].num_fourmi = e->s[i].num_fourmi;
								e->s[i].num_fourmi = 0;
								//if(e->s[z].end == 1)
										printf("L%d-%d ", e->s[z].num_fourmi, e->s[z].nb_salle);
							//	printf("L%d-%d ", e->s[z].num_fourmi, e->s[z].nb_salle);
							}
							z++;
						}
					}
					else
					{

						save_one = -2;
					}
			/*		sleep(1);
					test = 0;
					while(test < e->leng_salle)
					{
						printf("-> %d %d %d		%d %d	->%d _>%d\n", e->s[test].nb_salle, e->s[test].x, e->s[test].y , e->s[test].start, e->s[test].end, e->s[test].poid, e->s[test].is_full);
						test++;
					}
					printf("\n\n\n\n");*/
				}
				




				































				i++;
			}
			//ft_print(e);	
			poid++;
		}






	}	
}
