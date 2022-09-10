#include <cs50.h>
#include <stdio.h>

int	main(void)
{
	long	cardnumber;
	int		digits;
	int		checksum;
	int		i;
	
	number = get_long("Credit Card No.: ");
	//Count how many digits the number has
	digits = 0;
	while (cardnumber > 0)
	{
		cardnumber /= 10;
		digits++;
	}
	//Test the digit counter
	printf("%d digits\n", digits);
}
