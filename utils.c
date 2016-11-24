/*
** utils.c for utils in /home/azword/delivery/PSU_2016_my_ls/
**
** Made by Nathan Tréhout
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Thu Nov 24 04:34:05 2016 Nathan Tréhout
** Last update Thu Nov 24 06:52:17 2016 Nathan Tréhout
*/

#include <unistd.h>

int	isArgs(char c)
{
  if (c == 'l' || c == 'R' || c == 'd' || c == 'r' || c == 't')
    return (0);
  else
    return (1);
}

int	isPresent(char *tab, char c)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (tab[i])
    {
      if (tab[i] == c)
	count++;
      i++;
    }
  return (count);
}

char    *my_realloc(char *str, int nb)
{
  char  *temp;
  int   i;

  i = 0;
  temp = malloc(my_strlen(str) + nb);
  if (temp == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      temp[i] = str[i];
      i++;
    }
  temp[i] = '\0';
  free(str);
  return (temp);
}

char	*getArgs(int ac, char **av, char *args)
{
  int	i;
  int	j;
  int	k;

  i = j = k = 0;
  while (j != ac)
    {
      if (av[j][i] != '-')
	j++;
      else
	{
	  while (av[j][i] != '\0')
	    {
	      if (isArgs(av[j][i]) == 0 && isPresent(args, av[j][i]) == 0)
		{
		  args[k] = av[j][i];
		  k++;
		}
	      i++;
	    }
	  i = 0;
	  j++;
	}
    }
  return (args);
}
