#include <iostream>
#include <cmath>
class Movie
{   private:
        int card;
        int ticket;
        double perc;
    public:
        //Конструкторы
        Movie();
        Movie(int movie_Card, int movie_Ticket, double movie_Perc);
    public:
        static int movie(int Input_card, int Input_ticket, double Input_perc);
};

Movie::Movie()
{
    card = 0;
    ticket = 0;
    perc = 0.0;
}

Movie::Movie(int movie_Card, int movie_Ticket, double movie_Perc){
    card = movie_Card;
    ticket = movie_Ticket;
    perc = movie_Perc;
}


int Movie::movie(int Input_card, int Input_ticket, double Input_perc)
{
    int price_A = 0;
    double price_B = Input_card;

    int rem = 0;

    int n = 1;
    int i = 1;
        
    while(i <= n){
        price_A = i * Input_ticket;
        price_B += Input_ticket * pow(Input_perc, i);
        i++;
        n++; 
    
        if(ceil(price_B) < price_A){
            rem = n - 1;
            return rem;
        }
    }    
}

int main(){
    Movie object(100, 10, 0.95);
    std::cout << object.movie(100, 10, 0.95) << std::endl;  
    return 0;
}