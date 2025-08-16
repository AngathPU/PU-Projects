Purpose of the Program 
📚 It’s a small E-Library book management system where you can:
-->Search for books by title
-->Borrow books
-->Return books
-->Undo your last borrow or return
It uses:
-->A linked list to store the list of books in memory
-->A stack to remember recent actions so they can be undone
----------------------------------------------------------------------------------------
**⚒️How It Works Internally**
1. Storing Books🫙
Each book has:
-->A unique ID
-->A title and an author
-->A status: either “Available” or “Borrowed”
-->All books are linked together in a chain (linked list) so they can be added easily without using arrays.

2. Finding a Book🔎
-->When you give a book ID, the program starts from the first book and follows the chain until it finds the one with the matching ID.

3. Searching Books 🔍
-->You type part of a title (e.g., “War”).
-->The program checks each book’s title to see if that text appears in it.
-->Any matches are displayed with their ID, title, author, and current status.

5. Returning a Book
You give the book’s ID.
If it’s currently borrowed, it’s marked “Available.”
This action (RETURN + book ID) is also saved in the stack for undo

