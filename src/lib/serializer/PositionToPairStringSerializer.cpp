#include "serializer/ParseErrorException.h"
#include "serializer/PositionToPairStringSerializer.h"
#include <regex>
#include <stdexcept>


std::string PositionToPairStringSerializer::serialize(const Position &position) const {
    return position.getTitle() + ":" + position.getValue();
}

Position PositionToPairStringSerializer::deserialize(const std::string &strPosition) const {
    if(!strPosition.empty() && (*strPosition.begin() == ':' ||  *(strPosition.end()-1) == ':')) {
        throw ParseErrorException("invalid format");
    }

    Position res;
    std::string tmp;
    std::regex re(":");
    std::sregex_token_iterator ptr(strPosition.begin(), strPosition.end(), re, -1), last;
    if(std::distance(ptr, last) != 2) {
        throw ParseErrorException("invalid format");
    }
    res.setTitle(*ptr);
    ++ptr;
    res.setValue(*ptr);
    return res;
}
