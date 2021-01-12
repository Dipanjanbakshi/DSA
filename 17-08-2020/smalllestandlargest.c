#include <stdio.h>
int main()
{
        int n;
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
        int smallest=a[0],largest=a[0];
        for(int i=0; i<n; i++)
        {
                if(a[i]<smallest)
                {
                        smallest=a[i];
                }
                if(a[i]>largest)
                {
                        largest=a[i];
                }
        }
        printf("The largest numer is-%d\n",largest );
        printf("The smallest numer is-%d\n",smallest );

        return 0;
}
