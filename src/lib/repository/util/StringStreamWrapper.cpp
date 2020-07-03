#include "repository/util/StringStreamWrapper.h"


void StringStreamWrapper::clearBuffer() {
    stream.str(std::string());
}



void StringStreamWrapper::write(const std::string &str) {
    stream << str;
}

void StringStreamWrapper::clearStream() {
    stream.clear();
}

void StringStreamWrapper::seekg(int pos, std::ios::seekdir seek) {
    stream.seekg(pos, seek);
}

void StringStreamWrapper::read(std::string &str) {
    str = stream.str();
}

void StringStreamWrapper::flush() {
    stream.flush();
}

std::string StringStreamWrapper::str() {
    return stream.str();
}

bool StringStreamWrapper::isOpen() {
    return stream.good();
}
