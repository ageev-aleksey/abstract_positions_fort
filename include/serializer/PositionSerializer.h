#ifndef ABSTRACT_POSITIONS_POSITIONSERIALIZER_H
#define ABSTRACT_POSITIONS_POSITIONSERIALIZER_H

#include "entity/Position.h"

class PositionSerializer {
public:
    virtual std::string serialize(const Position &position) const = 0;
    virtual Position deserialize(const std::string &strPosition) const = 0;
};
#endif //ABSTRACT_POSITIONS_POSITIONSERIALIZER_H
