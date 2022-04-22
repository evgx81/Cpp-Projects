#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <list>
#include <algorithm>

class Player
{
    // Количество очков игрока
    int m_score;
    // Лист слов, использованных игроком в игре
    std::list<std::string> m_words;
public:
    Player() : m_score{} {}
    ~Player();
    Player(const Player&);
public:
    // Получаем количество очков игрока
    int get_score();
    // Получаем лист, использованных игроком слов в игре
    std::list<std::string> get_words();
public:
    // Добавляем слово к листу слов игрока
    void add_word(std::string);
    // Увеличиваем счет игрока на заданную величину
    void increase_score(int);
    // Удаляем слово из листа слов игрока
    void remove_word(std::string);
    // Уменьшаем счет игрока на заданную величину
    void decrease_score(int);
public:
    friend std::ostream& operator<<(std::ostream&, const Player&);
};

#endif