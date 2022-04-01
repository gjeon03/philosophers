NAME = philo

FILES = main utils init actions thread ft_atoi

CC = gcc
RM = rm -f

SRC_DIR = src
BUILD_DIR = build
INC_DIR = include

CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(INC_DIR)

SRCS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))

OBJS = $(addprefix ./, $(addsuffix .o, $(FILES)))

all: $(NAME)

./%.o:  $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@ $(IFLAGS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -g -o $(NAME) $(CFLAGS) $(IFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all