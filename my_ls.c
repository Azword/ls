/*
** my_ls.c for my_ls in /home/azword/delivery/PSU_2016_my_ls/
**
** Made by Nathan Tréhout
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Mon Nov 21 15:12:23 2016 Nathan Tréhout
** Last update Wed Nov 30 21:07:15 2016 Nathan Tréhout
*/

#include <dirent.h>
#include <unistd.h>
#include <include/my.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>

int	displayPerms(char *path)
{
  struct stat stats;
  struct passwd *passwd;
  char	*time;
  int i;
  passwd = getpwuid(stats.st_uid);
  if (stat(path, &stats) == -1)
    {
      my_putstr("stat error");
      return (84);
    }
  my_printf((S_ISDIR(stats.st_mode)) ? "d" : "-");
  my_printf((stats.st_mode & S_IRUSR) ? "r" : "-");
  my_printf((stats.st_mode & S_IWUSR) ? "w" : "-");
  my_printf((stats.st_mode & S_IXUSR) ? "x" : "-");
  my_printf((stats.st_mode & S_IRGRP) ? "r" : "-");
  my_printf((stats.st_mode & S_IWGRP) ? "w" : "-");
  my_printf((stats.st_mode & S_IXGRP) ? "x" : "-");
  my_printf((stats.st_mode & S_IROTH) ? "r" : "-");
  my_printf((stats.st_mode & S_IWOTH) ? "w" : "-");
  my_printf((stats.st_mode & S_IXOTH) ? "x" : "-");
  my_putchar(' ');
  my_printf("%d %s ", stats.st_nlink, passwd->pw_name, stats.st_size);
  free(passwd);
  return (0);
}

void	ls_heart(struct dirent *entry, char *path, int n)
{
  char *dest;

  dest = malloc(sizeof(char) * my_strlen(path) * 2);
  if (n == 1)
    {
      dest = my_strcat(dest, path);
      dest = my_strcat(dest, "/");
      dest = my_strcat(dest, entry->d_name);
      displayPerms(dest);
    }
  if (entry->d_name[0] != '.')
    my_printf("%s\n", entry->d_name);
}

void	open_directory(char *av, char *args, int n)
{
  int	i;
  DIR	*dir;
  struct dirent	*entry;

  i = 0;
  if ((dir = opendir(av)) == NULL)
    {
     // my_printf("[ERROR] opendir");
      return (84);
    }
  while ((entry = readdir(dir)) != NULL)
    {
      if (isPresent(args, 'l') == 1)
	i = 1;
      if (entry->d_name[0] != '.')
	ls_heart(entry, av, i);
    }
  closedir(dir);
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
      i = 1;
      while (av[i] != '\0')
	{
	  open_directory(av[i], args, 1);
	  i++;
	}
    }
  return (0);
}
