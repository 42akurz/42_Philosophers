CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = philo
SOURCES = ./src/main.c ./src/parse.c ./src/allocate.c ./src/helper.c \
			./src/reaper.c ./src/actions.c ./src/join_destroy.c ./src/init.c \
			./src/threads.c ./src/free.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

val:
	docker run -ti -v $(PWD):/test memory-test:0.1 bash -c "cd /test/; gcc -pthread $(SOURCES) -o main && valgrind --leak-check=full ./main 2 500 200 200 5; rm -f ./main"