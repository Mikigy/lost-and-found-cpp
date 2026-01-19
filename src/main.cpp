#include <iostream>
#include "item_management.h"
#include "search.h"
#include "claim.h"
#include "utils.h"

using namespace std;

const int MAX = 100;
int countItems = 0;

int main() {
    int id[MAX], claimed[MAX] = {0};
    char name[MAX][20], color[MAX][20], location[MAX][20];
    char date[MAX][15], secret[MAX][20];
    char reporter[MAX][30], claimer[MAX][30];
    char dateReported[MAX][15], dateClaimed[MAX][15];

    int choice;

    do {
        cout << "\n1.Add\n2.View\n3.Search\n4.Claim\n5.History\n6.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem(id, name, color, location, date, secret,
                        reporter, claimer, dateReported, dateClaimed, claimed);
                break;
            case 2:
                viewLostItems(id, name, color, location, date, claimed);
                break;
            case 3:
                searchItem(name, color, location, date, claimed);
                break;
            case 4:
                claimItem(id, secret, claimer, dateClaimed, claimed);
                break;
            case 5:
                viewHistory(id, name, color, location, date,
                            reporter, claimer, dateReported, dateClaimed, claimed);
                break;
        }
    } while (choice != 6);

    return 0;
}