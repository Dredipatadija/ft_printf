#include <stdio.h>

int main(void)
{
	int i;

	i = printf("%.3p", "hola");
	printf("%d", i);
	return (0);
}
