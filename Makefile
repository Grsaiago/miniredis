NAME = miniredis

CC = g++

CFLAGS = -Wall -Wextra -g

INCLUDE_PATH = ./include

INCLUDE = -I $(INCLUDE_PATH)

DEPS =	$(wildcard/$(INCLUDE_PATH)/*.hpp) \
		$(SRCS) \

SRCS =	$(wildcard ./src/*.cpp) \
		$(wildcard ./classes/*.cpp) \

all: $(NAME)

$(NAME): $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRCS) -o $(NAME)

clean:
	@rm -f $(NAME)

re: clean all
