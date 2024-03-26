#include <unistd.h>

/*Se realiza un desplazamiento de bits hacia la derecha
en byte posiciones (octet >> byte).
Esto significa que cada bit se moverá a la derecha byte veces.
(& 1) Se realiza una operación AND a nivel de bits.
El operador & toma dos operandos y produce un resultado
en el que cada bit es 1 si y solo si los bits correspondientes
en ambos operandos son 1.
Aquí, 1 es una máscara que tiene todos los bits en 0,
excepto el bit menos significativo, que está en 1 (00000001).
El bit menos significativo (LSB) de un número representa la posición
del bit más a la derecha en su representación binaria.
Se suma el carácter '0' para convertirlo en un carácter.*/
void	print_bits(unsigned char octet)
{
	unsigned int	byte;
	unsigned char	bit;

	//nº de bits en un valor unsigned char
	byte = 8;
	while (byte--)
	{
		bit = (octet >> byte & 1) + '0';
		write(1, &bit, 1);
	}
}
