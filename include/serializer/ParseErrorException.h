#ifndef ABSTRACT_POSITIONS_PARSEERROREXCEPTION_H
#define ABSTRACT_POSITIONS_PARSEERROREXCEPTION_H

#include <stdexcept>

/**
 * \brief класс описывающий ошибку при сериализации сущности \see Position
 */
class ParseErrorException : public std::runtime_error {
public:
    explicit ParseErrorException(const std::string &what);
};




#endif //ABSTRACT_POSITIONS_PARSEERROREXCEPTION_H
