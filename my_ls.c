/*
** my_ls.c for my_ls in /home/azword/delivery/PSU_2016_my_ls/
**
** Made by Nathan Tréhout
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Mon Nov 21 15:12:23 2016 Nathan Tréhout
** Last update Thu Nov 24 06:55:12 2016 Nathan Tréhout
*/

#include <dirent.h>
#include <unistd.h>
#include <include/my.h>

#define KBLU  "\x1B[34m"
#define KNRM  "\x1B[0m"

char	**file_to_tab(char *toIntroduce, char **files)
{

}

void	apply_modifiers(char *av, char **files, char *args, int n)
{
  int	i;
  DIR	*dir;
  struct dirent	*entry;

  i = 0;
  if ((dir = opendir(av)) == NULL)
    {
      my_printf("[ERROR] opendir");
      return (84);
    }
  while ((entry = readdir(dir)) != NULL)
    {
    }
  closedir(dir);
  return (0);
}

int	main(int ac, char **av)
{
  int	i;
  char	*args;

  i = 1;
  if (ac == 1)
    {
      print_basic(".");
      return (84);
    }
  else
    {
      args = malloc(sizeof(char) * 6);
      getArgs(ac, av, args);
      i = (args[0] != '\0') ? 2 : 1;
      if (i == 2)
	my_printf("Les arguments sont %s\n", args);
    }
  i = 1;
  while (av[i] != '\0')
    {
      print_basic(av[i]);
      i++;
    }
  //init(av, ac, args, i);
  return (0);
}
