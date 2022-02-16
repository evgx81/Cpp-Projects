#ifndef CAR_H
#define CAR_H

#include <iostream>

struct StateNumber
{
    // Регион (3 знака)
    std::string m_region;
    // Номер (6 знаков)
    int m_number;
public:
    StateNumber() : m_region{}, m_number{} {}
    StateNumber(std::string region, int number) : m_region(region), m_number(number) {}
    StateNumber(const StateNumber& state_number)
    {
        m_region = state_number.m_region;
        m_number = state_number.m_number;
    }
public:
    // `operator==` нужен для сравнения ключей в случае коллизий
    bool operator==(const StateNumber& state_number)
    {
        return m_region == state_number.m_region && m_number == state_number.m_number;
    }
    // Вывод государственного номера   
    friend std::ostream& operator<<(std::ostream& os, const StateNumber& state_number)
    {
        os << state_number.m_region << ' ' << state_number.m_number;
        return os;
    }
    // Считывание государственного номера   
    friend std::istream& operator>>(std::istream& is, StateNumber& state_number)
    {
        is >> state_number.m_region >> state_number.m_number;
        is.ignore();
        return is;
    } 
};

enum Condition
{
    PARK, // 0
    ROUTE // 1
};

class Car
{
    // Государственный регистрационный номер
    StateNumber m_state_number;  
    // Фирма-производитель
    std::string m_firm_name;
    // ФИО водителя
    std::string m_driver_name;
    // Номер маршрута
    int m_route_number;
    // Состояние(в парке, на маршруте)
    Condition m_condition;
public:
    Car() : m_state_number{}, m_firm_name{}, m_driver_name{}, m_route_number{}, m_condition{} {}
    Car(std::string region, int number, std::string firm_name, std::string driver_name, int route_number, Condition condition) :
        m_state_number(region, number), m_firm_name(firm_name), m_driver_name(driver_name), m_route_number(route_number), m_condition(condition) {}
    Car(const Car&);
public:
    // Вывод полей машины
    friend std::ostream& operator<<(std::ostream&, const Car&);
    // Считывание полей машины
    friend std::istream& operator>>(std::istream&, Car&);
    // Получаем поле для ключа
    StateNumber& get_key()
    {
        return m_state_number;
    }
};

#endif