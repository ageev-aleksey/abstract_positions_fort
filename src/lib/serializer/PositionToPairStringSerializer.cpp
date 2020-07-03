#include "serializer/ParseErrorException.h"
#include "serializer/PositionToPairStringSerializer.h"
#include <regex>
#include <stdexcept>


std::string PositionToPairStringSerializer::serialize(const std::list<Position> &position) const {
    std::string res;
    for(auto itr = position.begin(); itr != (--position.end()); ++itr) {
        res.append(itr->getTitle() + "::" + itr->getValue() + "\r\n");
    }
    if(!position.empty()) {
        auto itr = --position.end();
        res.append(itr->getTitle() + "::" + itr->getValue());
    }
    return res;
}

std::list<Position> PositionToPairStringSerializer::deserialize(const std::string &strPosition) const {
    if(strPosition.empty()) {
        return std::list<Position>();
    }
    std::regex regexSplitElements("\r\n");
    std::sregex_token_iterator elementsPtr(strPosition.begin(), strPosition.end(), regexSplitElements, -1), end;
    std::list<Position> res;
    for(; elementsPtr != end; ++elementsPtr) {
        if(elementsPtr->str().empty()) {
            //TODO реакция на пустую запись
        }
        if(*elementsPtr->str().begin() == ':' ||  *(--elementsPtr->str().end()) == ':') {
            throw ParseErrorException("invalid format");
        }

        Position tmp;
        std::regex re("::");
        const std::string &str = elementsPtr->str();
        std::sregex_token_iterator ptr(str.begin(), str.end(), re, -1), last;
        if(std::distance(ptr, last) != 2) {
            throw ParseErrorException("invalid format");
        }
        tmp.setTitle(*ptr);
        ++ptr;
        tmp.setValue(*ptr);
        res.push_back(tmp);
    }

    return res;
}
