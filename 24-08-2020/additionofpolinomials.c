#include <stdio.h>

int main()
{
        printf("For first polynomial\n");
        int d=0;
        printf("Enter degree of first polynomial\n");
        scanf("%d",&d );
        int a[d];
        int x=0;
        for(int i=0; i<d; i++)
        {
                printf("Enter coefficent of the x^%d ",x );
                scanf("%d",&a[i] );
                x++;
        }
        printf("The polynomial is " );
        x=0;
        for(int i=0; i<d; i++)
        {
                printf("%dx^%d",a[i],x );
                if(i<d-1)
                {
                        printf("+" );
                }
                x++;
        }
        printf("For second polynomial\n");
        int e=0;
        printf("Enter degree of second polynomial\n");
        scanf("%d",&e );
        int b[e];
        x=0;
        for(int i=0; i<e; i++)
        {
                printf("Enter coefficent of the x^%d ",x );
                scanf("%d",&b[i] );
                x++;
        }
        printf("The polynomial is " );
        x=0;
        for(int i=0; i<e; i++)
        {
                printf("%dx^%d",b[i],x );
                if(i<d-1)
                {
                        printf("+" );
                }
                x++;
        }
        printf("\n");
        if(d==e) {
                int sum[e];
                for(int i=0; i<e; i++)
                {
                        sum[i]=a[i]+b[i];
                }
                printf("The resulting polynomial is " );
                x=0;
                for(int i=0; i<e; i++)
                {
                        printf("%dx^%d",sum[i],x );
                        if(i<d-1)
                        {
                                printf("+" );
                        }
                        x++;
                }
        }
        else
        {
                printf("Addition not possible.\n" );
        }

}
