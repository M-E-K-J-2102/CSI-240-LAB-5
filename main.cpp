//  filename:  main.cpp

/*
Author:        Wei Kian Chen
Modified by:   Matthew Kane
Class:         CSI-240-04
Assignment:    Lab 5
Date Assigned: 5/3/2024
Due Date:      22/3/2024 @ 1:00 PM
Description:   short lab that deals with linked lists
   Explore linked list.

Certification of Authenticity :
   I certify that this is entirely my own work, except
   where I have given fully documented references to the
   work of others.I understand the definition and consequences
   of plagiarism and acknowledge that the assessor of this
   assignment may, for the purpose of assessing this assignment:
   - Reproduce this assignment and provide a copy to another
     member of academic staff; and / or
   - Communicate a copy of this assignment to a plagiarism
     checking service(which may then retain a copy of this
    assignment on its database for the purpose of future
     plagiarism checking)
*/


#include <iostream>
#include "linkedList.h"

using namespace std;

int main()
{
   LinkedList list;
   int i, index, value;

   for (i = 0; i < 10; i++)
   {
       list.insertInOrder(i);
   }
   
   // Display original for comparison
   cout << "Original linked list:\n";
   list.display();
  
   // Change an element of the list
   cout << "\nWhat Index would you like to change: ";
   cin >> index;

   cout << "\nWhat value would you like to change index " << index << " to: ";
   cin >> value;

   // Sorts the list back in order after changing a value
   list.remove(index);
   list.insertInOrder(value);

   list.display();
   
   // remove the once changed item
   cout << "What value do you want to remove: ";
   cin >> value;
   list.remove(value);

   list.display();

   //Find if an element exists in the list
   cout << "What value do you want to check if it exists: ";
   cin >> value;

   if (list.isExist(value))
   {
       cout << value << " is in the list!" << endl;
   }
   else
   {
       cout << value << " is not in the list!" << endl;
   }

   return 0;
}