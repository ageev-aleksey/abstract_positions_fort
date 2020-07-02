#ifndef ABSTRACT_POSITIONS_PARSEERROREXCEPTION_H
#define ABSTRACT_POSITIONS_PARSEERROREXCEPTION_H

#include <stdexcept>

class ParseErrorException : public std::runtime_error {
public:
    explicit ParseErrorException(const std::string &what);
};




#endif //ABSTRACT_POSITIONS_PARSEERROREXCEPTION_H
