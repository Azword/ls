/*
** my.h for my_ls in /home/azword/delivery/PSU_2016_my_ls/include
** 
** Made by Nathan Tréhout | Az'
** Login   <nathan.trehout@epitech.eu>
** 
** Started on  Sun Dec  4 23:39:26 2016 Nathan Trehout
** Last update Sun Dec  4 23:39:29 2016 Nathan Trehout
*/

#include <dirent.h>
#include <sys/stat.h>

int	open_directory(char *av, char *args, int n, int ac);

int	verif_if_file(char *path, char  *args, int ac, int n);

int	print_total(char *path);

int	ls_heart(struct dirent *entry, char *path, int n);

int	print_basic(char *v, int n);

char	*getArgs(int ac, char **av, char *args);

char    *my_realloc(char *str, int nb);

char	*my_strdup(char *str, int k);

char	*last_edit(struct stat stats, time_t str);

int	displayPerms(char *path);

int	isPresent(char *tab, char c);

int	isArgs(char c);

int	my_strlen(char *str);

char	*my_strcat(char *dest, char *src);

int	my_printf(char *str, ...);

int	my_putstr(char *str);

void	my_putchar(char c);

void	init(int ac, char **av, char *args , char **dir_to_print);

void	pre_call_R(char **av, char *args, char **dir_to_print);

void	pre_call_l(char **av, char *args, int ac);

int	my_ls_R(char *path, char *args, int i, char **dir_to_print);

int	print_first_path(struct dirent *entry, DIR *dir, char *path,
      		     char **dir_to_print, char *args);

int	assign_if_dir(char *name, char *path, char **dir_to_print);

char	**reinitialize(char **dir_to_print);

char	*my_path_fusion(char *path, char *name);

int	show_perms_bis(char *path);

