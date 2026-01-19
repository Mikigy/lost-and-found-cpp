#include <iostream>
#include <iomanip>
#include <cstring>
#include "item_management.h"

using namespace std;

extern int countItems;

void addItem(int* id, char name[][20], char color[][20],
             char location[][20], char date[][15],
             char secret[][20], char reporter[][30],
             char claimer[][30],
             char dateReported[][15], char dateClaimed[][15],
             int* claimed) {

    cout << "\n====================== ADD LOST ITEM =======================\n";

    id[countItems] = countItems + 1;
    claimed[countItems] = 0;
    strcpy(claimer[countItems], "---");
    strcpy(dateClaimed[countItems], "---");

    cin.ignore();
    cout << "Reporter Name: ";  cin.getline(reporter[countItems], 30);
    cout << "Item Name: ";      cin >> name[countItems];
    cout << "Color: ";          cin >> color[countItems];
    cout << "Location: ";       cin >> location[countItems];
    cout << "Date (DD-MM): ";   cin >> date[countItems];
    cout << "Date Reported: ";  cin >> dateReported[countItems];
    cout << "Secret Mark: ";    cin >> secret[countItems];

    countItems++;
    cout << "\nItem added successfully!\n";
}

void viewLostItems(int* id, char name[][20], char color[][20],
                   char location[][20], char date[][15], int* claimed) {

    cout << "\n====================== LOST ITEMS LIST =====================\n";
    cout << left << setw(5) << "ID" << setw(20) << "Item"
         << setw(15) << "Color" << setw(20) << "Location"
         << setw(12) << "Date" << endl;

    for (int i = 0; i < countItems; i++) {
        if (!claimed[i]) {
            cout << setw(5) << id[i]
                 << setw(20) << name[i]
                 << setw(15) << color[i]
                 << setw(20) << location[i]
                 << setw(12) << date[i] << endl;
        }
    }
}