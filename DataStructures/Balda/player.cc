#include "player.hh"

Player::Player(const Player& player)
{
    m_score = player.m_score;
    std::copy(player.m_words.begin(), player.m_words.end(), std::back_inserter(m_words));
}

Player::~Player()
{
    m_words.clear();
    m_score = 0;
}

int Player::get_score()
{
    return m_score;
}

std::list<std::string> Player::get_words()
{
    return m_words;
}

void Player::add_word(std::string word)
{
    m_words.push_back(word);
}

void Player::increase_score(int received_score)
{
    m_score += received_score;
}

void Player::remove_word(std::string word)
{
    auto find_word = std::find(m_words.cbegin(), m_words.cend(), word);
    if (find_word == m_words.cend())
        throw std::range_error("There isn't such word in the list");
    m_words.erase(find_word);
}

void Player::decrease_score(int received_score)
{
    m_score -= received_score;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    std::cout << "Счет игрока: ";
    os << player.m_score; 
    std::cout << '\n';
    std::cout  << "Слова: ";
    for(auto iter = player.m_words.begin(); iter != player.m_words.end(); ++iter)
    {
        os << *(iter);
        std::cout << ' ';
    }
    std::cout << '\n';
    return os;
}