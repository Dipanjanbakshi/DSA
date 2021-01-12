#include <stdio.h>
#include <string.h>
int  main()
{
        char str[20];
        printf("Enter a string");
        scanf("%[^\n]", &str);
        printf("%s", str);
        printf("\n" );
        printf("%s",strrev(str));
}
