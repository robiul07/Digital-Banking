//Robiul Hossen//
//Gmail:rh2885493@gmail.com


#include <stdio.h>
#include <string.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct {
    char uname[15];
    char pass[15];
    char name[15];
    char address[15];
    char contact[15];
    double balance;
}create, match, temp, check;

void CheckBalance(int bank, char username[])
{
    system("cls");
    FILE *fptr;
    switch(bank)
    {
        case 1:
            fptr = fopen("info1.txt","r");
            break;
        case 2:
            fptr = fopen("info2.txt","r");
            break;
        case 3:
            fptr = fopen("info3.txt","r");
            break;
        case 4:
            fptr = fopen("info4.txt","r");
            break;
    }

    while(fscanf(fptr, "%s %s %s %s %s %lf", &check.uname, &check.pass, &check.name, &check.address, &check.contact, &check.balance) != EOF)
    {
        if(strcmp(check.uname,username)==0)
        {
            break;
        }
    }
    printf("\n\n\t  Your current account balance is: %lf\n\n", check.balance);
    fclose(fptr);

    printf("\n\n\t1. Go to Usermenu\n\t2. Go to Bank Selection\n\t0. Exit\n\tChoice: ");
    int c; scanf("%d", &c);
    if(c==1) menu(bank, username);
    if(c==2) BankSelect();
    if(c==0) exit(0);
}

void Deposit(int bank, char username[])///Deposit
{
    system("cls");
    double amount;

    FILE *fptr, *newptr;
    switch(bank)
    {
        case 1:
            fptr = fopen("info1.txt","r+");
            break;
        case 2:
            fptr = fopen("info2.txt","r+");
            break;
        case 3:
            fptr = fopen("info3.txt","r+");
            break;
        case 4:
            fptr = fopen("info4.txt","r+");
            break;
    }
    newptr = fopen("new.txt", "w");

    while(fscanf(fptr, "%s %s %s %s %s %lf", &check.uname, &check.pass, &check.name, &check.address, &check.contact, &check.balance) != EOF)
    {
        if(strcmp(check.uname,username)==0)///Deposit
        {
            printf("\n\t  How much you want to deposit: ");
            scanf("%lf", &amount);
            check.balance += amount;
            fprintf(newptr, "%s %s %s %s %s %lf\n", check.uname, check.pass, check.name, check.address, check.contact, check.balance);
            printf("\n\n\t  Deposit done successfully.\n");
        }
        else
        {
            fprintf(newptr, "%s %s %s %s %s %lf\n", check.uname, check.pass, check.name, check.address, check.contact, check.balance);
        }
    }

    fclose(fptr);
    fclose(newptr);
    switch(bank)
    {
        case 1:
            remove("info1.txt");
            rename("new.txt","info1.txt");
        case 2:
            remove("info2.txt");
            rename("new.txt","info2.txt");
        case 3:
            remove("info3.txt");
            rename("new.txt","info3.txt");
        case 4:
            remove("info4.txt");
            rename("new.txt","info4.txt");
    }
    printf("\n\n\t1. Go to Usermenu\n\t2. Go to Bank Selection\n\t0. Exit\n\tChoice: ");
    int c; scanf("%d", &c);
    if(c==1) menu(bank, username);
    if(c==2) BankSelect();
    if(c==0) exit(0);
}

void Withdraw(int bank, char username[])///Withdraw
{
    system("cls");
    double amount;

    FILE *fptr, *newptr;
    switch(bank)
    {
        case 1:
            fptr = fopen("info1.txt","r+");
            break;
        case 2:
            fptr = fopen("info2.txt","r+");
            break;
        case 3:
            fptr = fopen("info3.txt","r+");
            break;
        case 4:
            fptr = fopen("info4.txt","r+");
            break;
    }
    newptr = fopen("new.txt", "w");

    while(fscanf(fptr, "%s %s %s %s %s %lf", &check.uname, &check.pass, &check.name, &check.address, &check.contact, &check.balance) != EOF)
    {
        if(strcmp(check.uname,username)==0)///Withdraw
        {
            printf("\n\t  How much you want to withdraw: ");
            scanf("%lf", &amount);
            if(amount<=check.balance) {
                check.balance -= amount;
                fprintf(newptr, "%s %s %s %s %s %lf\n", check.uname, check.pass, check.name, check.address, check.contact, check.balance);
                printf("\n\n\t  Withdraw done successfully.\n");
            }
            else {
                printf("\n\n\t\t\tNot enough money available in your account!\n");
                fprintf(newptr, "%s %s %s %s %s %lf\n", check.uname, check.pass, check.name, check.address, check.contact, check.balance);
            }
        }
        else
        {
            fprintf(newptr, "%s %s %s %s %s %lf\n", check.uname, check.pass, check.name, check.address, check.contact, check.balance);
        }
    }

    fclose(fptr);
    fclose(newptr);
    switch(bank)
    {
        case 1:
            remove("info1.txt");
            rename("new.txt","info1.txt");
        case 2:
            remove("info2.txt");
            rename("new.txt","info2.txt");
        case 3:
            remove("info3.txt");
            rename("new.txt","info3.txt");
        case 4:
            remove("info4.txt");
            rename("new.txt","info4.txt");
    }
    printf("\n\n\t1. Go to Usermenu\n\t2. Go to Bank Selection\n\t0. Exit\n\tChoice: ");
    int c; scanf("%d", &c);
    if(c==1) menu(bank, username);
    if(c==2) BankSelect();
    if(c==0) exit(0);
}

void Edit(int bank, char username[])///Edit
{
    system("cls");
    FILE *fptr, *newptr;
    switch(bank)
    {
        case 1:
            fptr = fopen("info1.txt","r+");
            break;
        case 2:
            fptr = fopen("info2.txt","r+");
            break;
        case 3:
            fptr = fopen("info3.txt","r+");
            break;
        case 4:
            fptr = fopen("info4.txt","r+");
            break;
    }
    newptr = fopen("new.txt", "w");

    while(fscanf(fptr, "%s %s %s %s %s %lf", &check.uname, &check.pass, &check.name, &check.address, &check.contact, &check.balance) != EOF)
    {
        if(strcmp(check.uname,username)==0)///Edit
        {
            printf("\n\tWhat to edit:\n\t1.Username\n\t2.Password\n\t3.Name\n\t4.Address\n\t5.Contact\n\n\tEnter a choice: ");
            int ch, ch2;
            scanf("%d", &ch);
            if(ch==1) {
                printf("\n\tNew username: ");
                fflush(stdin); gets(check.uname);
            }
            if(ch==2) {
                printf("\n\tNew password: ");
                fflush(stdin); gets(check.pass);
            }
            if(ch==3) {
                printf("\n\tNew Name: ");
                fflush(stdin); gets(check.name);
            }
            if(ch==4) {
                printf("\n\tNew address: ");
                fflush(stdin); gets(check.address);
            }
            if(ch==5) {
                printf("\n\tNew contact: ");
                fflush(stdin); gets(check.contact);
            }
            fprintf(newptr, "%s %s %s %s %s %lf\n", check.uname, check.pass, check.name, check.address, check.contact, check.balance);
        }
        else
        {
            fprintf(newptr, "%s %s %s %s %s %lf\n", check.uname, check.pass, check.name, check.address, check.contact, check.balance);
        }
    }

    fclose(fptr);
    fclose(newptr);
    switch(bank)
    {
        case 1:
            remove("info1.txt");
            rename("new.txt","info1.txt");
        case 2:
            remove("info2.txt");
            rename("new.txt","info2.txt");
        case 3:
            remove("info3.txt");
            rename("new.txt","info3.txt");
        case 4:
            remove("info4.txt");
            rename("new.txt","info4.txt");
    }

    printf("\n\n\t1. Go to Usermenu\n\t2. Go to Bank Selection\n\t0. Exit\n\tChoice: ");
    int c; scanf("%d", &c);
    if(c==1) menu(bank, username);
    if(c==2) BankSelect();
    if(c==0) exit(0);
}

void Delete(int bank, char username[])///Delete
{
    system("cls");
    FILE *fptr, *newptr;
    switch(bank)
    {
        case 1:
            fptr = fopen("info1.txt","r+");
            break;
        case 2:
            fptr = fopen("info2.txt","r+");
            break;
        case 3:
            fptr = fopen("info3.txt","r+");
            break;
        case 4:
            fptr = fopen("info4.txt","r+");
            break;
    }
    newptr = fopen("new.txt", "w");

    while(fscanf(fptr, "%s %s %s %s %s %lf", &check.uname, &check.pass, &check.name, &check.address, &check.contact, &check.balance) != EOF)
    {
        if(strcmp(check.uname,username)==0)///Delete
        {
            printf("\n\t Profile has been deleted.\n");
            continue;
        }
        else
        {
            fprintf(newptr, "%s %s %s %s %s %lf\n", check.uname, check.pass, check.name, check.address, check.contact, check.balance);
        }
    }

    fclose(fptr);
    fclose(newptr);
    switch(bank)
    {
        case 1:
            remove("info1.txt");
            rename("new.txt","info1.txt");
        case 2:
            remove("info2.txt");
            rename("new.txt","info2.txt");
        case 3:
            remove("info3.txt");
            rename("new.txt","info3.txt");
        case 4:
            remove("info4.txt");
            rename("new.txt","info4.txt");
    }

    printf("\n\n\t1. Go to Bank Selection\n\t0. Exit\n\tChoice: ");
    int c; scanf("%d", &c);
    if(c==1) BankSelect();
    if(c==0) exit(0);
}

void SeeProfile(int bank, char username[])
{
    system("cls");
    FILE *fptr;
    switch(bank)
    {
        case 1:
            fptr = fopen("info1.txt","r");
            break;
        case 2:
            fptr = fopen("info2.txt","r");
            break;
        case 3:
            fptr = fopen("info3.txt","r");
            break;
        case 4:
            fptr = fopen("info4.txt","r");
            break;
    }

    while(fscanf(fptr, "%s %s %s %s %s %lf", &check.uname, &check.pass, &check.name, &check.address, &check.contact, &check.balance) != EOF)
    {
        if(strcmp(check.uname,username)==0)
        {
            break;
        }
    }
    printf("\n\n\t\tProfile Information\n\t\t--------------------\n");
    printf("\n\n\t Username: %s\n\t Name: %s\n\t Address: %s\n\t Contact: %s\n", check.uname, check.name, check.address, check.contact);

    fclose(fptr);

    printf("\n\n\t1. Go to Usermenu\n\t2. Go to Bank Selection\n\t0. Exit\n\tChoice: ");
    int c; scanf("%d", &c);
    if(c==1) menu(bank, username);
    if(c==2) BankSelect();
    if(c==0) exit(0);
}

void menu(int bank, char username[])
{
    top:
    system("cls");
    printf("\n\tYou are logged in!\n\n");
    printf("\n\t\t\t User Menu\n\t\t\t-----------\n");
    printf("\n\t#1. Check Balance\n");
    printf("\t#2. Deposit Balance\n");
    printf("\t#3. Withdraw Balance\n");
    printf("\t#4. See your profile\n");
    printf("\t#5. Edit profile\n");
    printf("\t#6. Request for deleting profile\n");
    printf("\t#7. Logout and Go to Bank Selection\n");
    printf("\t#0. Exit\n");
    printf("\n\t  Choose a option: ");
    int option;
    scanf("%d", &option);
    switch(option)
    {
        case 1:
            CheckBalance(bank, username);break;
        case 2:
            Deposit(bank, username);break;
        case 3:
            Withdraw(bank, username);break;
        case 4:
            SeeProfile(bank, username);break;
        case 5:
            Edit(bank, username);break;
        case 6:
            Delete(bank, username);break;
        case 7:
            BankSelect();
        case 0:
            exit(0);
        default:
            printf("\n\tInvalid input ! Try again.\n");
            goto top;
    }
}

void UserReg(int bank)
{
    FILE *fptr;
    up:
    system("cls");
    gotoxy(30,8);
    printf(":::~~~  Registration  ~~~:::");
    gotoxy(30,9);
    printf("----------------------------");
    switch(bank)
    {
        case 1:
            fptr = fopen("info1.txt","a+");
            break;
        case 2:
            fptr = fopen("info2.txt","a+");
            break;
        case 3:
            fptr = fopen("info3.txt","a+");
            break;
        case 4:
            fptr = fopen("info4.txt","a+");
            break;
    }
    printf("\n\n\tAttention ! No spaces are allowed in input ! \n");
    printf("\n\t  Set your username: ");
    fflush(stdin);
    gets(create.uname);
    while(fscanf(fptr, "%s %s %s %s %s %lf", &temp.uname, &temp.pass, &temp.name, &temp.address, &temp.contact, &temp.balance) != EOF)
    {
        if(strcmp(temp.uname, create.uname)==0)
        {
            printf("\n\n\t\tThis username is already used ! Try a new one.\n");
            fclose(fptr);
            goto up;
        }
    }

    printf("\t  Set a password: ");
    fflush(stdin);
    gets(create.pass);
    printf("\t  Enter your name: ");
    fflush(stdin);
    gets(create.name);
    printf("\t  Enter your address: ");
    fflush(stdin);
    gets(create.address);
    printf("\t  Enter your contact number: ");
    fflush(stdin);
    gets(create.contact);
    create.balance = 0;

    fprintf(fptr, "%s %s %s %s %s %lf\n", create.uname, create.pass, create.name, create.address, create.contact, create.balance);
    fclose(fptr);

    printf("\n\t\tAccount created successfully.\n");

    printf("\n\n\t1. Go to Bank Selection\n\t0. Exit\n\tChoice: ");
    int c; scanf("%d", &c);
    if(c==0) exit(0);
    if(c==1) BankSelect();
}

void LogIn(int bank)
{
    FILE *fptr;
    top:
    system("cls");
    gotoxy(30,8);
    printf(":::~~~  Login  ~~~:::");
    gotoxy(30,9);
    printf("---------------------");

    switch(bank)
    {
        case 1:
            fptr = fopen("info1.txt","r");
            break;
        case 2:
            fptr = fopen("info2.txt","r");
            break;
        case 3:
            fptr = fopen("info3.txt","r");
            break;
        case 4:
            fptr = fopen("info4.txt","r");
            break;
    }

    printf("\n\tEnter username: ");
    fflush(stdin);
    scanf("%s", match.uname);
    printf("\tEnter password: ");
    fflush(stdin);
    scanf("%s", match.pass);
    int flag=0;
    while(fscanf(fptr, "%s %s %s %s %s %lf", &temp.uname, &temp.pass, &temp.name, &temp.address, &temp.contact, &temp.balance) != EOF)
    {
        if(strcmp(temp.uname, match.uname)==0 && strcmp(temp.pass, match.pass)==0)
        {
            flag=1;
            fclose(fptr);
            menu(bank, temp.uname);
        }
    }

    if(flag != 1)
    {
        printf("\n\t\tWrong Username or password!  :/ \n");
        printf("\n\n\t1. Try again\n\t2. Go to Bank Selection\n\tChoice: ");
        int c; scanf("%d", &c);
        if(c==1) goto top;
        if(c==2) BankSelect();
    }
}

void LoginCreate(int bank)
{
    system("cls");
    gotoxy(30,10);
    printf("(1) Login to your account.\n");
    gotoxy(30,11);
    printf("(2) Request for a new account.\n");
    gotoxy(30,14);
    printf("Please enter your choice: ");
    int choice;
    scanf("%d", &choice);
    if(choice==1)
    {
        LogIn(bank);
    }
    if(choice==2)
    {
        UserReg(bank);
    }
}

void Welcome()
{
    gotoxy(35, 5);
    printf("::::::  Welcome to Smart Banking system  ::::::\n");
    gotoxy(8, 10);
    printf("This program lets you enjoy the hassle-free banking services.\n\tIt brings the services of several banks under a single platform.\n\tLETS GO! >>>\n\n");
}

void BankSelect()
{
    system("cls");
    Welcome();
    gotoxy(8,15);
    printf("Available Banks:\n");
    gotoxy(16,17);
    printf("1. Sonali Bank.\n");
    gotoxy(16,18);
    printf("2. Rupali Bank.\n");
    gotoxy(16,19);
    printf("3. Pubali Bank.\n");
    gotoxy(16,20);
    printf("4. Krishi Bank.\n");
    gotoxy(16,21);
    printf("0. Exit\n");

    gotoxy(12,24);
    printf("Please enter the serial number of your desired bank: ");
    int bank;
    scanf("%d", &bank);
    if(bank==0)
        exit(0);
    if(bank>4 || bank<1){
        gotoxy(30,28);
        printf("Wrong input !\n");
        gotoxy(4, 30);
        printf("\t1. Select again\n\t2. Exit\n");
        int c;
        printf("\tChoice: ");
        scanf("%d", &c);
        if(c==1)
            BankSelect();
        if(c==0)
            exit(0);
    }

    LoginCreate(bank);
}

int main()
{
    system("color b4");
    BankSelect();
}
