main: main.c
	$(CC) main.c -o main.out -Wall -Wextra -pedantic

count: count.c
	$(CC) count.c -o count -Wall -Wextra -pedantic
