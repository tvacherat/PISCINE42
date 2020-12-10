NAME		=	#NOM DU PROGRAMME
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
IFLAGS 		=	-I $(INC_PATH)
RM			=	rm -rf
INC_PATH 	=	#DOSSIER DES EN TETE
INC_NAME	=	#NOMS DES FICHIER D'EN TETE
SRC_PATH 	= 	#DOSSIER DES SOURCES
SRC_NAME 	=	#NOMS DES FICHIERS SOURCES
INC 		=	$(addprefix $(INC_PATH)/, $(INC_NAME))
SRC 		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
.SUFFIXES: 		.c .o .h
OBJ 		=	 $(SRC:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(INC)
				${CC} ${CFLAGS} -o ${NAME} ${OBJ}

%.o: %.c
				$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJ)

fclean		:	clean
				$(RM) $(NAME)

re			: 	fclean all

.PHONY: 		all fclean clean re
