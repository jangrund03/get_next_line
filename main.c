#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int file = open("txt", O_RDONLY);
	char* stash = malloc(1);
	char* result = read_to_stash(file, stash);
	printf("%s", result);
}
