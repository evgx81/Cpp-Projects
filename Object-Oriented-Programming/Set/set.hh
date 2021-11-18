#ifndef SET_H
#define SET_H

#include <iostream>
#include <stdexcept>

template <class T>
class Set {
    // Размер, на который увеличивается емкость множества при заполнении
    int m_chunk_size{10};
    // Емкость(кол-во элементов, которое мн-во может вместить на данный момент)
    int m_capacity;
    // Размер множества
    int m_size;
    // Массив хранит элементы множества
    T* m_data;
    // Функция увеличения емкости массива при его переполнении
    void increase_capacity();
    // Функция, которая перезаписывает старый массив в новый, удаляя нули в конце(элементы, которые были удалены)
    void rewriteArray();

public:
    Set() : m_capacity{m_chunk_size}, m_size{}, m_data{new T[m_chunk_size]} {};
    Set(int size) : m_capacity{size}, m_size{}, m_data{new T[size]} {};
    // Конструктор копирования
    Set(const Set<T>&);
    ~Set();
public:
    // Включение элемента в множество
    void insert(const T&);
    // Исключение элемента из множества
    void erase(const T&);
    // Объединение множеств
    Set<T> set_union(const Set<T>&);
    // Пересечение множеств
    Set<T> set_intersection(const Set<T>&);
    // Вычитание множеств
    Set<T> set_difference(const Set<T>&);
    // Отслеживание количества элементов
    int size();
    // Проверка присутствия элемента в множестве
    bool find(const T&);
    // Проверка включения одного множества в другое
    bool is_subset(const Set<T>&);
    
public:
    // Вывод множества
    friend std::ostream& operator<<(std::ostream& os, const Set<T>& m_set)
    {
        if (m_set.m_size == 0)
            os << "Множество пусто\n";
        else 
        {
            // Выводим готовое множество
            os << "Количество элементов: " << m_set.m_size << '\n';
            os << "Элементы: ";
            for(int i = 0; i < m_set.m_size; i++)
                os << m_set.m_data[i] << ' ';
            os << '\n';
            
        }

        return os;
    }
};

template <class T>
void Set<T>::increase_capacity()
{
    m_capacity += m_chunk_size;
    T* new_array = new T[m_capacity];
    for(int i = 0; i < m_size; ++i)
    {
        new_array[i] = m_data[i];
    }
    delete[] m_data;
    m_data = new_array;
}

template <class T>
void Set<T>::rewriteArray()
{
    T* new_array = new T[m_size];
    for(int i = 0; i < m_size; ++i)
    {
        new_array[i] = m_data[i];
    }
    delete[] m_data;
    m_data = new_array;
}

template <class T>
Set<T>::Set(const Set<T>& set)
{
    m_capacity = set.m_capacity;
    m_size = set.m_size;
    m_data = new T[set.m_chunk_size];
    for(int i = 0; i < set.m_size; i++)
        m_data[i] = set.m_data[i];
}

template <class T>
Set<T>::~Set()
{
    delete[] m_data;
}

template <class T>
void Set<T>::insert(const T& elem)
{
    // Если элемента нет в множестве, то добавляем его туда 
    if (find(elem) == false)
    {
        if (m_size == m_capacity)
            increase_capacity();

        m_data[m_size] = elem;
        m_size++;
    }
}

template <class T>
void Set<T>::erase(const T& elem)
{
    if (m_size == 0)
        throw std::out_of_range("The set is empty!\n");
    // Флаг того, что элемент удален
    bool flag = false;
    for(int i = 0; i < m_size; ++i)
    {
        if (m_data[i] == elem)
        {
            flag = true;
            for(int j = i; j < m_size; ++j)
            {
                m_data[j] = m_data[j+1];
            }
        }
    }
    
    // Если в множестве остались элементы, то перезаписываем массив
    // Иначе получаем пустое множество
    if(m_size > 0 && flag == true)
    {
        --m_size;
        rewriteArray();
    }
       
    
}
template <class T>
Set<T> Set<T>::set_union(const Set<T>& set)
{
    // Создаем пустое множество, которое представляет объединение
    Set<T> s3;
    // Заполняем объединение элементами первого множества
    for(int i = 0; i < m_size; i++)
        s3.insert(m_data[i]);
    
    // Флаг для совпадающих элементов в обоих множествах, чтобы они не дублировались
    // Тогда множество будет состоять из уникальных элементов
    bool flag;
    for(int j = 0; j < set.m_size; j++)
    {
        flag = false;
        for(int i = 0; i < m_size; i++)
        {
            if(m_data[i] == set.m_data[j])
            {
                flag = true;
                // Как только нашли повторяющийся элемент, выходим цикла
                break;
            }
        }
        if(flag == false)
            s3.insert(set.m_data[j]);
    }
    return s3;
    
}

template <class T>
Set<T> Set<T>::set_intersection(const Set<T>& set)
{
    // Создаем пустое множество, которое представляет gthtctxybt
    Set<T> s3;
    for (int i = 0; i < m_size; i++) 
    {
        for (int j = 0; j < set.m_size; j++) 
        {
            // Ищем только совпадающие элементы в обоих множествах
            if (m_data[i] == set.m_data[j]) 
            {
                s3.insert(m_data[i]);
                break;
            }
        }
    }
    return s3;
}

template <class T>
Set<T> Set<T>::set_difference(const Set<T>& set)
{
    // Создаем пустое множество, которое представляет вычитание
    Set<T> s3;
    bool flag;
    for (int i = 0; i < m_size; i++) 
    {
        for (int j = 0; j < set.m_size; j++) 
        {
            // Исключаем все элементы, которые находятся на пересечении 2-х множеств
            if (m_data[i] == set.m_data[j]) 
            {
                flag = false;
                break;
            } 
            else
            // Если элемент не принадлежит другому множеству, то добавляем его в нужное множество
                flag = true;
        }

        if (flag == true)
            s3.insert(m_data[i]);
    
    }
    return s3;
}

template <class T>
int Set<T>::size()
{
    return m_size;
}

template <class T>
bool Set<T>::find(const T& elem)
{
    for (int i = 0; i < m_size; i++) 
    {
        if (m_data[i] == elem)
            return true;
    }
    return false;
}

template <class T>
bool Set<T>::is_subset(const Set<T>& set)
{   
    // Количество элементов, которые совпадают в обоих подмножествах
    int count = 0;
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < set.m_size; j++) 
        {
            // Если находим совпадающий элемент, то уже не нужно до конца идти по множеству и проверять на совпадение
            if (m_data[i] == set.m_data[j])
            {
                count++;
                break;
            }
                
        }
    }
    // Если количество посчитанных элементов совпадает с размером множества, то возвращаем true
    if (count == set.m_size) {
        return true;
    }
    return false;   
}

#endif