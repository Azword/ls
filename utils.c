/*
** utils.c for utils in /home/azword/delivery/PSU_2016_my_ls/
**
** Made by Nathan Tréhout
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Thu Nov 24 04:34:05 2016 Nathan Tréhout
** Last update Thu Nov 24 06:55:48 2016 Nathan Tréhout
*/

#include <unistd.h>
#include <dirent.h>
#include <include/my.h>

#define KBLU  "\x1B[34m"
#define KNRM  "\x1B[0m"

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

void	print_basic(char *v)
{
  DIR	*dir;
  struct dirent *entry;

  if ((dir = opendir(v)) == NULL)
    {
      my_printf("[ERROR]");
      return (84);
    }
  while ((entry = readdir(dir)) != NULL)
    {
      if (entry->d_name[0] != '.')
	{
	  if (entry->d_type == 4)
	    my_printf("%s%s\n", KBLU, entry->d_name);
	  else
	    my_printf("%s%s\n", KNRM, entry->d_name);
	}
    }
}
