#include <stdio.h>
int main()
{
        int n;
        int sum_of_elements=0;
        double average=0;
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
                sum_of_elements=sum_of_elements+a[i];
        }
       printf("\n");
        average=sum_of_elements/n;
        printf("The sum of all elements are-%d\n", sum_of_elements );
        printf("The average of all elements are-%lf\n", average );
        return 0;
}
