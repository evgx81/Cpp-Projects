#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>
#include <iostream>
#include "cell.hh"

template<typename T>
class Matrix
{
    T** m_matrix;
    const int m_size;
public:
    Matrix(int size, T val = 0) : m_size{size}
    {
        //Выделение памяти
        m_matrix = new T*[m_size];
        for(int i = 0; i < m_size; ++i) 
            m_matrix[i] = new T[m_size];

        for(int i = 0; i < m_size; i++) 
        {
            for(int j = 0; j < m_size; j++)
                m_matrix[i][j] = val;
        }
        
    }
    Matrix(const Matrix& matrix) : m_size{matrix.m_size}
    {
        m_matrix = new T*[m_size];
        for(int i = 0; i < m_size; ++i) 
            m_matrix[i] = new T[m_size];
            
        for(int i = 0; i < m_size; i++) 
        {
            for(int j = 0; j < m_size; j++)
                m_matrix[i][j] = matrix.m_matrix[i][j];
        }
        
    }
    ~Matrix()
    {
        //Очистка памяти
        for(int i = 0; i < m_size; i++) 
            delete[] m_matrix[i];
        delete[] m_matrix;
    }

    T& operator[](Cell& cell)
    {
        return m_matrix[cell.m_x][cell.m_y];
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix)
    {
        //Ввод значений в массив из файла
        for(int i = 0; i < matrix.m_size; i++) 
        {
            for(int j = 0; j < matrix.m_size; j++) 
                is >> matrix.m_matrix[i][j];
        }
        return is;  
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
    {
        //Вывод значений массива
        for(int i = 0; i < matrix.m_size; i++) 
        {
            for(int j = 0; j < matrix.m_size; j++) 
                os << matrix.m_matrix[i][j] << ' ';
            os << '\n';
        }
        return os;
    }
};

#endif
