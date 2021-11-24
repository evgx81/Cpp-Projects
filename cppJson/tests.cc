#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#include "student.h"

auto json_test_1 = R"(
        {
            "name": 7,
            "age": "20",
            "course": 4,
            "marks": [
                {"Алгебра": 5},
                {"Чтение": 3},
                "Физкультура": 4,
                "Иконопись": 2,
                "Геометрия": 5
            ]
        }
    )"_json;


TEST(Tests, read_fron_json1) {
    Student stud_test;
    stud_test.read_from_json(json_test_1);
    EXPECT_EQ(stud_test.marks["Алгебра"], 5);
}

TEST(Tests, read_from_json2) {
    Student stud_test;
    stud_test.read_from_json(json_test_1);
    EXPECT_EQ(stud_test.marks["Чтение"], 5);
}

TEST(Tests, read_from_json3) {
    Student stud_test;
    stud_test.read_from_json(json_test_1);
    EXPECT_EQ(stud_test.name, "Peter");
}

TEST(Tests, read_fron_json4) {
    Student stud_test;
    stud_test.read_from_json(json_test_1);
    EXPECT_EQ(stud_test.course, 3);
}
