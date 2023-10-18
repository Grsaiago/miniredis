NAME = myredis

CC = g++

CFLAGS = -Wall -Wextra -g

SRCS = $(wildcard ./src/*.cpp)

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -f ./myredis

re: clean all
