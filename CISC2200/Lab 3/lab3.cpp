//
//  lab3.cpp
//  lab3
//
//  Created by Eugene Kim on 4/4/20.
//  Copyright © 2020 Yujin Kim. All rights reserved.
//

#include "ItemType.h"
#include "TreeType.h"
#include <iostream>

int main(){

    TreeType tree1;
    TreeType tree2;

    ItemType key;
    ItemType a;
    ItemType b;
    key.Initialize('F');
    tree1.InsertItem(key);

    cout << key << " is the key of the first tree." << endl;
    
    a.Initialize('A'); tree1.InsertItem(a);
    a.Initialize('H'); tree1.InsertItem(a);
    a.Initialize('B'); tree1.InsertItem(a);
    a.Initialize('G'); tree1.InsertItem(a);
    a.Initialize('I'); tree1.InsertItem(a);
    a.Initialize('E'); tree1.InsertItem(a);
    b.Initialize('D'); tree1.InsertItem(b);
    
    cout << "Tree 1: " << endl;
    tree1.Print();

    cout << "Leaf count: " << tree1.LeafCount() << endl;

    cout << "Ancestors of " << b << ':' << endl;
    tree1.Ancestors(b);

    cout << "Swapped Tree1: " << endl;
    tree1.Swap(tree2);
    tree2.Print();
    
    cout << "Delete " << a << " from Tree 1: " << endl;
    tree1.DeleteItem(a);
    tree1.Print();
    
    return 0;
}
