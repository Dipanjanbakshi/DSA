#include <stdio.h>
int main()
{
        int n,o;
        printf("Enter the number of elements");
        scanf("%d",&n );
        int a[n];
        printf("Enter the elements");
        for(int i=0; i<n; i++)
        {
                scanf("%d",&a[i] );
        }
        for(int i=0; i<n; i++)
        {
                printf("%d", a[i] );
        }
        printf("\n" );
        printf("Enter the position in which the element should be deleted");
        scanf("%d",&o );
        for(int i=o; i<n; i++)
        {
                a[i]=a[i+1];
        }
        for(int i=0; i<n-1; i++)
        {
                printf("%d", a[i] );
        }

        return 0;
}
