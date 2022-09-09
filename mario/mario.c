#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Integer values for height
    int height;
    int i;
    int j;

    height = 0;
    while (!(height > 0 && height < 9))
    {
        height = get_int("Height: ");
    }

    i = 1;
    //Newlines loop
    while (i <= height)
    {
        //Spaces
        j = 0;
        while (j < height - i)
        {
            printf(" ");
            j++;
        }
        //Hashes
        j = 0;
        while (j < i)
        {
            printf("#");
            j++;
        }
        //Mid spaces
        printf("  ");
        //Ending hashes
        j = 0;
        while (j < i)
        {
            printf("#");
            j++;
        }
        i++;
        printf("\n");
    }
}
