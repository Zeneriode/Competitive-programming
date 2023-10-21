//
// Created by Zener085 on 15.10.2023.
//

#ifndef COMPETITIVE_PROGRAMMING_GRAPH_INTERFACE_H
#define COMPETITIVE_PROGRAMMING_GRAPH_INTERFACE_H

#include <vector>

using namespace std;

template<typename V, typename E>
class GraphInterface {
    /**
     * Возвращает все узлы графа
     * @return Массив узлов графа
     */
    virtual vector<V> vertexes() = 0;

    /**
     * Возвращает все линии графа
     * @return Массив линий графа
     */
    virtual vector<E> edges() = 0;
    virtual void add_vertex(V vertex) = 0;
    virtual void add_edge(V v1, V v2) = 0;
    virtual void remove_vertex(V vertex) = 0;
    virtual void remove_edge(E edge) = 0;

    virtual V *path(V v1, V v2) = 0;
};

#endif //COMPETITIVE_PROGRAMMING_GRAPH_INTERFACE_H