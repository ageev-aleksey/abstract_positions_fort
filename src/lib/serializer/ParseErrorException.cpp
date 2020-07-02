#include "serializer/ParseErrorException.h"

ParseErrorException::ParseErrorException(const std::string &what) : std::runtime_error(what){}