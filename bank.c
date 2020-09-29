#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
int i,j;
int main_exit;
void menu();
void close();

struct date{
	int month,date,year;
};
struct{
	char name[50];
	int accno,age;
	char address[60];
	char citizenship[15];
	double phone;
	char acc_type[10];
	float amt;
	struct date dob;
	struct date deposite;
	struct date withdraw;
	
}add,upd,check,rem,transaction;

float interest (float t,float amount ,int rate){
	float si;
	si=(rate*t*amount)/100.0;
	return si;
}

void new(){
	int choice;
	FILE *ptr;
	ptr=fopen("record.dat","w");
	fclose(ptr);
	ptr=fopen("record.dat","a+");
	acc_no:
	system("cls");
	printf("\t\t\t\n ADD RECORD ");
	printf("\n\n Enter Date (mm/dd/yy): ");
	scanf("%d/%d/%d",&add.deposite.month,&add.deposite.date,&add.deposite.year);
	printf("\n\n Enter Account no : ");
	scanf("%d/%d/%d",&check.accno);
	while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",&add.accno,add.name,&add.dob.month,&add.dob.date,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposite.month,&add.deposite.date,&add.deposite.year)!=EOF)
	{
		if(check.accno==add.accno){
			printf("already accouunt in use ");
			sleep(3);
			goto acc_no;
		}
	}
	add.accno=check.accno;
	printf("\n\n Enter the name : ");
	scanf("%s",add.name);
		printf("\n\n Enter Date of birth (mm/dd/yy): ");
	scanf("%d/%d/%d",&add.dob.month,&add.dob.date,&add.dob.year);
		printf("\n\n Enter age : ");
	scanf("%d",&add.age);
		printf("\n\n Enter address : ");
	scanf("%s",add.address);
		printf("\n\n Enter citizenship : ");
	scanf("%s",add.citizenship);
		printf("\n\n Enter phone no : ");
	scanf("%lf",&add.phone);
		printf("\n\n Enter amount to deposite: ");
	scanf("%f",&add.amt);
	printf("\n\n enter type of account \n # saving \n#.current \n#fix(for 1 year)");
	scanf("%S",add.acc_type);
	fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",&add.accno,add.name,&add.dob.month,&add.dob.date,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposite.month,&add.deposite.date,&add.deposite.year);
	
	fclose(ptr);
	
	printf("\n\n\nselect 1 for menu 0 for exit :");
	scanf("%d",&choice);
	check:
	if(choice==1){
		menu();
	}
	else if(choice==0){
		close();
	}
	else{
		goto check;
	}
	
}

void edit(){
	
	int choice,test=0;
	FILE *old , *newone;
	old=fopen("record.dat","r");
	newone=fopen("new.dat","w");
	printf("\n Enter the account no. of the customer whose info you wnat to change :");
	scanf("%d",&upd.accno);
	
	while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",&add.accno,add.name,&add.dob.month,&add.dob.date,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposite.month,&add.deposite.date,&add.deposite.year)!=EOF)
	{
		if(upd.accno==add.accno){
			test=1;
			printf("\n\n which information do you want ot change ? \n1.address \n2.phone \n\n enter your choice : ");
			scanf("%d",&choice);
			system("cls");
			if(choice==1){
				
			}
			else if (choice==2){
				
			}
		
		}
	}
	
	
	
	
}
void trans(){
	
	
	
}
void see(){
	
}


void erase(){
	
}
void view(){
	int choice;
	
	FILE *view;
	view=fopen("record.dat","r");
	int test=0;
	system("cls");
	printf("\n ACC no. \t name \t\t\t address \t\t\tphone \n");
	
		while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d \n",&add.accno,add.name,&add.dob.month,&add.dob.date,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposite.month,&add.deposite.date,&add.deposite.year)!=EOF)
	{
			printf("\n %6d \t %s \t\t\t %s \t\t\t %.0lf \n",add.accno,add.name,add.address,add.phone);
			test++;
	}
	fclose(view);
	if(test==0){
		system("cls");
		printf("no data found");
		
	}
		printf("\n\n\nselect 1 for menu 0 for exit :");
	scanf("%d",&choice);
	check:
	if(choice==1){
		menu();
	}
	else if(choice==0){
		close();
	}
	else{
		goto check;
	}
	
}










void close(){
	printf("\n\nhere we shut down .......");
}





void menu(){
	int ch=0;
	system("cls");
	system("color 9");
	printf("\n\n welcome to the hetvi bank .....");
	
	printf("\n\n1.new account \n2.edit account \n3.transcation of money \n4.see \n5.view_list \n6.erase \n7.exit");
	printf("\n\n\n\n select your choice : ");
	scanf("%d",&ch);
	switch(ch){
		case 1 : new();break;
		case 2  : edit();break;
		case 3 : trans();break;
		case 4 :see();break;
		case 5 : view();break;
		case 6 : erase();break;
		case 7 :close();break;
	}
	
}



int main(){
	char pass[10],password[10]="hetvi";
	passs:
	printf("\n\n  Enter the passwor for bank:  ");
	scanf("%s",pass);
	
	if(strcmp(pass,password)==0)
	{
		printf("\n\n Enter in bank system successfully ....");
		for(i=0;i<6;i++){
			sleep(1);
			printf(".");
		}
			system("cls");
		menu();
	}
	
	
	else	{
		printf("\n\npassword is worng try again :");
		logic:
		printf("\n\nEnter 1 to contiune 0 for exit :");
		scanf("%d",&main_exit);
		if(main_exit==1){
			goto passs;
			
		}
		else if(main_exit==0){
			system("cls");
			close();
			
		}
		else{
			system("cls");
			goto logic;
		
		}
	}
	return 0;
	
}
