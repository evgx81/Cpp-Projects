#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

enum Roots {
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};

struct Solution {
    double root1;
    double root2;
    Roots roots_count;
    
    Solution() = default;
};

Solution SolveSquareEquation(double a, double b, double c) {
    auto disc{b * b - 4 * a * c};
    Solution solv;
    if (disc < 0) {
        solv.roots_count = NO_ROOTS;
    }
    else if (disc < std::numeric_limits<double>::epsilon()){
        solv.roots_count = ONE_ROOT;
        solv.root1 = -b / (2 * a);
    }
    else{
        auto sqrtDisc{sqrt(disc)};
        solv.root1 = (-b - sqrtDisc) / (2 * a);
        solv.root2 = (-b + sqrtDisc) / (2 * a);
        solv.roots_count = TWO_ROOTS;
    }

    return solv;

}

int main()
{
    using namespace std;
    Solution result = SolveSquareEquation(0, 1, 1); 
    if (result.roots_count == NO_ROOTS)
        cout << "Нет действительных корней";
    else if(result.roots_count == ONE_ROOT)
        cout << result.root1 << "\n";
    else 
        cout << result.root1 << " " << result.root2 << "\n";

    return EXIT_SUCCESS;
}