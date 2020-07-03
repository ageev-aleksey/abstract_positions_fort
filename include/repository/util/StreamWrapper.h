//
// Created by nrx on 03.07.2020.
//

#ifndef ABSTRACT_POSITIONS_STREAMWRAPPER_H
#define ABSTRACT_POSITIONS_STREAMWRAPPER_H

#include <iostream>
#include <string>


/**
 * \brief интерфейс обертки над потоками ввода вывода с++
 */
class StreamWrapper {
public:
    /**
     * \brief очистка буфера от данных
     */
    virtual void clearBuffer() = 0;
    /**
     * \brief восстановление рабочего состояния потока
     */
    virtual void clearStream() = 0;
    /**
     * \brief запись в поток
     * @param str - строка, которая будет записана в поток
     */
    virtual void write(const std::string &str) = 0;
    /**
     * \brief чтение из потока
     * @param str - строка, в которую будет выполнено считывание
     */
    virtual void read(std::string &str) = 0;
    /**
     * \brief Установка относительной позиции курсора в потоке
     * @param pos  - относительное смещение курсора
     * @param seek  - относительно чего задается смещение
     */
    virtual void seekg(int pos, std::ios::seekdir seek) = 0;
    /**
     * \brief метод заставляет поток отправить данные целевому объетку потока
     */
    virtual void flush() = 0;
    /**
     *  \brief метод для проверку возможности записи и чтения из потока
     * @return - открыт поток или нет
     */
    virtual bool isOpen() = 0;
};



#endif //ABSTRACT_POSITIONS_STREAMWRAPPER_H
