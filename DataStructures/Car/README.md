# Hash Table
Реализовать структуру данных "Хэш-таблица" в виде класса с одним из способов разрешения коллизий (цепочки переполнения, открытая адресация - линейное опробование, квадратичное опробование, двойное хэширование).  
Определить операции:  
- [+] инициализации таблицы,
- [+] вставки элемента по ключу,
- [+] удаления элемента по ключу,
- [+] поиска элемента по ключу,
- [+] печати таблицы,
- [+] очистки таблицы.  

[+] Реализовать автоматическое увеличение размерности хэш-таблицы в 2 раза:
- в случае цепочек переполнения - при превышении средней длины списка более 10 элементов;
- в случае открытой адресации - при заполненности хэш-таблицы выше заданного уровня(например, 75%).

Ввод и вывод данных организовать с помощью файлов.  
Реализовать в консоли интерфейс в виде меню с перечисленными операциями. Меню должно давать возможность повторить или выполнить новую операцию с таблицей. Последней операцией должен быть выход из меню. На основе разработанного класса выполнить задание.

Задан набор записей следующего вида:
- Государственный регистрационный номер:
  - регион (3 знака),
  - номер (6 знаков).
- Фирма-производитель,
- ФИО водителя,
- Номер маршрута,
- Состояние(в парке, на маршруте).

Поместить записи в хэш-таблицу. В качестве ключа использовать гос. номер. Для разрешения конфликтов примменить *квадратичное опробирование*. 
