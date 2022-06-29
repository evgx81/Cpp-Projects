#include <iostream>

#include "separate_chaining_table.hh"
#include "linear_probing_table.hh"

void test(SeparateChainingTable table) {
    table.insert(3, "Картошка");

    table.insert(4, "Огурец");
    table.print();
    std::cout << std::endl;
}

int main() {
    LinearProbingTable table1(1);

    table1.insert(1, "Помидор");
    table1.insert(1, "Кукуруза");
    table1.insert(2, "Нектарин");
    table1.print();
    std::cout << std::endl;

//     if (table1.find(2)) {
//         std::cout << "element found" << std::endl;
//     }
//     else {
//         std::cout << "not found" << std::endl;
//     }

//     try {
//         TValue val = table1.get(5);
//     }
//     catch (std::string obj) {
//         std::cout << obj << '\n';
//    }

//     table1.remove(1);
//     table1.remove(2);
    table1.print();
    std::cout << std::endl;


    SeparateChainingTable table2(2);
    table2.insert(1, "Яблоко");
    table2.insert(1, "Апельсин");
    table2.insert(2, "Арбуз");
    table2.insert(11, "Дыня");
    table2.insert(2, "Молоко");
    table2.print();
    std::cout << table2.get(2) << '\n';


    return 0;
}