#pragma once
#include <map>
#include <string>

using namespace std;

class GroceryTracker {
public:
    void loadData(string t_fileName);
    void createBackupFile(string t_fileName);
    int getItemFrequency(string t_item);
    void printAllFrequencies();
    void printHistogram();

private:
    map<string, int> m_itemFrequencies;
};