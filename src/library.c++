#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Book node for linked list
struct Book {
    int id;
    string title;
    string author;
    bool borrowed;
    Book* next;
};

// Undo action type
enum ActionType { BORROW, RETURN };

struct Action {
    ActionType type;
    int bookId;
};

Book* head = nullptr;
stack<Action> undoStack;

// Add book to front of linked list
void addBook(int id, string title, string author) {
    Book* newBook = new Book{id, title, author, false, head};
    head = newBook;
}

// Find book by id
Book* findBook(int id) {
    Book* cur = head;
    while (cur) {
        if (cur->id == id) return cur;
        cur = cur->next;
    }
    return nullptr;
}

// Search books by title (case-sensitive, simple substring match)
void searchBooks(string query) {
    Book* cur = head;
    bool found = false;
    while (cur) {
        if (cur->title.find(query) != string::npos) {
            cout << "ID: " << cur->id << ", Title: " << cur->title
                 << ", Author: " << cur->author
                 << ", Status: " << (cur->borrowed ? "Borrowed" : "Available") << "\n";
            found = true;
        }
        cur = cur->next;
    }
    if (!found) cout << "No books found with title containing '" << query << "'.\n";
}

// Borrow book by id
void borrowBook(int id) {
    Book* book = findBook(id);
    if (book && !book->borrowed) {
        book->borrowed = true;
        undoStack.push({BORROW, id});
        cout << "Borrowed \"" << book->title << "\" successfully.\n";
    } else {
        cout << "Book not available.\n";
    }
}

// Return book by id
void returnBook(int id) {
    Book* book = findBook(id);
    if (book && book->borrowed) {
        book->borrowed = false;
        undoStack.push({RETURN, id});
        cout << "Returned \"" << book->title << "\" successfully.\n";
    } else {
        cout << "Book was not borrowed.\n";
    }
}

// Undo last borrow/return action
void undo() {
    if (undoStack.empty()) {
        cout << "Nothing to undo.\n";
        return;
    }

    Action last = undoStack.top();
    undoStack.pop();

    Book* book = findBook(last.bookId);
    if (!book) {
        cout << "Undo failed: book not found.\n";
        return;
    }

    if (last.type == BORROW) {
        book->borrowed = false;
        cout << "Undo borrow: \"" << book->title << "\" is now available.\n";
    } else {
        book->borrowed = true;
        cout << "Undo return: \"" << book->title << "\" is now borrowed.\n";
    }
}

int main() {
    // Add sample books
    addBook(1, "1984", "George Orwell");
    addBook(2, "Brave New World", "Aldous Huxley");
    addBook(3, "Fahrenheit 451", "Ray Bradbury");
    addBook(4, "To Kill a Mockingbird", "Harper Lee");
    addBook(5, "The Great Gatsby", "F. Scott Fitzgerald");
    addBook(6, "Moby-Dick", "Herman Melville");
    addBook(7, "War and Peace", "Leo Tolstoy");
    addBook(8, "Pride and Prejudice", "Jane Austen");
    addBook(9, "The Catcher in the Rye", "J.D. Salinger");
    addBook(10, "Animal Farm", "George Orwell");
    addBook(11, "The Hobbit", "J.R.R. Tolkien");
    addBook(12, "The Lord of the Rings", "J.R.R. Tolkien");
    addBook(13, "Crime and Punishment", "Fyodor Dostoevsky");
    addBook(14, "The Odyssey", "Homer");
    addBook(15, "Les Misérables", "Victor Hugo");


    while (true) {
        cout << "\nOptions: search, borrow, return, undo, exit\nEnter choice: ";
        string choice;
        cin >> choice;

        if (choice == "search") {
            cout << "Enter title to search: ";
            string query; 
            cin.ignore();
            getline(cin, query);
            searchBooks(query);

        } else if (choice == "borrow") {
            cout<<"1,2,3,4,5,6,7,8,9,10,11,12,13,14,15";
            cout <<"\nEnter book ID to borrow: ";
            int id; cin >> id;
            borrowBook(id);

        } else if (choice == "return") {
            cout<<"1,2,3,4,5,6,7,8,9,10,11,12,13,14,15";
            cout <<"\nEnter book ID to return: ";
            int id; cin >> id;
            returnBook(id);

        } else if (choice == "undo") {
            undo();

        } else if (choice == "exit") {
            break;

        } else {
            cout << "Invalid choice.\n";
        }
    }

    // Cleanup linked list memory
    while (head) {
        Book* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}