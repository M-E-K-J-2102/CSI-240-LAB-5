//  filename:  linkedList.cpp

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

#include "linkedList.h"


LinkedList::Node::Node()
{
   mData = 0;
   //mNext = NULL;
   //mNext = 0;
   mNext = nullptr;
}


LinkedList::Node::Node(int data)
{
   mData = data;
   mNext = NULL;
}


LinkedList::LinkedList()
{
   mHead = NULL;
   mTail = NULL;
   mCount = 0;
}


LinkedList::~LinkedList()
{ 
   Node *tmp;

   tmp = mHead;
   while (mHead != NULL)
   {
      tmp = mHead;
      mHead = mHead->mNext;

      tmp->mNext = NULL;
      delete tmp;
   }
   mCount = 0;
   mHead = NULL;
   mTail = NULL;
}


int LinkedList::getCount()
{
   return mCount;
}


int LinkedList::getData(int index)
{
   return -1;
}


void LinkedList::setData(int index, int data)
{
    Node* tmp= mHead;

    // Iterates through liked list
    for (int i = 0; i < index; i++) 
    {
        if (tmp->mNext == NULL)
        {
            // Makes sure It is bounded
            cout << "Index not found\n";
            
            // Returns nothing and does not change anything if out of bounds
            return;
        }
        
        // Checks node
        tmp = tmp -> mNext;
    }

    // When node is found, assigns it the value of data
    tmp -> mData = data;

    return;
}


void LinkedList::display()
{
   Node *tmp;

   tmp = mHead;
   while (tmp != NULL)
   {
      cout << tmp->mData << " ";
      tmp = tmp->mNext;
   }
   cout << endl;
}


void LinkedList::insertAtBack(int data)
{
   Node *newNode;

   newNode = new Node(data);
   if (newNode == NULL)
      return;

   // check if the list is empty
   if (mCount == 0)  // mHead == NULL
   {
      mHead = newNode;
      mTail = newNode;
   }
   else
   {
      mTail->mNext = newNode;
      mTail = newNode;
   }

   mCount++;
}


void LinkedList::insertAtFront(int data)
{
   Node *newNode;

   newNode = new Node(data);
   if (newNode == NULL)
      return;

   // check if the list is empty
   if (mCount == 0)  // mHead == NULL
   {
      mHead = newNode;
      mTail = newNode;
   }
   else
   {
      newNode->mNext = mHead;
      mHead = newNode;
   }

   mCount++;
}


void LinkedList::insertInOrder(int data)
{
   Node* newNode, *tmp, *oneBefore;

   newNode = new Node(data);
   if (newNode == NULL)
      return;

   // 1. list is empty
   if (mCount == 0)  // mHead == NULL
   {
      mHead = newNode;
      mTail = newNode;
   }
   else
   {
      // 2. insert at head
      if (mHead->mData >= data)
      {
         newNode->mNext = mHead;
         mHead = newNode;
      }
      // 3. insert at tail
      else if (mTail->mData <= data)
      {
         mTail->mNext = newNode;
         mTail = newNode;
      }
      // 4. insert in the middle
      else
      {
         tmp = mHead->mNext;
         oneBefore = mHead;
         while (tmp->mData < data)
         {
            oneBefore = tmp;
            tmp = tmp->mNext;
         }
         oneBefore->mNext = newNode;
         newNode->mNext = tmp;
      }
   }

   mCount++;
}


bool LinkedList::isExist(int searchKey)
{
    Node* tmp;
    tmp = mHead;

    while (tmp != NULL)
    {
        if (tmp->mData == searchKey)
        {   // If searcKey coincides with mData it returns true
            return true;
        }
        // Next iteration
        tmp = tmp->mNext;
    }
    // If no mData matches searchKey the function returns false
    return false;
}


int LinkedList::remove(int searchKey) // search key is value
{
    // Checks list is not empty
    if (mHead == NULL)
    {
        return -1;
    }

    Node* tmp = mHead;
    Node* prev = NULL;
    int junk;

    // Iterates through liked list
    while (tmp != NULL)
    {
        if (prev == NULL && tmp->mData == searchKey) 
        {
            // If searchKey is the first node, set first node to the next node and delete the original first node
            mHead = tmp -> mNext;
            junk = tmp->mData;
            delete tmp;
            return junk;
        }
        else if (tmp->mNext == NULL && tmp->mData == searchKey )
        {
            // If searchKey is at the end, set tail to prev and delete tmp and set the new last element's mNext to NULL
            mTail = prev;
            junk = tmp->mData;
            prev->mNext = NULL;
            delete tmp;
            return junk;
        }
        else if ((prev != NULL && tmp->mData == searchKey) && (tmp->mNext != NULL))
        {
            // If searchKey is in the middle, set prev pointer to node after tmp and delete tmp
            prev->mNext = tmp->mNext;
            junk = tmp->mData;
            delete tmp;
            return junk;
        }

        // Iterate to next node
        prev = tmp;
        tmp = tmp->mNext;
    }
    cout << "Index not found\n";
    return -1;
}