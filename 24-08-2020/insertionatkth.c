#include <stdio.h>
int main()
{
        int n,m,o;
        printf("Enter the number of elements");
        scanf("%d",&n );
        int a[n+1];
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
        printf("Enter the element to be inserted");
        scanf("%d",&m );
        printf("Enter the position in which the element should be inserted");
        scanf("%d",&o );
        for(int i=n+1; i>=o; i--)
        {
                a[i]=a[i-1];
        }
        a[o]=m;
        for(int i=0; i<n+1; i++)
        {
                printf("%d", a[i] );
        }

        return 0;
}
