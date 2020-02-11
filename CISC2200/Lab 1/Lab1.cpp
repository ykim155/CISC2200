//
//  Lab1.cpp
//  CISC2200
//
//  Created by Yujin Kim on 1/28/20.
//  Copyright © 2020 Yujin Kim. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#include "ItemType.h"
#include "UnsortedType.h"

void PrintList( UnsortedType& list);

const int max_length = 10;

int main(){

    //Declaring lists.
    UnsortedType listAll;
    UnsortedType listMerged;
    UnsortedType listSmall;
    UnsortedType listLarge;

    //Creating ItemType objects of random values between 0 and 10 in an array to fill listAll.
    ItemType a[max_length];
    srand((unsigned) time(0));
    for(int i = 0; i<10; i++){
        a[i].Initialize((rand() % 11));
        listAll.InsertItem(a[i]);
    }

    //Initializing ItemType object "key" to use in SplitList function. Random value between 0 and 10 is assigned.
    ItemType key;
    key.Initialize((rand() % 10) + 1);
    
    cout << "The Key is: "; key.Print(); cout << endl; //Print list key.
    cout << "Full List: "; PrintList(listAll); cout << endl; //Printing full list for comparison.
    
    listAll.SplitList(key, listSmall, listLarge); //Calling the SplitList function.
    
    cout << "List less than or equal to key: "; PrintList(listSmall); cout << endl; //Printing list with elements <= key.
    cout << "List greater than key: "; PrintList(listLarge); cout << endl; //Printing list with elements > key.

    listMerged.MergeList(listSmall, listLarge); //Merging listOne and listTwo
    cout << "Merged list from previous two lists: "; PrintList(listMerged); cout << endl; //Printing merged list
    
    listAll.MakeEmpty(); //Making listAll empty.
    listMerged.MakeEmpty(); //Making listMerged empty.
    listSmall.MakeEmpty(); //Making listSmall empty.
    listLarge.MakeEmpty(); //Making listLarge empty.
    
    //This if-else statement checks if all lists are empty and prints accordingly.
    if(listAll.IsEmpty() && listMerged.IsEmpty() && listSmall.IsEmpty() && listLarge.IsEmpty())
        cout << "All lists are empty!" << endl;
    else
        cout << "One or more lists are not empty!" << endl;

    return 0;
}

// Pre:  list has been initialized.
// Post: Each component in list has been written.
void PrintList( UnsortedType& list)
{
  int length;
  ItemType item;

  list.ResetList( );
  length = list.GetLength( );
  for (int counter = 1; counter <= length; counter++)
  {
    list.GetNextItem(item);
    item.Print( );
  }
}
