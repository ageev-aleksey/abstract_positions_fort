#ifndef ABSTRACT_POSITIONS_POSTIONTOPAIRSTRING_H
#define ABSTRACT_POSITIONS_POSTIONTOPAIRSTRING_H

#include "PositionSerializer.h"

class PositionToPairStringSerializer : public PositionSerializer {
public:
    std::string serialize(const Position &position) const override;
    Position deserialize(const std::string &strPosition) const override;
};


#endif //ABSTRACT_POSITIONS_POSTIONTOPAIRSTRING_H
