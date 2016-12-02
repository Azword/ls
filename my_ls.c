/*
** my_ls.c for my_ls in /home/azword/delivery/PSU_2016_my_ls/
**
** Made by Nathan Tréhout
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Mon Nov 21 15:12:23 2016 Nathan Tréhout
** Last update Fri Dec  2 16:16:26 2016 Nathan Tréhout
*/

#include <dirent.h>
#include <unistd.h>
#include <include/my.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>

int	displayPerms(char *path)
{
  struct stat stats;
  struct passwd *passwd;
  struct group *grp;
  char	*time;
  if (stat(path, &stats) == -1)
    {
      my_putstr("stat error");
      return (84);
    }
  time = last_edit(stats, stats.st_mtime);
  passwd = getpwuid(stats.st_uid);
  grp = getgrgid(stats.st_gid);
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
  my_printf("%d %s %s ", stats.st_nlink, passwd->pw_name, grp->gr_name);
  my_printf("%d%s ", stats.st_size, time);
}

void	ls_heart(struct dirent *entry, char *path, int n)
{
  char *dest;

  dest = malloc(sizeof(char) * my_strlen(path) + my_strlen(entry->d_name) * 4);
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
}

void	print_total(char *path)
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

void	open_directory(char *av, char *args, int n, int ac)
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
    {
      return (84);
    }
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
}

int	main(int ac, char **av)
{
  int	i;
  char	*args;

  if (ac == 1 || (ac == 2 && av[1][1] == 'l'))
    {
      (ac == 1) ? print_basic(".", 0) : 0;
      (ac != 1) ? print_basic(".", 1) : 0;
    }
  else
    {
      args = malloc(sizeof(char) * 6);
      getArgs(ac, av, args);
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
  return (0);
}
