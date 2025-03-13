//  filename:  linkedList.h

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

#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

using namespace std;

const int LINKED_LIST_NO_VALUE = -10000;

class LinkedList
{
   struct Node
   {
      int  mData;
      Node *mNext;

      Node();
      Node(int data);
   };

   private:
      Node *mHead, *mTail;
      int  mCount;

   public:
      LinkedList();
      ~LinkedList();

      void display();
      int  getCount();
      int  getData(int index);
      void insertAtBack(int data);
      void insertAtFront(int data);
      void insertInOrder(int data);
      bool isExist(int searchKey);
      int  remove(int searchKey);
      void setData(int index, int data);
};

#endif