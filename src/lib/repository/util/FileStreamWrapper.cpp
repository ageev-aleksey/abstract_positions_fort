#include "repository/util/FileStreamWrapper.h"
#include <fstream>
#include <sstream>


FileStreamWrapper::FileStreamWrapper(const std::string &path) {
    filePath = path;
    stream.open(filePath, std::ios::in | std::ios::out | std::ios::app);
}

void FileStreamWrapper::clearBuffer() {
    stream.close();
    stream.open(filePath, std::ios::in | std::ios::out | std::ios::trunc);
}

void FileStreamWrapper::write(const std::string &str) {
    stream << str;
}

void FileStreamWrapper::clearStream() {
    stream.clear();
}

void FileStreamWrapper::seekg(int pos, std::ios::seekdir seek) {
    stream.seekg(pos, seek);
}

void FileStreamWrapper::read(std::string &str) {
    std::ostringstream oss;
    oss << stream.rdbuf();
    str = oss.str();
}

void FileStreamWrapper::flush() {
    stream.flush();
}


