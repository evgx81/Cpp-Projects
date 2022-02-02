#include <iostream>
using namespace std;

int quarter(double x[], double y[]){

    if(x[0] == 0 || x[1] == 0 || x[2] == 0 || y[0] == 0 || y[1] == 0 || y[2] == 0)
        return -1;

    if((x[0] * x[1] < 0 || x[0] * x[2] < 0) || (y[0] * y[1] < 0 || y[0] * y[2] < 0))
        return 0;

    if (x[0] < 0 && x[1] < 0 && x[2] < 0){
        if(y[0] < 0 && y[1] < 0 && y[2] < 0)
            return 3;
        else
            return 4;
    }
    else{

        if(y[0] < 0 && y[1] < 0 && y[2] < 0)
            return 2;
        else
            return 1;
    }

}

int main(){
    int n = 0;
    cout << "Введите количество треугольников: ";
    cin >> n;

    int* quarters = new int[n];

    cout << "Введите координаты сторон треугольника" << endl;
    for(int i = 1; i <= n; i++){
        double x[3]; //Для x - координат
        double y[3]; //Для y - координат

        for(int j = 0; j < 3; j++){
            cout << "x" << j + 1 << " = ";
            cin >> x[j];
            cout << "y" << j + 1 << " = ";
            cin >> y[j]; 
        }

        for(int j = 0; j < 3; j++)
            cout << x[j] << " " << y[j] << " ";

        cout << endl;

        quarters[i - 1] = quarter(x, y);
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        cout << quarters[i] << " ";

        if(quarters[i] > 0)
            count++;
    }

    cout << "\n";

    cout << "Количество треугольников, лежащих в каждой координатной четверти и не пересекающих оси координат: " << count << endl;

    return 0;
}