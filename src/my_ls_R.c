/*
** my_ls_args.c for ls_args in /home/azword/delivery/PSU_2016_my_ls/
**
** Made by Nathan Tréhout
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Sat Dec  3 05:40:28 2016 Nathan Tréhout
** Last update Sat Dec  3 08:16:41 2016 Nathan Tréhout
*/

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include "include/my.h"

int	assign_if_dir(char *name, char *path, char **dir_to_print)
{
  struct stat stats;
  char *real_path;
  int	i;

  i = 0;
  real_path = my_path_fusion(path, name);
  if (stat(real_path, &stats) == -1)
    return (84);
  if (S_ISDIR(stats.st_mode))
    {
      while (dir_to_print[i] != '\0')
	i++;
      dir_to_print[i] = real_path;
    }
  return (0);
}

int	print_first_path(struct dirent *entry, DIR *dir, char *path,
			 char **dir_to_print, char *args)
{
  if ((dir = opendir(path)) == NULL)
    return (84);
  while ((entry = readdir(dir)) != NULL)
    {
      if (isPresent(args, 'l') && entry->d_name[0] != '.')
	displayPerms(my_path_fusion(path, entry->d_name));
      if (entry->d_name[0] != '.')
	{
	  if (isPresent(args, 'l'))
	    my_printf("%s\n", entry->d_name);
	  else
	    my_printf("%s  ", entry->d_name);
	  assign_if_dir(entry->d_name, path, dir_to_print);
	}
    }
  if (isPresent(args, 'l') == 0 || args[0] == '\0')
    my_putchar('\n');
  closedir(dir);
  return (0);
}

int	my_ls_R(char *path, char *args, int i, char **dir_to_print)
{
  DIR	*dir;
  struct dirent	*entry;

  if (path[0] != '-')
    my_printf("%s:\n", path);
  if (isPresent(args, 'l'))
    print_total(path);
  print_first_path(entry, dir, path, dir_to_print, args);
  if (dir_to_print[i] != '\0')
    {
      my_putchar('\n');
      return (my_ls_R(dir_to_print[i], args, i + 1, dir_to_print));
    }
  return (0);
}
