#pragma once

#include <vector>
#include <set>
#include <limits>

class Graph {
public:
    Graph(size_t vertices_count);

    void AddEdge(int from, int to, int weight);

    int prima_alg() const;

private:
    std::vector<std::vector<std::pair<int, int>>> vertices;
};
