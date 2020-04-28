//
//  DirectedWeightedGraph.cpp
//  Lab 4
//
//  Created by Eugene Kim on 4/28/20.
//  Copyright © 2020 Yujin Kim. All rights reserved.
//

#include "DirectedWeightedGraph.h"
#include <iostream>

// Default Constructor.
DirectedWeightedGraph::DirectedWeightedGraph(){
    count = 0;
    capacity = 20;
}

// Constructor with max capacity parameter.
DirectedWeightedGraph::DirectedWeightedGraph(int max){
    count  = 0;
    capacity = max;
}

// Destructor
DirectedWeightedGraph::~DirectedWeightedGraph(){
    // Intentionally empty.
}

// Checking if the graph is empty.
bool DirectedWeightedGraph::isEmpty() const{
    return 0 == count;
}

// Checking if the graph is full.
bool DirectedWeightedGraph::isFull() const{
    return count == capacity;
}

// Add a vertex.
void DirectedWeightedGraph::AddVertex(VertexType v){
    vertices.push_back(v);
}

// Add an edge.
void DirectedWeightedGraph::AddEdge(VertexType v1, VertexType v2, int w){
    int index1 = IndexIs(v1);
    vertices[index1].edges[v2.value] = w;
}

// Delete a vertex.
void DirectedWeightedGraph::DeleteVertex(VertexType v){
    int index = IndexIs(v);
    // Deletes the actual vertex from vector of vertices.
    vertices.erase(vertices.begin() + index);
    // Iterate through all vertices to find edges.
    for(int i = 0; i < vertices.size(); i++){
        // Set the iterator at every vertex.
        unordered_map<int, int>::iterator it = vertices[i].edges.begin();
        // While the iterator is not at the end.
        while(it != vertices[i].edges.end()){
            // If the key is equal to v, erase it.
            if(it->first == v.value){
                vertices[i].edges.erase(it);
                break;
            }
        }
    }
}

// Delete an edge
bool DirectedWeightedGraph::DeleteEdge(VertexType v1, VertexType v2){
    
}
