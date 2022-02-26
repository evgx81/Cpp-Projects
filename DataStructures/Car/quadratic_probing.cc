#include "quadratic_probing.hh"

QuadraticProbingTable::QuadraticProbingTable(int tableSize)
{
    m_capacity = tableSize;
    m_table = new HashItem[tableSize];
    for(int i = 0; i < m_capacity; ++i)
    {
        m_table[i].m_status = EMPTY;
    }
    m_size = 0;
}

QuadraticProbingTable::QuadraticProbingTable(const QuadraticProbingTable& table)
{
    m_capacity = table.m_capacity;
    m_size = table.m_size;
    m_table = new HashItem[table.m_size];
    for(int i = 0; i < table.m_size; ++i)
        m_table[i] = table.m_table[i];
}


QuadraticProbingTable::~QuadraticProbingTable()
{
    delete[] m_table;
    m_size = 0;
}

void QuadraticProbingTable::rehashing()
{
    // Чтобы пройтись по всем элементам старого массива
    int old_capacity = m_capacity;
    // Увеличиваем размерность
    m_capacity = m_capacity * 2;
    m_size = 0;

    HashItem* old_array = new HashItem[old_capacity];
    for(int i = 0; i < old_capacity; i++)
        old_array[i] = m_table[i];

    delete[] m_table;
    m_table = new HashItem[m_capacity];
    for(int i = 0; i < old_capacity; ++i)
    {
        // Запоняем новый массив индексами
        if(old_array[i].m_status == FILLED)
        {
            insert(old_array[i].m_key, old_array[i].m_value);
        }

    }
}

bool QuadraticProbingTable::is_elem_in_table_with_quadratic_probing(int hash_position, TKey key)
{
    int i{};
    int index{-1};
    bool isFound = false;
    // Пока не обошли все ячейки
    while(i < m_capacity)
    {
        index = (hash_position + i + i*i) % m_capacity;
        if (m_table[index].m_key == key && m_table[index].m_status != REMOVED)
        {
            isFound = true;
            break;
        }    
        i++;
    }

    if (i == m_capacity) 
        isFound = false;
    return isFound;
}

int QuadraticProbingTable::find_index_elem_with_quadratic_probing(int hash_position, TKey key)
{
    int i{};
    int index{-1};
    // Пока не обошли все ячейки
    while(i < m_capacity)
    {
        index = (hash_position + i + i*i) % m_capacity;
        if (m_table[index].m_key == key && m_table[index].m_status != REMOVED)
            break;    
        i++;
    }

    if (i == m_capacity)
        index = -1;
    return index;
}

int QuadraticProbingTable::quadratic_probing(int hash_position)
{
    int i{1};
    int newPosition{-1};
    // Пока не обошли все ячейки
    while(i <= m_capacity)
    {
        newPosition = (hash_position + i + i*i) % m_capacity;
        if (m_table[newPosition].m_status == EMPTY || m_table[newPosition].m_status == REMOVED)
            break;
        else
            i++;
    }
    if (i == m_capacity) 
        newPosition = -1;
    return newPosition;
}

int QuadraticProbingTable::hash(TKey key)
{
    int ASCII_sum{};
    int m_region_size = key.m_region.size();
    for(int i = 0; i < m_region_size; ++i)
        ASCII_sum += (int)(key.m_region[i]);

    return (ASCII_sum + key.m_number) % m_capacity;
}

void QuadraticProbingTable::insert(TKey key, TValue value)
{
    if (this->isFull())
    {
        rehashing();
    }

    int position = hash(key);
    
    if (m_table[position].m_status == EMPTY || m_table[position].m_status == REMOVED)
    {
        m_table[position].m_value = value;
        m_table[position].m_key = key;
        m_table[position].m_status = FILLED;
        m_size++;
    }
    else
    {
        int newPosition = quadratic_probing(position);
        m_table[newPosition].m_value = value;
        m_table[newPosition].m_key = key;
        m_table[newPosition].m_status = FILLED;
        m_size++;

    }
    
}

bool QuadraticProbingTable::remove(TKey key)
{
    int position = hash(key);

    if (m_table[position].m_status == EMPTY || m_table[position].m_status == REMOVED)
    {
        m_table[position].m_status = REMOVED;
        m_size--;
        return true;
    }
    else
    {
        int index = find_index_elem_with_quadratic_probing(position, key);
        if(index == -1)
            // Элемента с данным индексом нет в таблице
            return false;

        m_table[index].m_status = REMOVED;
        m_size--;
        return true;
    }

}


bool QuadraticProbingTable::find(TKey key)
{
    int position = hash(key);
    bool isFound = m_table[position].m_status == FILLED;
    
    if (isFound == true)
        return true;
    else
    {
        isFound = is_elem_in_table_with_quadratic_probing(position, key);
        if (isFound == true)
            return true;
        return false;
    }    

}

void QuadraticProbingTable::clear()
{
    for(int i = 0; i < m_capacity; ++i)
    {
        if (m_table[i].m_status == FILLED)
        {
            m_table[i].m_status = REMOVED;
            m_size--;
        }
    }
}

TValue QuadraticProbingTable::get(TKey key)
{
    int position = hash(key);
    bool isFound = m_table[position].m_status == FILLED;

    if(isFound == true)
        return m_table[position].m_value;
    else
    {
        int index = find_index_elem_with_quadratic_probing(position, key);
        if(index != -1)
            return m_table[index].m_value;
        else
            throw std::range_error("There isn't an element with this key");
    }    
}
    
bool QuadraticProbingTable::isEmpty()
{
    return m_size == 0;
}

int QuadraticProbingTable::size()
{
    return m_size;
} 

void QuadraticProbingTable::print()
{
    if(isEmpty())
        std::cout << "Таблица пуста\n";
    else
    {
        for(int i = 0; i < m_capacity; ++i)
        {
            std::cout << i << ' ';
            if(m_table[i].m_status == EMPTY || m_table[i].m_status == REMOVED)
                std::cout << ' ' << '\n';
            else
                std::cout << m_table[i] << '\n';
        }
            

        std::cout << "Количество элементов в таблице: " << m_size << '\n' << '\n'; 
    }

}