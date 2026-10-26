#include <iostream>
#include <limits>
#include <string>
#include "GroceryTracker.h"

using namespace std;

int main() {
    GroceryTracker tracker;

    // Load the grocery data when the program starts.
    tracker.loadData("CS210_Project_Three_Input_File.txt");

    // Automatically create the required backup file.
    tracker.createBackupFile("frequency.dat");

    int menuChoice = 0;

    while (menuChoice != 4) {
        cout << endl;
        cout << "==============================" << endl;
        cout << "       CORNER GROCER" << endl;
        cout << "==============================" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Display all item frequencies" << endl;
        cout << "3. Display histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> menuChoice;

        // Check for non-numeric input.
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please enter a number from 1 to 4."
                << endl;

            continue;
        }

        if (menuChoice == 1) {
            string itemName;

            cout << "Enter the item you wish to search for: ";
            cin >> itemName;

            int frequency = tracker.getItemFrequency(itemName);

            cout << itemName << " was purchased "
                << frequency << " time(s)." << endl;
        }
        else if (menuChoice == 2) {
            cout << endl;
            cout << "Item Frequencies" << endl;
            cout << "----------------" << endl;

            tracker.printAllFrequencies();
        }
        else if (menuChoice == 3) {
            cout << endl;
            cout << "Item Histogram" << endl;
            cout << "--------------" << endl;

            tracker.printHistogram();
        }
        else if (menuChoice == 4) {
            cout << "Thank you for using Corner Grocer." << endl;
        }
        else {
            cout << "Invalid choice. Please enter a number from 1 to 4."
                << endl;
        }
    }

    return 0;
}