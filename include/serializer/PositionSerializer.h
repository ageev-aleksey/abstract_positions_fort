#ifndef ABSTRACT_POSITIONS_POSITIONSERIALIZER_H
#define ABSTRACT_POSITIONS_POSITIONSERIALIZER_H

#include "entity/Position.h"
#include <list>


class PositionSerializer {
public:
    virtual std::string serialize(const std::list<Position> &pos) const = 0;
    virtual std::list<Position> deserialize(const std::string &strPosition) const = 0;
};
#endif //ABSTRACT_POSITIONS_POSITIONSERIALIZER_H
