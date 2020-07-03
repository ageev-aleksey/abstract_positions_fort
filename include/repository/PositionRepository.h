//
// Created by nrx on 02.07.2020.
//

#ifndef ABSTRACT_POSITIONS_POSITIONREPOSITORY_H
#define ABSTRACT_POSITIONS_POSITIONREPOSITORY_H

#include "entity/Position.h"
#include <list>

class PositionRepository {
public:
    virtual void save(const Position &position) = 0;
    virtual std::list<Position> findByTitle(const std::string &title) = 0;
    virtual std::list<Position> getAll() = 0;
    virtual void deletePosition(const Position &position) = 0;
    virtual ~PositionRepository() = default;
};

#endif //ABSTRACT_POSITIONS_POSITIONREPOSITORY_H
