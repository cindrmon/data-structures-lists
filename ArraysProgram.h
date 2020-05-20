#include <iostream>
#include"ListsUsingArrays.h"

using namespace std;

typedef int ChoiceType;

// Main Menu
void Menu(ARRAY_SIZE listSize)
{

    cout << "====================================\n";
    cout << "LIST (ARRAY) PROGRAM\n";
    cout << "====================================\n";
    cout << "There are currently " << ArrayCountItem(listSize) << " items in the list.\n";

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
}

USER_INPUT ChoicePicker()
{

    USER_INPUT Choice;

    cout << "Enter the number of your choice: ";
    cin >> Choice;

    while ((Choice < 1) || (Choice > 5))
    {

        cout << "Invalid Choice! Please try again!\n"
             << "Enter the number of your choice (1-5): ";
        cin >> Choice;
    }

    return Choice;
}

void ArrayMain()
{

    ARRAY List[MAX_SIZE] = {0}, NewData, SearchData;
    ARRAY_SIZE ListSize = -1, Position;
    USER_INPUT Choice;

    do
    {

        Menu(ListSize);
        Choice = ChoicePicker();

        switch (Choice)
        {

        case 1: // add an item

            cout << endl
                 << "Enter position: ";
            cin >> Position;

            while (Position < 1 || Position > ArrayCountItem(ListSize) + 1)
            {
                cout << endl
                     << "POSITION IS INVALID... TRY AGAIN!!!";
                cout << endl
                     << "Enter position: ";
                cin >> Position;
            }

            cout << endl
                 << "Enter new data: ";
            cin >> NewData;

            ArrayAddItem(List, NewData, Position - 1, &ListSize);

            break;

        case 2: // delete an item

            if (ArrayListEmpty(ListSize))
            {
                cout << endl
                     << "The List is Empty!" << endl;
                break;
            }

            else
            {

                cout << endl
                     << "Enter position to delete: ";
                cin >> Position;
                while (Position < 1 || Position > ArrayCountItem(ListSize))
                {
                    cout << endl
                         << "POSITION IS INVALID... TRY AGAIN!!!";
                    cout << endl
                         << "Enter position: ";
                    cin >> Position;
                }

                ArrayDeleteItem(List, Position - 1, &ListSize);
                break;
            }

        case 3: // locate an item

            if (ArrayListEmpty(ListSize))
            {
                cout << endl
                     << "The List is Empty!" << endl;
                break;
            }

            else
            {

                cout << "\nEnter Search Data: ";
                cin >> SearchData;

                ArrayLocateItem(List, SearchData, ListSize);

                break;
            }

        case 4: // print all Items

            ArrayPrintItems(List, ListSize);
            break;

        default:

            cout << "\nTHANK YOU FOR USING THIS PROGRAM";
            cout << "\nGOOD BYE!!!";
        }
    } while (Choice != 5);
}