#pragma once

#include <vector>
#include <set>
#include <limits>
#include <algorithm>

class Graph {
public:
    Graph(size_t vertices_count);

    void AddEdge(int from, int to, int weight);

    int kruskal_alg();

private:
    struct GraphVertice {
        int from;
        int to;
        int weight;
    };

    std::vector<GraphVertice> vertices;

    int find_root(int i, std::vector<int>& parent);

    void merge_root(int a, int b, std::vector<int>& parent);
};
