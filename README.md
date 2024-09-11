# User Management System

## Overview

This project is a user management system implemented in C++ that supports user login, friendship management, and user searches. The system uses a linked list to store user information and a treap data structure for managing friendships.

## Features

- **User Management**: Store and manage user information including username, name, and email.
- **Friendship Management**: Add and remove friends using a treap.
- **User Interaction**: Command-line interface for user operations.

## Requirements

- C++ compiler (e.g., g++, clang++)
- C++17 standard or later

## File Structure

- `main.cpp`: Contains the main logic and user interaction.
- `Linkedlist.h`: Defines the `Linkedlist`, `USER`, and `TreapNode` classes.
- `all-users.in`: Input file with user data (comma-separated).
- `all-users-relations.in`: Input file with user relationships (comma-separated).

## Installation

1. **Clone the Repository**:

    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```

2. **Compile the Code**:

    ```bash
    g++ -std=c++17 -o user_management main.cpp
    ```

    This command will create an executable named `user_management`.

## Usage

1. **Run the Program**:

    ```bash
    ./user_management
    ```

2. **Main Menu**:

    - **Login**: Enter your username to log in.
    - **Exit**: Exit the program.

3. **User Menu** (After logging in):

    - **1- List all friends**: Displays the list of friends for the logged-in user.
    - **2- Search by username**: Search for a user by username and display their information.
    - **3- Add friend**: Add a new friend by entering their username.
    - **4- Remove friend**: Remove a friend by entering their username.
    - **5- People you may know**: List users who are not friends but might be known.
    - **6- Logout**: Log out of the current session.

## Example

```plaintext
******Main menu******
Login
Exit
Login
Enter username: johndoe
******User menu******
1- List all friends
2- Search by username
3- Add friend
4- Remove friend
5- People you may know
6- Logout
