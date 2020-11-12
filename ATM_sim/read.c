#include<stdio.h>
int main() 
{
    char c[1000];
    FILE *fptr;
    fptr = fopen("1.txt", "r");
    fscanf(fptr, "%[^\n]", c);
    char cd_no[20];
    int k;
    for(k=0;c[k]!=' ';k++)
    {
        cd_no[k]=c[k];
        printf("\n%d\n",c[k]);

    }
    cd_no[k]='\0';
    printf("\n");
    printf("%s\n",cd_no);
    for(int k=0;cd_no[k]!='\0';k++)
        printf("%c",cd_no[k]);
    int i=0;
    for(;c[i]!='\0';i++);
        printf("\n%d\n",c[i]);

    fclose(fptr);
    return 0;
}