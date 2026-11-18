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
    // Constructor: Create 2 slots for each type (6 total)
    ParkingSystem() {
        slots.push_back({1, "Bike", false, "", 0});
        slots.push_back({2, "Bike", false, "", 0});
        slots.push_back({3, "Car", false, "", 0});
        slots.push_back({4, "Car", false, "", 0});
        slots.push_back({5, "Truck", false, "", 0});
        slots.push_back({6, "Truck", false, "", 0});
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

    // --- CHECK AVAILABILITY ---
    void showAvailability() {
        cout << "\n--- LIVE AVAILABILITY ---\n";
        for (int i = 0; i < slots.size(); i++) {
            cout << "Slot " << slots[i].id << " (" << slots[i].type << "): ";
            if (slots[i].isOccupied) {
                cout << "[ OCCUPIED by " << slots[i].plate << " ]\n";
            } else {
                cout << "[ FREE ]\n";
            }
        }
        cout << "-------------------------\n";
    }
};

// 3. Main Menu
int main() {
    ParkingSystem sys;
    int choice = 0;

    while (choice != 4) {
        cout << "\n=== SMART PARKING ===\n";
        cout << "1. Park Vehicle\n";
        cout << "2. Unpark Vehicle\n";
        cout << "3. Check Availability\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) sys.park();
        else if (choice == 2) sys.unpark();
        else if (choice == 3) sys.showAvailability();
        else if (choice == 4) cout << "Exiting...\n";
        else cout << "Invalid choice!\n";
    }

    return 0;
}