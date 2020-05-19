#include<iostream>

#include"ListsUsingArrays.h"
#include"ListsUsingLinked.h"

using namespace std;

typedef int ChoiceType;

// Main Menu
void menu(ARRAY_SIZE listSize) {

    cout << "====================================\n";
    cout << "LIST (ARRAY) PROGRAM\n";
    cout << "====================================\n";
    cout << "There are currently " << listCountItem(listSize) << " items in the list.\n";

    cout << endl
         << endl;
    cout << "====================================\n";
    cout << "Options:\n";
    cout << "(1). Add item to the list\n"
         << "(2). Delete Item From The list\n"
         << "(3). Locate Items in the list\n"
         << "(4). Print Items in the list\n"
         << "(5). Exit Program\n"
         << "====================================\n";

   cout << endl
        << endl;

    cout << "Enter the number of your choice";
}

int main() {

}