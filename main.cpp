#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

// Function declarations
void login();
void registr();
void forgot();

// Main function
int main()
{
    int choice;
    
    // Displaying the main menu
    cout << "***********************************************************************\n\n\n";
    cout << "                      Welcome to login page                               \n\n";
    cout << "*******************        MENU        *******************************\n\n";
    cout << "1.LOGIN" << endl;
    cout << "2.REGISTER" << endl;
    cout << "3.FORGOT PASSWORD (or) USERNAME" << endl;
    cout << "4.Exit" << endl;
    cout << "\nEnter your choice :";
    
    // User input for menu choice
    cin >> choice;
    cout << endl;

    // Switch case to handle user's choice
    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registr();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "Thanks for using this program.\nThis program is created by @InhaleCode(rxn)\n\n";
        break;
    default:
        // Handling incorrect input
        system("cls");
        cout << "You've made a mistake, Try again..\n"
             << endl;
        main();
    }
}

// Function for user login
void login()
{
    int count;
    string user, pass, u, p;

    // Clearing the console
    system("cls");

    // Getting user input for username and password
    cout << "please enter the following details" << endl;
    cout << "USERNAME :";
    cin >> user;
    cout << "PASSWORD :";
    cin >> pass;

    // Opening the database file for reading
    ifstream input("database.txt");

    // Checking each line in the file for a match
    while (input >> u >> p)
    {
        if (u == user && p == pass)
        {
            count = 1;
            system("cls");
        }
    }

    // Closing the file
    input.close();

    if (count == 1)
    {
        cout << "\nHello " << user << "\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
        cin.get();
        cin.get();
        main();
    }
    else
    {
        cout << "\nLOGIN ERROR\nPlease check your username and password\n";
        main();
    }
}

// Function for user registration
void registr()
{
    string reguser, regpass, ru, rp;

    // Clearing the console
    system("cls");

    // Getting user input for new username and password
    cout << "Enter the username :";
    cin >> reguser;
    cout << "\nEnter the password :";
    cin >> regpass;

    // Opening the database file for writing (appending)
    ofstream reg("database.txt", ios::app);

    // Writing new user information to the file
    reg << reguser << ' ' << regpass << endl;

    // Closing the file
    system("cls");
    cout << "\nRegistration Successful\n";
    main();
}

// Function for password/username recovery
void forgot()
{
    int ch;
    // Clearing the console
    system("cls");

    cout << "Forgotten ? We're here for help\n";
    cout << "1.Search your id by username" << endl;
    cout << "2.Search your id by password" << endl;
    cout << "3.Main menu" << endl;
    cout << "Enter your choice :";
    cin >> ch;

    switch (ch)
    {
    case 1:
    {
        int count = 0;
        string searchuser, su, sp;

        cout << "\nEnter your remembered username :";
        cin >> searchuser;

        // Opening the database file for reading
        ifstream searchu("database.txt");

        // Searching for the username in the file
        while (searchu >> su >> sp)
        {
            if (su == searchuser)
            {
                count = 1;
            }
        }

        // Closing the file
        searchu.close();

        if (count == 1)
        {
            cout << "\n\nHurray, account found\n";
            cout << "\nYour password is " << sp;
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else
        {
            cout << "\nSorry, Your userID is not found in our database\n";
            cout << "\nPlease kindly contact your system administrator for more details \n";
            cin.get();
            cin.get();
            main();
        }
        break;
    }
    case 2:
    {
        int count = 0;
        string searchpass, su2, sp2;

        cout << "\nEnter the remembered password :";
        cin >> searchpass;

        // Opening the database file for reading
        ifstream searchp("database.txt");

        // Searching for the password in the file
        while (searchp >> su2 >> sp2)
        {
            if (sp2 == searchpass)
            {
                count = 1;
            }
        }

        // Closing the file
        searchp.close();

        if (count == 1)
        {
            cout << "\nYour password is found in the database \n";
            cout << "\nYour Id is : " << su2;
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else
        {
            cout << "Sorry, We cannot found your password in our database \n";
            cout << "\nkindly contact your administrator for more information\n";
            cin.get();
            cin.get();
            main();
        }

        break;
    }
    case 3:
    {
        cin.get();
        main();
    }
    default:
        cout << "Sorry, You entered the wrong choice. Kindly try again" << endl;
        forgot();
    }
}
