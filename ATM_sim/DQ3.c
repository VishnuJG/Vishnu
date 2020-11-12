#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX 256
#define SENTENCE 6
const char* sen1[] = {"computer","was","invented","by","charles","babbage"};
const char* sen2[] = {"john","willkins","booth","killed","abraham","lincon"};
void shuffle(char *);
void main()
{
int ip,ch,c=0;
printf("Select your choice:\n");
printf("Enter 1 for word shuffling game\n");
printf("Enter 2 for sentence shuffling game\n");
printf("Enter 3 for paragraph shuffling game\n");
scanf("%d",&ip);
switch(ip)
{
case 1:
{
printf("You have chose to play word shuffling game\nLet's continue\n");
printf("Choose your difficulty:\nEnter 1 for easy\nEnter 2 for hard\n");
scanf("%d",&ch);
switch(ch){
case 1:
{
char a1e1[10],a1e2[10],a1e3[10];
char ew1[]="spoon",ew2[]="phone",ew3[]="bottle";
shuffle(ew1);
scanf("%s",&a1e1);
if(strcmp(a1e1,"spoon")==0)
c++;
shuffle(ew2);
scanf("%s",&a1e2);
if(strcmp(a1e2,"phone")==0)
c++;
shuffle(ew3);
scanf("%s",&a1e3);
if(strcmp(a1e3,"bottle")==0)
c++;
printf("Your score is :%d",c);
}
break;
case 2:
{
char a2e1[10],a2e2[10],a2e3[10];
char dw1[]="endodontology",dw2[]="cryptocurrency",dw3[]="communication";
shuffle(dw1);
scanf("%s",&a2e1);
if(strcmp(a2e1,"endodontology")==0)
c++;
shuffle(dw2);
scanf("%s",&a2e2);
if(strcmp(a2e2,"cryptocurrency")==0)
c++;
shuffle(dw3);
scanf("%s",&a2e3);
if(strcmp(a2e3,"communication")==0)
c++;
printf("Your score is :%d",c);
}
break;
default:{
printf("Invalid option");
break;
}}
break;}
case 2:
{
int c21,c22;
printf("You have chose to play sentence shuffling game\nLet's continue\n");
srand (time(NULL));
shufflesen1();
for (int p = 0; p < SENTENCE;p++)
printf("%s ", sen1[p]);
printf("\nThis is jumbled sentence\nGuess the correct one :D\n");
printf("1. computer was invented by charles babbage\n2.babbage computer was invented by charles\n Choose correct one\n");
scanf("%d",&c21);
if(c21==1)
printf("Correct!!!!\n");
else
printf("Wrong choice\n");
shufflesen2();
for (int p = 0; p < SENTENCE;p++)
printf("%s ", sen2[p]);
printf("\nThis is jumbled sentence\nGuess the correct one :D\n");
printf("1. willkin john lincon killed abrham booth\n2.abraham lincon killed willkin booth john\n3.john wilkin booth killed abraham lincon\n Choose correct one\n");
scanf("%d",&c22);
if(c22==3)
printf("Correct!!!!\n");
else
printf("Wrong choice\n");
break;
}
case 3:
{
printf("You have chose to play paragraph shuffling game\nLet's continue\n");
printf("Choose your difficulty:\nEnter 1 for easy\nEnter 2 for hard\n");
scanf("%d",&ch);
break;
}
default:
{
printf("Ivalid selection");
}
}
}
void shuffle(char *sBuff)
{
int i, random, length = strlen(sBuff);
char temp;
for (i = length-1; i > 0; i--)
{
random = rand()%(i+1);
temp = sBuff[random];
sBuff[random] = sBuff[i];
sBuff[i] = temp;
}
printf("%s\n",sBuff);
printf("This is jumbled word\nGuess the correct one :D\n");
}
void shufflesen1()
{
    int size = SENTENCE;
    if (size > 1)
    {
        int i;
        for (i = 0; i < size - 1; i++)
        {
        int j = rand() %SENTENCE;
        const char* temp = sen1[j];
        sen1[j] = sen1[i];
        sen1[i] = temp;
        }
    }
}
void shufflesen2()
{
    int size = SENTENCE;
    if (size > 1)
    {
        int i;
        for (i = 0; i < size - 1; i++)
        {
        int j = rand() %SENTENCE;
        const char* temp = sen2[j];
        sen2[j] = sen2[i];
        sen2[i] = temp;
        }
    }
}