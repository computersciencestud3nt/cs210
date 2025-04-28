#include <iostream>
#include "GroceryTracker.h"

void ShowMenu() {
    std::cout << "\n=== Corner Grocer Menu ===\n";
    std::cout << "1. Search for an item frequency\n";
    std::cout << "2. Display all item frequencies\n";
    std::cout << "3. Display histogram\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    GroceryTracker tracker;
    tracker.LoadData("CS210_Project_Three_Input_File.txt");
    tracker.SaveToBackupFile("frequency.dat");

    int choice;
    std::string item;

    do {
        ShowMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter item name: ";
            std::cin >> item;
            std::cout << item << " was purchased " 
                      << tracker.GetItemFrequency(item) << " times.\n";
            break;
        case 2:
            tracker.PrintAllFrequencies();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}