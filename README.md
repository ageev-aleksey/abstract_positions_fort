## Консольное приложение для работы с записями ключ::значение

[![Build Status](https://travis-ci.com/ageev-aleksey/abstract_positions_fort.svg?branch=master)](https://travis-ci.com/ageev-aleksey/abstract_positions_fort)

**Возможности:**
 - Добавление записи Ключ::Значение. Ключи могут повторятся у разных записей.
 - Поиск записи по ключу.
 - Удаление записи по ключу.
 - вывод списка всех записей
 
 **Использование:**
 - app [путь к файлу с записями] - если аргумент не указан будет спльзоваться файл по умолчанию (positions.txt)
 - После запуска программы, манипулирования записями происходит с помощью комманд:
    * add <ключ> <значение> - команда для добавления записи
    * all - выводит список всех записей
    * find <ключ> - поиск всех записей с заданным ключем
    * remove <ключ> - команда для удаления записей. Она сначало найдет все записи с заданным ключем,
     а потом предложить выбор: какие записи из найденных удалить.
     * exit - выход и программы
     
 **Пример использования:**
- ./app
````
    using default file: positions.txt
    > add key1 value1
    > add test_key2 value2    
    > add key1 2020
    > all
    Position(title=key1; value=2020)
    Position(title=key1; value=value1)
    Position(title=test_key2; value=value2)
    > find key1
    Position(title=key1; value=2020)
    Position(title=key1; value=value1)
    > find f
    > remove key1
    -- founded 2 positions; 
    -- what positions to remove? Indicate numbers cross a space.
    -- [0] Position(title=key1; value=2020)
    -- [1] Position(title=key1; value=value1)
    --> 0 1
    > all
    Position(title=test_key2; value=value2)
    > exit

````
 
 
