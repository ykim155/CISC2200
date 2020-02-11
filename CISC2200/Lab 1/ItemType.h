//
//  ItemType.h
//  CISC2200
//
//  Created by Yujin Kim on 1/28/20.
//  Copyright © 2020 Yujin Kim. All rights reserved.
//
//  SPECIFICATION FILE ItemType.h
#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
using namespace std;

enum  RelationType { LESS, EQUAL, GREATER };

class  ItemType        // declares class data type
{
public :             // 4 public member functions

  ItemType() {}

  RelationType ComparedTo( ItemType  otherItem ) const
  {
    if ( value  <  otherItem.value )
       return  LESS;
    else if ( value  > otherItem.value )
       return  GREATER;
    else  return  EQUAL;
  }

  void Print( ) const
  {
      cout  <<  value << ' ';//  <<  endl;
  }

   void Initialize( int value )
  {
    this->value  =  value;
  }


private :            // 1 private data member
    int  value;         // could be any type
} ;
#endif
