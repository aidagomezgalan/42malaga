// #include <stdlib.h>
// #include <stdio.h>

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

void	fill(char **tab, t_point size, t_point current_pos, char to_fill)
{
	/*Si la posición actual (current_pos) está fuera de los límites de la matriz (fuera de los rangos de la matriz en X o Y),
	o si el carácter en la posición actual no coincide con el carácter de relleno (to_fill),
	la función fill se detiene y retorna para evitar un bucle infinito o salir de los límites de la matriz.*/
	if (current_pos.y < 0 || current_pos.y >= size.y || current_pos.x < 0
		|| current_pos.x >= size.x || tab[current_pos.y][current_pos.x] != to_fill)
		return ;
	/*Si la celda actual es válida (está dentro de los límites de la matriz y contiene el carácter que se quiere rellenar),
	se establece el carácter de la celda actual a 'F' (o cualquier carácter de relleno deseado).*/
	tab[current_pos.y][current_pos.x] = 'F';
	// la función fill se invoca recursivamente en las celdas adyacentes a la actual:
	// Celda a la izquierda:
	fill(tab, size, (t_point){current_pos.x - 1, current_pos.y}, to_fill);
	// Celda a la derecha:
	fill(tab, size, (t_point){current_pos.x + 1, current_pos.y}, to_fill);
	// Celda arriba:
	fill(tab, size, (t_point){current_pos.x, current_pos.y - 1}, to_fill);
	// Celda abajo:
	fill(tab, size, (t_point){current_pos.x, current_pos.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

// char	**make_area(char **zone, t_point size)
// {
// 	char	**new;

// 	new = malloc(sizeof(char *) * size.y);
// 	for (int i = 0; i < size.y; ++i)
// 	{
// 		new[i] = malloc(size.x + 1);
// 		for (int j = 0; j < size.x; ++j)
// 			new[i][j] = zone[i][j];
// 		new[i][size.x] = '\0';
// 	}
// 	return (new);
// }

// int	main(void)
// {
// 	t_point size = {8, 5};
// 	char *zone[] = {
// 		"11111111",
// 		"10001001",
// 		"10010001",
// 		"10110001",
// 		"11100001",
// 	};

// 	char **area = make_area(zone, size);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	printf("\n");

// 	t_point begin = {7, 4};
// 	flood_fill(area, size, begin);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	return (0);
// }
