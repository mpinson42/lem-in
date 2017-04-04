#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct s_salle
{
	int x;
	int y;
	int nb_salle;
	int is_full;
	int *bridg;
	int size_bridg;
	int poid;
	int start;
	int end;
}				t_salle;

typedef struct s_bridg
{
	int bridg_1;
	int bridg_2;

}				t_bridg;

typedef struct s_env
{
	t_salle *s;
	t_bridg *b;
	int leng_salle;
	int leng_bridg;
	int nb_fourmi;
}				t_env;

void edit_poid(t_env *e);

#endif