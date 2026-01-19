#include "lostfound.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include "search.h"
#include "utils.h"

using namespace std;

extern int countItems;

void searchItem(char name[][20], char color[][20],
                char location[][20], char date[][15], int* claimed) {

    char search[20], temp[20];
    bool found = false;

    cout << "Enter item name: ";
    cin >> search;
    toLower(search);

    for (int i = 0; i < countItems; i++) {
        if (!claimed[i]) {
            strcpy(temp, name[i]);
            toLower(temp);
            if (strstr(temp, search)) {
                cout << "Item: " << name[i] << "\nColor: " << color[i]
                     << "\nLocation: " << location[i]
                     << "\nDate: " << date[i] << "\n\n";
                found = true;
            }
        }
    }

    if (!found) cout << "No item found.\n";
}
