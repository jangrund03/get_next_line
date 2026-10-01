

debug: get_next_line.c get_next_line_utils.c
	$(CC) -O0 -g3 -Wall -Wextra get_next_line.c get_next_line_utils.c main.c -o main
