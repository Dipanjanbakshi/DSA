#include <stdio.h>
#include <stdlib.h>
int main() {
        int row,col;
        printf("Enter no of rows\n" );
        scanf("%d",&row );
        printf("Enter no of columns\n" );
        scanf("%d",&col );
        int *ptr = (int *)malloc(row * col * sizeof(int));
        int i, j;
        if(ptr == NULL)
        {
                printf("Error! memory not allocated.");
                exit(0);
        }

        printf("Enter elements: ");
        for(i = 0; i < row; i++)
        {
                for(j = 0; j < col; j++)
                {
                        scanf("%d", ptr[row][col]);
                }
        }
        free(ptr);
        return 0;
}
