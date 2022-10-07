#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

//Function to check that string only contains chars. 1 yes, 0 no.
int onlychars(string str)
{
    int i;

    i = 0;
    while (str[i] != 0)
    {
        if (isalpha(str[i]) == 0)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

//Function checks that there are no duplicate characters in string.
int noduplicates(string str)
{
    int     i;
    int     j;
    char    ch;
    char    case_offset;

    case_offset = 'a' - 'A';
    i = 0;
    while (str[i] != 0)
    {
        //Extra step for more clear explanation.
        ch = str[i];
        j = 0;
        while (str[j] != 0)
        {
            //If the character appears again in a different location, duplicate.
            if ((str[j] == ch || str[j] == ch + case_offset || str[j] == ch - case_offset) && j != i)
            {
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

//Function to determine the length of a char string.
int ft_strlen(string str)
{
    int i;

    i = 0;
    while (str[i] != 0)
    {
        i++;
    }
    return (i);
}

//Function makes all chars in a string uppercase.
void    makeupper(string str)
{
    int      i;

    i = 0;
    while (str[i] != 0)
    {
        str[i] = toupper(str[i]);
        i++;
    }
}

//Function makes the substitution cipher based on the ordered alphabet. Re-use plain.
void makecipher(string plain, string key)
{
    int     i;
    int     letter;
    int     case_offset;
    char    cipher;

    case_offset = 'a' - 'A';
    i = 0;
    while (plain[i] != 0)
    {
        if (plain[i] >= 'a')
        {
            letter = plain[i] - 'a';
            cipher = key[letter] + case_offset;
        }
        else if (plain[i] >= 'A' && plain[i] <= 'Z')
        {
            letter = plain[i] - 'A';
            cipher = key[letter];
        }
        else
        {
            cipher = plain[i];
        }
        plain[i] = cipher;
        i++;
    }
}

int main(int argc, string argv[])
{
    string  plain;
    string  cipher;

    //Check input for number of arguments
    if (argc != 2)
    {
        printf("Input error.\n");
        return (1);
    }
    //Check integrity of key: number and type
    if (ft_strlen(argv[1]) != 26 || onlychars(argv[1]) != 1 || noduplicates(argv[1]) == 0)
    {
        printf("Key error.\n");
        return (1);
    }
    plain = get_string("plaintext: ");
    makeupper(argv[1]);
    makecipher(plain, argv[1]);
    printf("ciphertext: %s\n", plain);
    return (0);
}
