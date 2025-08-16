🚗 Smart Parking Lot Management – Features
1. Dynamic Parking System
Uses a linked list to manage active parked cars.
Each car is dynamically allocated (new/delete), so memory is only used when cars are present.

2. Entry (Parking a Car)
When a car enters:
Checks if space is available.
If not full → allocates a new node and inserts it at the front of the list.
If full → denies entry with an overflow message.

3. Exit (Removing a Car)
User can remove a car by entering its plate number.
System searches through the list:
If found → car node is deleted and memory is freed.
If not found → message is displayed (Car not found).

4. Lot Status Display
Shows current status in the format:
--- Parking Lot Status (3/5) ---
Car KA-01-AA-1234
Car KA-02-BB-5678
Car KA-03-CC-9999
-----------------------------
Displays number of cars parked vs. total capacity.
If empty, prints "Lot is empty.".

5. Overflow Handling
Prevents exceeding the maximum capacity.
If user tries to park more cars than MAX_CAPACITY, prints:
Parking Lot FULL! Car <plate> denied entry.

6. Memory Management
Dynamically allocates memory for each car (new).
On exit:
Cleans up all allocated memory (delete).
Prevents memory leaks.

7. Menu-Driven Interface
User-friendly console menu:
1 → Park a Car
2 → Remove a Car
3 → Display Lot Status
4 → Exit Program

✅ Summary:
This system simulates a basic smart parking lot:
Keeps track of entries/exits dynamically.
Avoids over-parking (overflow protection).
Displays real-time lot status.
Cleans up memory safely.
