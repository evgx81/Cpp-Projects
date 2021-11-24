#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <map>

struct Person {
    std::string name;
    int age;
};

struct Student : public Person {
    int course;
    std::map<std::string, int> marks;
    void read_from_json(const nlohmann::json& j);
};

#endif