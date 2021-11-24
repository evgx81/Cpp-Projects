#include <nlohmann/json.hpp>
#include "student.h"

using json = nlohmann::json;

void Student::read_from_json(const json& j) {
    j.at("name").get_to(this->name);
    j.at("age").get_to(this->age);
    j.at("course").get_to(this->course);
    j.at("marks").get_to(this->marks);    
}