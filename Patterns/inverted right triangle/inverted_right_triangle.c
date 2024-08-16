#include <stdio.h>
int startriangle(int rows)
{
    int i, j;
    for(i = rows; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int numberrowtriangle(int rows)
{
    int i, j;
    for(i = rows; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            printf("%d", i);
        }
        printf("\n");
    }
}

int numbercoltriangle(int rows)
{
    int i, j;
    for(i = rows; i > 0; i--)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
}

int alphabetcoltriangle(int rows)
{
    int i, j;
    for(i = rows; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            printf("%c", 'A' + j);
        }
        printf("\n");
    }
}

int alphabetrowtriangle(int rows)
{
    int i, j;
    for(i = rows; i >= 1; i--)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%c", 'A' + (rows - i));
        }
        printf("\n");
    }
}

int rightalignedinvertedtriangle(int rows)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < i; j++)
        {
            printf(" ");
        }
        for(j = 0; j < rows - i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int rightalignednumbertriangle(int rows)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < i; j++)
        {
            printf(" ");
        }
        for(j = 0; j < rows - i; j++)
        {
            printf("%d", i);
        }
        printf("\n");
    }
}

int rightnumbercoltriangle(int rows)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < i; j++)
        {
            printf(" ");
        }
        for(j = 0; j < rows - i; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
}

int main()
{
    int i, j, rows;
    printf("Enter the no.of rows:");
    scanf("%d", &rows);
    
    int starprint = startriangle(rows);
    int numberrowsprint = numberrowtriangle(rows);
    int numbercolprint = numbercoltriangle(rows);
    int alphabetrowprint = alphabetrowtriangle(rows);
    int alphabetcolprint = alphabetcoltriangle(rows);
    int rightaligedinvertedprint = rightalignedinvertedtriangle(rows);
    int rightaligednumberprint = rightalignednumbertriangle(rows);
    int rightaligedcolprint = rightnumbercoltriangle(rows);

    return 0;
}
