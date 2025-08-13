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

