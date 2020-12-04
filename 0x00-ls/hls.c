#include "hls.h"

/**
 * main - Function that list the content of a directory
 * Return: If succes return 0
 **/
int main(void)
{
	DIR *dirp;
	struct dirent *readp;
	int hiddendir_first, hiddendir_second;

	dirp = opendir(".");

	if (dirp != NULL)
	{
		while ((readp = readdir(dirp)) != NULL)
		{
			hiddendir_first = _strcmp(readp->d_name, ".");
			hiddendir_second = _strcmp(readp->d_name, "..");
			if (hiddendir_first != 0 && hiddendir_second != 0)
				printf("%s ", readp->d_name);
		}
		printf("\n");
	}
	else
	{
		perror("hls: cannot access");
		/*fprintf(stderr, "hls: cannot access %s: %s\n", argv[1], strerror(errno));*/
		return (2);
	}

	closedir(dirp);
	return (0);
}
