#include<iostream>

typedef int LIST_SIZE; // accumulates the list size of the linked list, since there is no more limit
typedef int USER_INPUT; // user input for main.cpp
typedef int ETC; // for other use

using namespace std;


struct List {

    int Data;
    List* Next;

}*GenesisBlock = NULL, *PlatformBlock, *DataSet;

// function to test if list is empty
bool LinkedListEmpty() {

    if(GenesisBlock==NULL)
        return 1;
    else 
        return 0;

}

// prints items in the list
void LinkedListPrintItems() {

    ETC IDX;

    if(LinkedListEmpty()) 
    cout << "The List is empty!\n";

    else {

        PlatformBlock = GenesisBlock;
        IDX = 1;

        while(PlatformBlock!=NULL){

            cout << "\nThe value of Node [" << IDX << "] = " << PlatformBlock->Data << endl;
            ++IDX;
            PlatformBlock = PlatformBlock->Next;


        }

    }

}

// initializes and makes X number of items in the list
void LinkedListAddItems(LIST_SIZE NumberOfNodes) {

    for(ETC IDX = 1; IDX<=NumberOfNodes; ++IDX){

        DataSet = (List*) malloc(sizeof(List));
        cout << "\nEnter the value of Node " << IDX << ": ";
        cin >> DataSet->Data;
        DataSet->Next = NULL;

        if(GenesisBlock==NULL){

            GenesisBlock = DataSet;
            PlatformBlock = DataSet;
            // Sets the first node to the start/genesis node

        }

        else{

            PlatformBlock->Next = DataSet;
            PlatformBlock = DataSet;
            // moves the platform forward

        }

    }

}

// inserts items from the list
void LinkedListInsertItems(USER_INPUT InsertData, LIST_SIZE Position) {

    List *InsertList, *Previous, *Current;
    ETC IDX;

    InsertList = (List*) malloc(sizeof(List));
    InsertList->Data = InsertData;
    InsertList->Next = NULL;

    if(LinkedListEmpty())
        cout << "The List is Empty!\n";

    else if(Position == 1) {

        InsertList->Next = GenesisBlock;
        GenesisBlock = InsertList;
        // sets data if position selects is 1 (which is the genesis block)

    }

    else{

        Previous = GenesisBlock;
        Current = GenesisBlock->Next;

        IDX = 1;

        // moves the Previous and Current pointers to desired Position
        // NOTE: the position must always be subtracted to two 
        while(IDX <= Position-2) {

            Previous = Previous->Next;
            Current = Current->Next;
            ++IDX;

        }

        // actual insertion phase
        Previous->Next = InsertList;
        InsertList->Next = Current;

    }

}

void LinkedListDeleteItems (USER_INPUT DeleteData) {

    List *Previous, *Eliminate;

    Eliminate = GenesisBlock;

    if(LinkedListEmpty())
        cout << "The List is Empty!\n";

    else {

        if(GenesisBlock->Data = DeleteData) {

            GenesisBlock = GenesisBlock->Next;
            free(Eliminate);

            cout << "\nItem Successfully Deleted!\n";

        }

        else{

            while(Eliminate != NULL && Eliminate->Data != DeleteData){

                Previous = Eliminate;
                Eliminate = Eliminate->Next;

            }

            if(Eliminate==NULL)
                cout << "\nNode to be deleted doesn't exist!\n";

            else{

                Previous->Next = Eliminate->Next;
                free(Eliminate);

                cout << "\nItem Successfully Deleted!\n";

            }

        }

    }

}

void LinkedListLocateItems (USER_INPUT SearchData) {

    ETC IDX;

    if(LinkedListEmpty())
        cout << "\nThe list is empty!\n";

    else{

        IDX = 1;
        PlatformBlock = GenesisBlock;

        while(PlatformBlock != NULL && PlatformBlock->Data != SearchData){

            PlatformBlock = PlatformBlock->Next;
            ++IDX;

        }

        if(PlatformBlock == NULL)
            cout << "\nNode does not exist.\n";

        else
            cout << "\nNode requested is at Node [ " << IDX << " ].\n";

    }

}

LIST_SIZE LinkedListCountItems() {

    LIST_SIZE IDX;

    IDX = 0;
    PlatformBlock = GenesisBlock;

    while(PlatformBlock != NULL) {

        ++IDX;
        PlatformBlock = PlatformBlock->Next;

    }

    return IDX;

}