#include <iostream>
#include "graph.h"
#include "tsp.h"

void voyager() {
    for (int N = 2; N <= 10; ++N) {
        int exps_count = 10;
        double ttl_quality_for_X = 0;
        double ttl_quality_for_G = 0;

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

            auto C = TSP::approx_quality(graph, points);
            ttl_quality_for_X += std::max(C / optimal_length, optimal_length / C);      // ro(n)
            ttl_quality_for_G += (C - ttl_quality_for_X*ttl_quality_for_X) / optimal_length;
        }

        double avg_quality_X = ttl_quality_for_X / exps_count;
        double avg_quality_G = ttl_quality_for_G / exps_count;
        std::cout << "N = " << N << ", среднее значение качества приближения = " << avg_quality_X << ", среднеквадратичное отклонение качества приближения = " << avg_quality_G <<std::endl;
    }
}


int main() {
    voyager();
    return 0;
}



