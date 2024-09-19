// 2D Array matrix 

#include <stdio.h>
#define ROW 4
#define COL 5
int main()
{
    int mat[ROW][COL], i, j;
    printf("Enter the elements for the matrix(%d * %d): \n", ROW, COL);
    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            scanf("%d\n", &mat[i][j]);
        }
    }
        
    printf("The matrix are:\n");
    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}