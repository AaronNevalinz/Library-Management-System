# Library Management System (LMS) Documentation

## Overview

The Library Management System (LMS) is a simple console-based application developed in C++ for managing user and book records in a library. The system provides basic functionalities such as adding users, modifying user details, listing users, searching users, deleting users, adding books, modifying book details, listing books, searching books, deleting books, and more.

## Table of Contents
1. Introduction
2. System Operations
3. User Operations
4. Book Operations
5. Main Function
6. Conclusion


### 1. Introduction
   
The Library Management System is designed to help librarians manage user and book information efficiently. It features a simple user interface that allows users to perform various operations, ensuring smooth library management.

### 2. System Operations 

2.1 Password Verification
- The system requires users to enter a password ("aaron") to access the main menu.
- Incorrect password attempts result in a brief delay and a password re-entry prompt.
  
![Screenshot from 2023-12-28 10-29-27](https://github.com/AaronNevalinz/Library-Management-System/assets/76948733/7f6bf1c6-3fde-496f-96b7-3ff2bdbea60a)


2.2 Main Menu
- Users are presented with a main menu, providing options to navigate to the Users Management Panel or the Books Management Panel.
  
![Screenshot from 2023-12-28 10-31-34](https://github.com/AaronNevalinz/Library-Management-System/assets/76948733/f23945d3-eaf7-41f9-8d0e-ab21e64939dd)


### 3. User Operations 

3.1 Users Management Panel

- Add User: Allows the addition of user records, including first name, last name, gender, user ID, and phone number.
- Modify User: Enables modification of user details based on user input.
- List Users: Displays a list of all users in the database.
- List Rentals: Placeholder for future functionality.
- Search User: Searches for a user by first name.
- Delete User: Deletes a user record based on user input.
  
![Screenshot from 2023-12-28 10-32-46](https://github.com/AaronNevalinz/Library-Management-System/assets/76948733/178fcd10-79ac-4af4-9939-5e194c3052f0)


### 4. Book Operations 

4.1 Books Management Panel

- Add Book: Adds book records, including book name, author, publisher, book ID, and quantity.
- Modify Book: Modifies book details based on user input.
- List Books: Displays a list of all books in the database.
- Rent Book: Placeholder for future functionality.
- Search Book: Searches for a book by name.
- Delete Book: Deletes a book record based on user input.
  
![Screenshot from 2023-12-28 10-33-16](https://github.com/AaronNevalinz/Library-Management-System/assets/76948733/bc2b253a-c570-4c73-92d1-7450715f3d47)


### 5. Main Function 

- The `main` function initiates the password verification process and loads the main menu upon successful authentication.
  
![Screenshot from 2023-12-28 10-34-44](https://github.com/AaronNevalinz/Library-Management-System/assets/76948733/4e23806f-863d-4b79-adce-6d7fc0d7952e)


### 6. Conclusion 

The Library Management System is a basic C++ application that facilitates user and book management for a library. The system provides essential functionalities, allowing librarians to add, modify, list, search, and delete user and book records. Future enhancements could include additional features such as book rentals and improved user interfaces.

This documentation provides a high-level overview of the system's functionality and structure. For more detailed information, refer to the comments within the code and the respective function definitions.
