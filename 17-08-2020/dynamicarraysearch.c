#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n, i, *ptr, search= 0,flag=0,pos=0;

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
        printf("Enter element to be searched-" );
        scanf("%d",&search );
        for(i = 0; i < n; i++)
        {
                if(ptr[i]==search)
                {  flag=1;
                   pos=i;}
        }
        if(flag==1)
        {
                printf("The element is present in position-%d",pos );
        }
        else
                printf("Search element not present.");

        free(ptr);

        return 0;
}
