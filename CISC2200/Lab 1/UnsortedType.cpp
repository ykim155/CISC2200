//
//  UnsortedType.cpp
//  CISC2200
//
//  Created by Yujin Kim on 1/28/20.
//  Copyright © 2020 Yujin Kim. All rights reserved.
//
#include "UnsortedType.h"

//constructor

UnsortedType::UnsortedType()
{
  length=0;
  listData = NULL;
}

//destructor

UnsortedType::~UnsortedType()
{
  MakeEmpty();
}


int UnsortedType::GetLength() const
{
  return length;
}


bool UnsortedType::IsFull() const
{
  NodeType* location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch (std::bad_alloc e)
  {
    return true;
  }
}

bool UnsortedType::IsEmpty() const
{
    return (listData == NULL)? true: false;

}


void UnsortedType::MakeEmpty()
{
  NodeType *tempPtr;
  while (listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
  length = 0;
  listData = NULL;
}

// Pre: list is not full and item is not in list.
// Post: item is in the list; length has been incremented.

void UnsortedType::InsertItem ( ItemType  item )
{
  NodeType * location;
     // obtain and fill a node
  location = new  NodeType;
  location->info = item;
  location->next = listData;
  listData = location;
  length++;

}

// Pre: Key member of item is initialized.
// Post: If found, item�s key matches an element�s key in the list and a copy of that
// element has been stored in item; otherwise, item is unchanged.

void  UnsortedType::RetrieveItem( ItemType&  item, bool&  found )
{
   bool  moreToSearch;
    NodeType*  location;
   location = listData;
    found = false ;
    moreToSearch = ( location  !=  NULL ) ;
    while ( moreToSearch  &&  !found )
    {
          if ( item.ComparedTo(location->info ))             // match here
          {
                found = true;
               item  = location->info;
      }
      else                    // advance pointer
      {
               location = location->next;
               moreToSearch = ( location  !=  NULL );
          }
   }
}


//pre: item's key has been initialized. An element in the list has a key that matches item's
//Post: no element in the list has a key that matches item's

void UnsortedType::DeleteItem(ItemType item)
{
NodeType* location = listData;
NodeType* tempLocation;
// Find the item
if (item.ComparedTo(listData->info) == EQUAL)
{ // item in first location
  tempLocation = location;
  listData = listData->next; //move the head of the list
}
else{
      //let location points to the node before the matching node
      while (item.ComparedTo((location->next)->info) != EQUAL)
                location = location->next;

      //remove the middle one, connect the two ends
       tempLocation = location->next;
       location->next = (location ->next)->next;
     
}
delete tempLocation;
length--;
}

void UnsortedType::ResetList()
{
  currentPos = NULL;
}

//Pre: the item at the current position is not the last in the list
//Post: current position has been updated. Item is current item. Does not check for running off the end of the list

void UnsortedType::GetNextItem(ItemType& item)
{
  if (currentPos == NULL)
    currentPos = listData;
  else
    currentPos = currentPos->next;

  item = currentPos->info;
}

//Function: Divides list into two separate list, split by the key.
//Pre: List is initialized and not empty. listOne and listTwo are both initialized and empty.
//Post: listOne contains all elements that are less than or equal to the key. listTwo contains all elements greater than the key.

void UnsortedType::SplitList(ItemType item, UnsortedType& listOne, UnsortedType& listTwo){
    NodeType* location = new NodeType; //Obtaining and allocating memory for node.
    location = listData; //Location is now at the start of the list.
    for(int i = 1; i <= length; i++){ //Loops until the list is at the end.
        switch(location -> info.ComparedTo(item)){ //Switch statement to compare list items to key using the ComparedTo function.
            case LESS:
                listOne.InsertItem(location -> info); //Inserting item that is less than key into listOne.
                break;
            case EQUAL:
                listOne.InsertItem(location -> info); //Inserting item that is equal to key into listOne.
                break;
            case GREATER:
                listTwo.InsertItem(location -> info); //Inserting item that is greater than key into listOne.
                break;
        }
        location = location -> next; //Advancing location to next node.
    }
}

//Function: Merge two lists into one.
//Pre: List has been initialized and is empty. listOne and listTwo have been initialized and are not empty.
//Post: List contains all elements from listOne and listTwo. Duplicate elements are kept.

void UnsortedType::MergeList(UnsortedType& listOne, UnsortedType& listTwo){
    NodeType* location = new NodeType; //Obtaining and allocating memory for node.
    location = listOne.listData; //Location is now at the start of listOne.
    for(int i = 1; i <= listOne.GetLength(); i++){ //Adding elements from listOne to list.
        InsertItem(location -> info); //Inserting element from listOne at the start of the list.
        location = location -> next; //Advancing location to next node.
    }
    location = listTwo.listData; //Location is now at the start of listTwo.
    for(int i = 1; i <= listTwo.GetLength(); i++){ //Adding elements from listTwo to list.
        InsertItem(location -> info); //Inserting element from listTwo at the start of the list.
        location = location -> next; //Advancing location to next node.
    }
}
