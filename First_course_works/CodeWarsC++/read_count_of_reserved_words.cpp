#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//объявление структуры слова
struct KeyWord
{
    char keyword[20];
    int count;
};

//объявление и инициализация таблицы слов
KeyWord KeyWordTable[] = 
{
    {"else", 0}, {"for", 0}, {"if", 0}, {"include", 0}, {"while", 0}, {"namespace", 0}
};


/*В массиве KeyWordTable создается таблица для пяти зарезервированных слов.
Каждый элемент в этой таблице инициализирется уаазанием зарезервированного слова
и начального положения счетчика count=0.
Первый инициализатор массива {"else", 0} приводит к тому, что элемент
KeyWordTable[0] содержит строку "else" со значением счетчика 0.
*/

//настраиваемый алгоритм поиска слов
int SeqSearch(KeyWord *tab, int n, char* word)
{
    int i;
    //сканировать список, сравнивать word с keyword в текущей записи
    for(i = 0; i < n; i++, tab++){
        if(strcmp(word, tab->keyword) == 0)
            return i;//при совпадении вернуть индекс
    }
    return -1;//к сожалению нет совпадения
}

//извлечь слово, начинающееся с буквы и, возможно,
//другие цифры
int GetWord(ifstream& fin, char w[])
{
    char c;
    int i = 0;

    //пропустить не алфавитный ввод
    while(fin.get(c) && !isalpha(c));

    //вернуть 0 (неудача в конце файла)
    if(fin.eof())
        return 0;
    /*eof - выдаёт истину, если файл пуст, а если файл не пуст, то выдаётся ложь.
    Эта функция часто применяется, при работе с вводом/выводом из файлов 
    с использованием операций ">>" и "<<".*/

    //записать первый символ word
    w[i++] = c;

    //собирать буквы, цифры и символ окончания строки
    while (fin.get(c) && (isalpha(c) || isdigit(c)))
        w[i++] = c;
    w[i] = '\0';

    return 1;     //вернуть 1 (Успех)   
}

int main(){
    const int MAXWORD = 50; // максимальный размер любого слова

    //объявить и инициализировать размер таблицы
    const int NKEYWORDS = sizeof(KeyWordTable) / sizeof(KeyWord);

    int n;
    char word[MAXWORD], c;

    ifstream fin;
    //открываем файл с проверкой ошибки
    fin.open("read_count_of_reserved_words.cpp", ios::in);
    if(!fin){
        cerr << "Невозможно открыть файл 'read_count_of_reserved_words.cpp'" << endl;
        exit(1);
    }

    //извлекать слова до конца файла
    while(GetWord(fin, word))
        //при совпадении с таблицей keyword увеличивать счетчик
        if((n = SeqSearch(KeyWordTable, NKEYWORDS, word)) != -1)
            KeyWordTable[n].count++;
    
    //сканировать таблицу keyword и печатать поля записи
    for(n = 0; n < NKEYWORDS; n++)
        if(KeyWordTable[n].count > 0){
            cout << KeyWordTable[n].count;
            cout << " " << KeyWordTable[n].keyword << endl;
        }
    return 0;
}

