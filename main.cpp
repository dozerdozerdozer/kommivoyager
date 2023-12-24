#include <iostream>
#include "graph.h"
#include "tsp.h"

void voyager() {
    for (int N = 2; N <= 10; ++N) {
        int exps_count = 10;
        double ttl_quality = 0;

        for (int exp = 0; exp < exps_count; ++exp) {

            Graph graph(N);
            auto points = TSP::gen_rand_points(N);

            for (int i = 0; i < N; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    int weight = static_cast<int>(TSP::evklid_dist(points[i], points[j]) * 10);
                    graph.AddEdge(i + 1, j + 1, weight);
                }
            }

            std::vector<int> points_arr = TSP::points_arr(N);
            double optimal_length = TSP::opt_route_lenght(points, points_arr);

            ttl_quality += TSP::approx_quality(graph, points) / optimal_length;
        }

        double avg_quality = ttl_quality / exps_count;
        std::cout << "N = " << N << ", avg quality = " << avg_quality << std::endl;
    }
}



int main() {
    voyager();
    return 0;
}
