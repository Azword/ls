##
## Makefile for makefile in /home/azword/delivery/PSU_2016_my_ls/
##
## Made by Nathan Tréhout
## Login   <nathan.trehout@epitech.eu>
##
## Started on  Mon Nov 21 15:02:24 2016 Nathan Tréhout
## Last update Mon Nov 21 15:06:24 2016 Nathan Tréhout
##

PROJECT	=	*.c

NAME	=	my_ls

all:	$(NAME)

$(NAME):	$(PROJECT)
	gcc -g $(PROJECT) -o $(NAME) -L lib/ -lmy

clean:
	rm -f $(NAME)

fclean:	clean

re:	fclean	all
