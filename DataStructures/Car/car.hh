#ifndef CAR_H
#define CAR_H

#include <iostream>

struct StateNumber
{
    // Регион (3 знака)
    int m_region;
    // Номер (6 знаков)
    std::string m_number;
};

class Car
{
    // Государственный регистрационный номер
    StateNumber m_num;  
    // Фирма-производитель
    std::string m_firm_name;
    // ФИО водителя
    std::string m_driver_name;
    // Номер маршрута
    int m_route_number;
    // Состояние(в парке, на маршруте)
    enum Condition
    {
        PARK,
        ROUTE
    };
    
};

#endif