#include <iostream>
#include <nlohmann/json.hpp>
#include "student.h"

// for convenience
using json = nlohmann::json;

int main()
{
    auto j2 = R"(
        {
            "happy": true,
            "pi": 3.141
        }
    )"_json;

    std::string s = j2.dump();

    //Вывод json в строку
    std::cout << s << '\n';

    //Вывод json с отступами
    std::cout << j2.dump(4) << '\n';

    auto j3 = R"(
        {
            "name": "Vasya",
            "age": 25,
            "course": 1,
            "marks": {
                "Алгебра": 3,
                "Чтение": 4,
                "Физкультура": 5
            }
        }
    )"_json;

    Student stud1;
    stud1.read_from_json(j3);
    std::cout << stud1.age << "\n";

    json j4;
    j4["name"] = "Vasya";
    j4["age"] = 25;
    j4["course"] = 1;
    j4["marks"] = {{"Алгебра", 3}, {"Закон божий", 5}};

    //std::cout << j4.dump(4) << '\n';

    Student stud2;
    stud2.read_from_json(j4);

    std::cout << stud2.marks["Алгебра"] << '\n';
}