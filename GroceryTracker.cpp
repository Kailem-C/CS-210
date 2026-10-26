#include <iostream>
#include <fstream>
#include "GroceryTracker.h"

using namespace std;

// Reads grocery items from the input file and counts each item.
void GroceryTracker::loadData(string t_fileName) {
    ifstream inputFile(t_fileName);
    string item;

    if (!inputFile.is_open()) {
        cout << "Error: Could not open input file." << endl;
        return;
    }

    while (inputFile >> item) {
        m_itemFrequencies[item]++;
    }

    inputFile.close();
}

// Creates the required frequency.dat backup file.
void GroceryTracker::createBackupFile(string t_fileName) {
    ofstream outputFile(t_fileName);

    if (!outputFile.is_open()) {
        cout << "Error: Could not create backup file." << endl;
        return;
    }

    for (const auto& item : m_itemFrequencies) {
        outputFile << item.first << " " << item.second << endl;
    }

    outputFile.close();
}

// Returns the frequency of one grocery item.
int GroceryTracker::getItemFrequency(string t_item) {
    if (m_itemFrequencies.count(t_item) > 0) {
        return m_itemFrequencies[t_item];
    }

    return 0;
}

// Displays every grocery item and its frequency.
void GroceryTracker::printAllFrequencies() {
    for (const auto& item : m_itemFrequencies) {
        cout << item.first << " " << item.second << endl;
    }
}

// Displays every grocery item as a histogram.
void GroceryTracker::printHistogram() {
    for (const auto& item : m_itemFrequencies) {
        cout << item.first << " ";

        for (int i = 0; i < item.second; ++i) {
            cout << "*";
        }

        cout << endl;
    }
}