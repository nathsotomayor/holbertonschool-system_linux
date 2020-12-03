#include "hls.h"

/**
 * main - Function that list the content of a directory
 * @argc: Number of arguments
 * @argv: String array of arguments
 * Return: If succes return 0
 **/
int main(int argc, char **argv)
{
	DIR *dirp;
	struct dirent *readp;

	if (argc == 1)
		dirp = opendir("./");
	else if (argc == 2)
		dirp = opendir(argv[1]);
	else if (argc > 2)
		exit(1);

	if (dirp != NULL)
	{
		while ((readp = readdir(dirp)) != NULL)
			printf("%s ", readp->d_name);
		printf("\n");
	}
	else
	{
		fprintf(stderr, "hls: cannot access %s: %s\n", argv[1], strerror(errno));
		exit(2);
	}

	closedir(dirp);
	return (0);
}
