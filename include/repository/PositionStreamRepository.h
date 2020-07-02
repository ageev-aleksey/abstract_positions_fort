//
// Created by nrx on 02.07.2020.
//

#ifndef ABSTRACT_POSITIONS_POSITIONSTREAMREPOSITORY_H
#define ABSTRACT_POSITIONS_POSITIONSTREAMREPOSITORY_H

#include <memory>
#include "repository/PositionRepository.h"
#include "serializer/PositionSerializer.h"

class PositionStreamRepository : public PositionRepository {
public:
    PositionStreamRepository(std::unique_ptr<std::iostream> stream, std::unique_ptr<PositionSerializer> formatter);
    void save(const Position &position) override;
    std::list<Position> findByTitle(const std::string &title) override;
    std::list<Position> getAll() override;
    void deletePosition(const Position &position) override;
private:
    std::unique_ptr<std::iostream> stream;
    std::unique_ptr<PositionSerializer> serializer;
};


#endif //ABSTRACT_POSITIONS_POSITIONSTREAMREPOSITORY_H
