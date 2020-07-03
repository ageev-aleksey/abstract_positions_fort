#include "repository/PositionStreamRepository.h"
#include<iostream>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>

PositionStreamRepository::PositionStreamRepository(std::shared_ptr<StreamWrapper> stream,
                                                   std::unique_ptr<PositionSerializer> serializer)
 : stream(std::move(stream)), serializer(std::move(serializer)) {
    init();
}

PositionStreamRepository::~PositionStreamRepository() {
    //TODO исключение в деструкторе!!
    try {
        flush();
    } catch(std::runtime_error exp) {
        std::clog << "PositionStreamRepository: Invalid flushing file in destructor";
    }
}

void PositionStreamRepository::save(const Position &position) {
    isUpdate = true;
    buffer.insert(position);
}

std::list<Position> PositionStreamRepository::findByTitle(const std::string &title) {
    auto itr = buffer.find(Position(title, ""));
    std::list<Position> res;
    if(itr == buffer.end()) {
        return res;
    }
    std::copy_if(itr, buffer.end(), std::back_inserter(res),
            [&](const Position& pos) {return pos.getTitle() == title;});
    return res;
}

std::list<Position> PositionStreamRepository::getAll() {
    return std::list<Position>{buffer.begin(), buffer.end()};
}

void PositionStreamRepository::deletePosition(const Position &position) {
    isUpdate = true;
    auto itr = buffer.find(position);
    while(itr != buffer.end()) {
        if(*itr == position) {
            auto tmp = itr;
            ++tmp;
            buffer.erase(itr);
            itr = tmp;
            continue;
        }
        ++itr;
    }
}

//size_t PositionHash::operator()(const Position &pos) const

//bool PositionEqual::operator()(const Position &first, const Position &second) const {
//    return first.getTitle() == second.getTitle();
//}
size_t PositionStreamRepository::PositionHash::operator()(const Position &pos) const {
    std::hash<std::string> strHash;
    return strHash(pos.getTitle());
}

void PositionStreamRepository::flush() {
    if(isUpdate) {
        stream->clearStream();
        stream->clearBuffer();
        stream->seekg(0, std::ios::beg);
        std::list<Position> posList(buffer.begin(), buffer.end());
        std::string s = serializer->serialize(posList);
        stream->write(s);
        stream->flush();
        isUpdate = false;
    }
}


void PositionStreamRepository::init() {
    if(!stream) {
        throw std::runtime_error("Invalid stream pointer");
    }
    if(!serializer) {
        throw std::runtime_error("Invalid serializer pointer");
    }
    stream->clearStream();
    stream->seekg(0, std::ios::beg);
    std::string tmp;
    stream->read(tmp);
    std::list<Position> listPos = serializer->deserialize(tmp);
    for(auto &el : listPos) {
        buffer.insert(std::move(el));
    }
    isUpdate = false;
}

bool PositionStreamRepository::PositionEquals::operator()(const Position &first, const Position &second) const {
    return first.getTitle() == second.getTitle();
}
