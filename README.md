# PU-Projects
my projects in college :-

1.{
Train Route Navigation (Circular Doubly Linked List)
Description
This program simulates a real-time navigation system for a train route using a circular doubly linked list data structure.

The chosen route represents an actual sequence of stations from Vadodara to Bidar, and the circular nature means that after reaching the last station, the train continues back to the first station without stopping.

The program allows the user to move forward (next), move backward (prev), and exit the journey using simple commands.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
**Key Features**
1.Circular Doubly Linked List Implementation

->Each station is represented as a node containing:
   ->Station ID
   ->Station Name
->Pointers to the next and previous stations
->The next pointer of the last station links to the first station.
->The prev pointer of the first station links to the last station.

2.Interactive Navigation
->The user can:
  ->Move forward to the next station.
  ->Move backward to the previous station.
  ->Exit the simulation.

3.Realistic Route
->Route contains the following stations:
Vadodara → Surat → Vasai Road → Lonavala → Pune → Solapur → Kalaburgi → Bidar 

                                   }

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct StationNode {
    int id;
    string name;
    StationNode* next;
    StationNode* prev;
    StationNode(int id, string name) : id(id), name(name), next(nullptr), prev(nullptr) {}
};

class TrainRoute {
private:
    StationNode* head;
    StationNode* tail;
    StationNode* current;
    bool isCircular;

public:
    TrainRoute(bool circular = false) : head(nullptr), tail(nullptr), current(nullptr), isCircular(circular) {}

    void addStation(int id, string name) {
        StationNode* node = new StationNode(id, name);
        if (!head) {
            head = tail = current = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
            if (isCircular) {
                tail->next = head;
                head->prev = tail;
            }
        }
    }

    void nextStation() {
        if (current) current = current->next ? current->next : head;
    }

    void prevStation() {
        if (current) current = current->prev ? current->prev : tail;
    }

    void showCurrent() {
        if (current) {
            cout << "🚉 Now at: " << current->name << endl;
        } else {
            cout << "No station available." << endl;
        }
    }

    void startJourney() {
        string command;
        cout << "\n=== Train Route Navigation ===\n";
        cout << "Type 'next' to go to the next station, 'prev' for previous, 'exit' to stop.\n";
        showCurrent();

        while (true) {
            cout << "Command: ";
            cin >> command;
            if (command == "next") {
                nextStation();
                showCurrent();
            } 
            else if (command == "prev") {
                prevStation();
                showCurrent();
            } 
            else if (command == "exit") {
                cout << "Journey ended.\n";
                break;
            } 
            else {
                cout << "Invalid command. Use 'next', 'prev', or 'exit'.\n";
            }
        }
    }
};

int main() {
    TrainRoute route(true); // Circular route
    route.addStation(1, "Vadodara");
    route.addStation(2, "Surat");
    route.addStation(3, "Vasai Road");
    route.addStation(4, "Lonavala");
    route.addStation(5, "Pune");
    route.addStation(6, "Solapur");
    route.addStation(7, "Kalaburgi");
    route.addStation(8, "Bidar");
    route.startJourney();
    return 0;
}


                                   
