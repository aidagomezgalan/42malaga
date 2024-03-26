#include <unistd.h>

/*Un array para rastrear caracteres vistos (ASCII)
Se inicia a 0 cada posición para indicar que no se ha visto.
Se compara si el número ascii del carácter (*s1) 
en la posición de seen es 0 y se imprime.
Después se marca como 1 para indicar que ese carácter ya ha salido.*/
void	ft_union(char *s1, char *s2)
{
	int	seen[256] = {0};

	while (*s1)
	{
		if (seen[(unsigned char)*s1] == 0)
		{
			write(1, s1, 1);
			seen[(unsigned char)*s1] = 1;
		}
		s1++;
	}
	while (*s2)
	{
		if (seen[(unsigned char)*s2] == 0)
		{
			write(1, s2, 1);
			seen[(unsigned char)*s2] = 1;
		}
		s2++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
