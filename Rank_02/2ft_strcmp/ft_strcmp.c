// Ej: s1 = '-10' y s2 = '20' => -10-20 = 30 ; 
//(unsigned char)s1 = '-10' y s2 = '20' => 246-20 = 226
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// int ft_strcmp(char *s1, char *s2)
// {
// 	int i;

//  i = 0;
//  while (s1[i] == s2[i] && s1[i])
// 	    i++;
//  return (s1[i] - s2[i]);
// }
