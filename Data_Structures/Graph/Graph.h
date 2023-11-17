//
// Created by User on 15.10.2023.
//

#ifndef COMPETITIVE_PROGRAMMING_GRAPH_H
#define COMPETITIVE_PROGRAMMING_GRAPH_H

#include "Graph_Interface.h"
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, string> psi;

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

template<typename V>
class Graph : public GraphInterface<V, Road> {
    vector<V> _vertexes;
    vector<Road> _edges;

 public:
    Graph() = default;

    vector<V> vertexes() override {
        return _vertexes;
    }

    vector<Road> edges() override {
        return _edges;
    }

    void add_vertex(V vertex) override {
        _vertexes.push_back(vertex);
    }

    void add_edge(V v1, V v2) override {
        _edges.push_back(Road(v1, v2));
    }

    void remove_vertex(V vertex) override {
        auto index = find(_vertexes.begin(), _vertexes.end(), vertex);
        if (index != _vertexes.end()) _vertexes.erase(index);
    }

    void remove_edge(Road edge) override {
//        auto index = find(_edges.begin(), _edges.end(), edge);
//        _edges.erase(index);
    }

    vector<V> djkst(V v1, V v2) {
        unordered_map<V, vector<V>> paths;
        vector<V> start(1, v1);
        paths[v1] = start;

        unordered_set<V> path_exist;
        path_exist.insert(v1);

        queue<V> next;
        next.push(v1);

        unordered_set<V> visited;

        while (!next.empty()) {
            V actual = next.front();
            next.pop();

            if (visited.contains(actual)) continue;
            visited.insert(actual);

            for (Road edge : this->_edges) {
                if (edge.city1 == actual) {
                    V neigh = edge.city2;

                    if (!path_exist.contains(neigh) || paths[neigh].size() > paths[actual].size() + 1) {
                        paths[neigh] = paths[actual];
                        paths[neigh].push_back(neigh);
                        next.push(neigh);
                        if (visited.contains(neigh)) visited.erase(neigh);
                        if (!path_exist.contains(neigh)) path_exist.insert(neigh);
                    }
                } else if (edge.city2 == actual) {
                    V neigh = edge.city1;

                    if (!path_exist.contains(neigh) || paths[neigh].size() > paths[actual].size() + 1) {
                        paths[neigh] = paths[actual];
                        paths[neigh].push_back(neigh);
                        next.push(neigh);
                        if (visited.contains(neigh)) visited.erase(neigh);
                        if (!path_exist.contains(neigh)) path_exist.insert(neigh);
                    }
                }
            }
        }
        return paths[v2];
    }

    vector<V> dfs(V actual, V v2, set<V> visited, vector<V> path) {
        path.push_back(actual);
        if (actual == v2) return path;

        if (visited.contains(actual)) {
            path.pop_back();
            return path;
        }

        visited.insert(actual);

        for (Road edge : this->_edges) {
            if (edge.city1 == actual) {
                vector<V> new_path = dfs(edge.city2, v2, visited, path);
                if (new_path.size() == path.size()) {
                    continue;
                }
                return new_path;
            } else if (edge.city2 == actual) {
                vector<V> new_path = dfs(edge.city1, v2, visited, path);
                if (new_path.size() == path.size()) {
                    continue;
                }
                return new_path;
            }
        }
        path.pop_back();
        return path;
    }

    vector<V> path(V v1, V v2) override {
        vector<V> path;
        set<V> visited;

        return dfs(v1, v2, visited, path);
    }
};


#endif  //COMPETITIVE_PROGRAMMING_GRAPH_H
