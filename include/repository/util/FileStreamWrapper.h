//
// Created by nrx on 03.07.2020.
//

#ifndef ABSTRACT_POSITIONS_FILESTREAMWRAPPER_H
#define ABSTRACT_POSITIONS_FILESTREAMWRAPPER_H

#include "repository/util/StreamWrapper.h"
#include <fstream>


class FileStreamWrapper : public StreamWrapper  {
public:
    explicit FileStreamWrapper(const std::string &path);
    void clearBuffer() override;
    void clearStream() override;
    void write(const std::string &str) override;
    void read(std::string &str) override;
    void seekg(int pos, std::ios::seekdir seek) override;
    void flush() override;
    bool isOpen() override;


private:
    std::string filePath;
    std::fstream stream;
};
#endif //ABSTRACT_POSITIONS_FILESTREAMWRAPPER_H
