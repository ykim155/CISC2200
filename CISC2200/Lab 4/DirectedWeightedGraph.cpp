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

// Get the vector index of vertex v.
int DirectedWeightedGraph::IndexIs(VertexType v){
    int i = 0;
    while(v != vertices[i]){
        // If i reaches the end of the vertices vector, IndexIs will return -1, indicating non-existance.
        if(i == vertices.size())
            return -1;
        // Otherwise, keep looking.
        else
            i++;
    }
    return i;
}

// Add a vertex.
void DirectedWeightedGraph::AddVertex(VertexType v){
    vertices.push_back(v);
    count++;
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
            it++;
        }
    }
    count--;
}

// Delete an edge from v1 to v2
void DirectedWeightedGraph::DeleteEdge(VertexType v1, VertexType v2){
    int index = IndexIs(v1);
    // Iterator to go through map of edges for v1.
    unordered_map<int, int>::iterator it = vertices[index].edges.begin();
    while(it != vertices[index].edges.end()){
        if(it->first == v2.value){
            vertices[index].edges.erase(it);
            break;
        }
    }
}

// Return weight of an edge going from v1 to v2.
int DirectedWeightedGraph::GetWeight(VertexType v1, VertexType v2){
    int index = IndexIs(v1);
    return vertices[index].edges[v2.value];
}

// See if an edge exists between v1 and v2.
bool DirectedWeightedGraph::EdgeExists(VertexType v1, VertexType v2){
    int index = IndexIs(v1);
    return (vertices[index].edges.find(v2.value) != vertices[index].edges.end());
}

// See if a vertex v exists.
bool DirectedWeightedGraph::VertexExists(VertexType v){
    return IndexIs(v) != -1;
}

// Print vertices.
void DirectedWeightedGraph::Print(){
    for(int i = 0; i < vertices.size(); i++){
        unordered_map<int, int>::iterator it = vertices[i].edges.begin();
        while(it != vertices[i].edges.end()){
            cout << vertices[i].value << " points to " << it->first << " weighted " << it->second << endl;
        }
    }
}

// Traverse using Breadth First Traversal.
void DirectedWeightedGraph::Traverse(VertexType v){
    queue<VertexType> vq;
    // Mark all vertices as unvisited.
    for(int i = 0; i < vertices.size(); i++){
        vertices[i].mark = DEFAULT;
    }
    // The starting vertex has been visited.
    vq.push(vertices[IndexIs(v)]);
    vertices[IndexIs(v)].mark = VISITED;
    // While vq is not empty.
    while(!vq.empty()){
        // Dequeue vertex and print it
        v = vq.front();
        cout << vq.front().value << endl;
        vq.pop();
        unordered_map<int, int>::iterator it = v.edges.begin();
        while(it != v.edges.end()){
            // If unvisited, visit and push into vq.
            if(vertices[IndexIs(it->first)].mark == DEFAULT){
                vertices[IndexIs(it->first)].mark = VISITED;
                vq.push(vertices[IndexIs(it->first)]);
            }
        }
    }
}
