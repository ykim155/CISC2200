//
//  UnsortedType.h
//  CISC2200
//
//  Created by Yujin Kim on 1/28/20.
//  Copyright © 2020 Yujin Kim. All rights reserved.
//

#ifndef UnsortedType_h
#define UnsortedType_h

#include "ItemType.h"


struct NodeType {
     ItemType info;
     NodeType * next;
};

class  UnsortedType        // declares a class data type
{
public :
    UnsortedType();
    ~UnsortedType();
    void MakeEmpty( );        // 10 public member functions
    bool IsFull( ) const;
    bool IsEmpty( ) const;
    int  GetLength( ) const;  // returns length of list
    void RetrieveItem( ItemType&  item, bool&  found );
    void InsertItem( ItemType item );
    void DeleteItem( ItemType  item );
    void ResetList( );
    void GetNextItem( ItemType & item );
    //Two new member functions
    void SplitList(ItemType item, UnsortedType& listOne, UnsortedType& listTwo);
    void MergeList(UnsortedType& listOne, UnsortedType& listTwo);
private:
    NodeType* listData;
    int length;
    NodeType* currentPos;
};

#endif
