#include "car.hh"

Car::Car(const Car& car)
{
    m_state_number = car.m_state_number;
    m_firm_name = car.m_firm_name;
    m_driver_name = car.m_driver_name;
    m_route_number = car.m_route_number;
    m_condition = car.m_condition;
}

Car& Car::operator=(const Car& car) 
{
    m_state_number = car.m_state_number;
    m_firm_name = car.m_firm_name;
    m_driver_name = car.m_driver_name;
    m_route_number = car.m_route_number;
    m_condition = car.m_condition;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Car& car)
{
    os << car.m_state_number << ' ' << car.m_firm_name << ' ' << car.m_driver_name << ' ' << car.m_route_number << car.m_condition;
    return os;
}

std::istream& operator>>(std::istream& is, Car& car)
{
    is >> car.m_state_number;
    getline(is, car.m_firm_name, ' ');
    getline(is, car.m_driver_name, ' ');

    // Правильной обработки считания перечисления
    int condition{};
    is >> car.m_route_number >> condition;
    car.m_condition = condition == 0 ? PARK : ROUTE;
    is.ignore();
    return is;
}