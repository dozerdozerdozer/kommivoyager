#include "tsp.h"
#include <random>


// генерация рандомных точек
std::vector<std::pair<double, double>> TSP::gen_rand_points(int N) {
    std::vector<std::pair<double, double>> random_generated_points;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < N; ++i) {
        double u = distribution(gen);
        double v = distribution(gen);

        // преобразование Бокса-Мюллера
        double X = cos(2.0 * M_PI * u) * sqrt(-2.0 * log(v));
        double Y = sin(2.0 * M_PI * u) * sqrt(-2.0 * log(v));

        random_generated_points.emplace_back(X, Y);

        /*  double u = static_cast<double>(std::rand() * (1 / RAND_MAX));
            double v = static_cast<double>(std::rand() * (1 / RAND_MAX));

            не подходит т.к. "Clang-Tidy: Rand() has limited randomness; use C++11 random library instead. */
    }

    return random_generated_points;
}


// расстояние от точки p1 до точки p2
double TSP::evklid_dist(const std::pair<double, double>& point_1, const std::pair<double, double>& point_2) {
    double dist_x = point_1.first - point_2.first;
    double dist_y = point_1.second - point_2.second;
    return std::sqrt(dist_x * dist_x + dist_y * dist_y);
}


// качество приближения задачи коммивояжера
double TSP::approx_quality(Graph& graph, const std::vector<std::pair<double, double>>& points) {
    double total_weight = 0;
    for (int i = 0; i < points.size() - 1; ++i) {
        int from = i + 1;
        int to = i + 2;
        total_weight += evklid_dist(points[from - 1], points[to - 1]);
    }
    total_weight += evklid_dist(points.back(), points.front());

    int minimum_weight = graph.kruskal_alg();

    return total_weight / minimum_weight;
}


// массив порядка точек
std::vector<int> TSP::points_arr(int N) {
    std::vector<int> remove_arr(N);
    std::iota(remove_arr.begin(), remove_arr.end(), 0);
    return remove_arr;
}


// длина оптимального маршрута
double TSP::opt_route_lenght(const std::vector<std::pair<double, double>>& points, const std::vector<int>& points_arr) {
    double length = 0.0;
    for (int i = 0; i < points_arr.size() - 1; ++i) {
        int from = points_arr[i] + 1;
        int to = points_arr[i + 1] + 1;
        length += evklid_dist(points[from - 1], points[to - 1]);
    }
    length += evklid_dist(points[points_arr.back()], points[points_arr.front()]);

    return length;
}
