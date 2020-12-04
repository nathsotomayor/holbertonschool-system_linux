#include "hls.h"

/**
 * main - Function that list the content of a directory
 * @argc: Number of arguments
 * @argv: String array of arguments
 * Return: If succes return 0
 **/
int main(int argc, char *argv[])
{
	DIR *dirp;
	struct dirent *readp;

	dirp = opendir(".");

	if (argc == 2)
		dirp = opendir(argv[1]);

	if (dirp != NULL)
	{
		while ((readp = readdir(dirp)) != NULL)
		{
			if (readp->d_type != DT_UNKNOWN  && readp->d_name[0] != *".")
				printf("%s ", readp->d_name);
		}
		printf("\n");
	}
	else
	{
		perror("hls: cannot access");
		return (2);
	}
	closedir(dirp);

	return (0);
}
