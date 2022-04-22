#ifndef BALDA_H
#define BALDA_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "player.hh"

// В стандартном варианте игры размер поля 5*5
const int SIZE = 5;

class Balda
{
    // Заданное первое слово, с которого начинается игра
    std::string m_base_word;
    // Заданный набор слов
    std::vector<std::string> m_words;
    // Игровое поле, куда будут вставляться слова игроков
    std::vector<std::vector<char>> m_playing_field;
    // Первый игрок
    Player m_first_player;
    // Второй игрок
    Player m_second_player;
public:
    Balda(std::string, std::vector<std::string>);
    ~Balda();
private:
    // Функция, которая удаляет символ из слова
    void remove(std::vector<std::vector<char>>&, std::pair<int, int>);
    // Функция, которая возвращает клетку, в которой находится последний символ слова
    std::pair<int, int> get_adjacent_cell_with_symbol(std::vector<std::vector<char>>, std::pair<int, int>, char);
private:
    // Функция, которая вставляет последний символ слова в матрицу
    void insert_word(bool&, std::pair<int, int>&, int, std::vector<std::vector<bool>>&, std::vector<std::vector<char>>&, std::string, std::pair<int, int>&);
    // Функция, которая находит первую свободную смежную вершину у клетки
    std::pair<int, int> get_first_empty_adjacent_cell(std::vector<std::vector<char>>, std::pair<int, int>);
    // Функция, которая возвращает true, если слово можно вставитьна доску
    std::pair<int, int> is_word_can_be_inserted(std::vector<std::vector<char>>&, std::string);
private:
    // Функция проверки, что не вышли за пределы игрового поля
    bool isValid(int, int);
    // Функция, которая проверяет, можем ли шагнуть в клетку
    bool can_step(int, int, std::vector<std::vector<bool>>);
    // Функция проверки того, что игровое поле заполнено
    bool is_field_filled();
    // Функция, которая использованы ли все слова в заданном наборе слов
    bool is_all_words_used(std::vector<bool>);
public:
    // Функция, которая выведет набор слов, который приведет первого игрока к победе
    void analyze_game();
    // Рекурсивная функция, которая будет просматривать всевозможные комбинации слов
    void back_tracking(std::vector<std::vector<char>>&, std::vector<std::string>, std::vector<bool>&, int);
private:
    // Функция, которая проверяет есть ли слова, которые нельзя вставить в матрицу
    bool is_some_words_not_inserted(std::vector<bool>); 
public:
    friend std::ostream& operator<<(std::ostream&, const Balda&);
};

#endif