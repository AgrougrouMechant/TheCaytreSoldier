NAME	= TheCaytreSoldier

SRC		= main.c \
		  aff_func.c

OBJ		= $(SRC:.c=.o)

LIB		= -lmingw32 -lSDLmain -lSDL -lSDL_image -lSDL_ttf

RM		= del

CC		= gcc

$(NAME) : $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

all		: $(NAME)

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME).exe