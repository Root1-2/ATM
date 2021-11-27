#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>


//Declaring_Functions
void signin();
void aboutus();
void signup();
void mainmenu();
void checkBalance();
void semesterfee();
void moneyDeposit();
void moneyWithdraw();
void menuExit();
void info();

float balance = 10000;


//GOTO Initalized
void gotoxy(int x, int y)

{
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//Storing File value in Structure


struct information
{
    char username[20];
    char password[20];
    int date, month, year;
    char pnumber[20];
    int age;
    char fname[20];
    char lname[20];
    char fathname[20];
    char mothname[20];
    char address[50];
};


//Homepage
int main()
{
    system("cls");
    int i;
    gotoxy(40, 2);
    printf("WELCOME TO OUR ATM BANKING SYSTEM.");
    gotoxy(40, 5);
    printf("HOW CAN WE HELP YOU?");
    gotoxy(35, 10);
    printf("1. SIGN IN");
    gotoxy(35, 12);
    printf("2. SIGN UP");
    gotoxy(35, 14);
    printf("3. ABOUT US");
    gotoxy(35, 15);
    printf("(GO TO FULL SCREEN MODE IN CONSOLE)");
    gotoxy(35, 17);
    printf("4. EXIT");
    gotoxy(35, 20);
    printf("CHOOSE AN OPTION: ");
    scanf("%d", &i);


    switch(i)
    {
    case 1:
        signin();
        break;

    case 2:
        signup();
        break;

    case 3:
        aboutus();
        break;

    case 4:
        menuExit();

    default:
        gotoxy(36, 24);
        printf("WRONG INPUT. PLEASE PRESS ANY KEY AND ENTER TO TRY AGAIN....");
        char option[10];
        scanf("%s", &option);
        main();

    }

    mainmenu();

}

void signup()
{
    char username[20];
    char password[20];
    char ch;
    FILE *fp;
    struct information u1;


    // Opening file to
    // write data of a user
    fp = fopen("username.txt", "ab");

    system("cls");

    gotoxy(40, 2);
    printf("!!!!!CREATE YOUR ACCOUNT!!!!!");

    printf("\n\nFIRST NAME...");
    scanf("%19s", u1.fname);

    printf("\nLAST NAME...");
    scanf("%19s", u1.lname);

    printf("\nFATHER's NAME(FIRST NAME ONLY)...");
    scanf("%19s", u1.fathname);

    printf("\nMOTHER's NAME(FIRST NAME ONLY)...");
    scanf("%19s", u1.mothname);

    printf("\nADDRESS(DISTRICT ONLY)..");
    scanf("%19s", u1.address);

    printf("\nDATE OF BIRTH...");
    printf("\nDATE-");
    scanf("%d", &u1.date);
    printf("\nMONTH-");
    scanf("%d", &u1.month);
    printf("\nYEAR-");
    scanf("%d", &u1.year);

    printf("\nPHONE NUMBER...");
    scanf("%19s", u1.pnumber);

    printf("\nAGE...");
    scanf("%d", &u1.age);

    printf("\nUSERNAME.. ");
    scanf("%19s", u1.username);

    printf("\nPASSWORD..");
    scanf("%19s", u1.password);

    fwrite(&u1, sizeof(u1), 1, fp);

    fclose(fp);

    system("cls");
    gotoxy(40, 10);
    printf("ACCOUNT CREATED SUCCESSFULLY.\n");

    char option[10];
    gotoxy(33, 14);
    printf("PRESS ANY KEY THEN ENTER TO GO TO SIGN IN PAGE");
    scanf("%s", option);
    signin();
}

void signin()
{
    system("cls");

    char username[20];
    char password[20];

    char ch;
    FILE *fp;
    struct information u1;


    // Opening file of
    // user data
    fp = fopen("username.txt","rb");

    if (fp == NULL)
    {
        printf("\nERROR IN OPENING FILE\n");
        printf("FILE DOESN'T EXIST\nYOU HAVE TO CREATE AN ACCOUNT FIRST\n");
        printf("PRESS ANY KEY & ENTER TO CREATE AN ACCOUNT\n");
        char option[10];
        scanf("%s", option);
        signup();
    }
    gotoxy(34, 2);
    printf(" ACCOUNT LOGIN ");
    gotoxy(7, 5);
    printf("***********************************************"
           "********************************");

    gotoxy(35, 10);
    printf("==== LOG IN ====");

    // Take input
    gotoxy(35, 12);
    printf("ENTER USERNAME.. ");
    scanf("%19s", username);

    gotoxy(35, 14);
    printf("ENTER PASSWORD.. ");
    scanf("%19s", password);


    // Checking if username & password
    // exists in the file or not
    while (fread(&u1, sizeof(u1), 1, fp))
        {
            if (strcmp(username, u1.username) == 0)
            {
                if (strcmp(password, u1.password) == 0)
                {
                    mainmenu();
                }

                else
            {
                printf("\n\n\nINFORMATION INCORRECT.\n");
                printf("WOULD YOU LIKE TO TRY AGAIN?\n");
                printf("< 1 > YES\n");
                printf("< 2 > NO\n");
                int option;
                do
                {
                    printf("PLEASE CHOOSE YOUR OPTIONS...");
                    scanf("%d", &option);
                    if (option == 1)
                    {
                        signin();
                    }
                    else if(option == 2)
                    {
                        main();
                    }
                    else
                    {
                        printf("INVALID INPUT. PLEASE PRESS ANY KEY AND ENTER TO TRY AGAIN");
                        char choose[10];
                        scanf("%s", &choose);
                    }
                } while (option > 2);
                }

            }

            else
            {
                printf("\n\n\nINFORMATION INCORRECT.\n");
                printf("WOULD YOU LIKE TO TRY AGAIN?\n");
                printf("< 1 > YES\n");
                printf("< 2 > NO\n");
                int option;

            do
            {
                printf("PLEASE CHOOSE YOUR OPTIONS...");
                scanf("%d", &option);
                if (option == 1)
                {
                    signin();
                }
                else if(option == 2)
                {
                    main();
                }
                else
                {
                    printf("INVALID INPUT. PLEASE PRESS ANY KEY AND ENTER TO TRY AGAIN");
                    char choose[10];
                    scanf("%s", &choose);
                }
            } while (option > 2);

            }

        }

       fclose(fp);

}



void mainmenu()

{

    int option, choose;
    system("cls");
    gotoxy(31, 2);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    gotoxy(40, 4);;
    printf("WELCOME TO OUR ATM BANK\n");
    gotoxy(31, 5);;
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    gotoxy(40, 7);
    printf("HOW CAN WE HELP YOU?\n");
    gotoxy(31, 8);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    gotoxy(28, 10);
    printf("PRESS < 1 >  CHECK BALANCE\n");
    gotoxy(28, 11);
    printf("PRESS < 2 >  DEPOSIT\n");
    gotoxy(28, 12);
    printf("PRESS < 3 >  WITHDRAW\n");
    gotoxy(28, 13);
    printf("PRESS < 4 >  SEMESTER FEE\n");
    gotoxy(28, 14);
    printf("PRESS < 5 >  INFORMATION\n");
    gotoxy(28, 15);
    printf("PRESS < 6 >  HOMEPAGE\n\n");
    gotoxy(28, 16);
    printf("PRESS < 7 >  EXIT\n\n");
    gotoxy(28, 18);
    printf("CHOOSE AN OPTION: ");
    scanf("%d", &option);
    gotoxy(28, 20);



        switch (option)
        {
            case 1:

                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                break;

            case 7:

                break;

            default:
            gotoxy(20, 24);
            printf("WRONG INPUT. PLEASE PRESS ANY KEY AND ENTER TO TRY AGAIN....");
            char option[10];
            scanf("%s", &option);
            mainmenu();
        }

}


void aboutus()

{
    system("cls");

    printf("\t\t\t\t\t\t\t\t***ABOUT OUR PROJECT **\n"
"\t\t\t\t\t\t\t\t  [ ATM MACHINE ]\n\n\n\nIN EARLIER YEARS"
"ALL THE TRANSACTIONS WERE TO BE DONE MANUALLY, STILL DONE BUT"
"VERY RARELY, AS IT IS A DIFFICULT TASK. NOW BANKS USE THIS TO GIVE THEIR CUSTOMERS TO"
"\nHAVE EASY & FASTER TRANSACTIONS. THUS OUR PROJECT IS A GOOD TASK TO HAVE TRANSACTIONS"
"EASIER, FASTER & FOR EMERGENCIES. OUR ATM MACHINE SYSTEM PROJECT IS BASED ON A \nCONCEPT OF"
"MANAGING AN ACCOUNT PERSONALLY. FROM THIS SYSTEM, THE USER CAN LOGIN AND CHECK"
"TOTAL BALANCE, DEPOSIT AMOUNT AND WITHDRAW AMOUNT EASILY AS IT IS LESS \nTIME-CONSUMING."
"STUDENT ALSO CAN PAY THEIR SEMESTER FEES USING THIS ATM MACHINE. THE WHOLE PROJECT IS"
"DEVELOPED IN C PROGRAMMING LANGUAGE, MANY FUNCTIONS, DIFFERENT \nVARIABLES, STRINGS AND FILE HANDLING"
"HAVE BEEN USED FOR THE DEVELOPMENT OF THIS PROJECT. THIS IS A MINI PROJECT SO IT"
"CONTAINS LESS FEATURES THAN USUAL. BUT IT'S EASY \nTO OPERATE AND UNDERSTANDABLE BY THE USERS.\n\n\n");

    printf("\t\t\t\t\t\t\t\t\t*** ABOUT US***\n\n\n\n"
"\t\tA GROUP OF FIVE MEMBERS WORKING TOGETHER FROM DIFFERENT"
"BATCHES OF DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING (LEADING UNIVERSITY)\n");

    printf("\n\n\n\t\t\t\t\t\t\t1. ABDULLAH AL MASRUR       2012020255\n"
           "\t\t\t\t\t\t\t2. TASFIAH TAHSIN AHSAN     2012020258\n"
           "\t\t\t\t\t\t\t3. AKIB SHIKDAR             1712020031\n"
           "\t\t\t\t\t\t\t4. SADIK MUHAMMAD SHAHREAR  1712020110\n"
           "\t\t\t\t\t\t\t5. JANNATUL FERDOUS SABRIN  2012020251");


    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\tWOULD YOU LIKE TO GO TO THE HOME PAGE AGAIN?\n\n");
    printf("\t\t\t\t\t\t\t\t<1> YES \n\t\t\t\t\t\t\t\t<2> NO\n\n");
    int option;

    do
    {
        printf("\t\t\t\t\t\t\t\tPLEASE CHOOSE YOUR OPTIONS...");
        scanf("%d", &option);
        if (option == 1)
        {
            main();
        }
        else if(option == 2)
        {
            menuExit();
        }
        else
        {
            printf("INVALID INPUT. PLEASE PRESS ANY KEY AND ENTER TO TRY AGAIN");
            char choose[10];
            scanf("%s", &choose);
        }
    } while (option > 2);


}


void info()

{
    system("cls");
    FILE* fp;
    int choice, i;
    fp = fopen("username.txt", "rb");
    struct information u1;

    if (fp == NULL)
    {
        printf("error in opening file");
    }
    while (fread(&u1, sizeof(u1), 1, fp))
    {
            gotoxy(28, 2);
            printf("..........................");
            gotoxy(28, 4);
            printf("==== YOUR ACCOUNT INFO ====");
            gotoxy(28, 6);
            printf("***************************");
            gotoxy(28, 8);
            printf("NAME..%s %s", u1.fname, u1.lname);

            gotoxy(28, 10);
            printf("FATHER's NAME(FIRST NAME ONLY)..%s", u1.fathname);

            gotoxy(28, 12);
            printf("MOTHER's NAME(FIRST NAME ONLY)..%s", u1.mothname);

            gotoxy(28, 14);
            printf("MOBILE NUMBER..%s", u1.pnumber);

            gotoxy(28, 16);
            printf("DATE OF BIRTH.. %d-%d-%d", u1.date, u1.month, u1.year);

            gotoxy(28, 18);
            printf("ADDRESS(DISTRICT ONLY)..%s", u1.address);

            gotoxy(28, 20);
            printf("AGE...%d", &u1.age);
    }

        gotoxy(20, 23);
        printf("WOULD YOU LIKE TO GO BACK TO MAIN MENU?:\n");
        gotoxy(17, 25);
        printf("< 1 > YES\n");
        gotoxy(17, 27);
        printf("< 2 > NO\n");
        int option;

        do
        {
        printf("\n\nPLEASE CHOOSE YOUR OPTIONS...");
        scanf("%d", &option);
        if (option == 1)
        {
            mainmenu();
        }
        else if(option == 2)
        {
            menuExit();
        }
        else
        {
            printf("INVALID INPUT. PLEASE PRESS ANY KEY AND ENTER TO TRY AGAIN");
            char choose[10];
            scanf("%s", &choose);
        }
        } while (option > 2);

        fclose(fp);
}


void semesterfee()

{
    system("cls");
    gotoxy(28, 2);
    printf("YOUR SEMESTER FEE IS 5000TK THIS SEMESTER\n");
    gotoxy(28, 4);
    printf("PRESS ANY KEY THEN ENTER TO CONFIRM...");
    char p[10];
    scanf("%s", p);

    if (balance>5000)
    {

    balance -= 5000;
    gotoxy(28, 7);
    printf("YOU SUCCESSFULLY TRANSEFERED YOUR SEMESTER FEE INTO YOUR UNIVERSITY ACCOUNT\n");
    gotoxy(28, 9);
    printf("YOUR CURRENT BALANCE IS %.2f\n", balance);

    }

    else

    {
        gotoxy(28, 7);
        printf("YOU HAVE INSUFFICIENT BALANCE. PLEASE ADD MORE MONEY INTO YOUR ACCOUNT.\n");

    }
        gotoxy(20, 11);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        gotoxy(20, 13);
        printf("WOULD YOU LIKE TO GO BACK TO MAIN MENU?:\n");
        gotoxy(17, 15);
        printf("< 1 > YES\n");
        gotoxy(17, 17);
        printf("< 2 > NO\n");
        int option;

        do
        {
        printf("\n\nPLEASE CHOOSE YOUR OPTIONS...");
        scanf("%d", &option);
        if (option == 1)
        {
            mainmenu();
        }
        else if(option == 2)
        {
            menuExit();
        }
        else
        {
            printf("INVALID INPUT. PLEASE PRESS ANY KEY AND ENTER TO TRY AGAIN");
            char choose[10];
            scanf("%s", &choose);
        }
        } while (option > 2);

}


void checkBalance()
{
    system("cls");

    gotoxy(28, 2);
    printf("YOU CHOOSE TO SEE YOUR BALANCE\n");
    gotoxy(28, 4);
    printf("****YOUR AVAILABLE BALANCE IS:   $%.2f\n", balance);
    gotoxy(20, 6);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        gotoxy(17, 8);
        printf("WOULD YOU LIKE TO DO ANOTHER TRANSACTION:\n");
        gotoxy(17, 10);
        printf("< 1 > YES\n");
        gotoxy(17, 12);
        printf("< 2 > NO\n");
        int option;

        do
        {
            gotoxy(10, 14);
            printf("PLEASE CHOOSE YOUR OPTIONS...");
            scanf("%d", &option);
            if (option == 1)
                {
                    mainmenu();
                }
            else if(option == 2)
                {
                    menuExit();
                }
            else
                {
                    printf("INVALID INPUT. PLEASE PRESS ANY KEY AND ENTER TO TRY AGAIN");
                    char choose[10];
                    scanf("%s", &choose);
                }
        } while (option > 2);


}

void menuExit()
{
    system("cls");
    printf("\n\n\t\t\t\t-----THANK YOU FOR CHOOSING OUR ATM SYSTEM!!!-----\n");
    printf("\t\t\t\t-----WE HOPE YOU COME BACK AGAIN SOON!!!----------\n\n\n");

    exit(0);
}

void moneyDeposit()
{
    system("cls");

    float deposit;
    gotoxy(28, 2);
    printf("YOU CHOOSE TO DEPOSIT MONEY\n");
    gotoxy(22, 4);
    printf("$$$$YOUR BALANCE IS: $%.2f\n\n", balance);
    gotoxy(22, 7);
    printf("****ENTER YOUR AMOUNT TO DEPOSIT: ");
    scanf("%f", &deposit);

    balance += deposit;

    gotoxy(22, 9);
    printf("****YOUR NEW BALANCE IS:   $%.2f\n\n", balance);

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        gotoxy(17, 12);
        printf("WOULD YOU LIKE TO DO ANOTHER TRANSACTION:\n");
        gotoxy(17, 14);
        printf("< 1 > YES\n");
        gotoxy(17, 16);
        printf("< 2 > NO\n");
        int option;

        do
        {
            gotoxy(10, 18);
            printf("PLEASE CHOOSE YOUR OPTIONS...");
            scanf("%d", &option);
            if (option == 1)
                {
                    return;
                }
            else if(option == 2)
                {
                    menuExit();
                }
            else
                {
                    printf("INVALID INPUT. PLEASE PRESS ANY KEY AND ENTER TO TRY AGAIN");
                    char choose[10];
                    scanf("%s", &choose);
                }
        } while (option > 2);


}

void moneyWithdraw()
{
    system("cls");

    float withdraw;

    gotoxy(28, 2);
    printf("YOU CHOOSE TO WITHDRAW MONEY\n");
    gotoxy(22, 4);
    printf("$$$$YOUR BALANCE IS: $%.2f\n\n", balance);
    gotoxy(22, 6);
    printf("ENTER YOUR AMOUNT TO WITHDRAW:");
    scanf("%f", &withdraw);


    if (withdraw <= balance)
        {
            balance -= withdraw;
            gotoxy(28, 9);
            printf("$$$$YOUR WITHDRAWING MONEY IS:  $%.2f\n", withdraw);
            gotoxy(28, 11);
            printf("****YOUR NEW BALANCE IS:   $%.2f\n\n", balance);


        }

    else
        {
            gotoxy(28, 9);
            printf("+++YOU DON'T HAVE ENOUGH MONEY+++\n");
            gotoxy(28, 11);
            printf("****YOUR CURRENT BALANCE IS:   $%.2f\n\n", balance);
            gotoxy(28, 13);
            printf("PLEASE DEPOSIT MONEY\n");

        }

    gotoxy(17, 16);
    printf("WOULD YOU LIKE TO DO ANOTHER TRANSACTION:\n");
    gotoxy(17, 18);
    printf("< 1 > YES\n");
    gotoxy(17, 20);
    printf("< 2 > NO\n");
    int option;

        do
            {
                gotoxy(10, 22);
                printf("PLEASE CHOOSE YOUR OPTIONS...");
                scanf("%d", &option);
                if (option == 1)
                    {
                        mainmenu();
                    }
                else if(option == 2)
                    {
                        menuExit();
                    }
                else
                    {
                        printf("INVALID INPUT. PLEASE PRESS ANY KEY AND ENTER TO TRY AGAIN");
                        char choose[10];
                        scanf("%s", &choose);
                    }
            } while (option > 2);
}


