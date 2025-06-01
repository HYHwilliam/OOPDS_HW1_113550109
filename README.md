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

Use a C++ compiler such as `g++`:

```bash
g++ main.cpp Library.cpp Book.cpp -o library
./library


Library Menu
Once the program starts, users can interact with the following menu:
Library Menu:
1. Add Book
2. Search Book
3. Checkout Book
4. Return Book
5. List All Books
6. Exit
Enter your choice (1-6):
Users should enter a valid numeric option (1-6) to proceed.

Input Formats
Below are the expected input formats for various functionalities:
1. Add a Book
Users will be prompted to enter book details:
- Title: Any string, case-insensitive
- Author: Any string, case-insensitive
- Genre: Any string, case-insensitive
- Published Year: 4-digit integer (e.g., 2001)
- Available Copies: Positive integer (e.g., 5)
Example:
Title: The Great Gatsby
Author: F. Scott Fitzgerald
Genre: Fiction
Published Year: 1925
Available Copies: 3
Book added successfully.


If a book with the same title, author, genre, and year exists, the system will ask if you want to update the existing copies.

2. Search a Book
Users can search books by title, author, genre, or year using the Search Book option.
Search by Title
- Exact matches are prioritized.
- Partial matches will also be displayed.
- Case-insensitive search is supported.
Example:
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


Search by Author
- Enter the author's name to find books they have written.
Example:
Enter the author of the book: Hemingway
Exact matches:
--------------------------------------------------
Title  : The Old Man and the Sea
Author : Hemingway
Genre  : Fiction
Year   : 1952
Copies : 10
--------------------------------------------------


Search by Genre
- Enter the genre to filter books within that category.
Example:
Enter the genre: Fiction
Exact matches:
--------------------------------------------------
Title  : The Great Gatsby
Author : F. Scott Fitzgerald
Genre  : Fiction
Year   : 1925
Copies : 3
--------------------------------------------------


Search by Year
- Enter a 4-digit year to find books published in that year.
Example:
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
Example:
Enter book title to checkout: Harry Potter
Book checked out successfully.
Now Available: 1


If a book has 0 available copies, the system will notify:
Book is not available now.



4. Return a Book
Users can return a borrowed book by entering its title.
Example:
Enter book title to return: Harry Potter
Book returned successfully.
Now Available: 2


If the book has never been checked out:
This book is not lended, so it's impossible to return.



5. List All Books
Displays all books in the library sorted alphabetically:
============================================ Book List ============================================
No.   Title                          Author              Genre             Year  Copies
----------------------------------------------------------------------------------------------------
1     Harry Potter                   J.K. Rowling       Magic             2001  2
2     Les Miserables                 Victor Hugo        Tragedy           1862  1
3     The Old Man and the Sea         Hemingway         Novel             1952  10
====================================================================================================



Error Handling
- Invalid input length detection: Users must input correct formats (e.g., 4-digit year).
- Case-insensitive searching: Ensures more accurate book retrieval.
- Handling unavailable books: Users cannot check out books with zero copies remaining.
- Duplicate book detection: If the same book exists, users are prompted to update copies instead of adding duplicates.
