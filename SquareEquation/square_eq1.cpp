#include <iostream>
#include <cmath>
#include <variant>
#include <limits>
#include <type_traits>
struct NotASquareEquation {};

using SquareEquationRoots = std::variant<std::monostate, double, std::pair<double, double>, NotASquareEquation>;

SquareEquationRoots SolveSquareEquation(double a, double b, double c) {
    if (std::abs(a) < std::numeric_limits<double>::epsilon())
        return NotASquareEquation{};
    else {
        auto disc{b * b - 4 * a * c};
        if (disc < 0)
            return std::monostate{};
        else if (disc < std::numeric_limits<double>::epsilon())
            return -b / (2 * a);
        else {
            auto sqrtDisc{sqrt(disc)};
            return std::make_pair((-b - sqrtDisc) / (2 * a), (-b + sqrtDisc) / (2 * a));
        }
    }
}

// 1 вариант
struct ResultPrinter {
    void operator()(std::monostate) {
        std::cout << "No real roots\n";
    }
    void operator()(double x) {
        std::cout << "1 root: " << x << std::endl;
    }
    void operator()(const std::pair<double, double>& twoRoots) {
        std::cout << "2 roots: " << twoRoots.first << ", " << twoRoots.second << std::endl;
    }
    void operator()(NotASquareEquation) {
        std::cout << "This is not a square equation\n";
    }
};

template <typename T>
struct always_false : std::false_type {};

int main()
{
    // 1 вариант
    std::visit(ResultPrinter{}, SolveSquareEquation(1, 1, 1));

    // 2 вариант
    auto result = SolveSquareEquation(0, 1, -1);
    if (std::get_if<std::monostate>(&result))
        std::cout << "No real roots\n";
    else if (auto singleRoot = std::get_if<double>(&result))
        std::cout << "1 root: "  << *singleRoot << std::endl;
    else if (auto twoRoots = std::get_if<std::pair<double, double>>(&result))
        std::cout << "Two roots: " << twoRoots->first << ", " << twoRoots->second << "\n";
    else if (std::get_if<NotASquareEquation>(&result))
        std::cout << "This is not a square equation\n";
    else
        std::cout << "Ha-ha-ha!!!\n";

    // 3 вариант
    auto visitor = [](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::monostate>)
            std::cout << "No real roots\n";
        else if constexpr (std::is_same_v<T, double>)
            std::cout << "1 root: " << arg << '\n';
        else if constexpr (std::is_same_v<T, std::pair<double, double>>)
            std::cout << "2 roots: " << arg.first << " " << arg.second << std::endl;
        else if constexpr(std::is_same_v<T, NotASquareEquation>)
            std::cout << "This is not square equation" << std::endl;
        else
            static_assert(always_false<T>::value, "Non-exhaustive visitor!");
    };

    std::visit(visitor, SolveSquareEquation(1, 0, 0));

    return EXIT_SUCCESS;
}
