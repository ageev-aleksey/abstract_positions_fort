#ifndef ABSTRACT_POSITIONS_POSITIONSTREAMREPOSITORY_H
#define ABSTRACT_POSITIONS_POSITIONSTREAMREPOSITORY_H

#include <memory>

#include "repository/PositionRepository.h"
#include "serializer/PositionSerializer.h"
#include "repository/util/StreamWrapper.h"
#include <unordered_set>

class PositionStreamRepository : public PositionRepository {
public:
    PositionStreamRepository(std::shared_ptr<StreamWrapper> stream, std::unique_ptr<PositionSerializer> formatter);
    ~PositionStreamRepository();
    void save(const Position &position) override;
    std::list<Position> findByTitle(const std::string &title) override;
    std::list<Position> getAll() override;
    void deletePosition(const Position &position) override;

    void flush();
private:
    void init();
    struct PositionHash  {
        size_t operator()(const Position &pos) const;
    };
    struct PositionEquals {
        bool operator()(const Position &first, const Position &second) const;
    };

    std::unordered_multiset<Position, PositionHash, PositionEquals> buffer;
    std::shared_ptr<StreamWrapper> stream;
    std::unique_ptr<PositionSerializer> serializer;
    bool isUpdate;
};




//struct PositionEqual : public std::equal_to<Position> {
//    bool operator()(const Position& x, const Position &y) const;
//};

#endif //ABSTRACT_POSITIONS_POSITIONSTREAMREPOSITORY_H
