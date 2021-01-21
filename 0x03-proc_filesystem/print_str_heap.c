#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * main - Print a string in the heap
 * Return: EXIT_FAILURE if malloc fail, or print a string in an infinite loop.
 */
int main(void)
{
	char *str;
	unsigned long int i;

	str = strdup("String in the heap");
	if (str == NULL)
	{
	  fprintf(stderr, "Error allocating memory\n");
	  return (EXIT_FAILURE);
	}

	i = 0;
	while (str)
	{
	  printf("[%lu] %s (%p)\n", i, str, (void *)str);
	  sleep(2);
	  i++;
	}
	return (EXIT_SUCCESS);
}
