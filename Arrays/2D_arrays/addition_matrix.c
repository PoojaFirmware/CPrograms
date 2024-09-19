// 2D Array matrix 

#include <stdio.h>
#define ROW 2
#define COL 3
int main()
{
    int mat1[ROW][COL],mat2[ROW][COL], mat3[ROW][COL], i, j;
    printf("Enter the elements for the matrix1(%d * %d): \n", ROW, COL);
    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            scanf("%d\n", &mat1[i][j]);
        }
    }

    printf("Enter the elements for the matrix2(%d * %d): \n", ROW, COL);
    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            scanf("%d\n", &mat2[i][j]);
        }
    }

    printf("Addition the elements for the matrix1(%d * %d): \n", ROW, COL);
    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("The matrix are:\n");
    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            printf("%5d", mat3[i][j]);
        }
        printf("\n");
    }
}
