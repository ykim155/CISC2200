//
//  main.cpp
//  Lab 4
//
//  Created by Eugene Kim on 4/28/20.
//  Copyright © 2020 Yujin Kim. All rights reserved.
//

#include <iostream>
#include "DirectedWeightedGraph.h"

using namespace std;

int main() {
    DirectedWeightedGraph graph;
    
    // Adding vertices 0-9 using AddVertex().
    for(int i = 0; i < 10; i++){
        graph.AddVertex(VertexType(i));
    }
    
    // Adding edges using AddEdge(). Using the graph on Lab 4 handout as example.
    graph.AddEdge(VertexType(1), VertexType(2), 100);
    graph.AddEdge(VertexType(1), VertexType(3), 50);
    graph.AddEdge(VertexType(1), VertexType(4), 150);
    graph.AddEdge(VertexType(3), VertexType(1), 10);
    graph.AddEdge(VertexType(3), VertexType(7), 50);
    graph.AddEdge(VertexType(4), VertexType(5), 200);
    graph.AddEdge(VertexType(4), VertexType(6), 100);
    graph.AddEdge(VertexType(5), VertexType(6), 100);
    graph.AddEdge(VertexType(7), VertexType(6), 30);
    
    // Test Print().
    cout << "Original Graph: " << endl;
    graph.Print();
    cout << endl;
    
    // Test Traverse().
    cout << "Traversal of Graph: " << endl;
    graph.Traverse(VertexType(1));
    
    // Delete Edge using DeleteEdge().
    graph.DeleteEdge(VertexType(1), VertexType(4));
    cout << "After deletion of edge 1 to 4: " << endl;
    graph.Print();
    cout << endl;
    
    // See if an edge is there with EdgeExists()
    cout << "Is there an edge, going from 4 to 5?" << endl;
    if(graph.EdgeExists(VertexType(4), VertexType(5)))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    // Get the weight with GetWeight().
    cout << "What's the weight of the edge, going from 4 to 5?" << endl;
    cout << graph.GetWeight(VertexType(4), VertexType(5)) << endl;
}
