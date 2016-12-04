/*
** pre_call.c for pre_call in /home/azword/delivery/PSU_2016_my_ls/
**
** Made by Nathan Tréhout
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Sat Dec  3 07:51:39 2016 Nathan Tréhout
** Last update Sat Dec  3 08:16:35 2016 Nathan Tréhout
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

void	pre_call_l(char **av, char *args, int ac)
{
  int	i;

  i = 1;
  while (av[i] != '\0')
    {
      if (ac != 2 && av[i] != av[1])
	my_putchar('\n');
      if (av[i + 1] == '\0')
	open_directory(av[i], args, 2, ac);
      else
	open_directory(av[i], args, 1, ac);
      i++;
    }
}

void	pre_call_R(char **av, char *args, char **dir_to_print)
{
  int	i;

  i = 1;
  while (av[i] != '\0')
    {
      my_ls_R(av[i], args, 0, dir_to_print);
      if (av[i + 1] != '\0')
	my_putchar('\n');
      dir_to_print = reinitialize(dir_to_print);
      i++;
    }
}

void	init(int ac, char **av, char *args , char **dir_to_print)
{
  int	i;

  i = 1;
  (ac == 1) ? print_basic(".", 0) : 0;
  if (ac == 2 && args[0] != '\0')
    {
      if (isPresent(args, 'R'))
	my_ls_R(".", args, 0, dir_to_print);
      else if (isPresent(args, 'l'))
	print_basic(".", 1);
    }
  else
    {
      if (isPresent(args, 'R') == 0)
	pre_call_l(av, args, ac);
      else if (isPresent(args, 'R') != 0)
	pre_call_R(av, args, dir_to_print);
    }
}
