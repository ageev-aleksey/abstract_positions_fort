//
// Created by nrx on 03.07.2020.
//

#ifndef ABSTRACT_POSITIONS_STREAMWRAPPER_H
#define ABSTRACT_POSITIONS_STREAMWRAPPER_H

#include <iostream>
#include <string>

class StreamWrapper {
public:
    virtual void clearBuffer() = 0;
    virtual void clearStream() = 0;
    virtual void write(const std::string &str) = 0;
    virtual void read(std::string &str) = 0;
    virtual void seekg(int pos, std::ios::seekdir seek) = 0;
    virtual void flush() = 0;
    virtual bool isOpen() = 0;


};



#endif //ABSTRACT_POSITIONS_STREAMWRAPPER_H
