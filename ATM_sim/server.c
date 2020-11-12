#include<stdio.h>
void withdrawal(int ,int );
void deposit(int,int);
int search(long long int);
int check_pass(long long int cd_no);
void ministatement(long long int);
int new_card_number();
void change_password(long long int);



int check_pass(long long int cd_no)
{
    FILE *fptr;char c[1000];
    fptr = fopen("1.txt", "r");
    fscanf(fptr, "%[^\t]", c);
    int k=0;int flag=0;
	long long int srujan;int j;long int bal=0;int pin=0,l=0;
    int a;
    printf("\tPlease enter the pin number\n");
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
        for(l=j+1;c[l]!='\n';l++)
        {
            pin=(pin*10)+(c[l]-48);
        }
		if(cd_no==srujan)
			flag=1;
        if(flag==1)
            break;
        k+=(i-15);
    } 
    printf("\nPin:\n%d\n",pin);
    printf("\nBal:\n%ld\n",bal);
    printf("\ncard number:\n%lld\n",srujan);
	return(flag);
}

void main()
{
	start:;
    
	long long int card_num=0;
	printf("Hello welcome to pantanjali ATM\n ");
	printf("Please enter the card number\n");
	scanf("%lld",&card_num);
    
	if(check_pass(card_num))
        printf("sdfsf");
	/*if(search(card_num))
	{
		printf("\tAccount found \n");
		printf("Getting account details please wait.... \n\n");
		printf("\tPlease enter the pin number\n");
		int a;
		scanf("%d",a);
		if(check_pass(a,card_num))
		{
			printf("Please wait while we verify\n");
			printf("Pin accepeted\n");
			printf("Please enter \n W for withdrawal \n M for mini-statement \n C to change password \n balance enquiry\n money transfer \n deposit");
			int operation=getchar();
			if(operation==119 || operation==87)
			{
				printf("Please enter the amount to be withdrawed\n");
				int amt=0;
				scanf("%d",&amt);
				withdrawal(amt,card_num);
			}
			else if(operation==109 || operation==77)
			{
				printf("One moment please your request is being proccessed\n");
				ministatement(card_num);
			}
			else if(operation==99 || operation==67)
			{
				printf("Password change process initiated\n");
				//change_password(card_num);
			}
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
			printf("New account creation process initiated please hold on one moment\nThank for choosing to create a bank account with us\n");
			//int z=new_card_number();
			printf("Please enter a pin number for your new account\n");
			//change_password(z);
			printf("Your account is successfully created and is ready for use\n");
			printf("To go through the features of this ATM machine please press 1 \n To withdraw the card from the machine press 0\n");
			int y;
			scanf("%d",&y);
			if(y)
			{
				goto start;
			}
		}
	}*/
}
