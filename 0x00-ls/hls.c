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
	int hiddendir_first, hiddendir_second;

	dirp = opendir(".");

	if (argc == 2)
		dirp = opendir(argv[1]);

	if (dirp != NULL)
	{
		while ((readp = readdir(dirp)) != NULL)
		{
			hiddendir_first = _strcmp(readp->d_name, ".");
			hiddendir_second = _strcmp(readp->d_name, "..");
			if (readp->d_type != DT_UNKNOWN  && hiddendir_first != 0 && hiddendir_second != 0)
				printf("%s ", readp->d_name);
		}
		printf("\n");
		closedir(dirp);
	}
	else
	{
		perror("hls: cannot access");
		/*fprintf(stderr, "hls: cannot access %s: %s\n", argv[1], strerror(errno));*/
		return (2);
	}

	return (0);
}
