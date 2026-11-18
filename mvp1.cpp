#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// 1. Structure to hold slot details
struct Slot {
    int id;
    string type;
    bool isOccupied;
    string plate;
    time_t entryTime;
};

// 2. Main System Class
class ParkingSystem {
private:
    vector<Slot> slots;

    // Hardcoded rates
    int getRate(string type) {
        if (type == "Bike") return 10;
        if (type == "Car") return 20;
        return 40; // Truck
    }

public:
    // Constructor: Create 3 slots for demo (1 Bike, 1 Car, 1 Truck)
    ParkingSystem() {
        slots.push_back({1, "Bike", false, "", 0});
        slots.push_back({2, "Car", false, "", 0});
        slots.push_back({3, "Truck", false, "", 0});
    }

    // --- PARK VEHICLE ---
    void park() {
        int typeChoice;
        string plate;

        cout << "\n1. Bike\n2. Car\n3. Truck\nChoose type: ";
        cin >> typeChoice;

        string typeName = "Bike";
        if (typeChoice == 2) typeName = "Car";
        if (typeChoice == 3) typeName = "Truck";

        cout << "Enter Plate Number: ";
        cin >> plate;

        // Check if already parked
        for (int i = 0; i < slots.size(); i++) {
            if (slots[i].isOccupied && slots[i].plate == plate) {
                cout << "Error: This vehicle is already parked!\n";
                return;
            }
        }

        // Find free slot and park
        for (int i = 0; i < slots.size(); i++) {
            if (slots[i].type == typeName && slots[i].isOccupied == false) {
                slots[i].isOccupied = true;
                slots[i].plate = plate;
                slots[i].entryTime = time(0);

                cout << "\n--- ENTRY TICKET ---\n";
                cout << "Slot ID: " << slots[i].id << "\n";
                cout << "Plate: " << plate << "\n";
                cout << "Rate: Rs " << getRate(typeName) << "/hr\n";
                cout << "--------------------\n";
                return;
            }
        }
        cout << "No free slot available for " << typeName << "\n";
    }

    // --- UNPARK VEHICLE ---
    void unpark() {
        string plate;
        cout << "\nEnter Plate Number to Exit: ";
        cin >> plate;

        for (int i = 0; i < slots.size(); i++) {
            if (slots[i].isOccupied && slots[i].plate == plate) {
                
                // Calculate time
                time_t exitTime = time(0);
                long long seconds = exitTime - slots[i].entryTime;
                long long hours = seconds / 3600;
                if (hours < 1) hours = 1; // Minimum 1 hour

                // Calculate bill
                int rate = getRate(slots[i].type);
                long long total = hours * rate;

                cout << "\n--- BILL ---\n";
                cout << "Plate: " << plate << "\n";
                cout << "Hours: " << hours << "\n";
                cout << "Total: Rs " << total << "\n";
                cout << "------------\n";

                // Free the slot
                slots[i].isOccupied = false;
                slots[i].plate = "";
                return;
            }
        }
        cout << "Vehicle not found!\n";
    }
};

// 3. Main Menu
int main() {
    ParkingSystem sys;
    int choice = 0;

    while (choice != 3) {
        cout << "\n=== SMART PARKING ===\n";
        cout << "1. Park Vehicle\n";
        cout << "2. Unpark Vehicle\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) sys.park();
        else if (choice == 2) sys.unpark();
        else if (choice == 3) cout << "Exiting...\n";
        else cout << "Invalid choice!\n";
    }

    return 0;
}