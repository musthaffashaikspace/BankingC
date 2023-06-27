#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
const int PROJECT_PASS=786;
struct accounts{
	char name[40];
	char fath_name[40];
	char moth_name[40];
	char last_name[40];
	char address[100];
	int age;
	int acc_pass;
	int ATM_pin;
	long long int balance;
	long long int fd;
	long long int pay_due;
};
struct accounts look[10]={
		{"Rajesh","Ramesh","Kumari","Menon","105 Shanti nagar Bangalore",32,9899,7865,10000,1200000,0},
		{"Shankar","Rahul","Shivani","Kumar","Samatanagar Bangalore",23,6543,8765,11000,1100000,0},
		{"Mohommed","Javed","Sana","Shaik","Opposite Apollo Hospital Bangalore",45,6432,1232,7000,700000,0},
		{"Rakesh","Roshan","Geeta","Singh","Gokul Society 115 Bangalore",29,8876,8754,8000,1300000,0},
};
void new_account(int i);
void project_password(void);
int exist_account(int m);
void ATM(int y);
void loan(int g);
void fixed_depo(int r);
void accountinfo(int t);
int main(void)
{
	project_password();
	int n=4,b,opt1;
	char ch;
	printf("\t\tPlease choose from the following\n");
	printf("\t\t1.New Account\t\t2.Existing Account\n\t\t3.Account Info\t\t4.(Q to quit)\n");
	while(scanf("%d",&opt1)==1)
	{
		switch(opt1){
			case(1): new_account(n);
					   n++;
					   break;
			case(2): b=exist_account(n);
					   break;
			case(3): accountinfo(b);
					   break;
			default : printf("Choose a valid option\n");
					  break;
		}
		printf("\n\t\tPlease choose from the following\n");
		printf("\t\t1.New Account\t2.Existing Account\n\t\t3.Account Info\t4.(Q to quit)\n");
		getchar();
	}
}
void project_password(void)
{
	int pass;
	int i=0;
	printf("\n\n\n\n\n\n\n\n\t\t\t");
	while(i<50)
	{
		printf("-");
		i++;
	}
	printf("\n");
	printf("\t\t\t|\t\t\t\t\t\t |\n");
	printf("\t\t\t|\t*WELCOME TO STATE BANK OF BIT*\t\t |\n");
	printf("\t\t\t|\t\t\t\t\t\t |\n");
	printf("\t\t\t|\t*-Please enter password to continue-*\t |\n");
	printf("\t\t\t|\t\t");
	while((scanf("%d",&pass))==1)
	{
		int i=0;
		if(pass==PROJECT_PASS)
		{
			printf("\t\t\t|\t\t\t\t\t\t |\n");
			printf("\t\t\t");
			while(i++<50)
				putchar('-');
			break;
			
		}
		else
		{
			printf("\t\t\t|\tPlease type a valid password\t\t | \n");
			printf("\t\t\t|\t\t");
			continue;
		}
	}
	getchar();
	getchar();
	system("cls");
	return;
}
void new_account(int i)
{
	getchar();
	int k=0;
	printf("Please type your name:");
	gets(look[i].name);
	printf("\nPlease type your father\'s name:");
	gets(look[i].fath_name);
	printf("\nPlease type your mother\'s name:");
	gets(look[i].moth_name);
	printf("\nPlease type your last name:");
	gets(look[i].last_name);
	printf("\nPlease type your adress:");
	gets(look[i].address);
	printf("\nPlease type your age:");
	scanf("%d",&look[i].age);
	printf("\nPlease set an account password:");
	scanf("%d",&look[i].acc_pass);
	printf("\nPlease set an ATM pin: ");
	scanf("%d",&look[i].ATM_pin);
	printf("\nPlease deposit some amount of money: ");
	while(scanf("%ld",&look[i].balance)==1)
	{
		if((look[i].balance)<=5000)
			printf("\nPlease deposit above $5000");
		else
			break;
	}
	printf("\nPlease deposit FD amount (0 to quit)");
	scanf("%lld",&look[i].fd);
	printf("\nACCOUNT CREATED!!!");
	
}
int exist_account(int m)
{
	getchar();
	char usern[40];
	int u=0,pass,found,ch;
	printf("\nPlease type your username:");
	gets(usern);
	while(u<m)
	{
		if((strcmp(usern,look[u].name))!=0)
		{
			u++;
			found=0;
		}
		else
		{
			printf("\nPASSWORD:");
			found=1;
			while((scanf("%d",&pass))==1)
			{
				if(pass!=look[u].acc_pass)
				{
					printf("\nPlease type a valid account password");
					continue;
				}
				else
					break;
			}
			break;
			
		}
	}
	if(found==0)
	{
		printf("\nAccount was not found\n");
		exit(0);
	}
	printf("\nPlease provide an option to choose from\n");
	printf("1.Loan\t2.FD\t3.ATM\t'4.q' to quiut\n");
	while((scanf("%d",&ch))==1)
	{
		switch(ch)
		{
			case(1): loan(u);
					   break;
			case(2): fixed_depo(u);
					   break;
			case(3): ATM(u);
					   break;
		}
		printf("\nPlease provide an option to choose from\n");
		printf("1.Loan\t2.FD\t3.ATM\t'4.q' to quiut\n");
	}
	return u;
}
void ATM(int y)
{
	long int num;
	int pin,opt;
	char ch,c;
	printf("Type your ATM pin:");
	scanf("%d",&pin);
	if(pin!=look[y].ATM_pin)
	{
		printf("\nIncorrect password!!!\n");
		exit(0);
	}
	printf("\nChoose from options below:\n");
	printf("1.Deposit\t2.Withdraw\t3. Change ATM pin\t4.Balance Enquiry(q to quit)");
	while((scanf("%d",&opt))==1)
	{
		switch(opt)
		{
			case(1):printf("\nType the amount you want to deposit\n");
					  scanf("%d",&num);
					  if(num>10000)
					  	break;
					  look[y].balance+=num;
					  break;
			case(2):printf("\nType the amount you want to withdraw\n");
					  scanf("%d",&num);
					  if(num>5000)
					  	break;
					  look[y].balance-=num;
					  break;
			case(3):printf("\nType your new pin\n");
					  scanf("%d",&look[y].ATM_pin);
					  break;
			case(4):printf("\nBalance:%d",look[y].balance);
					  break;
			default :printf("\nChoose valid option\n");
					 break;
		}
		printf("\nChoose from options below:\n");
		printf("1.Deposit\t2.Withdraw\t3. Change ATM pin\t4.Balance Enquiry(q to quit)");
	}
}
void loan(int g)
{
	long long int erase;
	long long int loan_amt;
	printf("\nHow much loan do you want\n");
	scanf("%lld",&loan_amt);
	if(loan_amt>look[g].fd)
	{
		printf("Loan greater than FD amount-not possible\n");
		return;
	}
	printf("\nOur bank has interest rate of 12percent per anum:");
	look[g].pay_due=loan_amt+(0.12*loan_amt);
	printf("\nYou have to pay %.3f per month\n",(loan_amt*0.12)/12);
	printf("\n Type amount if you want to erase some part of loan now 0 to exit\n");
	scanf("%d",&erase);
	look[g].pay_due-=erase;
	return;
}
void fixed_depo(int r)
{
	int k;
	int u;
	long long int result,tnk;
	printf("Type the time in year of fixed deposit\n");
	scanf("%d",&k);
	printf("Type in the current year of fixed deposit\n");
	scanf("%d",&u);
	tnk=look[r].fd;
	while(u<k)
	{
		look[r].fd+=((10-u)/10)*look[r].fd;
		u++;
	}
	result=look[r].fd;
	look[r].fd=tnk;
	printf("\nYou will get %lld at the end of your term\n",result);
}
void accountinfo(int t)
{
	getchar();
	printf("Name:%s\n\nFathers name:%s\n\nMothers Name:%s\n\nAddress:%s\nBalance:%lld\nFD:%lld\nLoan Due Payment:%lld\n",look[t].name,look[t].fath_name,
	look[t].moth_name,look[t].address,look[t].balance,look[t].fd,look[t].pay_due);
	return;
}
