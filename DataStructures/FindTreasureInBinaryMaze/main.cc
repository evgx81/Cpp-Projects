#include "queue.hh"
#include "matrix.hh"

bool isValid(int row, int col)
{
    return (row >= 0) && (row < 10) && (col >= 0) && (col < 10);
}

// Находим на кратчайший путь к заданной вершине
int shortestWayInMatrix(Matrix<int> matrix, Cell start, Cell dest)
{
    // Добавим ориентацию
    // Покоординатно: вверх, влево, вправо, вниз
    int rowNum[4] = {-1, 0, 0, 1};
    int colNum[4] = {0, -1, 1, 0};

    // Матрица, которая определяет является ли клетка посещенной
    // На данный момент, мы не посетили еще ни одной вершины, поэтому инициализируем все нулями
    Matrix<bool> visitedCells(10, false);
    // Помечаем, что посетили начальное положение
    visitedCells[start] = true;
    // Создаем очередь
    Queue queue;
    // Добавляем начальную клетку в очередь, расстояние до нужной вершины равно 0 
    queue.enQueue(start, 0);

    while(!queue.isEmpty())
    {
        // Получаем верхнюю клетку
        Cell currentCell = queue.getFrontCell();
        int currentDist = queue.getFrontDistance();

        // Если нашли клад, то возвращаем путь
        if(currentCell == dest)
            return currentDist;

        // Иначе удаляем верхнюю клетку
        queue.deQueue();
        // Добавляем в очередь соседние клетки удаленной клетки
        for (int i = 0; i < 4; i++)
        {
            // Передвигаемся в соседнюю клетку
            int row = currentCell.m_x + rowNum[i];
            int col = currentCell.m_y + colNum[i];

            // Создаем клетку с данными координатами
            Cell adjacentCell{row, col};

            // Если соседняя вершина не выходит за границы лабиринта, еще не посещена и проходима, добавляем ее в очередь
            if(isValid(row, col) && matrix[adjacentCell] == 0 && visitedCells[adjacentCell] == false)
            {
                visitedCells[adjacentCell] = true;
                queue.enQueue(adjacentCell, currentDist + 1);
            }
        }
    }
    // Возвращаем -1, если заданная вершина не может быть достигнута
    return -1;
}

int main()
{   
    try
    {
        Matrix<int> matrix(10);
        // Открываем файл для считывания
        std::ifstream fin("matrix.txt", std::ios::in);
        if (!fin.is_open()) {
            throw "Unable to open file for reading!\n";
        }
        fin >> matrix;
        fin.close();

        // Начальное положение кладоискателя
        Cell start;
        std::cout << "Введите начальное положение кладоискателя\n";
        std::cin >> start;

        if (matrix[start] == 1)
            throw std::invalid_argument("Начальное положение кладоискателя является непроходимой клеткой!");
    
        if ((start.m_x > 0 && start.m_x < 10) && (start.m_y > 0 && start.m_y < 10))
            throw std::invalid_argument("Начальное положение не находится на краевой клетке!");
    

        // Координаты клада
        Cell destination;
        std::cout << "Введите координаты клада\n";
        std::cin >> destination;

        if (matrix[destination] == 1)
            throw std::invalid_argument("Положение клада является непроходимой клеткой!");

        int shortestWay = shortestWayInMatrix(matrix, start, destination);
        if (shortestWay == -1)
            std::cout << "Пути от клетки " << start << " к клетке " << destination << " не существует\n";
        else
            std::cout << "Самый короткий путь до клада: " << shortestWay << '\n';
    }
    catch(std::invalid_argument err)
    {
        std::cerr << err.what() << '\n';
    } 
    

    return 0;
}
