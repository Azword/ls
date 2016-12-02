#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>

int open_directory(char *av, char *args, int n, int ac);
int verif_if_file(char *path, char  *args, int ac, int n);
int print_total(char *path);
int ls_heart(struct dirent *entry, char *path, int n);
int print_basic(char *v, int n);
char *getArgs(int ac, char **av, char *args);
char    *my_realloc(char *str, int nb);
char *my_strdup(char *str, int k);
char *last_edit(struct stat stats, time_t str);
int displayPerms(char *path);
int isPresent(char *tab, char c);
int isArgs(char c);
int my_strlen(char *str);
char *my_strcat(char *dest, char *src);
int my_printf(char *str, ...);
int my_putstr(char *str);
void my_putchar(char c);  
  
  

