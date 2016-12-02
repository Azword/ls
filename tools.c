/*
** tools.c for tools in /home/azword/delivery/PSU_2016_my_ls/
**
** Made by Nathan Tréhout
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Fri Dec  2 16:58:19 2016 Nathan Tréhout
** Last update Fri Dec  2 17:11:03 2016 Nathan Tréhout
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

int	isArgs(char c)
{
  if (c == 'l' || c == 'R' || c == 'd' || c == 'r' || c == 't' || c == 'a')
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
  while (tab[i] != '\0')
    {
      if (tab[i] == c)
	count++;
      i++;
    }
  return (count);
}

int	displayPerms(char *path)
{
  struct stat stats;
  struct passwd *passwd;
  struct group *grp;
  char	*time;

  if (stat(path, &stats) == -1)
      return (84);
  time = last_edit(stats, stats.st_mtime);
  passwd = getpwuid(stats.st_uid);
  grp = getgrgid(stats.st_gid);
  if (stats.st_mode & S_IFCHR)
    my_putchar('c');
  else
    my_printf((S_ISDIR(stats.st_mode)) ? "d" : "-");
  my_printf((stats.st_mode & S_IRUSR) ? "r" : "-");
  my_printf((stats.st_mode & S_IWUSR) ? "w" : "-");
  my_printf((stats.st_mode & S_IXUSR) ? "x" : "-");
  my_printf((stats.st_mode & S_IRGRP) ? "r" : "-");
  my_printf((stats.st_mode & S_IWGRP) ? "w" : "-");
  my_printf((stats.st_mode & S_IXGRP) ? "x" : "-");
  my_printf((stats.st_mode & S_IROTH) ? "r" : "-");
  my_printf((stats.st_mode & S_IWOTH) ? "w" : "-");
  if (stats.st_mode & S_ISVTX)
    my_putchar('t');
  else
    my_printf((stats.st_mode & S_IXOTH) ? "x" : "-");
  my_printf(" %d %s %s ", stats.st_nlink, passwd->pw_name, grp->gr_name);
  my_printf("%d%s ", stats.st_size, time);
}
