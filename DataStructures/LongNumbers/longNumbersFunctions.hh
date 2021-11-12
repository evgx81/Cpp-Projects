#ifndef LONG_NUMBERS_H
#define LONG_NUMBERS_H

#include "List.hh"
#include <string>

// Функция, которая будет заполнять лист цифрами
void readNumberFromFile(TList&, const std::string, bool&);

// Функция, кот считает кол-во цифр в числах
int sizeNumber(TList);

// Функция будет хранить минимальное число разрядов из 2-ч чисел
int minCount(TList);

// Возвращает указатель на голову суммы, кот представлена списком
TList sum(TList, TList);

// Функция, которая до конца считает сумму, если числа отличаются по кол-ву цифр
void sumLastDigits(TList&, TList&, int, int, int);

// Возвращает указатель на голову разности, кот представлена списком
TList sub(TList, TList);

// Функция, которая до конца считает разность, если числа отличаются по кол-ву цифр
void subLastDigits(TList&, TList&, int);

// Функция, которая будет с конца удалять нули 
void subNormalize(TList&);

// Функция печати результа
void print(TList, bool);

// Функция определения наибольшего числа из одинаковых по длину
bool compareNumbersForSub(TList, TList);

// Функция печати суммы в зависимости от знака
void printSum(TList, TList, bool, bool);

// Функция печати разности в зависимости от знака
void printSub(TList, TList, bool, bool);

#endif
