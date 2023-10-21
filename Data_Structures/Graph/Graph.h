//
// Created by User on 15.10.2023.
//

#ifndef COMPETITIVE_PROGRAMMING_GRAPH_H
#define COMPETITIVE_PROGRAMMING_GRAPH_H

#include "Graph_Interface.h"
#include <algorithm>
#include <vector>

using namespace std;

template<typename V, typename E>
class Graph : public GraphInterface<V, E> {
    vector<V> _vertexes;
    vector<E> _edges;

 public:
    Graph() = default;

    vector<V> vertexes() override {
        return _vertexes;
    }

    vector<E> edges() override {
        return _edges;
    }

    void add_vertex(V vertex) override {
        _vertexes.push_back(vertex);
    }

    void add_edge(V v1, V v2) override {
        _edges.push_back(E(v1, v2));
    }

    void remove_vertex(V vertex) override {
        auto index = find(_vertexes.begin(), _vertexes.end(), vertex);
        if (index != _vertexes.end()) _vertexes.erase(index);
    }

    void remove_edge(E edge) override {
        auto index = find(_edges.begin(), _edges.end(), edge);
        _edges.erase(index);
    }

    int MinDist(int distance[], bool visit[]){
        int minimum = INT_MAX, ind;
        for(int i = 0; i < _edges.size(); ++i){
            if(visit[i] == false && distance[i] <= minimum){
                minimum = distance[i];
                ind = i;
            }
        }
        return ind;
    }

    V *path(V v1, V v2) override {
        int distance[_edges.size()];
        bool visit[_edges.size()];
        for(int i = 0; i < _edges.size(); i++)
        {
            distance[i] = INT_MAX;
            visit[i] = false;
        }
        distance[v1] = 0;
        for(int i = 0; i < _edges.size(); ++i){
            int m = MinDist(distance, visit);
            visit[m] = true;
            for(int j = 0; j < _edges.size(); ++j){
                if(!visit[j] && _edges[m][j] && distance[m] != INT_MAX && distance[m]+_edges[m][j] < distance[j]){
                    distance[j] = distance[m] + _edges[m][j];
                }
            }
        }
        for(int i = 0; i < _edges.size(); i++){
            char str = 65 + i;
            cout << str << "\t\t\t" << distance[i] << endl;
        }

        return nullptr;
    }
};


#endif  //COMPETITIVE_PROGRAMMING_GRAPH_H
