# OOPDS_Hw2  
# 📚 Library Management System

This is a **C++ console-based Library Management System** that allows users to add, search, list, checkout, and return books. It provides basic management functionalities for a small-scale library and is operated via a command-line interface.

---

## ✅ Features

- Add new books with title, author, genre, year, and available copies.
- Prevent duplicate entries by checking if the book already exists.
- Search books by **Title**, **Author**, **Genre**, or **Published Year**.
- Checkout and return books with availability tracking.
- Case-insensitive searches and sorted output.
- Friendly, interactive menu interface.

---

## 🛠 How to Use

### 1. Compile and Run the Program

```bash
g++ main.cpp Library.cpp Book.cpp -o library
./library
2. Library Menu
Once the program starts, users can interact with the following menu:

plaintext
Library Menu:
1. Add Book
2. Search Book
3. Checkout Book
4. Return Book
5. List All Books
6. Exit
Enter your choice (1-6):
Users should enter a valid numeric option (1-6) to proceed.
📥 Input Formats
1. Add a Book
Users will be prompted to enter book details:

plaintext
Title: <book title>
Author: <author name>
Genre: <genre>
Published Year: <4-digit year, e.g., 2023>
Available Copies: <positive integer>
If a book with the same title, author, genre, and year exists, the system will ask:

plaintext
Would you like to update the number of available copies? (Y/N):
2. Search a Book
Users can search books by title, author, genre, or year using the Search Book option.

Example of search by title:

plaintext
Enter the title: Potter
Exact matches:
--------------------------------------------------
Title  : Harry Potter
Author : J.K. Rowling
Genre  : Magic
Year   : 2001
Copies : 2
--------------------------------------------------
Similar title found:
--------------------------------------------------
Title  : The Potter's Craft
Author : Charles Freeman
Genre  : Art
Year   : 1920
Copies : 1
--------------------------------------------------
Search by author:

plaintext
Enter the author of the book: Hemingway
Exact matches:
--------------------------------------------------
Title  : The Old Man and the Sea
Author : Hemingway
Genre  : Fiction
Year   : 1952
Copies : 10
--------------------------------------------------
Search by genre:

plaintext
Enter the genre: Fiction
Exact matches:
--------------------------------------------------
Title  : The Great Gatsby
Author : F. Scott Fitzgerald
Genre  : Fiction
Year   : 1925
Copies : 3
--------------------------------------------------
Search by year:

plaintext
Enter published year: 1862
Exact matches:
--------------------------------------------------
Title  : Les Miserables
Author : Victor Hugo
Genre  : Tragedy
Year   : 1862
Copies : 2
--------------------------------------------------
3. Checkout a Book
Users can borrow a book by entering its title.

plaintext
Enter book title to checkout: Harry Potter
Book checked out successfully.
Now Available: 1
If no copies are available:

plaintext
Book is not available now.
4. Return a Book
Users can return a borrowed book by entering its title.

plaintext
Enter book title to return: Harry Potter
Book returned successfully.
Now Available: 2
If the book was never checked out:

plaintext
This book is not lended, so it's impossible to return.
5. List All Books
Displays all books in the library sorted alphabetically:

plaintext
============================================ Book List ============================================
No.   Title                          Author              Genre             Year  Copies
----------------------------------------------------------------------------------------------------
1     Harry Potter                   J.K. Rowling        Magic             2001  2
2     Les Miserables                 Victor Hugo         Tragedy           1862  1
3     The Old Man and the Sea       Hemingway           Novel             1952  10
====================================================================================================
⚠️ Error Handling
Input length and format validation (e.g., 4-digit year).

Case-insensitive searching.

Handling unavailable books during checkout.

Duplicate book detection and updating copies instead of adding duplicates.

📂 Project Structure
kotlin
複製
編輯
.
├── Book.h        # Book class declaration
├── Book.cpp      # Book class implementation
├── Library.h     # Library class declaration
├── Library.cpp   # Library class implementation
├── main.cpp      # Entry point with menu loop
📌 Requirements
C++11 or newer

Standard C++ libraries: iostream, string, vector, iomanip, etc.

No external dependencies

