#include <iostream>

/*
    Пример: расстановка N ферзей на шахматной доске
    N = 8 - кол-во ферзей

       0 1 2 3 4 5 6 7
    0: * * * q * * * *     * - пустая клетка
    1: q * * * * * * *     q - клетка с ферзём
    2: * * * * q * * *
    3: * * * * * * * q     d[8] - массив решения по столбцам
    4: * q * * * * * *     d[i] - индекс строки с ферзём для i-го столбца
    5: * * * * * * q *     h[i] - занята ли i-я строка
    6: * * q * * * * *     diag_add - занята ли возрастающая диагональ (i+j)
    7: * * * * * q * *     diag_sub - занята ли убывающая диагональ (i-j+(N-1))

    d = [1, 4, 6, 0 , 2, 7, 5, 3]
*/


void queenPlacement(int d[], bool h[], bool diag_sub[], bool diag_add[], int pos, int N, bool& found) {
    if (pos == N) {
        found = true;
        for (int i = 0; i < N; ++i) {
            std::cout << d[i] << ' ';
        }
        std::cout << '\n';
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (h[i] == false && diag_add[pos + i] == false && diag_sub[i - pos + N - 1] == false) {
            d[pos] = i;
            h[i] = true;
            diag_add[pos + i] = true;
            diag_sub[i - pos + N - 1] = true;
            queenPlacement(d, h, diag_sub, diag_add, pos + 1, N, found);
            // В этом случае будет выводится одно решение
            // if (found) {
            //     return;
            // }
            d[pos] = 0;
            h[i] = false;
            diag_add[pos + i] = false;
            diag_sub[i - pos + N - 1] = false;
        }
    }
}


int main() {
    std::cout << "Queens arrangement: " << '\n';
    const int BOARD_SIZE = 8;
    
    int positions[BOARD_SIZE];

    bool h[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; ++i)
        h[i] = false;

    const int DIAGONALS_NUMBER = 2 * BOARD_SIZE - 1;
    bool diag_sub[DIAGONALS_NUMBER];
    bool diag_sum[DIAGONALS_NUMBER];
    for (int i = 0; i < DIAGONALS_NUMBER; ++i) {
        diag_sum[i] = false;
        diag_sub[i] = false;
    }
    bool found = false;
    queenPlacement(positions, h, diag_sub, diag_sum, 0, BOARD_SIZE, found);
    std::cout << '\n';

    return 0;
}