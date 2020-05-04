#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

template <class Type>
struct nodeType
{
    Type info; /// data type of info
    nodeType *link;
}; /// end nodeType


/// assumes three parameters, first link, last link, and item to insert
template <class Type>
Type insertLast(nodeType<Type>* &first, nodeType<Type>* &last, Type item)
{
    nodeType<Type> *newNode = NULL;
    /// set up my linked list with first node
    if (last == NULL) /// creating first node
    {
        newNode = new nodeType<Type>; /// temp pointer to space for node
        newNode->info = item; /// numbers btw 1 and 100
        newNode->link = NULL;
        first = newNode; /// linked list with one node
        last = newNode;  /// first and last point to it.
    }/// insertLast first node in list
    else /// if list is not empty
    {
        newNode = new nodeType<Type>; /// temp pointer to space for node
        newNode->info = item; /// intialize info to a value
        newNode->link = NULL;
        last->link = newNode; /// make this node next node in list
        last = newNode;  /// point last to last node in list
    } /// end add node
}/// end insertLast function

template <class Type>
Type printList(nodeType<Type>* &first)
{
    nodeType<Type> *current;

    current = first; /// start at beginning of list

    /// print out list
    while (current != NULL)
    {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;
}

template <class Type>
Type reverseOrder( nodeType<Type>* &current)
{
    /// print reverse order
    if (current != NULL)
    {
        reverseOrder(current->link);
        cout << current->info << " ";
    }
}


int main()
{
    nodeType<int> *first = NULL;    /// first node of linked list
    nodeType<int> *last = NULL;     /// last node of linked list
    nodeType<int> *newNode = NULL; /// used to create new nodes
    nodeType<int> *current = NULL; /// traversal pointer
    nodeType<int> *previous = NULL;
    int listSize; /// size of the list
    int item; /// random number for creating list
    int num;

    /// need seed for random number generator (rand())
    ///srand(time(0));

    cout << "== This programs prints a list in reverse order ==\n"
    << endl;

    cout << "Enter the size of your list: ";
    cin >> listSize;
    cout << endl;

    for (int count = 0; count < listSize; count++)
    {
        /// prompting user to input items of list
        cout << "Enter a number to add to the list: ";
        cin >> item;

        insertLast(first, last, item); /// encapsulation
    }
    cout << endl;

    cout << "Printing list: ";
    printList(first); /// print out the list in a forward manner

    cout << "Printing reverse order: ";
    reverseOrder(first); /// print out the list in a reverse manner

    cout << endl;

    return 0;
}/// end main
