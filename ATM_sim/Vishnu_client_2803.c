#include<stdio.h>
#include<stdlib.h>
void withdrawal(long long int cd_no);//2
void deposit(long long int cd_no);//2
int search(long long int cd_no);//4
int check_pass(long long int cd_no);//1
void ministatement(long long int cd_no);//3
int new_card_number();//1
void change_password(long long int cd_no);//3
int loan();//4
#define interest(x,y) (x*(y/100))
#define processing(x) (x*(0.5/100))

int new_card_number()
{
    FILE *fptr;char c[1000];
    fptr = fopen("1.txt", "r");
    fscanf(fptr, "%[^\t]", c);
    int k=0;int flag=0;
	long long int srujan;int j;long int bal=0;int l=0;
    long long int cd_no;int a=0;
    printf("\nEnter the card number:\n");
    scanf("%lld",&cd_no);
    char fbal[100];
    while(c[k]!='\0')
    {  
        int i=k;l++;
        srujan=0;
		for(;c[i]!='\n';i++);
        i-=k;
    	for(;c[k]!=' ';k++)
    	{
       		srujan=(srujan*10)+(c[k]-48);
    	}
        
		if(cd_no==srujan)
			flag=1;
        if(flag==1)
            break;
        k+=(i-15);
        a=k;
        //printf("%d",flag);
    } 
    fclose (fptr);//printf("%d",a);
    if(flag==0)
    {
        char da[1000];
        fptr = fopen("1.txt", "w");
        fscanf(fptr, "%[^\t]", da);int s=0;
        long long int rem=cd_no;int count=0;
        while(rem)
        {
            rem=rem/10;
            count++;
        }
        int x=count;
        rem=cd_no;
        while(rem)
        {
            fbal[count-1]='0'+(rem%10);
            rem=rem/10;
            count--;
        }
        fbal[x]=' ';fbal[x+1]='\0';
        printf("\n");
        for(int q=0;fbal[q]!='\0';q++)
        {
            //printf("%c",fbal[q]);
        }
        int dep;
        printf("\n Please enter the amount you wish to deposit:\n");
        scanf("%d",&dep);
        int re=dep;count=0;
        while(re)
        {
            re=re/10;
            count++;
        }
        int w;
        w=x+count+1;re=dep;
        while(re)
        {
            fbal[x+count]='0'+(re%10);
            re=re/10;
            count--;
        }
        fbal[w]=' ';fbal[w+1]='\0';     
        printf("\n");
        int pin;
        printf("\n Please enter the new pin:\n");
        scanf("%d",&pin);
        re=pin;count=0;
        while(re)
        {
            re=re/10;
            count++;
        }
        int r=w+count+1;re=pin;
        while(re)
        {
            fbal[w+count]='0'+(re%10);
            re=re/10;
            count--;
        }
        fbal[r]='\0';
        printf("\n");
        for(int h=0;fbal[h]!='\0';h++);
            //printf("%c\n",fbal[h]);
        s=0;
        for(;;a++)
        {
            if(fbal[s]=='\0')
                break;
            c[a]=fbal[s];
            s++;
        }
        c[a]='\n';c[a+1]='\0';
        for(int q=0;c[q]!='\0';q++)
        {
            fputc(c[q],fptr);
        }
        fclose(fptr);
        return (1);
    }
    else
    {
        printf("\nCard number already exists\n");
        return(0);
    }
    fclose(fptr);
}
void ministatement(long long int cd_no)
{
    FILE *fptr;char c[1000];
    fptr = fopen("1.txt", "r");
    fscanf(fptr, "%[^\t]", c);
    int k=0;int flag=0;
	long long int srujan;int j;long int bal=0;int l=0;
    while(c[k]!='\0')
    {  
        int i=k;
        srujan=0;bal=0;
		for(;c[i]!='\n';i++);
        i-=k;
    	for(;c[k]!=' ';k++)
    	{
       		srujan=(srujan*10)+(c[k]-48);
    	}
        for(j=k+1;c[j]!=' ';j++)
        {
            bal=(bal*10)+(c[j]-48);
        }
		if(cd_no==srujan)
			flag=1;
        if(flag==1)
            break;
        k+=(i-15);
    } 
    fclose(fptr);
    printf("\nMINISTATEMENT:");
    printf("\nBalance:%ld",bal);
}
void change_password(long long int cd_no)
{
    FILE *fptr;char c[1000];
    fptr = fopen("1.txt", "r");
    fscanf(fptr, "%[^\t]", c);
    int k=0;int flag=0;
	long long int srujan;int j;int l=0;
    int a,newpin=0;
    printf("\nEnter the new pin:");
    scanf("%d",&newpin);
    char fbal[10];
    while(c[k]!='\0')
    {  
        int i=k;
        srujan=0;
		for(;c[i]!='\n';i++);
        i-=k;
    	for(;c[k]!=' ';k++)
    	{
       		srujan=(srujan*10)+(c[k]-48);
    	}
        for(j=k+1;c[j]!=' ';j++);
        for(l=j+1;c[l]!='\n';l++);
        a=j+1;
		if(cd_no==srujan)
			flag=1;
        if(flag==1)
            break;
        k+=(i-15);
    } 
    fclose (fptr);
    char da[10000];
    fptr = fopen("1.txt", "w");
    fscanf(fptr, "%[^\t]", da);int s=0;
    int rem=newpin;int count=0;
    while(rem)
    {
        rem=rem/10;
        count++;
    }
    int x=count;
    rem=newpin;
    while(rem)
    {
       fbal[count-1]='0'+(rem%10);
       rem=rem/10;
       count--;
    }
    fbal[x]='\0';
    for(int h=0;fbal[h]!='\0';h++);
        //printf("%c\n",fbal[h]);
    for(;c[a]!='\n';a++)
    {
        if(fbal[s]=='\0')
            break;
        
        c[a]=fbal[s];
        s++;
    }

    for(int q=0;c[q]!='\0';q++)
    {
        fputc(c[q],fptr);
    }
    fclose(fptr);
    printf("Your pin has been successfully updated to the new one\n");
}
void deposit(long long int cd_no)
{
    FILE *fptr;char c[1000];
    fptr = fopen("1.txt", "r");
    fscanf(fptr, "%[^\t]", c);
    int k=0;int flag=0;
	long long int srujan;int j;long int bal=0;int pin=0,l=0;
    int a,amt;
    printf("\nEnter the amount to be deposited:");
    scanf("%d",&amt);
    char fbal[10];
    while(c[k]!='\0')
    {  
        int i=k;
        srujan=0;bal=0;pin=0;
		for(;c[i]!='\n';i++);
        i-=k;
    	for(;c[k]!=' ';k++)
    	{
       		srujan=(srujan*10)+(c[k]-48);
    	}
        a=k+1;
        for(j=k+1;c[j]!=' ';j++)
        {
            bal=(bal*10)+(c[j]-48);
        }
        bal=bal+amt;
		if(cd_no==srujan)
			flag=1;
        if(flag==1)
            break;
        k+=(i-15);
    } 
    fclose (fptr);
    char da[1000];
    fptr = fopen("1.txt", "w");
    fscanf(fptr, "%[^\t]", da);int s=0;
    int rem=bal;int count=0;
    while(rem)
    {
        rem=rem/10;
        count++;
    }
    int x=count;
    rem=bal;
    while(rem)
    {
       fbal[count-1]='0'+(rem%10);
       rem=rem/10;
       count--;
    }
    fbal[x]='\0';
    for(int h=0;fbal[h]!='\0';h++);
        //printf("%c\n",fbal[h]);
    for(;c[a]!=' ';a++)
    {
        if(fbal[s]=='\0')
            break;
        
        c[a]=fbal[s];
        s++;
    }

    for(int q=0;c[q]!='\0';q++)
    {
        fputc(c[q],fptr);
    }
    fclose(fptr);
    printf("\nAmount has be deposted successfully\n");
}
void withdrawal(long long int cd_no)
{
    FILE *fptr;char c[10000];
    fptr = fopen("1.txt", "r");
    fscanf(fptr, "%[^\t]", c);
    int k=0;int flag=0;
	long long int srujan;int j;long int bal=0;int pin=0,l=0;
    int a,amt;
    printf("\nEnter the amount to be withdrawn:");
    scanf("%d",&amt);
    char fbal[10];
    while(c[k]!='\0')
    {  
        int i=k;
        srujan=0;bal=0;pin=0;
		for(;c[i]!='\n';i++);
        i-=k;
    	for(;c[k]!=' ';k++)
    	{
       		srujan=(srujan*10)+(c[k]-48);
    	}
        a=k+1;
        for(j=k+1;c[j]!=' ';j++)
        {
            bal=(bal*10)+(c[j]-48);
        }
        bal=bal-amt;
		if(cd_no==srujan)
			flag=1;
        if(flag==1)
            break;
        k+=(i-15);
    } 
    fclose (fptr);
    char da[1000];
    fptr = fopen("1.txt", "w");
    fscanf(fptr, "%[^\t]", da);int s=0;
    int rem=bal;int count=0;
    while(rem)
    {
        rem=rem/10;
        count++;
    }
    int x=count;
    rem=bal;
    while(rem)
    {
       fbal[count-1]='0'+(rem%10);
       rem=rem/10;
       count--;
    }
    fbal[x]='\0';
    for(int h=0;fbal[h]!='\0';h++);
        //printf("%c\n",fbal[h]);
    for(;c[a]!=' ';a++)
    {
        if(fbal[s]=='\0')
            break;
        
        c[a]=fbal[s];
        s++;
    }

    for(int q=0;c[q]!='\0';q++)
    {
        fputc(c[q],fptr);
    }
    fclose(fptr);
    printf("\nAmount withdrawn successfully\n");
}
int check_pass(long long int cd_no)
{
    FILE *fptr;char c[1000];
    fptr = fopen("1.txt", "r");
    fscanf(fptr, "%[^\t]", c);
    int k=0;int flag=0;
	long long int srujan;int j;long int bal=0;int pin=0,l=0;
    int a;
    printf("Please enter the pin number:");
	scanf("%d",&a);
    while(c[k]!='\0')
    {  
        int i=k;
        srujan=0;bal=0;pin=0;
		for(;c[i]!='\n';i++);
        i-=k;
    	for(;c[k]!=' ';k++)
    	{
       		srujan=(srujan*10)+(c[k]-48);
    	}
        for(j=k+1;c[j]!=' ';j++)
        {
            bal=(bal*10)+(c[j]-48);
        }
		if(cd_no==srujan)
			flag=1;
        if(flag==1)
            break;
        k+=(i-15);
    } 
	for(l=j+1;l<=j+4;l++)
    {
            pin=(pin*10)+(c[l]-48);
    }
	if(pin==a)
        flag=1;
	else
	{
		flag=0;
	}
    fclose(fptr);
	return(flag);
}
int search(long long int cd_no)
{
    FILE *fptr;char c[1000];
    fptr = fopen("1.txt", "r");
    fscanf(fptr, "%[^\t]", c);
    int k=0;int flag=0;
	long long int srujan;
    while(c[k]!='\0')
    {  
        int i=k;
        srujan=0;
		for(;c[i]!='\n';i++);
        i-=k;
    	for(;c[k]!=' ';k++)
    	{
       		srujan=(srujan*10)+(c[k]-48);
    	}
		if(cd_no==srujan)
			flag=1;
        if(flag==1)
            break;
        k+=(i-15);
    } 
    fclose(fptr);
    //printf("\ncard number:\n%lld\n",srujan);
	return(flag);
}
int loan()
{
    st:;
    printf("Please enter the purpose of loan\n");
    printf("H for Home loan\tV for Vehicle loan\nE for Education loan\tB for Business loan\nM for medical related loans:\n");
    getchar();
    int ch=getchar();
    if(ch!=71 && ch!=104 && ch!=86 && ch!=118 && ch!=69 && ch!=101 && ch!=66 && ch!=98 && ch!=77 && ch!=109)
    {
        printf("Invalid input press 1 to re-try and 0 to exit\n");
        int x;scanf("%d",&x);
        if(x==1)
        {
            goto st;
        }
        else if(x==0)
        {
            exit(1);
        }
        else
        {
            exit(2);
        }
         
    }
    printf("Please enter the amount of money you wish to apply for:");
    float principle=0;
    scanf("%f",&principle);
    float sum=principle;
    printf("\nPlease enter the number of years you wish to pay back the loan in:");
    int year;
    scanf("%d",&year);int fiyear=year;
    if(ch==71 || ch==104)
    {
        printf("You have choosen Home loan plan\nThe interest rates are as follows:\nThe present interest rates stand at 7.25%%.p.a\nPrecessing fee of 0.5%% is levied on the total amount taken as loan\n");
        while(year)
        {
            sum=sum+interest(sum,7.25);
            year--;
        }
    }
    else if(ch==86 || ch==118)
    {
        printf("You have choosen Vehicle loan plan\nThe interest rates are as follows:\nThe present interest rates stand at 8.9%%.p.a\nPrecessing fee of 0.5%% is levied on the total amount taken as loan\n");
        while(year)
        {
            sum+=interest(sum,8.9);
            year--;
        }
    }
    else if(ch==69 || ch==101)
    {
        printf("You have choosen Education loan plan\nThe interest rates are as follows:\nThe present interest rates stand at 10.25%%.p.a\nPrecessing fee of 0.5%% is levied on the total amount taken as loan\n");
        while(year)
        {
            sum+=interest(sum,10.25);
            year--;
        }
    }
    else if(ch==66 || ch==98)
    {
        printf("You have choosen Business loan plan\nThe interest rates are as follows:\nThe present interest rates stand at 14.5%%.p.a\nPrecessing fee of 0.5%% is levied on the total amount taken as loan\n");
        while(year)
        {
            sum+=interest(sum,14.5);
            year--;
        }
    }
    else if(ch==77 || ch==109)
    {
        printf("You have choosen Medical loan plan\nThe interest rates are as follows:\nThe present interest rates stand at 7.25%%.p.a\nPrecessing fee of 0.5%% is levied on the total amount taken as loan\n");
        while(year)
        {
            sum+=interest(sum,11.99);
            year--;
        }
    }
    sum+=processing(principle);
    printf("\n\nThe total amount of money you need to pay after %d years is %f\n*********************************************************************************************\n",fiyear,sum);
    retry:;
    printf("If you wish to check some other loan press 1 \nIf you wish to exit press 0\n");
    int cho;
    scanf("%d",&cho);
    switch(cho)
    {
        case 1:goto st;
            break;
        case 0:exit(0);
            break;
        default:printf("Invalid input press 1 to re-try 0 to exit and 2 to return to other functions of the ATM\n");
            int x;scanf("%d",&x);
            if(x==1)
            {
                goto retry;
            }
            else if(x==0)
            {
                exit(1);
            }
            else if(x==2)
            {
                return(1);
            }
    }
    return(0);
}

void main()
{
	start:;
	long long int card_num=0;
	printf("\n\t\tHello welcome to JANATHA BANK ATM\n\n");
	printf("Please enter the card number:");
	scanf("%lld",&card_num);
	if(search(card_num))
	{
		printf("\tAccount found\n");
		printf("Getting account details please wait.... \n\n");
        pinr:;
		if(check_pass(card_num))
		{	
            printf("Please wait while we verify....\n");
			printf("Pin accepeted\n");
            rum:;
			printf("Please enter \n W for withdrawal \t M for mini-statement \n C to change password \t D to deposit\n L for loan and loan related information\n");
			int x=getchar();
			char operation;
			scanf("%c",&operation);
			if(operation=='w' || operation=='W')
			{
                printf("One moment please your request is being proccessed...\n");
				withdrawal(card_num);
                int d;
                printf("\nIf u wish to go through the functons again press 1 else press 0 to exit:");
                scanf("%d",&d);
                if(d==1)
                    goto rum;
                else
                    exit(1);
			}
			else if(operation=='m' || operation=='M')
			{
				printf("One moment please your request is being proccessed...\n");
				ministatement(card_num);
                printf("\nIf u wish to go through the functons again press 1 else press 0 to exit:");
                int d;
                scanf("%d",&d);
                if(d==1)
                    goto rum;
                else
                    exit(1);
			}
            else if(operation=='l' || operation=='L')
            {
                int w=loan();
                if(w==1)
                {
                    goto rum;
                }
            }
			else if(operation=='c' || operation=='C')
			{
				printf("Password change process initiated\n");
				change_password(card_num);
                int d;
                printf("\nIf u wish to go through the functons again press 1 else press 0 to exit:");
                scanf("%d",&d);
                if(d==1)
                    goto rum;
                else
                    exit(1);
			}
			else if(operation=='d' || operation=='D')
			{
                printf("One moment please your request is being proccessed...\n");
				deposit(card_num);
                int d;
                printf("\nIf u wish to go through the functons again press 1 else press 0 to exit:");
                scanf("%d",&d);
                if(d==1)
                    goto rum;
                else
                    exit(1);
			}
            else
            {
                printf("Invalid input press 1 to re-try 0 to exit and 2 to return to other functions of the ATM\n");
                int x;scanf("%d",&x);
                if(x==1)
                {
                    goto rum;
                }
                else if(x==0)
                {
                    exit(1);
                }
                else if(x==2)
                {
                    goto start;
                }
            }
            
		}
        else
        {
            printf("\nInvalid password entered you might want to try again! Press 1 to try again and press 0 to exit\n");
            int d;
            scanf("%d",&d);
            if(d==1)
                goto pinr;
            else
                exit(1);
        }

	}
	else
	{
		printf("Your card number does not hold an account in here\n");
		printf("Do you want to create an account right now?\n");
		printf("Press 1 to start new acount creation \n press 0 to withdraw your card from the machine \n");
		int x=0;
		scanf("%d",&x);
		if(x)
		{
			init:;
            printf("New account creation process initiated please hold on one moment\nThank for choosing to create a bank account with us\n");
			int z=new_card_number();
			if(z)
			{
                printf("Your account is successfully created and is ready for use\n");
			    printf("To go through the features of this ATM machine please press 1 \n To withdraw the card from the machine press 0\n");
			    int y;
			    scanf("%d",&y);
			    if(y==1)
			    {
				    goto start;
			    }
                else
                    exit(2);
            }
            else
            {
                printf("\nUnfortunately Your new card initiation has failed\nIf u wish to try again press 1 else press 0 to exit:\n");
                scanf("%d",&x);
                if(x==1)
                    goto init;
                else
                    exit(0);
            }
		}
	}
}
