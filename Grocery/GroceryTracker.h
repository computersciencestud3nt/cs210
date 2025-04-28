#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>

class GroceryTracker {
private:
    std::map<std::string, int> frequencyMap;

public:
    GroceryTracker();
    void LoadData(const std::string& filename);
    int GetItemFrequency(const std::string& item) const;
    void PrintAllFrequencies() const;
    void PrintHistogram() const;
    void SaveToBackupFile(const std::string& filename) const;
};

#endif