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
//       ДЗ
    }

    V *path(V v1, V v2) override {
//        ДЗ - Поиск в ширину
        return nullptr;
    }
};


#endif  //COMPETITIVE_PROGRAMMING_GRAPH_H
