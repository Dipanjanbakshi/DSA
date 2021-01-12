#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n, i, *ptr;

        printf("Enter number of elements: ");
        scanf("%d", &n);

        ptr = (int*) malloc(n * sizeof(int));

        if(ptr == NULL)
        {
                printf("Error! memory not allocated.");
                exit(0);
        }

        printf("Enter elements: ");
        for(i = 0; i < n; i++)
        {
                scanf("%d", ptr + i);
        }
        int j = 0; loop:
        {
                for(i = 0; i < n; i++ )
                {
                        if(ptr[i]%2!=0&&ptr[i+1]%2==0)
                        {
                                int x=ptr[i];
                                ptr[i]=ptr[i+1];
                                ptr[i+1]=x;
                        }
                } if (j<n)
                {
                        j++;
                        goto loop;
                }
        }
        for(i = 0; i < n; i++)
        {
                printf("%d", *(ptr+i) );
        }

        free(ptr);

        return 0;
}
