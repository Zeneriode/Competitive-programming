//
// Created by User on 15.10.2023.
//

#ifndef COMPETITIVE_PROGRAMMING_GRAPH_H
#define COMPETITIVE_PROGRAMMING_GRAPH_H

#include "Graph_Interface.h"
#include <algorithm>
#include <vector>

using namespace std;

struct Road {
    string city1;
    string city2;
    int length;
    Road(string city1, string city2, int length) {
        this->city1 = city1;
        this->city2 = city2;
        this->length = length;
    }
    Road(string city1, string city2) {
        this->city1 = city1;
        this->city2 = city2;
        this->length = 1;
    }
};

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
//        auto index = find(_edges.begin(), _edges.end(), edge);
//        _edges.erase(index);
    }

    vector <V> path(V v1, V v2) override {
        unordered_set<V> visited;  // Множество посещённых городов
        vector<Road> visited_edges;  // Множество посещённых рёбер
        vector<V> path; // Путь от одной точки до другой
        queue<V> next; // Очередь вершин которые нужно пройти после текущей
        next.push(v1); // Добавление первой вершины
        while (!next.empty()) { // Пока у вершины не будет соседствующих вершин
            V actual = next.back(); // Вытаскиваем вершину из очереди
            next.pop();
            if (visited.contains(actual)) // Если уже прошлись по этой вершине, то скип
                continue;
            visited.insert(actual);
            if (actual == v2) { // Если мы дошли до искомого элемента, заканчиваем цикл
                break;
            }
            for (E edge : this->_edges) {                                     // Проход по всем ребрам
                if (edge.city1 == actual && !visited.contains(edge.city2)) {  // Если есть путь до вершины, то добавляем её в очередь (идём дальше)
                    next.push(edge.city2);
                    visited_edges.push_back(edge);
                } else if (edge.city2 == actual && !visited.contains(edge.city1)) {
                    next.push(edge.city1);
                    visited_edges.push_back(edge);
                }
            }
        }
        visited.clear();
        V next_vertex = v2; // Текущая вершина которая будет записана в путь
        while (!visited.contains(v1)) {
            for (E edge : visited_edges) {   // Проход по всем ребрам
                if (edge.city1 == next_vertex) { // Если нашли ребро с текущей вершиной, то переходим к новой вершине
                    visited.insert(next_vertex);
                    next_vertex = edge.city2;
                    break;
                } else if (edge.city2 == next_vertex) {
                    visited.insert(next_vertex);
                    next_vertex = edge.city1;
                    break;
                }
            }
        }
        for (V v : visited) {
            path.push_back(v);
        }
        return path;
    }
};

//    vector<V> path(V v1, V v2) override {
//        unordered_set<V> visited;  // Множество посещённых городов
//        vector<Road> visited_edges;  // Множество посещённых рёбер
//        vector<V> path; // Путь от одной точки до другой
//
//        priority_queue<pair<int, V>, vector<pair<int, V>>, greater<pair<int, V>>> next; // Очередь вершин которые нужно пройти после текущей
//        next.push(make_pair(0, v1)); // Добавление первой вершины
//        unordered_map<V, V> previous;
//
//        while (!next.empty()) { // Пока у вершины не будет соседствующих вершин
//            V actual = next.top().second; // Вытаскиваем вершину из очереди
//            next.pop();
//
//            if (visited.contains(actual)) // Если уже прошлись по этой вершине, то скип
//                continue;
//            visited.insert(actual);
//
//            if (actual == v2) { // Если мы дошли до искомого элемента, заканчиваем цикл
//                break;
//            }
//
//            for (E edge : this->_edges) {                                     // Проход по всем ребрам
//                if (edge.city1 == actual && !visited.contains(edge.city2)) {
//                    int newDistance = _edges[actual] + edge.weight;
//                    if (newDistance < _edges[edge.city2]) {  // Если есть путь до вершины, то добавляем её в очередь (идём дальше)
//                        next.push(make_pair(newDistance, edge.city2));
//                        previous[edge.city2] = actual;
//                        visited_edges.push_back(edge);
//                    }
//                } else if (edge.city2 == actual && !visited.contains(edge.city1)) {
//                    int newDistance = _edges[actual] + edge.weight;
//                    if (newDistance < _edges[edge.city1]) {
//                        next.push(make_pair(newDistance, edge.city1));
//                        previous[edge.city1] = actual;
//                        visited_edges.push_back(edge);
//                    }
//                }
//            }
//        }
//        visited.clear();
//        V next_vertex = v2; // Текущая вершина которая будет записана в путь
//        while (!visited.contains(v1)) {
//            for (E edge : visited_edges) {   // Проход по всем ребрам
//                if (edge.city1 == next_vertex) { // Если нашли ребро с текущей вершиной, то переходим к новой вершине
//                    visited.insert(next_vertex);
//                    next_vertex = edge.city2;
//                    break;
//                } else if (edge.city2 == next_vertex) {
//                    visited.insert(next_vertex);
//                    next_vertex = edge.city1;
//                    break;
//                }
//            }
//        }
//        V nextVertex = v2;
//        while (nextVertex != v1) {
//            path.push_back(nextVertex);
//            nextVertex = previous[nextVertex];
//        }
//        path.push_back(v1);
//        reverse(path.begin(), path.end());
//        return path;
//    }
//};


#endif  //COMPETITIVE_PROGRAMMING_GRAPH_H
