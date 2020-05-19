#include <iostream>

// modifiable array maximum size (must not exceed 2,147,483,647; cuz if u do, i'll go to your fucking house and fucking kill you)
#define MAX_SIZE 1000

typedef int ARRAY; // array only typedef: used only for array variables
typedef int ARRAY_SIZE; // array size typedef: used for manual input of how much an array is based on user input
typedef int USER_INPUT; // USER_INPUT typedef: used for user-inputted data
typedef int ETC; // ETC typedef: used for user-inputted data positions

using namespace std;

/* assume that the list is 
    n elements

    last element == n-1
    --> must keep integer variable to keep track to the last element

    0. Check if list is empty:

    the list is empty if
        last_element < 0

    1. Check if list is full:

    the list is full if
        last_element == MAX_SIZE-1

*/

// function to test if list is full (returns 1 if full or 0 if not full)
int ArrayListFull(ARRAY_SIZE ListSize)
{

    if (ListSize == MAX_SIZE - 1)
        return (1); // outputs that list is indeed full
    else
        return (0); // outputs that list is empty
}

// function to test if list is empty (returns 1 if empty or 0 if it isn't)
int ArrayListEmpty(ARRAY_SIZE ListSize)
{

    if (ListSize < 0)
        return (1);
    else
        return (0);
}

// function to print contents of a list
void ArrayPrintItems(ARRAY aList[], ARRAY_SIZE ListSize)
{

    int IDX;

    // always make this if statement to check if array is empty
    if (ArrayListEmpty(ListSize))
        cout << "\nThe list is empty!\n\n";

    else
        for (IDX = 0; IDX <= ListSize; ++IDX)
            cout << "\nThe value of item [" << IDX + 1 << "] = " << aList[IDX] << ".";
        cout << endl << endl;
}

// function to locate an item in list and print its position (assuming items are unique)
void ArrayLocateItem(ARRAY aList[], USER_INPUT searchValue, ARRAY_SIZE ListSize)
{

    int IDX = 0;

    // always make this if statement to check if array is empty
    if (ArrayListEmpty(ListSize))
        cout << "\nThe list is empty!\n\n";

    else
    {
        while ((IDX != ListSize + 1) && (aList[IDX] != searchValue))
        {
            ++IDX;

        }
        if (IDX != ListSize + 1)
            cout << "\nItem Requested is at slot " << IDX + 1 << ".\n\n";

        else
            cout << "\nItem does not exist..\n\n";
    }
}

// function to add/insert an item in an array
void ArrayAddItem(ARRAY aList[], USER_INPUT newData, ETC newDataPos, ARRAY_SIZE *addrListSize)
{

    int IDX;

    // error handling if the list is full
    if (ArrayListFull(*addrListSize) == 1)
        cout << "\nThe list is full!";

    else
    {

        // moves all the data to clear space for new data at newDataPos to be inserted
        for (IDX = *addrListSize; IDX >= newDataPos; --IDX)
            aList[IDX + 1] = aList[IDX];

        // adds the newData at newDataPos
        aList[newDataPos] = newData;

        // modifies the array size to +1 cuz of the new data added
        ++(*addrListSize);
        cout << "\nItem successfully added to list..\n\n";
    }
}

// function to delete an item in array
void ArrayDeleteItem(ARRAY aList[], ETC rmDataPos, ARRAY_SIZE *addrListSize)
{

    int IDX;

    // error handling if list is empty
    if (ArrayListEmpty(*addrListSize))
        cout << "\nThe list is empty!\n\n";

    else
    {

        // moves all the data down to overwrite the deleted data at rmDataPos
        for (IDX = rmDataPos + 1; IDX <= *addrListSize; ++IDX)
            aList[IDX - 1] = aList[IDX];

        // modifies the array size to -1 cuz of the old data removed
        --(*addrListSize);
        cout << "\nItem Successfully Removed!\n\n";
    }
}

// function to count items on list
ARRAY_SIZE ArrayCountItem(ARRAY_SIZE ListSize)
{
    return (ListSize + 1);
}
