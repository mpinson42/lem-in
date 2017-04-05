#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"



#include <stdio.h>

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
	int num_fourmi;
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
	int poid_max;
}				t_env;

typedef struct s_resolv
{
	int fin;
	int i;
	int poid;
	int save;
	int save_one;
	int bridg;
	int y;
	int z;
	int test;
	int nb_fourmi;
	int fourmi[255];
	int fourmiz;
}				t_resolv;

typedef struct s_pars
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
}				t_pars;

typedef struct s_edit
{
	int i;
	int y;
	int z;
	int x;
	int a;
	int chr[255];
	int bol;
}				t_edit;

void edit_poid(t_env *e);
void ft_resolv(t_env *e);
int ft_strlen_tab(char **tab);
int ft_pars(t_env *e);

#endif