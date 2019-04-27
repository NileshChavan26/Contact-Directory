#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
struct node
{
  struct node *link;
  long float phone;
  char name[20],addr[20];
} *header='\0';


void insertc(long float ph,char *namec,char *add)
{  int i;
   struct node *n,*p,*q;
   n=(struct node *)malloc(sizeof(struct node));
   n->phone=ph;
   for(i=0;i<20;i++)
    {
      n->name[i]=namec[i];
      n->addr[i]=add[i];
    }
      n->link ='\0';
   if(header=='\0')
   {
      header=n;
      return;
   }
   q='\0';
   p=header;
   while(p!='\0')
   {
      if(p->phone==ph)
      {
       printf("\n****SAME NUMBER IS ALREADY EXIST PLZ CHECK AGAIN****");
       return;
      }
      p=p->link;
   }
   p=header;
   if(strcmp(p->name,n->name)>0)
   {
     n->link=header;
     header=n;
     return;
   }

   if(strcmp(p->name,n->name)<=0)
   {
     while(strcmp(p->name,n->name)<=0)
     {
       q=p;
       if(p->link!='\0')
       {
	p=p->link;
       }
       else
       {
	break;
       }
     }
     if(q->link!='\0')
     {
       n->link=q->link;
       q->link=n;
     }
     else
     {
      q->link=n;
     }
   }
}

void deletec(char *namec)
{
  struct node *p,*q;
  if(header=='\0')
  {
    printf("\n*****NO CONTACTS FOR DELETE*****");
    return;
  }
  q='\0';
  p=header;
  if(strcmp(p->name,namec)==0)
  {
     header=p->link;
     printf("\n*****Contact %s is deleted*****",p->name);
     return;
  }
  while(p!='\0')
  {
    if(strcmp(p->name,namec)==0)
    {
      q->link=p->link;
      printf("\n*****Contact %s is Deleted*****",p->name);
      return;
    }
    q=p;
    p=p->link;
  }
  printf("\n******Such contact not found******");
}

void searchname(char names[])
{
  struct node *p;
  if(header=='\0')
  {
    printf("\t\t*****NO CONTACTS AVAILABLE*****");
    return;
  }
  p=header;
  if(strcmp(p->name,names)==0)
  {
	 printf("\n**********************\nName--> %s",p->name);
	 printf("\nPhone no--> %.lf",p->phone);
	 printf("\nAddress--> %s\n**********************",p->addr);
	 return;
  }

  while(p!='\0')
  {
       if(strcmp(p->name,names)==0)
       {
	 printf("\n**********************\nName--> %s",p->name);
	 printf("\nPhone no--> %.lf",p->phone);
	 printf("\nAddress--> %s\n**********************",p->addr);
	 return;
       }
       p=p->link;

  }
  printf("***** NO match found *****");
}

void searchno(long float num)
{
  struct node *p;
  if(header=='\0')
  {
    printf("\t\t*****NO CONTACTS AVAILABLE*****");
    return;
  }
  p=header;
  if(p->phone==num)
  {
	printf("\n**********************\nName--> %s",p->name);
	 printf("\nPhone no--> %.lf",p->phone);
	 printf("\nAddress--> %s\n**********************",p->addr);
	 return;
  }

  while(p!='\0')
  {
       if(p->phone==num)
       {
	 printf("\n*********************\nName--> %s",p->name);
	 printf("\nPhone no--> %.lf",p->phone);
	 printf("\nAddress--> %s\n*********************",p->addr);
	 return;
       }
       p=p->link;
  }
  printf("***** NO match found *****");
}

void traversec()
{
  struct node *p;
  if(header=='\0')
  {
    printf("\n************No Contacts Available************");
    return;
  }
  printf("\n\n\t\t*******************************\n\t\t\tLIST OF CONTACTS\n\t\t*******************************");
  printf("\n\nNAME\t\tPHONE NO\t\tADDRESS\n");
  p=header;
  while(p!='\0')
  {
    printf("\n%s\t\t%.lf\t\t%s",p->name,p->phone,p->addr);
    p=p->link;
  }
}


void main()
{
    int ch,i,n,ch2;
    char namec[20],address[20];

   long float ph;
    clrscr();
    printf("******************WELCOME TO PHONEBOOK******************");
    do
    {
     printf("\n\n=======================\n[1] Add a contact\n[2] Delete a contact\n[3] Search for contact\n[4] List all contact\n=======================\nEnter your choice--> ");
     scanf("%d",&ch);

     switch(ch)
     {
      case 1:printf("\nEnter the name--> ");
	     scanf("%s", namec);
	     printf("Enter the number--> ");
	     scanf("%lf", &ph);
	     printf("Enter the address--> ");
	     scanf("%s",address);
	     insertc(ph,namec,address);
	     break;
      case 2:printf("\nEnter the name want to delete-->");
	     scanf("%s",namec);
	     deletec(namec);
	     break;

      case 3:printf("\n[1] Search by Name\n[2] search by Number\nEnter your choice--> ");
	     scanf("%d",&ch2);
	      switch(ch2)
	      {
		case 1:printf("Enter the name\n");
		       scanf("%s",namec);
		       searchname(namec);
		       break;

		case 2:printf("Enter the number\n");
		       scanf("%lf", &ph);
		       searchno(ph);
	      }
	      break;
      case 4: traversec();
	       break;

      default: printf("\nInvalid choice");

     }
     printf("\n\n*NOTE::-Do u want to do any task press 1 to continue AND ANY KEY for exit--> ");
     scanf("%d",&n);
    }while(n==1);
}