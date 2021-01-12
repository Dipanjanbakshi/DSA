#include <stdio.h>
int main(){
        int c,d;
        printf("Enter no of rows\n" );
        scanf("%d",&c );
        printf("Enter no of columns\n" );
        scanf("%d",&d );
        int a[c][d];

        int i, j;
        for(i=0; i<c; i++) {
                for(j=0; j<d; j++) {
                        printf("Enter values");
                        scanf("%d", &a[i][j]);
                }
        }

        printf("Two Dimensional array elements:\n");
        for(i=0; i<c; i++) {
                for(j=0; j<d; j++) {
                        printf("%d ", a[i][j]);

                }
                printf("\n");
        }
        int f=0;
        int k, l;
        for(k=0; k<c; k++) {
                for(l=0; l<d; l++) {
                        if(a[k][l]!=0)
                        {f++;}
                }

        }
        int g=f+1,h=3;
        int b[g][h];
        for(k=0; k<g; k++) {
                for(l=0; l<h; l++) {

                        b[0][0]=f;
                        b[0][1]=c;
                        b[0][2]=d;
                }
        } k=1;
        for(i=0; i<c; i++) {
                for(j=0; j<d; j++) {
                        if(a[i][j]!=0)
                        {
                                {
                                        l=0;  {

                                                b[k][l]=a[i][j];
                                                l++;
                                                b[k][l]=i;
                                                l++;
                                                b[k][l]=j;
                                                k++;
                                        }
                                }

                        }
                }
        }
        printf("\n");
        for(i=0; i<g; i++) {
                for(j=0; j<h; j++) {
                        printf("%d ", b[i][j]);

                }
                printf("\n");
        }
        return 0;
}
