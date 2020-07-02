#include "repository/PositionStreamRepository.h"
#include<iostream>

PositionStreamRepository::PositionStreamRepository(std::unique_ptr<std::iostream> stream,
                                                   std::unique_ptr<PositionSerializer> serializer) {

}

void PositionStreamRepository::save(const Position &position) {

}

std::list<Position> PositionStreamRepository::findByTitle(const std::string &title) {
    return std::list<Position>();
}

std::list<Position> PositionStreamRepository::getAll() {
    return std::list<Position>();
}

void PositionStreamRepository::deletePosition(const Position &position) {

}
