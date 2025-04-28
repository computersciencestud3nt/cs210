#include "GroceryTracker.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm> // I added this becouse my program would not end loop

// Constructor
GroceryTracker::GroceryTracker() {}

// Convert any string to lowercase
std::string GroceryTracker::ToLowerCase(const std::string& str) const {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Load and process input data file
void GroceryTracker::LoadData(const std::string& filename) {
    std::ifstream file(filename);
    std::string item;

    if (!file.is_open()) {
        std::cerr << "Error opening input file.\n";
        return;
    }

    while (file >> item) {
        ++frequencyMap[ToLowerCase(item)];
    }

    file.close();
}

// Return frequency count for a specific item (case-insensitive)
int GroceryTracker::GetItemFrequency(const std::string& item) const {
    std::string normalized = ToLowerCase(item);
    auto it = frequencyMap.find(normalized);
    return it != frequencyMap.end() ? it->second : 0;
}

// Print all items and their frequencies
void GroceryTracker::PrintAllFrequencies() const {
    for (const auto& pair : frequencyMap) {
        std::cout << pair.first << " " << pair.second << "\n";
    }
}

// Print histogram using asterisks to represent frequency
void GroceryTracker::PrintHistogram() const {
    for (const auto& pair : frequencyMap) {
        std::cout << std::left << std::setw(12) << pair.first << " ";
        std::cout << std::string(pair.second, '*') << "\n";
    }
}

// Save all frequencies to a backup file
void GroceryTracker::SaveToBackupFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    for (const auto& pair : frequencyMap) {
        outFile << pair.first << " " << pair.second << "\n";
    }
    outFile.close();
}