//
// Created by nrx on 03.07.2020.
//

#ifndef ABSTRACT_POSITIONS_FILESTREAMWRAPPER_H
#define ABSTRACT_POSITIONS_FILESTREAMWRAPPER_H

#include "repository/util/StreamWrapper.h"
#include <fstream>

/**
 * \brief обертка над std::fstream - поток вввода/вывода в файл
 */
class FileStreamWrapper : public StreamWrapper  {
public:
    /**
     *  \brief открытие на чтение и запись файла
     * @param path - путь до файла
     */
    explicit FileStreamWrapper(const std::string &path);
    /**
     * \brief очистка файла
     */
    void clearBuffer() override;
    void clearStream() override;
    /**
     * \brief запись в файл
     * @param str - строка, которая будет записана в файл
     */
    void write(const std::string &str) override;
    /**
     * \brief чтение всего файла
     * @param str - строка в, которую будет прочитан весь файл
     */
    void read(std::string &str) override;
    /**
     * \brief относительное смещение в файле
     * @param pos  - относительное смещение в файле
     * @param seek  - относительно чего задается смещение
     */
    void seekg(int pos, std::ios::seekdir seek) override;
    /**
     * \brief принудительная отправка данных из буферов в файл
     */
    void flush() override;
    /**
     * \brief метод проверят удалось ли открыть файл
     * @return открыт файл или нет
     */
    bool isOpen() override;


private:
    std::string filePath;
    std::fstream stream;
};
#endif //ABSTRACT_POSITIONS_FILESTREAMWRAPPER_H
