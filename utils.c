/*
** utils.c for utils in /home/azword/delivery/PSU_2016_my_ls/
**
** Made by Nathan Tréhout
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Thu Nov 24 04:34:05 2016 Nathan Tréhout
** Last update Fri Dec  2 17:14:29 2016 Nathan Tréhout
*/

#include <dirent.h>
#include <unistd.h>
#include <include/my.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#include <stdlib.h>
#include <grp.h>

char	*last_edit(struct stat stats, time_t str)
{
  char  *time;
  char  *dest;
  int   i;
  int   j;

  j = 0;
  i = 3;
  time = ctime(&stats.st_mtime);
  dest = malloc(sizeof(char) * my_strlen(time));
  if (dest == NULL)
    return (NULL);
  while (time[i - 1] != ':')
    dest[j++] = time[i++];
  while (time[i] != ':')
    dest[j++] = time[i++];
  dest[j] = '\0';
  return (dest);
}

char	*my_strdup(char *str, int k)
{
  int	i;

  i = 0;
  while (i != k)
    {
      str[i] = '0';
      i++;
    }
  str[i] = '\0';
  return (str);
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

int	print_basic(char *v, int n)
{
  int	i;
  DIR	*dir;
  char	**files;
  struct dirent *entry;

  files = malloc(sizeof(char) * 100);
  if (files == NULL)
    return (84);
  i = 0;
  if ((dir = opendir(v)) == NULL)
    {
      return (84);
    }
  while ((entry = readdir(dir)) != NULL)
    {
      if (entry->d_name[0] != '.')
	{
	  if (n == 1)
	    {
	      displayPerms(entry->d_name);
	    }
	  my_printf("%s\n", entry->d_name);
	}
    }
  return (0);
}
