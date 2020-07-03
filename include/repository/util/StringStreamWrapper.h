#ifndef ABSTRACT_POSITIONS_FILESTREAMWRAPPER_H
#define ABSTRACT_POSITIONS_FILESTREAMWRAPPER_H

#include "repository/util/StreamWrapper.h"
#include <sstream>


class StringStreamWrapper : public StreamWrapper  {
public:
    void clearBuffer() override;
    void clearStream() override;
    void write(const std::string &str) override;
    void read(std::string &str) override;
    void seekg(int pos, std::ios::seekdir seek) override;
    void flush() override;
    bool isOpen() override;
    std::string str();



private:
    std::stringstream stream;
};
#endif //ABSTRACT_POSITIONS_FILESTREAMWRAPPER_H
