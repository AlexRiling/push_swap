NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = src
INCDIR = include

SRC = $(SRCDIR)/main.c $(SRCDIR)/parsing.c $(SRCDIR)/operations.c $(SRCDIR)/sorting.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJ)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
