/*
** others.c for others in /home/azword/delivery/PSU_2016_my_ls/
**
** Made by Nathan Tréhout
** Login   <nathan.trehout@epitech.eu>
**
** Started on  Sun Dec  4 23:00:35 2016 Nathan Tréhout
** Last update Sun Dec  4 23:22:18 2016 Nathan Tréhout
*/

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#include <stdlib.h>
#include <grp.h>
#include "include/my.h"

int	show_perms_bis(char *path)
{
  struct stat stats;

  if (stat(path, &stats) == -1)
    return (84);
  my_printf((stats.st_mode & S_IRUSR) ? "r" : "-");
  my_printf((stats.st_mode & S_IWUSR) ? "w" : "-");
  my_printf((stats.st_mode & S_IXUSR) ? "x" : "-");
  my_printf((stats.st_mode & S_IRGRP) ? "r" : "-");
  return (0);
}
