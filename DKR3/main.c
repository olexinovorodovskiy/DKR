#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int num_of_znaks(FILE *fp);

int main()
{
    FILE *fp;
    fp = fopen("Input.txt", "r");
    printf("Num of znaks is %d", num_of_znaks(fp));
    fclose(fp);
    getch();
    return 0;
}

int num_of_znaks(FILE *fp)
{
    int punctu = 0;
    char symbol = fgetc(fp);
    if (symbol == EOF)
        printf("EROOOOOOOOR, FILE IS EMPTY\n");
    else
    {
        while (symbol != EOF)
        {
            if (symbol == ',' || symbol == ';' || symbol == '.' || symbol == ':' ||symbol == '!' ||symbol == '-' ||symbol == '?')
                punctu++;
            symbol = fgetc(fp);
        }
    }
    return punctu;
}
