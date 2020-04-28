//
//  DirectedWeightedGraph.h
//  Lab 4
//
//  Created by Eugene Kim on 4/28/20.
//  Copyright © 2020 Yujin Kim. All rights reserved.
//

#ifndef DirectedWeightedGraph_h
#define DirectedWeightedGraph_h

#include "VertexType.h"
#include <vector>
#include <queue>

using namespace std;

class DirectedWeightedGraph{
public:
    // Constructors.
    DirectedWeightedGraph();
    DirectedWeightedGraph(int max);
    
    // Destructor.
    ~DirectedWeightedGraph();
    
    // const functions to check fullness or emptiness.
    bool isEmpty() const;
    bool isFull() const;
    
    // Add a vertex
    void AddVertex(VertexType v);
    
    // Delete a vertex and its edges. Vertex has to be in the graph.
    void DeleteVertex(VertexType v);
    
    // Add an edge between v1 and v2 with weight w. v1 and v2 have to be in the graph.
    void AddEdge(VertexType v1, VertexType v2, int w);
    
    // Delete an edge between v1 and v2. v1 and v2 have to be in the graph.
    void DeleteEdge(VertexType v1, VertexType v2);
    
    // Get the weight of edge between v1 and v2.
    int GetWeight(VertexType v1, VertexType v2);
    
    // Find edge between v1 and v2.
    bool EdgeExists(VertexType v1, VertexType v2);
    
    // Find vertex v.
    bool VertexExists(VertexType v);
    
    // Breadth First Traversal for vertex v.
    void Traverse(VertexType v);
    
    // Print the graph.
    void Print();
    
private:
    // Number of vertices in graph.
    int count;
    // Vertex capacity.
    int capacity;
    
    // Save all vertices
    vector<VertexType> vertices;
    
    // Get the vector index of vertex v.
    int IndexIs(VertexType v);
};

#endif /* DirectedWeightedGraph_h */
