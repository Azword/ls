/*
** my_ls.c for my_ls in /home/azword/delivery/PSU_2016_my_ls/
**
** Made by Nathan Tréhout
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Mon Nov 21 15:12:23 2016 Nathan Tréhout
** Last update Sat Dec  3 08:07:25 2016 Nathan Tréhout
*/

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <include/my.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>

int	ls_heart(struct dirent *entry, char *path, int n)
{
  char *dest;

  dest = malloc(sizeof(char) * my_strlen(path) + my_strlen(entry->d_name) * 4);
  if (dest == NULL)
    return (84);
  dest[0] = '\0';
  if (n == 1)
    {
      dest = my_strcat(dest, path);
      if (path[my_strlen(path) -1] != '/')
	dest = my_strcat(dest, "/");
      dest = my_strcat(dest, entry->d_name);
      displayPerms(dest);
    }
  if (entry->d_name[0] != '.')
    {
      my_printf("%s\n", entry->d_name);
    }
  free(dest);
  return (0);
}

int	print_total(char *path)
{
  int	i;
  DIR	*dir;
  struct dirent *entry;

  if ((dir = opendir(path)) == NULL)
    {
      return (84);
    }
  while ((entry = readdir(dir)) != NULL)
    {
      i++;
    }
  my_printf("total %d\n", i + 1);
  return (0);
}

int	verif_if_file(char *path, char  *args, int ac, int n)
{
  struct stat stats;

  if (stat(path, &stats) == -1)
    {
      my_putstr("stat error");
      return (84);
    }
  if (S_ISDIR(stats.st_mode) == 0)
    {
      if (isPresent(args, 'l'))
	displayPerms(path);
      if (ac != 2)
	my_printf("%s", path);
    }
  else
    {
      if (ac != 2)
	{
	  my_printf("%s:", path);
	  my_putchar('\n');
	}
    }
}

int	open_directory(char *av, char *args, int n, int ac)
{
  int	i;
  int	count;
  DIR	*dir;
  struct dirent	*entry;

  i = count = 0;
  if (av[1] == 'l' && av[2] == '\0')
    return (1);
  verif_if_file(av, args, ac, n);
  if ((dir = opendir(av)) == NULL)
      return (84);
  if (isPresent(args, 'l') == 1)
    print_total(av);
  while ((entry = readdir(dir)) != NULL)
    {
      if (isPresent(args, 'l') == 1)
	  i = 1;
      if (entry->d_name[0] != '.')
	ls_heart(entry, av, i);
    }
  closedir(dir);
  return (0);
}

int	main(int ac, char **av)
{
  int	i;
  char	*args;
  char	**dir_to_print;

  args = malloc(sizeof(char) * 6);
  if (args == NULL)
    return (84);
  getArgs(ac, av, args);
  if (isPresent(args, 'R'))
    {
      dir_to_print = malloc(sizeof(char) * 6000);
      if (dir_to_print == NULL)
	return (84);
    }
  init(ac, av, args, dir_to_print);
  return (0);
}
