#include<iostream>
#include"ListsUsingLinked.h"

using namespace std;

typedef int ChoiceType;

void Menu() {

    cout << "\n\n====================================\n";
    cout << "LIST (LINKED LISTS) PROGRAM\n";
    cout << "====================================\n";
    cout << "There are currently " << LinkedListCountItems() << " items in the list.\n"; // TODO: insert linked list counter here

    cout << endl
         << endl;
    cout << "====================================\n";
    cout << "Options:\n";
    cout << "(1). Initialize items to the list\n"
         << "(2). Insert item in between list\n"
         << "(3). Delete Item From The list\n"
         << "(4). Locate Items in the list\n"
         << "(5). Print Items in the list\n"
         << "(6). Exit Program\n"
         << "====================================\n";

    cout << endl
         << endl;
}

USER_INPUT ChoicePicker()
{

    USER_INPUT Choice;

    cout << "Enter the number of your choice: ";
    cin >> Choice;

    while ((Choice < 1) || (Choice > 6))
    {

        cout << "Invalid Choice! Please try again!\n"
             << "Enter the number of your choice (1-6): ";
        cin >> Choice;
    }

    return Choice;
}

void LinkedMain() {


     USER_INPUT Choice, NewData, deleteData, searchData;
     LIST_SIZE numberOfNodes, nodePosition;

     Menu();


     do{ 

     Choice = ChoicePicker();

          switch (Choice) {

               case 1:
                    cout << "\nEnter the number of nodes to make: ";
                    cin >> numberOfNodes;

                    LinkedListAddItems(numberOfNodes);
                    break;

               case 2:
                    cout << "\nEnter Position: ";
                    cin >> nodePosition;

                    cout << "Enter data: ";
                    cin >> NewData;

                    LinkedListInsertItems(NewData, nodePosition);
                    break;

               case 3:
                    cout << "\nEnter Data to Delete: ";
                    cin >> deleteData;

                    LinkedListDeleteItems(deleteData);
                    break;

               case 4:
                    cout << "\nEnter Search Data: ";
                    cin >> searchData;

                    LinkedListLocateItems(searchData);
                    break;

               case 5:
                    LinkedListPrintItems();
                    break;

               default:
                    cout << "Thank you for using this program\n"
                         << "Goodbye!";
                         
          }
     }while(Choice!=6);

}