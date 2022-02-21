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
}

void QuadraticProbingTable::rehashing()
{
    // Чтобы пройтись по всем элементам старогомассива
    int old_capacity = m_capacity;
    m_capacity = m_capacity * 2;
    HashItem* new_hash_table = new HashItem[m_capacity];

    for(int i = 0; i < old_capacity; ++i)
    {
        // Находим новые индексы для старых элементов в хэш-таблице, ячейки которых не пусты
        if(m_table[i].m_status == FILLED)
        {
            int index = hash(m_table[i].m_key);
            if (new_hash_table[index].m_status == FILLED)
            {

                int j{1};
                int newPosition{-1};
                // Пока не обошли все ячейки новой таблицы
                while(j <= m_capacity)
                {
                    newPosition = (index + j + j*j) % m_capacity;
                    if (new_hash_table[newPosition].m_status == EMPTY)
                        break;
                    else
                        j++;
                }
                new_hash_table[newPosition] = m_table[i];
            }
            else
                new_hash_table[index] = m_table[i];    
                
        }

    }

    delete[] m_table;
    m_table = new_hash_table;
}

int QuadraticProbingTable::find_elem_with_same_key(int hash_position, TKey key)
{
    int i{};
    int index{-1};
    // Пока не обошли все ячейки
    while(i < m_capacity)
    {
        index = (hash_position + i*i) % m_capacity;
        if (m_table[index].m_key == key)
            break;
        i++;
    }
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
        if (m_table[newPosition].m_status == EMPTY)
            break;
        else
            i++;
    }
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

    // Если элемента с данным ключом нет в таблице
    if (find(key) == false)
        return false;

    if (m_table[position].m_status == FILLED)
    {
        m_table[position].m_status = REMOVED;
        m_size--;
        // Т.к элемент успешно удален
        return true;
    }
    else
    {
        int index = find_elem_with_same_key(position, key);
        if(index == -1)
            // Элемента с данным индексом нет в таблице
            return false;
        else
        {
            m_table[index].m_status = REMOVED;
            m_size--;
            return true;
        }
        
    }
}
    
bool QuadraticProbingTable::find(TKey key)
{
    int position = hash(key);
    if (m_table[position].m_status == EMPTY || m_table[position].m_status == REMOVED)
        return false;
    return true;
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
    bool isFound = find(key);
    int position = hash(key);

    if(isFound == true)
        return m_table[position].m_value;
    else
    {
        int i{};
        int index{-1};
        // Пока не обошли все ячейки
        while(i < m_capacity)
        {
            index = (position + i*i) % m_capacity;
            if (m_table[index].m_key == key)
            {
                isFound = true;
                break;
            }    
            i++;
        }

        if(isFound == true)
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
    if(m_size == 0)
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