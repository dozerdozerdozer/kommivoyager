#pragma once

#include <vector>
#include "graph.h"


class TSP {
public:
    static std::vector<std::pair<double, double>> gen_rand_points(int N);

    static double evklid_dist(const std::pair<double, double>& p1, const std::pair<double, double>& p2);

    static double approx_quality(const Graph& graph, const std::vector<std::pair<double, double>>& points);

    static std::vector<int> points_arr(int N);

    static double opt_route_lenght(const std::vector<std::pair<double, double>>& points, const std::vector<int>& permutation);
};
