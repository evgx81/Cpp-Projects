#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <iterator>

// С помощью итераторов вывести только тебе объекты типа Data, суммаа полей которых кратна 2.

struct Data {
    int m_a;
    int m_b;
    Data(int a = 0, int b = 0) : m_a{a}, m_b{b} {}
};

bool test_function(Data d) {
    return (d.m_a + d.m_b) % 2 == 0;
}

int main()
{
    using namespace std;
    
    vector<Data> v{};

    v.emplace_back(Data(1, 2));
    v.emplace_back(Data(5, 1));
    v.emplace_back(Data(-1, 7));

    vector<Data> v1{};

    std::copy_if(v.begin(), v.end(), std::back_inserter(v1), [](auto elem){ return (elem.m_a + elem.m_b) % 2 == 0; });

    for (auto elem : v1) {
        cout << elem.m_a << " " << elem.m_b << endl;
    }
}