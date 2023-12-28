#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fstream>
#include <cstdlib>

using namespace std;
// global variables
const char code[50] = {"aaron"}; //password for the program

// system operations
void password();
void menu();
void usersPanel();
void booksPanel();

// manage user operations
void addUser();
void modifyUser();
void listUsers();
void listRentals();
void searchUser();
void deleteUser();

// manage book operations
void addBook();
void modifyBook();
void listBook();
void rentBook();
void searchBook();
void deleteBook();

// main function
int main()
{
    password();
}
int passTerminator = 1;

// The password is :{aaron}
void password(){
    char ch;
    int i;
    char pwd[50];
    cout << "================================================\n";
    cout << "LIBRARY MANAGEMENT SYSTEM\n";
    cout << "================================================\n\n\n";

    cout << "Enter your Password to continue: ";
    while(1){
        ch = getchar();
        if( ch == '\n' || ch == '\0')
            break;
        else if(ch == '\b'){
            i--;

        } else{
            pwd[i++] = ch;
            // cout << '*';
        }
    }
    if(strcmp(code, pwd) == 0){
        cout << "\n\nLoading";
        for( int a =1; a < 4; a++){
                cout << "...";
                cout.flush();
                sleep(1);
        }
        menu();
    } else {
        cout << "\n\nInvalid Password";
        for( int a =1; a < 6; a++){
                cout << "...";
                cout.flush();
                sleep(1);
        }
        system("clear");
        password();
    }
}
void menu(){
    system("clear");
    cout << "================================================\n";
    cout << "LIBRARY MANAGEMENT SYSTEM - MAIN MENU\n";
    cout << "================================================\n\n\n";

    int number;
    cout << "Enter your choice: \n";
    cout << "1. Users Management Panel\n";
    cout << "2. Books Management Panel\n\n ";
    cout << "Your Choice: ";
    cin >> number;
    cin.ignore();

    switch( number ){
        case 1:
            usersPanel();
            break;
        case 2: 
            booksPanel();
            break;
        default:
            cout << "Invalid Input";
            char ch;
            cout << "Going back to main menu...........\n";
            usleep(10);
            system("clear");
            menu();
    }
}
void usersPanel(){
    system("clear");
    cout << "================================================\n";
    cout << "LIBRARY MANAGEMENT SYSTEM - users panel\n";
    cout << "================================================\n\n\n";

    cout << "1. Add User\n";
    cout << "2. Modify User\n";
    cout << "3. List users\n";
    cout << "4. List Rentals\n";
    cout << "5. Search User\n";
    cout << "6. Delete User\n";
    cout << "7. Open Main Menu\n";
    cout << "8. Close the program\n\n\n";

    int choice;
    cout << "Your choice: ";
    cin >> choice;
    cin.ignore();

    switch(choice){
        case 1:
            addUser();
            break;
        case 2:
            modifyUser();
            break;
        case 3:
            listUsers();
            break;
        case 4:
            listRentals();
            break;
        case 5:
            searchUser();
            break;
        case 6:
            deleteUser();
            break;
        case 7:
            menu();
            break;
        case 8:
            usleep(10);
            cout << "Closing the program in (3) seconds...";
            exit(1);
    }

}
void booksPanel(){
    system("clear");
    cout << "================================================\n";
    cout << "LIBRARY MANAGEMENT SYSTEM - booksPanel\n";
    cout << "================================================\n\n\n";

    cout << "1. Add Book\n";
    cout << "2. Modify Book\n";
    cout << "3. List Book\n";
    cout << "4. Rent Book\n";
    cout << "5. Search Book\n";
    cout << "6. Delete Book\n";
    cout << "7. Open Main Menu\n";
    cout << "8. Close the program\n\n\n";

    int choice;
    cout << "Your choice: ";
    cin >> choice;
    cin.ignore();

    switch(choice){
        case 1:
            addBook();
            break;
        case 2:
            modifyBook();
            break;
        case 3:
            listBook();
            break;
        case 4:
            rentBook();
            break;
        case 5:
            searchBook();
            break;
        case 6:
            deleteBook();
            break;
        case 7:
            menu();
            break;
        case 8:
            cout << "Closing the program in (3) seconds...";
            cout.flush();
            sleep(2);
            exit(1);
        default:
            system("clear");
            cout << "\nInvalid Option... {returning to book menu..}";
            cout.flush();
            sleep(3);
            booksPanel();
    }
}
// defination of the user operation functions
void addUser(){
    label1:
        system("clear");
        char fname[50], lname[50];
        char gender;
        double phone, uid;
        ofstream usersFile("users.txt", ios::app);

        if(usersFile){
            cout << "Enter the user first Name: ";
            cin.getline(fname, 50);
            cout << "Enter user last name: ";
            cin.getline(lname, 50);
            cout << "Enter Gender: ";
            cin >> gender;
            cin.ignore();
            cout << "Enter UserID: ";
            cin >> uid;
            cin.ignore();
            cout << "Enter telephone: ";
            cin >> phone;
            cin.ignore();
            usersFile << fname << " " << lname << " " << gender << " " << uid << " " << phone << endl;

            cout << "\n\nUser Record successfully added to database...\n\n";
        } else{
            cout << "\n\nUnable to locate the file...\n\n";
        }
        // fclose(pF);
        usersFile.close();

        //retry screen
        char input;
        cout << "Do you want to enter more records [y/n]: ";
        cin >> input;
        cin.ignore();

        if(input == 'y' || input == 'Y'){
            goto label1;
        } else {
            cout << "\n\nRedirecting to user panel";
            for( int a =1; a < 6; a++){
                cout << "...";
                cout.flush();
                sleep(1);
            }
            usersPanel();
        }
}
void modifyUser(){
    system("clear");


    char fname[50], lname[50], gender;
    char fname1[50], lname1[50], gender1;
    double phone, uid, phone1, uid1;

    char find[50];

    int compare, flag = 0;

    cout << "Enter the name of the person you wanna modify: ";
    cin.getline(find, sizeof(find));


    // open the users.txt file for reading
    ifstream userFile("users.txt");
    // open the temporary.txt file for writing
    ofstream tempFile("temporary.txt");

    // if the file openings fail, print an error message and return
    if(!userFile.is_open() || !tempFile.is_open()){
        cerr << "Error opening the file for reading and writing....\n\n";
        return;
    }

    cin.ignore();
    // read lines in users.txt line by line
    while(userFile >> fname >> lname >> gender >> uid >> phone)
    {
        // check if the user exists by comparision
        compare = strcmp(find, fname);
        // if the user exists, prompt for modification
        if(compare == 0){
            cout << "\n------------------------------------------\n";
            cout << ">>> Record Found, Allowing Modifications <<<\n";
            cout << "--------------------------------------------\n";

            cout << "Enter First Name: ";
            cin.getline(fname1, sizeof(fname1));

            cout << "Enter last name: ";
            cin.getline(lname1, sizeof(lname1));

            cout << "Enter Gender: ";
            cin >> gender;
            cin.ignore();

            cout << "Enter User ID: ";
            cin >> uid1;
            // cin.ignore();

            cout << "Enter phone: ";
            cin >> phone;
            cin.ignore();
            // copy call users.txt data to temporary.txt file
            // update the information in the temporary.txt file
            tempFile << fname1 << " " << lname1 << " " << gender1 << " " << uid1 << " " << phone1 << endl;
            flag = 1;
        } else {
            tempFile << fname << " " << lname << " " << gender << " " << uid << " " << phone << endl;
        }
    }
    // close both files
    userFile.close();
    tempFile.close();

    
    // remove the original users.txt file
    remove("users.txt");
    // rename temporary.txt to users.txt
    rename("temporary.txt", "users.txt");

    if(flag == 0)
    {
        cout << "\n\n-----------------------------------\n";
        cout << ">>>> Record Not Found <<<<\n";
        cout << "---------------------------------------\n\n";
        cout << "Redirecting to user panel";
        for( int a =1; a < 6; a++)
        {
            cout << "...";
            cout.flush();
            sleep(1);
        }
            usersPanel();
    }

    cin.ignore();
    cout.flush();
    usersPanel();
}
void listUsers(){
    system("clear");
    char fname[50], lname[50], gender;
    double phone, uid;

    bool is_there_record = false;

    ifstream userRecords("users.txt", ios::in);
    if(!userRecords.is_open()){
        cerr << "\n\nError opening file";
        for(int a =1; a<4; a++){
            cout << "...";
            cout.flush();
            sleep(1);
        }
        usersPanel();
    }

    cout << "\t-------------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t\tList of users\n";
    cout << "\t-------------------------------------------------------------------------------------------\n\n";
    cout << "\tUID\t\t\tFull Name\t\t\tGender\t\t\tphone\n\n";

    while(userRecords >> fname >> lname >> gender >> uid >> phone)
    {
        strcpy(fname, " ");
        strcpy(fname, lname);
        cout << "\t" << uid << "\t\t\t" << fname << "\t\t\t\t" << gender << "\t\t\t" << phone << endl;

        is_there_record = true;        
    }
    userRecords.close();

    if(is_there_record = false)
    {
        cout << "\n\n------------------------------------------------\n";
        cout << "\t\t\tThere is no user record added yet\n";
        cout << "----------------------------------------------------\n";
    }
    char ch;
    cout << "\n\nPress any key to go back to the user panel\n";
    ch = getchar();
    usersPanel();
}



void listRentals(){
    system("clear");
    cout << "listing rentals\n\n\n";
}


void searchUser(){
    system("clear");
    char fname[50], lname[50], fname1[50], gender;
    double uid, phone;
    cout << "What is the name of the user you wanna search: ";
    cin.getline(fname1, sizeof(fname1));

    ifstream searchFile("users.txt");
    if(!searchFile.is_open()){
        cerr << "Error opening the file\n\n";
    }

    bool is_search_there = false;
    int compare;
    while(searchFile >> fname >> lname >> gender >> uid >> phone)
    {
        compare = strcmp(fname1, fname);
        if(compare == 0)
        {
            cout << "\t--------------------------------------------------\n";
            cout << "\t\t\t\tUser found\n";
            cout << "\t--------------------------------------------------\n\n";

            cout << "Returning user info";
            for(int a = 1; a <5; a++)
            {
                cout << "...";
                cout.flush();
                sleep(1);
            }
            cout << "\n\n\tUID\t\t\tFull Name\t\t\tGender\t\t\tphone\n\n";
            cout << "\t" << uid << "\t\t\t" << fname << "\t\t\t\t" << gender << "\t\t\t" << phone << endl << endl << endl;

            is_search_there = true;
        }
    }

    searchFile.close();

    if(is_search_there == false)
    {
        system("clear");
        cout << "--------------------------------------------------\n";
        cout << "\t\t\tNo User found>>>>>>>>\n";
        cout << "--------------------------------------------------\n\n\n";

        cout << "Redirecting to user panel";
        for(int a = 1; a < 5; a++)
        {
            cout << "...";
            cout.flush();
            sleep(1);
        }
        usersPanel();
    }
}
void deleteUser(){
    system("clear");
    char fname[50], lname[50], gender, find[50];
    double uid, phone;

    ifstream userFile("users.txt");
    ofstream tempFile("temp.txt");

    if(!userFile.is_open() || !tempFile.is_open())
    {
        cerr << "Error opening file....\n\n";
        cout << "Redirecting to the user panel";
        for( int a = 1; a < 5; a++)
        {
            cout << "...";
            cout.flush();
            sleep(1);
        }
        usersPanel();
    }
    cout << "What is the name of the user you would like to delete: ";
    cin.getline(find, sizeof(find));

    int compare, count = 0;
    bool flag = false;

    while(userFile >> fname >> lname >> gender >> uid >> phone)
    {
        compare = strcmp(find, fname);
        if( compare == 0 )
        {
            cout << "\n\t\t-----------------------------------------------\n";
            cout << "\t\t\tUser record deleted\n";
            cout << "\t\t-----------------------------------------------\n\n";

            flag = true;
        } 
        else
        {
            tempFile << fname << " " << lname << " " << gender << " " << uid << " " << phone << endl;
        }
        count++;
    }
    userFile.close();
    tempFile.close();

    if(count == 0)
    {
        cout << "No reacords yet\n";
    }


    if(flag == false)
    {
        cout << "---------------------------------------------\n";
        cout << "\t\t\t\tUser not found in the file\n";
        cout << "---------------------------------------------\n\n";

        cout << "Redirecting to the users panel";
        for(int a = 1; a < 8; a++)
        {
            cout << "...";
            cout.flush();
            sleep(1);
        }
        usersPanel();
    }
    else{
        remove("users.text");
        rename("temp.txt", "users.txt");
    }
}

// Defination of the books operation functions
void addBook(){
    label2:
        system("clear");
        char name[50], author[50], publisher[50];
        double bookid, quantity;
        bool flag = false;
        //create a books file
        ofstream booksFile("books.txt", ios::out | ios::app);
        // if books file exists, and is open: add book
        if(booksFile.is_open())
        {
            cout << "Enter the name of the book: ";
            cin.getline(name, sizeof(name));
            cout << "Enter the author name: ";
            cin.getline(author, sizeof(author));
            cout << "Enter the publisher name: ";
            cin.getline(publisher, sizeof(publisher));
            cout << "Enter the book id: ";
            cin >> bookid;
            cin.ignore();
            cout << "Enter the quantity of books: ";
            cin >> quantity;
            cin.ignore();

            booksFile << name << " " << author << " " << publisher << " " << bookid << " " << quantity << endl;

            cout << "\nBook successfully added to the database\n\n\n";

            flag = true;
        }
        // else, handle error
        else
        {
            cout << "--------------------------------------------\n";
            cout << "\t\t\tError opening the file\n";
            cout << "--------------------------------------------\n";
        }
        // close file
        booksFile.close();
        // prompt whether to add more book or not
        if(flag == true)
        {
            char ch;
            cout << "Do you wanna add more books[y/n]: ";
            cin >> ch;
            cin.ignore();
        // if yes, goto createbooks
            if( ch == 'y' || ch == 'Y')
            {
                goto label2;
            } 
        // else return to books panel
            else {
                cout << "\n\nReturning to the books panel";
                for(int a = 1; a < 4; a++){
                    cout << "...";
                    cout.flush();
                    sleep(1);
                }
                booksPanel();
            }

        }
}
void modifyBook(){
    system("clear");
    char name[50], name1[50], author[50], author1[50], publisher[50], publisher1[50];
    double id, quantity, id1, quantity1, find;
    // open books file for reading
    ifstream booksFile("books.txt");
    // create a temporary file for writing into
    ofstream tempBook("temp.txt");
    // loop through each line in the file
    while(!booksFile.is_open() || !tempBook.is_open())
    {
        cout << "Error opening the files...\n\n";
        cout << "Returning to the books panel";
        for( int a = 1; a<5; a++){
            cout << "...";
            cout.flush();
            sleep(1);
        }
    }
    // get the id of the book to be modified
    cout << "Enter the id of the book you wanna modify: ";
    cin >> find;
    cin.ignore();
    int compare;
    bool book_found = false;

    while(booksFile >> name >> author >> publisher >> id >> quantity)
    {
    // compare with the list of books in the database
        // compare = strcmp(find, id);
    // if exist copy each prompt user for modification
        if(find == id)
        {
            cout << "\n--------------------------------------------------\n";
            cout << "\t\t\tBook info found\n";
            cout << "----------------------------------------------------\n\n";

            cout << "Enter the book name: ";
            cin.getline(name1, sizeof(name1));
            cout << "Enter the author name: ";
            cin.getline(author1, sizeof(author1));
            cout << "Enter the publisher name: ";
            cin.getline(publisher1, sizeof(publisher1));
            cout << "Enter the book Id: ";
            cin >> id1;
            cin.ignore();
            cout << "Enter the quantity: ";
            cin >> quantity1;
            cin.ignore();

    // update data in the tempfile
            tempBook << name1 << " " << author1 << " " << publisher1 << " " << id1 << " " << quantity1 << endl;
            
            book_found = true;
        }
        else 
        {
    // else copy the previous data into the tempfile
            tempBook << name << " " << author << " " << publisher << " " << id << " " << quantity << endl;
        }
    }
    // close both files
    tempBook.close();
    booksFile.close();

    // remove the books.txt file
    remove("books.txt");
    // rename temp.txt to books.txt
    rename("temp.txt", "books.txt");

    if(book_found == false)
    {
        cout << "\nNo book with id: " << find << " found\n\n";
        cout << "Returning to the books panel";
        for( int a = 1; a < 5; a++)
        {
            cout << "...";
            cout.flush();
            sleep(1);
        }
        booksPanel();
    }
    else
    {
        cout << "\nBook ID: " << find << " modified successfully\n\n";
        cout << "Returning to the books panel";
        for(int a = 1; a < 5; a++)
        {
            cout << "...";
            cout.flush();
            sleep(1);
        }
        booksPanel();
    }

}
void listBook(){
    system("clear");

    char name[50], author[50], publisher[50];
    double id, quantity;
    bool is_there_record = false;
    ifstream listBooks("books.txt");

    if(!listBooks.is_open())
    {
        cout << "\nError opening the file...";
        cout << "Aborting, and returnung to books panel";
        for(int a = 1; a<5; a++)
        {
            cout << "...";
            cout.flush();
            sleep(1);
        }
        booksPanel();
    }

    cout << "\n\t\t------------------------------------------------------\n";
    cout << "\t\t\t\tListing books in database\n";
    cout << "\t\t--------------------------------------------------------\n\n";
    cout << "\tBook name\t\tAuthor name\t\t\tpublisher\t\tid\t\tquantity\n\n\n";

    while(listBooks >> name >> author >> publisher >> id >> quantity)
    {
        cout << "\t" << name << "\t\t\t" << author << "\t\t\t\t" << publisher << "\t\t" << id << "\t\t" << quantity << endl;
        is_there_record = true;
    }
    listBooks.close();

    if(is_there_record = false)
    {
        cout << "\n\n------------------------------------------------------\n";
        cout << ">>>>No records in the database\n";
        cout << "----------------------------------------------------------\n";

        cout << "\n\nReturning to the books panel";
        for(int a = 1; a < 5; a++)
        {
            cout << "...";
            cout.flush();
            sleep(1);
        }
        booksPanel();
    }

    char ch;
    cout << "\n\nPress any key to return to the books panel";
    ch = getchar();
    booksPanel();
}
void rentBook(){
    system("clear");
    cout << "Renting a Book\n\n\n";
}
void searchBook(){
    system("clear");
    char name[50], find[50], author[50], publisher[50];
    double id, quantity;

    fstream booksDB("books.txt");
    if(!booksDB.is_open())
    {
        cout << "\nError opening the file...";
        cout << "Aborting, and returnung to books panel";
        for(int a = 1; a<5; a++)
        {
            cout << "...";
            cout.flush();
            sleep(1);
        }
        booksPanel();
    }

    cout << "Enter the name of book: ";
    cin.getline(find, sizeof(find));

    int compare;
    bool available = false;
    
    while(booksDB >> name >> author >> publisher >> id >> quantity)
    {   
        compare = strcmp(find, name);
        if(compare == 0)
        {
            cout << "\n----------------------------------\n";
            cout << ">>>>Book found\n";
            cout << "------------------------------------\n";

            cout << "\tBook name\t\tAuthor name\t\t\tpublisher\t\tid\t\tquantity\n\n\n";
            cout << "\t" << name << "\t\t\t" << author << "\t\t\t\t" << publisher << "\t\t" << id << "\t\t" << quantity << endl;

            available = true;

            char ch;
            cout << "\n\nPress any key to return to the books panel";
            ch = getchar();
            booksPanel();
        }
    }
    booksDB.close();

    if(available == false)
    {
        cout << "\n\n------------------------------------------------------\n";
        cout << ">>>>No records in the database\n";
        cout << "----------------------------------------------------------\n";

        cout << "\n\nReturning to the books panel";
        for(int a = 1; a < 5; a++)
        {
            cout << "...";
            cout.flush();
            sleep(1);
        }
        booksPanel();
    }
}
void deleteBook(){
    system("clear");
    char fname[50], lname[50], gender, find[50];
    double uid, phone;

    ifstream userFile("books.txt");
    ofstream tempFile("temp.txt");

    if(!userFile.is_open() || !tempFile.is_open())
    {
        cerr << "Error opening file....\n\n";
        cout << "Redirecting to the user panel";
        for( int a = 1; a < 5; a++)
        {
            cout << "...";
            cout.flush();
            sleep(1);
        }
        usersPanel();
    }
    cout << "What is the name of the user you would like to delete: ";
    cin.getline(find, sizeof(find));

    int compare, count = 0;
    bool flag = false;

    while(userFile >> fname >> lname >> gender >> uid >> phone)
    {
        compare = strcmp(find, fname);
        if( compare == 0 )
        {
            cout << "\n\t\t-----------------------------------------------\n";
            cout << "\t\t\tUser record deleted\n";
            cout << "\t\t-----------------------------------------------\n\n";

            flag = true;
        } 
        else
        {
            tempFile << fname << " " << lname << " " << gender << " " << uid << " " << phone << endl;
        }
        count++;
    }
    userFile.close();
    tempFile.close();

    if(count == 0)
    {
        cout << "No reacords yet\n";
    }


    if(flag == false)
    {
        cout << "---------------------------------------------\n";
        cout << "\t\t\t\tUser not found in the file\n";
        cout << "---------------------------------------------\n\n";

        cout << "Redirecting to the users panel";
        for(int a = 1; a < 8; a++)
        {
            cout << "...";
            cout.flush();
            sleep(1);
        }
        usersPanel();
    }
    else{
        remove("users.text");
        rename("temp.txt", "users.txt");
    }
}