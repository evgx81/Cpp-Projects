#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

struct Book
{
    char fio[40];
    char book_name[40];
};

int main(){
    int n = 0;
    cout << "Введите количество книг в каталоге: ";
    cin >> n;

    cout << "\n";

    if(n < 0){
        cout << "Ошибка ввода данных" << endl;
        return 1;
    }
    cin.ignore();


    //Открываем файл для записи каталога книг
    ofstream fout("books.txt", ostream::out);

    //Контейннер, который будет хранить всех авторов и их произведения
    vector<Book> books;

    //Объект типа Book 
    Book author;

    if(fout.is_open()){
        //Здесь в цикле будем заполнять файл
        for(int i = 1; i <= n; i++){

            cout << "Введите название книги: ";
            cin.getline(author.book_name, 40);
            fout << "\t";      

            cout << "Введите ФИО автора: ";
            cin.getline(author.fio, 40);
            
            cout << "\n";

            books.push_back(author);
            cin.ignore();
 
        }
    }

    cin.ignore();

    for(int i = 0; i < books.size(); ++i){
        fout << books.at(i).book_name;
        fout << "\t"; 
        fout << books.at(i).fio;
        fout << "\n";
    }

    //Закрываем файл в режиме ввода
    fout.close();

    

    char author_name[40];
    cout << "Введите автора, произведения которого хотите найти: ";
    cin >> author_name;
           
    //Открывем новый файл
    ofstream file("editions.txt", ostream::out);  
    file << "Все произведения автора " << "\"" << author_name << "\"" << endl;
    //В контейнере ищем и сравниваем авторов и выводим его произведения
    for(int i = 0; i < books.size(); ++i){

        if(strcmp(books.at(i).fio, author_name) == 0){

            if(file.is_open()){
                file << books.at(i).book_name << endl;
            }

        }
    }

    return 0;
}