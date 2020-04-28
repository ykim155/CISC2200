//
//  VertexType.h
//  CISC2200
//
//  Created by Eugene Kim on 4/28/20.
//  Copyright © 2020 Yujin Kim. All rights reserved.
//

#ifndef VertexType_h
#define VertexType_h
#include <unordered_map>

using namespace std;
enum MARK {DEFAULT, VISITED};

class VertexType{
public:
    // Default Constructor
    VertexType(){
        value = -1;
        mark = DEFAULT;
    }
    // Constructor initialized with a value
    VertexType(int val){
        value = val;
    }
    // Overload equality operator
    bool operator == (VertexType const& vertex){
        return value == vertex.value;
    }
    // Overload inequality operator
    bool operator != (VertexType const& vertex){
        return value != vertex.value;
    }
    // Value variable
    int value;
    // Edges. unordered_map works like an unsorted dictionary in python.
    // Contains which vertex this vertex goes to with what weight.
    unordered_map<int, int> edges;
    // Default is DEFAULT and when visited is VISITED
    MARK mark;
};

#endif /* VertexType_h */
