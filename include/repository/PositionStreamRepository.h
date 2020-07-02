//
// Created by nrx on 02.07.2020.
//

#ifndef ABSTRACT_POSITIONS_POSITIONSTREAMREPOSITORY_H
#define ABSTRACT_POSITIONS_POSITIONSTREAMREPOSITORY_H

#include <memory>
#include "repository/PositionRepository.h"

class PositionStreamRepository : public PositionRepository {
public:
    explicit PositionStreamRepository(std::unique_ptr<std::iostream> stream);
    void save(const Position &position) override;
    std::list<Position> findByTitle(const std::string &title) override;
    std::list<Position> getAll() override;
    void deletePosition(const Position &position) override;
private:
    std::unique_ptr<std::iostream> stream;


};


#endif //ABSTRACT_POSITIONS_POSITIONSTREAMREPOSITORY_H
