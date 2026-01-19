#include <cctype>
#include <iostream>
#include <iomanip>
#include "utils.h"
#include "lostfound.h"

using namespace std;

extern int countItems;

void toLower(char* str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

void viewHistory(int* id, char name[][20], char color[][20],
                 char location[][20], char date[][15],
                 char reporter[][30], char claimer[][30],
                 char dateReported[][15], char dateClaimed[][15],
                 int* claimed) {

    cout << "\n====================== ITEM HISTORY ========================\n";
    for (int i = 0; i < countItems; i++) {
        cout << id[i] << " | " << name[i] << " | "
             << reporter[i] << " | " << claimer[i] << " | "
             << (claimed[i] ? "Claimed" : "Lost") << endl;
    }
}
