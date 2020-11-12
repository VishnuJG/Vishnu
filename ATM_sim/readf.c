#include<stdio.h>

int main()
{
    FILE *fptr;char c[1000];
    char try[100]={'1','2','3','4','4','3','2','1','2','3','4','5','5','4','3','2'};
    fptr = fopen("1.txt", "r");
    fscanf(fptr, "%[^\t]", c);
    char cd_no[200];
    int k=0;int flag=0;
    while(c[k]!='\0')
    {
        
        int x=0;int i=0;
        for(;c[k]!=' ';k++)
        {
            cd_no[x]=c[k];
            x++;
        }
        cd_no[k]='\0';
        for(;c[i]!='\n';i++);
        for(int a=0;a<k;a++)
        {
            if(cd_no[a]==try[a])
            {
                flag=1;
                a++;
            }  
            else
            {
                flag=0;
                break;
            }   
        }
        if(flag==1)
            break;
        k+=(i-15);
        
    } 
    printf("\nFlag:\n%d\n",flag);
    long long int srujan=0;
    for(int b=0;cd_no[b]!='\0';b++)
    {
        srujan=(srujan*10)+(cd_no[b]-48);
    }
    printf("\n%lld\n",srujan);
}
    