
#include<stdio.h>
#include<stdlib.h>
#include <cstring>
#include<conio.h>


struct order
{
	char code[20];
	char name[20];
	char date[20];
	int cost;
	
}b;
struct bill
{
	int bill_no;
	char name[20];
	long phone_no;
	int total_amount,quantity;
}bi;
int price=60;
void insert_details();
void viewAll();  
void find(); 
void order_item(); 
void old_record(); 
void search_bill();
void delete_item();
 

 main(void)
 {
 	char psword[100],user[100];
	int diff,tm;
	char p[100]="vinamra18",u[100]="vinamra",ch;
	char i;int j=0;
	printf("\nENTER USERNAME ");

	gets(user);

	printf("\nENTER PASSWORD ");

	while(i!='\r')
	{
		i=getch();
		if(i!='\r')
		if(i!='\b')
		{
			psword[j]=i;
			j++;
			printf("@");
		}
	}
	psword[j]='\0';
	if(strcmp(psword,"vinamra18")==0 && strcmp(user,"vinamra")==0)
		{
 	int ch;
 	do{
	printf("\n====================================================================");
	printf("\n");
	printf("\t VINAMRA BAKERY STORE ");
	printf("\n");
	printf("\n====================================================================\n");
	printf("[1] for To Insert item\n");
	printf("[2] for ALL items\n");
	printf("[3] for Find Order name, item no.\n");
	printf("[4] for Order item\n");
	printf("[5] for Search bill\n");
	printf("[6] for search bill by bill number or name\n");
	printf("[7] for delete items \n");
	printf("\nPress <0> Exit ");
    
	printf("\nEnter your Choice ::");
   	scanf("%d",&ch); 
	switch (ch)
   	{
    		case 1 :
    		insert_details();
   		break;
		case 2:   	
		viewAll();
   		break;
    		
		case 3:
    		find();
   		break;
		
		case 4:
		order_item();
		break;
		
		case 5:
		old_record();
		break;
		
		case 6:
		search_bill();	
		break;
		
		case 7:
		delete_item();
		break;
		
	

    		case 0:
    		exit(0);
    		break;

    		default:
    		printf("Wrong choice !");
    		break;
    			}
 }while(ch!=0);

}
}



void insert_details()
{
	
	FILE *fp;
	struct order b;
	printf("Enter item code :- ");	
	scanf("%s",b.code);
	printf("Enter  name :- ");	
	scanf("%s",b.name);
	printf("Enter Manufacture Date:- ");	
	scanf("%s",b.date);
	printf("Enter Item Price:- ");	
	scanf("%d",&b.cost);
		
		
   fp=fopen("bakery.txt","a");

	if(fp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
		printf("Record insert Sucessfull");
	}
		printf("\n");
	fclose(fp);
	}
void find() 
{
	struct item_b;
	FILE *fp;
	
	char ch[20];
	printf("Enter item code :");
	scanf("%s",ch);
	fp = fopen("bakery.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
			}
	else
	{	
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,ch) == 0)
			{	
				printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\titem name ::%s",b.name);
				printf("\n\t\titem date ::%s",b.date);
				printf("\n\t\tprice of item ::%d",b.cost);
			}
		}
		}

	fclose(fp);
}
void viewAll()
{
	char ch;
	FILE *fp;

	fp = fopen("bakery.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("clear");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);
}	
void order_item()
{
	static int number=400;
 struct order b;
 struct bill bi;
    int c=0,n,t=0;
	FILE *fp;

	FILE *ufp;
	number++;
	bi.bill_no=number;
	bi.total_amount=0;
	
	char ch; 
	char item_code[20];
	
	fp = fopen("bakery.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);
		printf("\nyour name :");
	    scanf("%s",bi.name);
	    printf("\nmobile number :");
	    scanf("%d",&bi.phone_no);
	ufp=fopen("oldTransection1.txt","a");

	fprintf(ufp,"\n\nbill no.: %d \nName of customer: %s \ncontact no.: %d\n",bi.bill_no,bi.name,bi.phone_no);
	printf("\n For order item Choosee item(Enter item Code First Letter Of item)\n");
	do
	{
	
	printf("\n Enter item code :");
	scanf("%s",item_code);
	fp = fopen("bakery.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	} 
	else
	{	//total_amount = b.cost * total_price;
	
	printf("\n ENJOY FOOD \n");

		while(getc(fp) != EOF)
		{
			c=0;
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,item_code) == 0)
				{	
				c=1;
				printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\titem name ::%s",b.name);
				printf("\n\t\tdate name ::%s",b.date);
				printf("\n\t\tPrice of item::%d",b.cost);
				
				printf("\n* Fill Deatails  *");
	            printf("\n Total number of items :");
	            scanf("%d",&bi.quantity);
	            
	            bi.total_amount = b.cost * bi.quantity;
	            t=bi.total_amount+t;
	            printf("your total amount is %d",bi.total_amount);
	
	            
	            if(ufp == NULL)
	            {
	             	printf("FIle not Found");
             	}
            	else
               	{
	            	fprintf(ufp,"quantity: %d ,item: %s ,MRP: %d , total: %d\n",bi.quantity,b.name,b.cost,bi.total_amount);
	              
	            }
	    	printf("\n");
	        fclose(fp);

			   }
			
		}
		if(c==0)
		printf("\ninvalid item code\n");
	}
	printf("press 1 for continue\n");
	scanf("%d",&n);
}while(n==1);
fprintf(ufp,"total amount to be paid %d",t);
	printf("\n Record insert Sucessfull to the old record file");
	fclose(ufp);
	
}
void old_record()
{
	char ch;
	FILE *fp;	
	fp = fopen("oldTransection1.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("clear");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);


}
void search_bill()
{
	struct bill bi;
	struct order b;
	int bill_no;
    	char ch;
    	int c1=0;
	FILE *fp;
	char name[20];

	fp = fopen("oldTransection1.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		
		printf("\nenter the bill no.");
		scanf("%d",&bill_no);
		
		while( ( ch = fgetc(fp) ) != EOF )
		    {
		    	fscanf(fp,"%d %s %d %d %s %d %d",&bi.bill_no,bi.name,&bi.phone_no,&bi.quantity,b.name,&b.cost,&bi.total_amount);
		    	if(bill_no==bi.bill_no)
		    	
		    	    while(!bill_no)
		    	    {
		    		c1=1;
		    		printf("\ncustomer_name:%s\n",bi.name);
		    		printf("bill_no.:%d\n",bi.bill_no);
		    		printf("contact_no:%d\n",bi.phone_no);
		    		printf("\nno. of items:%d",bi.quantity);
		    		printf("\nitem:%d",b.name);
		    		printf("\nMRP:%d",b.cost);
		    		printf("\ntotal price:%d",bi.total_amount);
		    		
		    		
		    		
				}
		    	
			}
			if(c1==0)
			{
				printf("no such bill");
			}
		
	}
	fclose(fp);
}
void add_item()
{
	char ch;
	FILE *ptr_file;
		int x;

		ptr_file =fopen("bakery.txt", "w+");

		if (!ptr_file)
			

		for (x=1; x<=10; x++)
			fprintf(ptr_file,"%d\n", x);

		fclose(ptr_file);

}
void delete_item()
{
	struct order b;
	int n=1;
	FILE *fp,*fp1;
	char k[20];
	
	
printf("Enter item code:");
puts(k);

fp=fopen("bakery.txt","r");
fp1=fopen("bakery1.txt","a");

while(!feof(fp))
{
	fscanf(fp,"%s %s %s %d \n",b.code,b.name,b.date,&b.cost);
	if(b.code!=k)
	{
		n=0;
		fprintf(fp1,"%s %s %s %d \n",b.code,b.name,b.date,&b.cost);
	}
	else 
	continue;
}
if(n==1)
printf("\nInvalid item code");
fclose(fp);
fclose(fp1);
remove("bakery.txt");
rename("bakery1.txt","bakery.txt");
}


