#include <iostream>

// modifiable array maximum size (must not exceed 2,147,483,647; cuz if u do, i'll go to your fucking house and fucking kill you)
#define MAX_SIZE 1000

// array only typedef: used only for array variables
typedef int ARRAY;
// array size typedef: used for manual input of how much an array is based on user input
typedef int ARRAY_SIZE;
// USER_INPUT typedef: used for user-inputted data
typedef int USER_INPUT;
// ETC typedef: used for user-inputted data positions
typedef int ETC;

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
int listFull(ARRAY_SIZE ListSize)
{

    if (ListSize == MAX_SIZE - 1)
        return (1); // outputs that list is indeed full
    else
        return (0); // outputs that list is empty
}

// function to test if list is empty (returns 1 if empty or 0 if it isn't)
int listEmpty(ARRAY_SIZE ListSize)
{

    if (ListSize < 0)
        return (1);
    else
        return (0);
}

// function to print contents of a list
void listPrintItems(ARRAY aList[], ARRAY_SIZE ListSize)
{

    int index;

    // always make this if statement to check if array is empty
    if (listEmpty(ListSize))
        cout << "\nThe list is empty!";

    else
        for (index = 0; index <= ListSize; ++index)
            cout << "\nThe value of item " << index + 1 << " = " << aList[index] << ".";
}

// function to locate an item in list and print its position (assuming items are unique)
void listLocateItem(ARRAY aList[], USER_INPUT searchValue, ARRAY_SIZE ListSize)
{

    int index = 0;

    // always make this if statement to check if array is empty
    if (listEmpty(ListSize))
        cout << "\nThe list is empty!";

    else
    {
        while ((index != ListSize + 1) && (aList[index] != searchValue))
        {
            ++index;

            if (index != ListSize + 1)
                cout << "\nItem Requested is at slot " << index + 1 << ".";

            else
                cout << "\nItem does not exist..";
        }
    }
}

// function to add/insert an item in an array
void listAddItem(ARRAY aList[], USER_INPUT newData, ETC newDataPos, ARRAY_SIZE *addrListSize)
{

    int index;

    // error handling if the list is full
    if (listFull(*addrListSize) == 1)
        cout << "\nThe list is full!";

    else
    {

        // moves all the data to clear space for new data at newDataPos to be inserted
        for (index = *addrListSize; index >= newDataPos; --index)
            aList[index + 1] = aList[index];

        // adds the newData at newDataPos
        aList[newDataPos] = newData;

        // modifies the array size to +1 cuz of the new data added
        ++(*addrListSize);
        cout << "\nItem successfully added to list..";
    }
}

// function to delete an item in array
void listDeleteItem(ARRAY aList[], ETC rmDataPos, ARRAY_SIZE *addrListSize)
{

    int index;

    // error handling if list is empty
    if (listEmpty(*addrListSize))
        cout << "\nThe list is empty!";

    else
    {

        // moves all the data down to overwrite the deleted data at rmDataPos
        for (index = rmDataPos + 1; index <= *addrListSize; ++index)
            aList[index - 1] = aList[index];

        // modifies the array size to -1 cuz of the old data removed
        --(*addrListSize);
        cout << "\nItem Successfully Removed!";
    }
}

// function to count items on list
ARRAY_SIZE listCountItem(ARRAY_SIZE ListSize)
{
    return (ListSize + 1);
}
