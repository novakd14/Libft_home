#include "libft.h"

void	solve(unsigned int index, char	*ptr)
{
	int	shift;

	shift = 13;
	(void) index;
	if (*ptr >= '0' && *ptr <= '9')
		*ptr = (*ptr - '0' + shift) % ('9' - '0' + 1) + '0';
	else if (*ptr >= 'a' && *ptr <= 'z')
		*ptr = (*ptr - 'a' + shift) % ('z' - 'a' + 1) + 'a';
	else if (*ptr >= 'A' && *ptr <= 'Z')
		*ptr = (*ptr - 'A' + shift) % ('Z' - 'A' + 1) + 'A';
	return ;
}

int main(void)
{
	char	str[] = "Rnpu cebwrpg bs gur 97 Pbzzba Pber pbagnvaf na rapbqrq uvag. Sbe rnpu pvepyr, bayl bar cebwrpg cebivqrf gur pbeerpg uvag arrqrq sbe gur arkg pvepyr. Guvf punyyratr vf vaqvivqhny, gurer vf bayl n cevmr sbe bar fghqrag jvaare cebivqvat nyy qrpbqrq zrffntrf. Nal nqinagntrq crbcyr pna cynl, yvxr pheerag be sbezre fgnss, ohg gur cevmr jvyy erznva flzobyvp. Gur uvag sbe guvf svefg cebwrpg vf: Ynetr pbjf trarebfvgl pbzrf jvgu punegf naq sbhe oybaqr ungf gb qrsl hccre tenivgl ureb";

	ft_striteri(str, solve);
	ft_putstr_fd(str, 1);
}
