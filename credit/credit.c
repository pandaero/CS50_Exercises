#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardnumber;
    long cardnumbercpy;
    int carddigit;
    int digits;
    int countdigits;
    int checksum;
    int firstdigit;
    int seconddigit;

    //Ask for the card number
    cardnumber = get_long("Credit Card No.: ");
    cardnumbercpy = cardnumber;
    digits = 0;
    //Count how many digits the number has
    while (cardnumber > 0)
    {
        cardnumber = cardnumber / 10;
        digits++;
    }
    countdigits = digits;
    //Test the digit counter
    //printf("%d digits\n", digits);
    //Mark invalid if wrong digit count
    if (digits != 16 && digits != 15 && digits != 13)
    {
        printf("INVALID\n");
        return (0);
    }
    //Checksum test (Luhn's Algorithm)
    checksum = 0;
    carddigit = 0;
    //Test starting conditions
    //printf("Card Dig: %d\nCard No.: %ld\nChecksum: %d\n", carddigit, cardnumbercpy, checksum);
    while (digits > 0 && countdigits == 16)
    {
        carddigit = cardnumbercpy % 10;
        cardnumbercpy = cardnumbercpy / 10;
        if (digits % 2 == 1)
        {
            if (2 * carddigit >= 10)
            {
                //Add each digit
                checksum += (2 * carddigit) / 10;
                checksum += (2 * carddigit) % 10;
            }
            else
            {
                checksum += 2 * carddigit;
            }
        }
        else
        {
            checksum += carddigit;
        }
        if (digits == 2)
        {
            seconddigit = carddigit;
        }
        if (digits == 1)
        {
            firstdigit = carddigit;
        }
        digits--;
    }
    while (digits > 0 && (countdigits == 15 || countdigits == 13))
    {
        carddigit = cardnumbercpy % 10;
        cardnumbercpy = cardnumbercpy / 10;
        if (digits % 2 == 0)
        {
            if (2 * carddigit >= 10)
            {
                //Add each digit
                checksum += (2 * carddigit) / 10;
                checksum += (2 * carddigit) % 10;
            }
            else
            {
                checksum += 2 * carddigit;
            }
        }
        else
        {
            checksum += carddigit;
        }
        if (digits == 2)
        {
            seconddigit = carddigit;
        }
        if (digits == 1)
        {
            firstdigit = carddigit;
        }
        digits--;
    }
    //Test by the end
    //printf("First Dig: %d\nSecond Dig: %d\nChecksum: %d\n", firstdigit, seconddigit, checksum);
    //Verify conditions for each provider
    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (countdigits == 16)
    {
        if (firstdigit == 5 && (seconddigit > 0 && seconddigit < 6))
        {
            printf("MASTERCARD\n");
        }
        else if (firstdigit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (countdigits == 15 && firstdigit == 3 && (seconddigit == 4 || seconddigit == 7))
    {
        printf("AMEX\n");
    }
    else if (countdigits == 13 && firstdigit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return (0);
}
