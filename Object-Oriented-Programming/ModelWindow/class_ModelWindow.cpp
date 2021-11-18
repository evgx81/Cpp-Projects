#include <iostream>
#include "class_ModelWindow.h"

ModelWindow::ModelWindow() {
    m_title = "Без имени"; 
    m_x = 0;
    m_y = 0; 
    m_width = 0; 
    m_height = 0; 
    m_color = "Нет цвета"; 
    m_visibility = true; 
    m_frame = true; 
}

ModelWindow::ModelWindow(std::string title, int x, int y,  int width, int height, std::string color, bool visibility, bool frame) : m_title(title), m_x(x), m_y(y), m_width(width), m_height(height), m_color(color), m_visibility(visibility), m_frame(frame) {}

void ModelWindow::set_title(const std::string& title) {
    m_title = title;
}

std::string ModelWindow::get_title() const {
    return m_title;
}

void ModelWindow::set_x(int x) {
    m_x = x;
}

int ModelWindow::get_x() const {
    return m_x;
}

void ModelWindow::set_y(int y) {
    m_y = y;
}

int ModelWindow::get_y() const {
    return m_y;
}

void ModelWindow::set_width(int width) {
    m_width = width;
}

int ModelWindow::get_width() const {
    return m_width;
}

void ModelWindow::set_height(int height) {
    m_height = height;
}

int ModelWindow::get_height() const {
    return m_height;
}

void ModelWindow::set_color(const std::string& color) {
    m_color = color;
}

std::string ModelWindow::get_color() const {
    return m_color;
}

void ModelWindow::set_visibility(bool visibility) {
    m_visibility = visibility;
}

bool ModelWindow::get_visibility() const {
    return m_visibility;
}

void ModelWindow::set_frame(bool frame) {
    m_frame = frame;
}

bool ModelWindow::get_frame() const {
    return m_frame;
}

// Передвижение по горизонтали
void ModelWindow::horizontalMove(int x) { // width, height
    // x - смещение экрана по горизонтали
    // условие для проверки пересечения правой границы экрана
    if (m_x + m_width + x >= SCREEN_WIDTH) {
        m_x = SCREEN_WIDTH - m_width - 1;
    }
    // будем предполагать, что смещение влево - отрицательное число
    else if (m_x - abs(x) <= 0) {
        m_x = 1; //т.к значение координаты по условию целочисленное
    }   
    else {
        // если условия не выполнены, смещаем экран на заданную величину x
        m_x += x; 
    }
}

// Передвижение по вертикали
void ModelWindow::verticalMove(int y) {
    // y - смещение экрана по вертикали
    if (m_y + y >= SCREEN_HEIGTH) {
        m_y = SCREEN_HEIGTH - 1; //т.к значение координаты по условию целочисленное
    }
    else if (m_y - m_height - abs(y) <= 0) {
        m_y = m_height + 1;   
    }
    else {
        // если условия не выполнены, смещаем экран на заданную величину y
        m_y += y;
    } 
}

// Изменение ширины
void ModelWindow::changeWidth(int width) {
    // width - изменение ширины рамки
    // первое условие для увелечения длины вправо
    if(m_x + m_width + width >= SCREEN_WIDTH) {
        //SCREEN_WIDTH - 1 - крайняя координата Верхнего правого угла, кот. может иметь рамка
        m_width += (SCREEN_WIDTH - 1) - (m_x + m_width);
    }
    // предполагаем, что если width отрицательна, то укорачиваем экран
    else if(m_width - abs(width) <= 0) {
        //останавливаем минимальное значение ширины экрана
        m_width = 1;
    }
    else {
        m_width += width;
    }
}

// Изменение высоты
void ModelWindow::changeHeight(int height) {
    // height - изменение высоты рамки
    if(m_y + height >= SCREEN_HEIGTH) {
        m_height += SCREEN_HEIGTH - 1 - m_y;
    }
    else if(m_y - m_height + height <= 0) {
        m_height = 1;
    }
    else {
        m_height += height;
    }
}

// Изменение одновременно длины и ширины
void ModelWindow::changeHeightWidth(int width, int height) {
    // При увеличении высоты и ширины экрана, мы должны одновременно увеличивать и ширину и высоту
    // Осуществляем проверку пришдших данных, они должны быть одного знака
    if((width > 0 && height < 0) || (width < 0 && height > 0)) {
        //Ничего не будем делать, т.к введены неверные данные
        width = 0;
        height = 0;
    }

    //Если высота и ширина выходят за предел экрана, то меняем их
    if (m_x + m_width + width >= SCREEN_WIDTH && m_y + height >= SCREEN_HEIGTH) {
        m_width += SCREEN_WIDTH - 1 - (m_x + m_width);
        m_height += SCREEN_HEIGTH - 1 - m_y;
    }
    //Если при уменьшении экрана достигнуты пределы пересечения, то устанавливаем  минимальные значеия длины и ширины
    else if (m_y - m_height + height <= 0 && m_width - abs(width) <= 0) {
        m_width = 1;
        m_height = 1;
    }
    // Если высота выходит за предел экрана, а ширина ничего не пересекает
    else if (m_y + height >= SCREEN_HEIGTH) {
        //Изменяем высоту до предела, а ширина остается увеличивается
        m_height += SCREEN_HEIGTH - 1 - m_y;
        m_width += width;

    }
    // Если ширина выходит за предел экрана, а высота ничего не пересекает
    else if (m_x + m_width + width >= SCREEN_WIDTH) {
        m_width += SCREEN_WIDTH - 1 - (m_x + m_width);
        m_height += height;

    }
    // Если все нормально и ничего не пересекается 
    else {
        m_height += height;
        m_width += width;
    }
}

// Изменение цвета
void ModelWindow::changeColor(const std::string& color) {
    m_color = color;
}

// Изменение состояния видимости
void ModelWindow::changeVisibility(bool visibility) {
    m_visibility = visibility;
}

// Изменение состояния рамки
void ModelWindow::changeFrame(bool frame) {
    m_frame = frame;
}

// Опрос состояния объекта
void ModelWindow::object_condition() {
    std::cout << "Видимость: " << std::boolalpha << m_visibility << std::endl;
    std::cout << "Наличие рамки: " << std::boolalpha << m_frame << std::endl;
}

// Метод вывода информации об объекте
void ModelWindow::toString() {
    std::cout << "Имя окна: " << m_title << std::endl;
    std::cout << "Координата x: " << m_x << std::endl;
    std::cout << "Координата y: " << m_y << std::endl;
    std::cout << "Ширина: " << m_width << std::endl;
    std::cout << "Высота: " << m_height << std::endl;
    std::cout << "Цвет: "  << m_color << std::endl;
    std::cout << "Видимость: " << std::boolalpha << m_visibility << std::endl;
    std::cout << "Наличие рамки: " << std::boolalpha << m_frame << std::endl;
}


int main() {
    // Сработал конструктор по умолчанию
    ModelWindow obj1;
    // Просмотр искомых значений
    obj1.toString();
    std::cout << "\n";
    // Изменим значения с помощью set
    // ПЕределать через switch
    obj1.set_title("Окно1");
    obj1.set_x(3);
    obj1.set_y(3);
    obj1.set_width(4);
    obj1.set_height(2);
    obj1.set_color("Blue");
    obj1.set_visibility(true);
    obj1.set_frame(true);
    // Просмотр изменных значений, выведем их с помощью get
    std::cout << "Имя окна: " << obj1.get_title() << std::endl;
    std::cout << "Координата x: " << obj1.get_x() << std::endl;
    std::cout << "Координата y: " << obj1.get_y() << std::endl;
    std::cout << "Ширина: " << obj1.get_width() << std::endl;
    std::cout << "Высота: " << obj1.get_height() << std::endl;
    std::cout << "Цвет: "  << obj1.get_color() << std::endl;
    std::cout << "Видимость: " << std::boolalpha << obj1.get_visibility() << std::endl;
    std::cout << "Наличие рамки: " << std::boolalpha << obj1.get_frame() << std::endl;
    std::cout << "\n";

    ModelWindow obj2("Окно1", 350, 350, 400, 200, "White", true, false);
    obj2.toString();
    std::cout << "\n";

    // Передвижение экрана по горизонтали
    obj2.horizontalMove(-1000);
    obj2.toString();

    // Передвижение экрана по по вертикали
    // obj2.verticalMove(100);
    // obj2.toString();
    // std::cout << "\n";

    // Изменение ширины
    // obj2.changeWidth(-5000);
    // obj2.toString();
    // std::cout << "\n";

    // Изменение высоты
    // obj2.changeHeight(-1000);
    // obj2.toString();
    // std::cout << "\n";

    // Изменение ширины и высоты
    // obj2.changeHeightWidth(-5000, -5000);
    // obj2.toString();
    // std::cout << "\n";

    // Изменение цвета
    obj2.changeColor("Red");

    // Изменение состояний
    obj2.changeVisibility(false);
    obj2.changeFrame(true);

    // Опрос состояния
    obj2.object_condition();

    // Метод вывода информации об объекте
    obj2.toString();

    
    return 0;
}