#include "balda.hh"
#include <queue>

Balda::Balda(std::string first_word, std::vector<std::string> words)
{
    m_base_word = first_word;
    if (first_word.size() != SIZE)
        throw std::range_error("Слово данного размера нельзя поместить на игровое поле");

    m_words.resize(words.size());
    for (int i = 0; i < m_words.size(); ++i)
        m_words[i] = words[i]; 

    m_playing_field.resize(SIZE);
    for (int i = 0; i < SIZE; ++i)
        m_playing_field[i].resize(SIZE, '-');

    
    for (int i = 0; i < m_base_word.size(); ++i)
    {
        m_playing_field[SIZE/2][i] = m_base_word[i];
    }

}

Balda::~Balda()
{
    m_words.clear();
    for (int i = 0; i < SIZE; ++i)
        m_playing_field[i].clear();
    m_playing_field.clear();
}

std::ostream& operator<<(std::ostream& os, const Balda& balda)
{
    std::cout << "Заданный набор слов: ";
    for (auto iter = balda.m_words.cbegin(); iter != balda.m_words.cend(); ++iter)
    {
        os << *(iter);
        std::cout << ' ';
    }    
    std::cout << '\n';

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            os << balda.m_playing_field[i][j];
            std::cout << ' ';
        }
        std::cout << '\n';
    }

    return os;
}

void Balda::analyze_game()
{
    // В начале игре помечаем все слова как неиспользованные
    std::vector<bool> used_words(m_words.size(), false);
    // Запускаем функцию перебора возможных вариантов
    back_tracking(m_playing_field, m_words, used_words, 1);
}

void Balda::back_tracking(std::vector<std::vector<char>>& matrix, std::vector<std::string> words, std::vector<bool>& used_words, int turn)
{
    // Если матрица заполнена и в игре использовали все слова
    if (is_field_filled() == true || is_all_words_used(used_words) == true)
    {
        // Вызывать функцию, котороя будет проверять принимать игроков, выведет те случаи, в которых выигрывает первый игрок
        if (m_first_player.get_score() > m_second_player.get_score())
        {
            std::cout << m_first_player << '\n';
            std::cout << m_second_player << '\n';
            std::cout << "---------------------------\n";
        }
        
    }
    // Проходим по массиву слов и ищем все неиспользованные слова
    for (int i = 0; i < m_words.size(); ++i)
    {
        if (used_words[i] == false)
        {
            std::pair<int, int> last_inserted_symbol= is_word_can_be_inserted(matrix, m_words[i]);
            if (last_inserted_symbol.first != -1 && last_inserted_symbol.second != -1)
            {
                used_words[i] = true;
                if (turn % 2 == 1)
                {
                    m_first_player.add_word(words[i]);
                    m_first_player.increase_score(words[i].size());
                }
                if (turn % 2 == 0 )
                {
                    m_second_player.add_word(words[i]);
                    m_second_player.increase_score(words[i].size());
                }
                back_tracking(matrix, words, used_words, turn + 1);
                used_words[i] = false;
                if (turn % 2 == 1)
                {
                    m_first_player.remove_word(words[i]);
                    m_first_player.decrease_score(words[i].size());
                }
                if (turn % 2 == 0)
                {
                    m_second_player.remove_word(words[i]);
                    m_second_player.decrease_score(words[i].size());
                }
                remove(matrix, last_inserted_symbol); 
            }
        }
    }
}

bool Balda::is_some_words_not_inserted(std::vector<bool> visited_words)
{
    for (int i = 0; i < visited_words.size(); ++i)
    {
        // Находим слово, которое нельзя вставить в матрицу
        if (visited_words[i] == false)
            return true;
    }
    return false;
}

bool Balda::is_field_filled()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (m_playing_field[i][j] == '-')
                return false;
        }
    } 
    return true;
}

bool Balda::is_all_words_used(std::vector<bool> visited_words)
{
    for (int i = 0; i < visited_words.size(); ++i)
    {
        // Если нашли не использованное слово
        if (visited_words[i] != true)
            return false;
    }
    return true;
}


std::pair<int, int> Balda::is_word_can_be_inserted(std::vector<std::vector<char>>& matrix, std::string word)
{
    int curr_symbol = 0;
    bool result = false;
    std::pair<int, int> last_position(-1, -1);
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            // Находим первый символ слова в матрице
            if (matrix[i][j] == word[curr_symbol] && result == false)
            {
                
                std::pair<int, int> start_position(i, j);

                std::vector<std::vector<bool>> visited_cells;
                visited_cells.resize(SIZE);
                for (int i = 0; i < SIZE; ++i)
                    visited_cells[i].resize(SIZE, false);

                visited_cells[start_position.first][start_position.second] = true;
                insert_word(result, start_position, curr_symbol + 1, visited_cells, matrix, word, last_position);

                for (int i = 0; i < SIZE; ++i)
                    visited_cells[i].clear();
                visited_cells.clear();
            }
        }
    }

    return last_position;
}


bool Balda::can_step(int row, int col, std::vector<std::vector<bool>> visited_cells)
{
    return isValid(row, col) && !visited_cells[row][col]; // add symbols check 
}

bool Balda::isValid(int row, int col)
{
    return (row >= 0) && (row < SIZE) && (col >= 0) && (col < SIZE);
}

void Balda::insert_word(bool& insert_result, std::pair<int, int>& curr_position, int curr_symbol, std::vector<std::vector<bool>>& visited_cells, std::vector<std::vector<char>>& matrix, std::string word, std::pair<int, int>& last_position) 
{
    if (curr_symbol == word.size() - 1) 
    {
        std::pair<int, int> adjacent_cell = get_first_empty_adjacent_cell(matrix, curr_position);
        
        if (adjacent_cell.first != -1 && adjacent_cell.second != -1)
        {
            matrix[adjacent_cell.first][adjacent_cell.second] = word[word.size()-1];
            insert_result = true;

            last_position.first = adjacent_cell.first;
            last_position.second = adjacent_cell.second;
            
        }
    }
    
    int rowNum[4] = {-1, 0, 0, 1};
    int colNum[4] = {0, -1, 1, 0};

    for (int i = 0; i < 4; i++)
    {
        // Передвигаемся в соседнюю клетку
        int row = curr_position.first + rowNum[i];
        int col = curr_position.second + colNum[i];

        // Если можем шагнуть в ячейку и символ этой ячейки совпадает с символом слова
        if (can_step(row, col, visited_cells) == true && matrix[row][col] == word[curr_symbol])
        {
            std::pair<int, int> next_position(row, col);
            visited_cells[next_position.first][next_position.second] = true;
            
            insert_word(insert_result, next_position, curr_symbol + 1, visited_cells, matrix, word, last_position);
            visited_cells[row][col] = false;
        }
    }
}



std::pair<int, int> Balda::get_first_empty_adjacent_cell(std::vector<std::vector<char>> matrix, std::pair<int, int> cell)
{
    std::pair<int, int> empty_cell(-1, -1);

    int rowNum[4] = {-1, 0, 0, 1};
    int colNum[4] = {0, -1, 1, 0};

    for (int i = 0; i < 4; i++)
    {
        int row = cell.first + rowNum[i];
        int col = cell.second + colNum[i];

        // Находим первую свободную смежную клетку
        if (isValid(row, col) && matrix[row][col] == '-')
        {
            empty_cell.first = row;
            empty_cell.second = col;
            return empty_cell;
        }
    }

    return empty_cell;
}

std::pair<int, int> Balda:: get_adjacent_cell_with_symbol(std::vector<std::vector<char>> matrix, std::pair<int, int> cell, char symb)
{
    std::pair<int, int> empty_cell(-1, -1);

    int rowNum[4] = {-1, 0, 0, 1};
    int colNum[4] = {0, -1, 1, 0};

    for (int i = 0; i < 4; i++)
    {
        int row = cell.first + rowNum[i];
        int col = cell.second + colNum[i];

        // Находим первую свободную смежную клетку
        if (isValid(row, col) && matrix[row][col] == symb)
        {
            empty_cell.first = row;
            empty_cell.second = col;
            return empty_cell;
        }
    }

    return empty_cell;
}


void Balda::remove(std::vector<std::vector<char>>& matrix, std::pair<int, int> index)
{
    matrix[index.first][index.second] = '-';
}

 // int curr_symbol = 0;
    // bool result = false;
    // for (int i = 0; i < SIZE; ++i)
    // {
    //     for (int j = 0; j < SIZE; ++j)
    //     {
    //         // Находим первый символ слова в матрице
    //         // Относительно этого символа будем удалять последний символ
    //         if (matrix[i][j] == word[curr_symbol] && result == false)
    //         {
                
    //             std::pair<int, int> start_position(i, j);
    //             std::vector<std::vector<bool>> visited_cells;
    //             visited_cells.resize(SIZE);
    //             for (int i = 0; i < SIZE; ++i)
    //                 visited_cells[i].resize(SIZE, false);

    //             visited_cells[start_position.first][start_position.second] = true;
                
    //             remove_word(result, start_position, curr_symbol + 1, visited_cells, matrix, word);

    //             for (int i = 0; i < SIZE; ++i)
    //                 visited_cells[i].clear();
    //             visited_cells.clear();
    //         }
    //     }
    // }

// void Balda::remove_word(bool& remove_result, std::pair<int, int>& curr_position, int curr_symbol, std::vector<std::vector<bool>>& visited_cells, std::vector<std::vector<char>>& matrix, std::string word)
// {
//     if (curr_symbol == word.size() - 1) 
//     {
//         std::pair<int, int> adjacent_cell = get_adjacent_cell_with_symbol(matrix, curr_position, word[word.size() - 1]);
        
//         if (adjacent_cell.first != -1 && adjacent_cell.second != -1)
//         {
//             matrix[adjacent_cell.first][adjacent_cell.second] = '-';
//             remove_result = true;    
//         }
        
//     }

//     int rowNum[4] = {-1, 0, 0, 1};
//     int colNum[4] = {0, -1, 1, 0};

//     for (int i = 0; i < 4; i++)
//     {
//         // Передвигаемся в соседнюю клетку
//         int row = curr_position.first + rowNum[i];
//         int col = curr_position.second + colNum[i];

//         // Если можем шагнуть в ячейку и символ этой ячейки совпадает с символом слова
//         if (can_step(row, col, visited_cells) == true && matrix[row][col] == word[curr_symbol])
//         {
//             visited_cells[row][col] = true;
//             std::pair<int, int> next_position(row, col);
//             remove_word(remove_result, next_position, curr_symbol + 1, visited_cells, matrix, word);
//             visited_cells[row][col] = false;
//         }
//     }
// }