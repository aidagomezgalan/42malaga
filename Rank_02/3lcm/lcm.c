// HCF (Highest Common Factor)
// MCD de 12 y 18 es 6 (12 / 6 = 2 y 18 / 6 = 3)
// Es el divisor más grande que ambos tienen en común.
unsigned int	hcf(unsigned int a, unsigned int b)
{
	if (b == 0)
		return (a);
	else
		return (hcf(b, a % b));
}

// LCM (Lowest Common Multiple)
// MCM de 4 y 6 es 12 (4 * 3 = 12 y 6 * 2 = 12)
// Es el múltiplo más pequeño que ambos comparten.
unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	else
		return ((a * b) / hcf(a, b));

}
