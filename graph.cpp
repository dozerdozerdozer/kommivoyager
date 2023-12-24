#include <cstdio>
#include "graph.h"


// конструктор массива
Graph::Graph(size_t vertices_count) {
    vertices.resize(vertices_count);
}


// добавление вершины
void Graph::AddEdge(int from, int to, int weight) {
    vertices[from - 1].emplace_back(to - 1, weight);
    vertices[to - 1].emplace_back(from - 1, weight);
}


// алгоритм Прима
int Graph::prima_alg() const {
    int start_vert = 1;
    std::set<std::pair<int, int>> verts;
    std::vector<int> key(vertices.size(), std::numeric_limits<int>::max());
    std::vector<bool> is_vert_in_ost_tree(vertices.size(), false);

    key[start_vert] = 0;
    verts.insert({0, start_vert});

    while (!verts.empty()) {
        int curr_vert = verts.begin()->second;
        verts.erase(verts.begin());

        is_vert_in_ost_tree[curr_vert] = true;

        for (const auto& neighbour : vertices[curr_vert]) {
            int to = neighbour.first;
            int weight = neighbour.second;

            if (!is_vert_in_ost_tree[to] && weight < key[to]) {
                verts.erase({key[to], to});
                key[to] = weight;
                verts.insert({key[to], to});
            }
        }
    }

    int result_weight = 0;
    for (int i = 0; i < vertices.size(); ++i) {
        result_weight += key[i];
    }

    return result_weight;
}
