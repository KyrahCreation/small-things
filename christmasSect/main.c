/*
** main.c for Christmas Sect (2nd edition) in /home/tom/Documents/Workspace/small-things
** 
** Made by Tom Partouche
** Login   <tom@kyrah.fr>
** 
** Started on  Wed Sep 13 17:21:09 2017 Tom Partouche
** Last update Wed Sep 13 18:44:32 2017 Tom Partouche
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char	*my_swap(char *list[], int a, int b)
{
  char *temp;
  temp = list[a];
  list[a] = list[b];
  list[b] = temp;
  return (*list);
}

void	main()
{
  char	*list1[] = {"Baptiste", "Celine", "Gaetan", "Pierre", "Tom", "Vincent"};
  char  *list2[] = {"Baptiste", "Celine", "Gaetan", "Pierre", "Tom", "Vincent"};

  FILE* resultat = NULL;

  resultat = fopen("resultat.txt", "w");
  
  int	i, g, r, j;
  int	n = 6;
  int	randnbr = 0;
  srand(time(NULL));

  printf("\n\n");
  for	(i = 0; i < 6; i++)
    {
      g = rand()%(6-i)+i;
      fprintf(resultat, "%s sera le Père Noël de ", list1[g]);
      *list1 = my_swap(list1, i, g);
      *list2 = my_swap(list2, i, g);

      if (i < 5)
	r = rand()%(6-(i+1))+(i+1);
      else
	r = rand()%(6-i)+i;
      fprintf(resultat, "%s.\n", list2[r]);
      *list2 = my_swap(list2, i, r);
   }
  printf("\n\n");

  fclose(resultat);
}
