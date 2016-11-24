/*
** my_ls.c for my_ls in /home/azword/delivery/PSU_2016_my_ls/
**
** Made by Nathan Tréhout
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Mon Nov 21 15:12:23 2016 Nathan Tréhout
** Last update Thu Nov 24 06:27:08 2016 Nathan Tréhout
*/

#include <dirent.h>
#include <unistd.h>
#include <include/my.h>

#define KBLU  "\x1B[34m"
#define KNRM  "\x1B[0m"

char	**file_to_tab(char *toIntroduce, char **files, int k, int pos)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (files[j + 1] != '\0')
    j++;

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
      i++;
      if (n != 0)
	{

	}
      else
	file_to_tab(entry->d_name, files, 1, i);
    }
  closedir(dir);
  return (0);
}

void	init(char **av, int ac, char *args, int i)
{
  char	**files;

  if (i == ac)
    return (84);
  my_printf("%s:\n", av[i]);
  if (isPresent(args, 'l'))
    apply_modifiers(av[i], files, args, 1);
  else
    apply_modifiers(av[i], files, args, 0);
  return (init(av, ac, args, i + 1));
}

int	main(int ac, char **av)
{
  int	i;
  char	*args;

  i = 1;
  if (ac == 1)
    {
      apply_modifiers(".", NULL, NULL, NULL);
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
  init(av, ac, args, i);
  return (0);
}
