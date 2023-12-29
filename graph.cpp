#include <cstdio>
#include "graph.h"
#include <algorithm>


// конструктор массива
Graph::Graph(size_t vertices_count) {
    vertices.resize(vertices_count);
}


// добавление вершины
void Graph::AddEdge(int from, int to, int weight) {
    vertices.push_back({from - 1, to - 1, weight});
}


// алгоритм Прима
int Graph::kruskal_alg() {
    std::sort(vertices.begin(), vertices.end(), [](const GraphVertice& a, const GraphVertice& b) {
        return a.weight < b.weight;
    });

    std::vector<int> parent(vertices.size());
    for (int i = 0; i < vertices.size(); ++i) {
        parent[i] = i;
    }

    int result_weight = 0;

    for (const auto& vertice : vertices) {
        int from_set = find_root(vertice.from, parent);
        int to_set = find_root(vertice.to, parent);

        if (from_set != to_set) {
            result_weight += vertice.weight;
            merge_root(from_set, to_set, parent);
        }
    }

    return result_weight;
}


int Graph::find_root(int i, std::vector<int>& parent) {
    if (i == parent[i])
        return i;
    return parent[i] = find_root(parent[i], parent);
}


void Graph::merge_root(int a, int b, std::vector<int>& parent) {
    a = find_root(a, parent);
    b = find_root(b, parent);
    if (a != b)
        parent[b] = a;
}
