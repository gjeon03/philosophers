NAME = philo

FILES = main utils init actions ft_print

CC = gcc
RM = rm -f

SRC_DIR = src
BUILD_DIR = build
INC_DIR = include

CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(INC_DIR)

SRCS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))

OBJS = $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(FILES)))

all: $(NAME)

# .c.o: $(SRCS)
# 	$(CC) $(CFLAGS) -c -o $@ $<
$(BUILD_DIR)/%.o:  $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@ $(IFLAGS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -g -o $(NAME) $(CFLAGS) $(IFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all