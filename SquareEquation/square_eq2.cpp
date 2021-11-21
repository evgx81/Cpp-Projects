#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

enum Roots {
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};

std::vector<double> SolveSquareEquation(double a, double b, double c) {
    std::vector<double> roots;

    auto disc{b * b - 4 * a * c};
    if (disc < 0) {
        return roots;
    }
    else if (disc < std::numeric_limits<double>::epsilon()){
        roots.emplace_back(-b / (2 * a));
    }
    else{
        auto sqrtDisc{sqrt(disc)};
        roots.emplace_back((-b - sqrtDisc) / (2 * a));
        roots.emplace_back((-b + sqrtDisc) / (2 * a));
    }

    return roots;
 
}

int main(){
    using namespace std;
    vector<double> result = SolveSquareEquation(0, 2, 1);
    if (result.size() == NO_ROOTS)
        cout << "Нет действительных корней" << "\n";
    else if(result.size() == ONE_ROOT)
        cout << result.size() << " root: " << result.at(0) << "\n";
    else 
        cout << result.size() << " roots: " << result.at(0) << ", " << result.at(1) << "\n";

    return EXIT_SUCCESS;
}
