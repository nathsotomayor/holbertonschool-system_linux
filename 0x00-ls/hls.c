#include "hls.h"

/**
 * main - Function based on simple ls (without args)
 * Return: If succes return 0
 **/
int main(void)
{
	DIR *dirp;
	struct dirent *readp;

	dirp = opendir("./");
	if (dirp != NULL)
	{
		while ((readp = readdir(dirp)) != NULL)
			printf("%s ", readp->d_name);
		printf("\n");
	}
	else
		perror("Couldn't open the directory");

	closedir(dirp);
	return (0);
}
