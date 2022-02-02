#include <iostream>
#include <set>
using namespace std;

/*
В городе N, 100 кондитерских магазинов. 
Известно что в каждом из магазинов не более 20 видов сластей в ассортименте. 
Какие виды сластей есть во всех магазинах? Существует ли магазин торгующий уникальной продукцией? 
Перечислите 5 видов сластей которые есть в большинстве магазинов города N. 
(ассортимент кондитерских магазинов рассматривается как длинна перечисляемого типа).
*/


int main(){
    //Массив содержит названия сладостей
    int sweets[20] =   {1, 2, 3, 4, 5,
                        6, 7, 8, 9, 10,
                        11, 12, 13, 14, 15, 
                        16, 17, 18, 19, 20};

    //В городе имеется 100 магазинов
    const int N = 3;
    int shops[N];
    //Пусть будет константное значение количества товаров в магазине
    const int amount = 5;

    multiset<int> candy_shops;
    set<int> sweets_of_shop; 

    for(int shop = 0; shop < N; shop++){

        for(int count_sweets = 0; count_sweets < amount; count_sweets++){
            int sweet = sweets[rand() % 20];
            sweets_of_shop.insert(sweet);
            candy_shops.insert(sweet);
        }
    }

    //Вывод элементов множеств
    multiset<int> :: iterator iter;
    for(iter = candy_shops.begin(); iter != candy_shops.end(); iter++)
        cout << *iter << " ";

    cout << endl;

    //Сладости, которые во всех магазинах - просто пересечение всех множеств сладостей каждого магазина.
    set<int> :: iterator it;
    for(it = sweets_of_shop.begin(); it != sweets_of_shop.end(); it++)
        cout << *it << " ";
    int count = 0;
    for(int j = 0; j < 20; j++){
        if(candy_shops.count(sweets[j]) == 1)
            count++;
    }

    cout << endl;

    if(count > 1)
        cout << "Существует" << endl;
    else
        cout << "Не существует" << endl;

    cout << "Наиболее часто встречаемые товары: " << endl;
    int max = 0;
    int index = 0;
    for(int j = 0; j < 20; j++){
        if(candy_shops.count(sweets[j]) > max){
            max = candy_shops.count(sweets[j]);
            index++;
        }
    }

    for(int j = 0; j < 20; j++){
        if(candy_shops.count(sweets[j]) == max)
            cout << (sweets[j]) << endl;
    }

    cout << endl;

    cout << max << endl;
    cout << index << endl;

    
    return 0;
    
  
}