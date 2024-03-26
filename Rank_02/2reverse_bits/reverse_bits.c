/*El bit menos significativo (LSB) de un número representa la posición
del bit más a la derecha en su representación binaria.
Se desplaza el LSB hacia la izquierda (result << 1).
Se añade el LSB de octet (octet & 1) al LSB de result
utilizando una operación OR a nivel de bits | (octet & 1).
octet se desplaza una posición a la derecha (octet >>= 1).
*/
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	unsigned int	byte;

	result = 0;
	byte = 8;
	while (byte--)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
	}
	return (result);
}
