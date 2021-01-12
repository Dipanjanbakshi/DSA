#include <stdio.h>
int main()
{
        int n;
        printf("k");
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
        for(int i=0; i<n; )
        { int x=a[n-1];
          if(a[i]<a[i+1]&& i!=n)
          {
                  a[i]=a[i+1];
                  i++;
          }
          a[n-1]=x;}
        for(int i=0; i<n; i++)
        {
                printf("%d", a[i] );
        }
        return 0;

}
