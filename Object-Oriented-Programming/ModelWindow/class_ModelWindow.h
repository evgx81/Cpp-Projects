#ifndef MODEL_H
#define MODEL_H

#include <string>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGTH 768

class ModelWindow {
    //Переменные класса
    std::string m_title;  // Заголовок
    int m_x, m_y;         // Координаты левого угла
    int m_width;          // Ширина
    int m_height;         // Высота
    std::string m_color;  // Цвет
    bool m_visibility;    // "Видимое/невидимое"
    bool m_frame;         // "С рамкой/без рамки"

public:
    // Конструктор по умолчанию
    ModelWindow();
    //Конструктор с параметрами
    ModelWindow(std::string title, int x, int y, int width, int height, std::string color, bool visibility, bool frame);
public:
    //Методы доступа к полям класса
    void set_title(const std::string&);
    std::string get_title() const;

    void set_x(int);
    int get_x() const;

    void set_y(int);
    int get_y() const;

    void set_width(int);
    int get_width() const;

    void set_height(int);
    int get_height() const;

    void set_color(const std::string&);
    std::string get_color() const;

    void set_visibility(bool);
    bool get_visibility() const;

    void set_frame(bool);
    bool get_frame() const; 

public:
    //Методы, реализующие указанные функции в задании
    void horizontalMove(int); // Передвижение по горизонтали
    void verticalMove(int); // Передвижение по вертикали

    void changeWidth(int); // Изменение ширины
    void changeHeight(int); // Изменение высоты
    void changeHeightWidth(int, int); // Изменние высоты и ширины

    void changeColor(const std::string&); // Изменение цвета

    void changeVisibility(bool); // Изменение состояния видимости
    void changeFrame(bool); // Изменение состояния рамки
    void object_condition(); //Опрос состояний окна

    void toString(); //Возвращает информацию об объекте в виде строки

};

#endif // MODEL_H