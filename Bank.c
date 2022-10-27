#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Menu();
struct date{
int day,month,year;
};
struct Account{
 char name[50],phone[12],acc_num[20],acc_type[10],address[200];
 int age;
 float amount;
 struct date dob;
 struct date deposit;
 struct date withdraw;
 }add,update,check,remov,transaction;
 
//For BOLD just replace the initial 0 before the ; with a 1. BOLD green would be\033[1;32m
void black () {
  printf("\033[1;30m");     //  Escape is: \033
}                           // Color Code is: [0;30m

void red() {
  printf("\033[1;31m");
}

void green() {
  printf("\033[1;32m");
}

void yellow() {
  printf("\033[1;33m");
}

void blue() {
  printf("\033[1;34m");
}

void purple() {
  printf("\033[1;35m");
}

void cyan() {
  printf("\033[1;36m");
}

void reset () {
  printf("\033[0m");           //Resets the text to defaults
}
void fordelay(int n)
{
  int k;
  for(int i=0;i<n;i++)k=i;
}

void Exit(){
system("clear");
green();
printf("\n\t\t\tThanks for using Bank System developed by Teja!!!!....\n");
fordelay(900000000);
}
void Create_New_account(){
   
    FILE *f=fopen("account_details.dat","a+");
            system("clear");
             purple();
	     printf("\n\t\t\tAdd Customer Account Details\n");
	      cyan(); printf("\n\t\t\tEnter the account number:"); reset();
	      scanf("%s",add.acc_num);
	      //if(strlen(add.acc_num)==0){red(); printf("\t\t\tPlease Enter Valid Account Number"); reset(); goto new_account;}
  while(fscanf(f,"%s %d %s %s %s %s %d/%d/%d %f",check.name,&check.age,check.phone,check.acc_num,check.acc_type,check.address,&check.dob.day,&check.dob.month,&check.dob.year,&check.amount)!=EOF){
        if(strcmp(check.acc_num,add.acc_num)==0){
         printf("\t\t\tPlease enter New Account Number");
         fordelay(100000000);
         Create_New_account();
         }
   }

cyan();     printf("\n\t\t\tEnter Customer's name:"); reset();
	    scanf("%s",add.name);
cyan();	    printf("\n\t\t\tEnter Customer's age:"); reset();
	    scanf("%d",&add.age);
cyan();	    printf("\n\t\t\tEnter Customer's Phone number:"); reset();
	    scanf("%s",add.phone);
cyan();	    printf("\n\tType of account:\n\t\t\t#Saving\n\t\t\t#Current\n\t\t\t#Fixed1(for 1 year)\n\t\t\t#Fixed2(for 2 years)\n\t\t\t#Fixed3(for 3 years)\n\n\t\t\tEnter your choice:");  reset();
	    scanf("%s",add.acc_type);
cyan();	    printf("\n\t\t\tEnter Valid address:");  reset();
	    scanf("%s",add.address);
cyan();	    printf("\n\t\t\tEnter Amount:"); reset();
	    scanf("%f",&add.amount);
cyan();	    printf("\n\t\t\tEnter the today's date (dd/mm/yyyy):");   reset();
	    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    
    fprintf(f,"%s %d %s %s %s %s %d/%d/%d %f\n",add.name,add.age,add.phone,add.acc_num,add.acc_type,add.address,add.dob.day,add.dob.month,add.dob.year,add.amount);
      fclose(f);
      green();
      printf("\t\t\tAccount Details Inserted Successfully\n");
      fordelay(100000000);
     returning:
          blue();
          printf("\n\t\t\tPress 1 for the Menu........\n\t\t\tPress 0 to exit the Menu:");
          int n;
          scanf("%d",&n);
          system("clear");
          if(n==1){
            fordelay(90000000);
            Menu();
            }
          else if(n==0){
             blue();
             Exit();
             fordelay(900000000);
             return;
             }
             
          else {
          red();
           printf("\t\t\tInvalid Option!!!\n");
           fordelay(900000000);
           goto returning;
           }
   }
   
void Edit_account(){
   int choice,test=0;
   FILE *old=fopen("account_details.dat","r");
   FILE *new=fopen("new.dat","w");
   green();
   printf("\n\t\t\t\tWelcome the Edit Page\n");
   purple();
   printf("\n\t\t\tEnter the Customer account number to edit:");     reset();
   scanf("%s",update.acc_num);
   while(fscanf(old,"%s %d %s %s %s %s %d/%d/%d %f\n",add.name,&add.age,add.phone,add.acc_num,add.acc_type,add.address,&add.dob.day,&add.dob.month,&add.dob.year,&add.amount)!=EOF){
        if(strcmp(add.acc_num,update.acc_num)==0)
        {
		  test=1;
		  edit:
		   yellow();
		   printf("\n\t\t\tWhich information do you want to change?\n\t\t\t1.Address\n\t\t\t2.Phone\n\n\t\t\tEnter your choice(1 for address and 2 for phone):");         reset();
		   scanf("%d",&choice);
		   fordelay(1000000);
		   if(choice==1)
		   {
		    cyan();
		    printf("\n\t\t\tEnter the New address:");        reset();
		     scanf("%s",update.address);
		      fprintf(new,"%s %d %s %s %s %s %d/%d/%d %f\n",add.name,add.age,add.phone,add.acc_num,add.acc_type,update.address,add.dob.day,add.dob.month,add.dob.year,add.amount);
		      system("clear");
		      green();
		      printf("\t\t\tAddress Updated Successfully!\n");
		      fordelay(10000000);   
		   }
		    else if(choice==2)
		   {
		    blue();
		     printf("\n\t\t\tEnter the New Phone Number:");         reset();
		     scanf("%s",update.phone);
		      fprintf(new,"%s %d %s %s %s %s %d/%d/%d %f\n",add.name,add.age,update.phone,add.acc_num,add.acc_type,add.address,add.dob.day,add.dob.month,add.dob.year,add.amount);
		      system("clear");
		      green();
		      printf("\t\t\tPhone number Updated Successfully!\n");  
		      fordelay(900000000); 
		   }
		   else{
		   red();
		     printf("\t\t\tEnter valid option!!!..\n");
		     fordelay(10000000);
		     system("clear");
		     goto edit;
		  }
		}
          else
              fprintf(new,"%s %d %s %s %s %s %d/%d/%d %f\n",add.name,add.age,add.phone,add.acc_num,add.acc_type,add.address,add.dob.day,add.dob.month,add.dob.year,add.amount);
         }
         
           
fclose(old);
fclose(new);
remove("account_details.dat");
rename("new.dat","account_details.dat");

 if(test!=1){
          system("clear");
          red();
          printf("\n\t\t\t\tNo Record Found");
          cyan();
         chance:
          printf("\n\t\t\tEnter 1 for try again\tEnter 2 for the Menu Page\t Enter 0 to exit the page\t\n");
          green();
          printf("\t\t\tEnter the your choice:");                reset();
          scanf("%d",&choice);
          fordelay(10000000);
          system("clear");
          if(choice==1)Edit_account();
          else if(choice==2)Menu();
          else if(choice==0){red(); Exit(); fordelay(100000000); return ;}
          else {
          printf("Enter valid option!!!!");
          goto chance;
        }
      }
      
else{
     yellow();
     printf("\t\t\tEnter 1 to go for Menu Page, 0 to exit:");          reset();
     scanf("%d",&choice);
     fordelay(1000000);
     if(choice==1)Menu();
     else return;}

}
void View_all_accounts(){
  FILE *view=fopen("account_details.dat","r+");
  int c=0;
  green();
  printf("\t\t\tAll Account Details:\n");
  purple();
  printf("\n\tName\tAge\tPhone\t\tAccount Number\tAccount Type\t Address\t\tAmount\n");
  while(fscanf(view,"%s %d %s %s %s %s %d/%d/%d %f\n",add.name,&add.age,add.phone,add.acc_num,add.acc_type,add.address,&add.dob.day,&add.dob.month,&add.dob.year,&add.amount)!=EOF){
      yellow();
      printf("\n\t%s\t%d\t%s\t%s\t%s\t\t%s\t\t%f",add.name,add.age,add.phone,add.acc_num,add.acc_type,add.address,add.amount);
    c++;
    }
    fclose(view);
    
    if(c==0){
      red();
      printf("\t\t\tNo Records Found!!!1..............");
      fordelay(100000);
      }
    returning:
          blue();
          printf("\n\t\t\tPress 1 for the Menu........\n\t\t\tPress 0 to exit the Menu:");       reset();
          int n;
          scanf("%d",&n);
          system("clear");
          if(n==1){
            fordelay(90000000);
            Menu();
            }
          else if(n==0){
             blue();
             Exit();
             fordelay(90000000);
             return;
             }
             
          else {
          red();
           printf("\t\t\tInvalid Option!!!\n");
           fordelay(90000000);
           goto returning;
           }
     
  
}
void Pay_account(){
int choice,t1=0,t2=0;
float amt;
   FILE *old=fopen("account_details.dat","r");
   FILE *new=fopen("new.dat","w");
   purple();
   printf("\n\t\t\tEnter the Customer account number to be pay:");    reset();
   scanf("%s",transaction.acc_num);
   yellow();
   printf("\n\t\t\tEnter your account number:");                       reset();
   scanf("%s",check.acc_num);
   blue();
   printf("\n\t\t\tEnter the amount to pay:");                       reset();
   scanf("%f",&amt);
   fordelay(10000000);
   system("clear");
   while(fscanf(old,"%s %d %s %s %s %s %d/%d/%d %f\n",add.name,&add.age,add.phone,add.acc_num,add.acc_type,add.address,&add.dob.day,&add.dob.month,&add.dob.year,&add.amount)!=EOF){
        if(strcmp(add.acc_num,check.acc_num)==0)    
        {
          t1=1;
             fprintf(new,"%s %d %s %s %s %s %d/%d/%d %f\n",add.name,add.age,add.phone,add.acc_num,add.acc_type,add.address,add.dob.day,add.dob.month,add.dob.year,add.amount-amt);
         }
         else
          fprintf(new,"%s %d %s %s %s %s %d/%d/%d %f\n",add.name,add.age,add.phone,add.acc_num,add.acc_type,add.address,add.dob.day,add.dob.month,add.dob.year,add.amount);
         }
           
           
fclose(old);
fclose(new);
remove("account_details.dat");
rename("new.dat","account_details.dat");

          old=fopen("account_details.dat","r");
         new=fopen("new.dat","w");
         
         while(fscanf(old,"%s %d %s %s %s %s %d/%d/%d %f\n",add.name,&add.age,add.phone,add.acc_num,add.acc_type,add.address,&add.dob.day,&add.dob.month,&add.dob.year,&add.amount)!=EOF){
        if(strcmp(add.acc_num,transaction.acc_num)==0)    
        {
          t2=1;
             fprintf(new,"%s %d %s %s %s %s %d/%d/%d %f\n",add.name,add.age,add.phone,add.acc_num,add.acc_type,add.address,add.dob.day,add.dob.month,add.dob.year,add.amount+amt);
         }
         else
          fprintf(new,"%s %d %s %s %s %s %d/%d/%d %f\n",add.name,add.age,add.phone,add.acc_num,add.acc_type,add.address,add.dob.day,add.dob.month,add.dob.year,add.amount);
         }

fclose(old);
fclose(new);
remove("account_details.dat");
rename("new.dat","account_details.dat");

 if(t2!=1&&t1!=1){
          system("clear");
          red();
          printf("\n\t\t\t\tNo Record Found!! Please Enter Customer Account Correct");
          cyan();
         chance:
          printf("\n\t\t\tEnter 1 for try again\tEnter 2 for the Menu Page\t Enter 0 to exit the page\t\n");
          green();
          printf("\t\t\tEnter the your choice:");             reset();
          scanf("%d",&choice);
          fordelay(10000000);
          system("clear");
          if(choice==1)Pay_account();
          else if(choice==2)Menu();
          else if(choice==0){red(); Exit(); fordelay(100000000); return ;}
          else {
          printf("Enter valid option!!!!");
          fordelay(100000000);
          goto chance;
        }
      }
      
else{
     green();
     printf("\n\t\t\tAmount Transfered Successfully!!!!!\n");
      yellow();
     printf("\n\t\t\tEnter 1 to go for Menu Page, 0 to exit:");         reset();
     scanf("%d",&choice);
     fordelay(1000000);
     if(choice==1)Menu();
     else Exit();}
}
void Transaction_History(){}
void Removing_Existing_Account(){
 int choice,test=0;
   FILE *old=fopen("account_details.dat","r");
   FILE *new=fopen("new.dat","w");
   green();
   printf("\n\t\t\tEnter the Customer account number to delete:");        reset();
   scanf("%s",remov.acc_num);
   while(fscanf(old,"%s %d %s %s %s %s %d/%d/%d %f\n",add.name,&add.age,add.phone,add.acc_num,add.acc_type,add.address,&add.dob.day,&add.dob.month,&add.dob.year,&add.amount)!=EOF){
        if(strcmp(add.acc_num,remov.acc_num)==0)
        {
            test=1;
            red();
            printf("\n\t\t\tAccount Deleted Successfully!!!!");
            fordelay(100000000);
	}
          else
              fprintf(new,"%s %d %s %s %s %s %d/%d/%d %f\n",add.name,add.age,add.phone,add.acc_num,add.acc_type,add.address,add.dob.day,add.dob.month,add.dob.year,add.amount);
         }
         
           
fclose(old);
fclose(new);
remove("account_details.dat");
rename("new.dat","account_details.dat");

 if(test!=1){
          system("clear");
          red();
          printf("\n\t\t\t\tNo Record Found!!");
          cyan();
         chance:
          printf("\n\t\t\tEnter 1 for try again\tEnter 2 for the Menu Page\t Enter 0 to exit the page\t\n");    
          green();
          printf("\t\t\tEnter the your choice:");           reset();
          scanf("%d",&choice);
          fordelay(10000000);
          system("clear");
          if(choice==1)Removing_Existing_Account();
          else if(choice==2)Menu();
          else if(choice==0){red(); Exit(); fordelay(100000000); return ;}
          else {
          printf("Enter valid option!!!!");
          fordelay(100000000);
          goto chance;
        }
      }
      
else{
     yellow();
     printf("\n\t\t\tEnter 1 to go for Menu Page, 0 to exit:");       reset();
     scanf("%d",&choice);
     fordelay(1000000);
     if(choice==1)Menu();
     else return;}

}
void Menu()
{
    int choice;
    system("clear");
    purple();
    printf("\n\n\t\t\t\tChoose the options\t\t\t\t\n");
    cyan();
    printf("\n1. Create New Account.\t\t\t\n2. Edit Your Account Details\t\t\t\n3. View Your All Account Details\t\t\t\n4. Pay Amount\t\t\t\n5. Remove Existing Account\t\t\t\n6. Exit");
    yellow();
    printf("\nEnter Your Options:");
    reset();
    scanf("%d",&choice);
    system("clear");
    switch(choice){
    case 1: Create_New_account();
             break;
            
    case 2: Edit_account();
             break;
    
    case 3: View_all_accounts();
             break;
             
    case 4: Pay_account();
            break;
             
    //case 4: Transaction_History();
      //       break;
             
    case 5: Removing_Existing_Account();
             break;
             
    case 6:Exit();
           break;
             }
    
}  
int main() 
{
    int i;
    char pass[20],password[20]="123456";
    system("clear");
    yellow();
    printf("\t\t\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
    for(i=0;i<5;i++)
    {
      printf("\t\t\t|");
      if(i==2){ printf("\t\tWelcome to the Bank Management System\t\t|\n"); green();}
      else printf("\t\t\t\t\t\t\t\t|\n");
    }
     printf("\t\t\t| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |\n");
     blue();
     printf("\n\t\t\tEnter your Security Pin Code:");
     reset();
    scanf("%s",pass);
    if(strcmp(pass,password)==0)
    {
       green();
       printf("\t\t\tPassword Matches!!");
       for(i=0;i<19;i++)
       {
          fordelay(9000000);
          printf(".");                   
       }  
        Menu();  
        system("clear");
    }
    else
    {
         red();
         printf("\t\t\t........Invalid Password!........\n\t\t\tPlease Enter Valid Pin Code\t\t\n");
         login_try:
           cyan();
           printf("\t\t\tPlease press 1 to Re-enter into the login................\t\t\t\n\t\t\tEnter 0 to exit the page\n");
           int n;
           printf("\t\t\tEnter the Number:");   reset();
           scanf("%d",&n);
           if(n==1)
           { 
             green();
             printf("\t\t\tRedirecting to main page");
             fordelay(90000000);
             for(i=0;i<19;i++)
             {
                fordelay(90000000);
                printf(".");   
             }
               printf("\n");
               system("clear");
               main();
           }
           
           else if(n==0)
           {
              purple();
              printf("\t\t\tExisting the page"); 
              Exit();
               fordelay(20000000);
                for(i=0;i<19;i++)
                {
                   fordelay(20000000);
                   printf(".");  
                }
                 printf("\n");
                  return 0;
           }
           
           else {
                red();
                printf("\t\t\t!!!!!!!!Invalid!!!!!!!!!!\n");
                fordelay(1000000000);
                system("clear");
                reset();
                goto login_try;
                }      
       }           
    return 0;
}
