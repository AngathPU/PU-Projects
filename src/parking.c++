#include <iostream>
#include <string>
using namespace std;

#define MAX_CAPACITY 5  // Maximum parking slots

// Structure to represent a parked car
struct Car {
    string plate;   // Car plate number
    Car* next;      // Pointer to next car in the list
};

// Global variables
Car* head = nullptr;     // Head pointer for linked list
int current_count = 0;   // Number of currently parked cars

// Function to park a car (Entry)
void parkCar(const string& plate) {
    if (current_count >= MAX_CAPACITY) {
        cout << "Parking Lot FULL! Car " << plate << " denied entry." << endl;
        return;
    }

    Car* newCar = new Car();
    newCar->plate = plate;
    newCar->next = head;  // Insert at head for simplicity
    head = newCar;

    current_count++;
    cout << "Car " << plate << " parked successfully." << endl;
}

// Function to remove a car (Exit)
void removeCar(const string& plate) {
    Car* temp = head;
    Car* prev = nullptr;

    // Search for the car
    while (temp != nullptr && temp->plate != plate) {
        prev = temp;
        temp = temp->next;
    }

    // If car not found
    if (temp == nullptr) {
        cout << "Car " << plate << " not found in lot." << endl;
        return;
    }

    // Remove node
    if (prev == nullptr) {
        head = temp->next;  // Removing head
    } else {
        prev->next = temp->next;
    }

    delete temp;
    current_count--;
    cout << "Car " << plate << " exited successfully." << endl;
}

// Function to display all parked cars
void displayLot() {
    cout << "\n--- Parking Lot Status (" << current_count 
         << "/" << MAX_CAPACITY << ") ---\n";

    if (head == nullptr) {
        cout << "Lot is empty." << endl;
        return;
    }

    Car* temp = head;
    while (temp != nullptr) {
        cout << "Car " << temp->plate << endl;
        temp = temp->next;
    }
    cout << "-----------------------------" << endl;
}

// Cleanup memory before exit
void cleanup() {
    while (head != nullptr) {
        Car* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function with menu
int main() {
    int choice;
    string plate;

    do {
        cout << "\n=== Smart Parking Lot Management ===\n";
        cout << "1. Park a Car (Entry)\n";
        cout << "2. Remove a Car (Exit)\n";
        cout << "3. Display Lot Status\n";
        cout << "4. Exit Program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter car plate number: ";
                cin >> plate;
                parkCar(plate);
                break;
            case 2:
                cout << "Enter car plate number to remove: ";
                cin >> plate;
                removeCar(plate);
                break;
            case 3:
                displayLot();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while(choice != 4);

    cleanup(); // Free allocated memory before exit
    return 0;
}
