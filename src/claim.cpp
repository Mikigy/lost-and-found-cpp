#include <iostream>
#include <cstring>
#include "claim.h"
#include "lostfound.h"

using namespace std;

extern int countItems;

void claimItem(int* id, char secret[][20], char claimer[][30],
               char dateClaimed[][15], int* claimed) {

    int searchId;
    char userSecret[20];

    cout << "Enter Item ID: ";
    cin >> searchId;

    for (int i = 0; i < countItems; i++) {
        if (id[i] == searchId && !claimed[i]) {
            cout << "Enter secret mark: ";
            cin >> userSecret;

            if (strcmp(secret[i], userSecret) == 0) {
                cin.ignore();
                cout << "Claimer Name: ";
                cin.getline(claimer[i], 30);
                cout << "Date Claimed: ";
                cin >> dateClaimed[i];
                claimed[i] = 1;
                cout << "Item claimed!\n";
            } else {
                cout << "Wrong secret.\n";
            }
            return;
        }
    }
    cout << "Invalid ID.\n";
}
