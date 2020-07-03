#include "asserts.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <unordered_set>
#include "repository/PositionStreamRepository.h"
#include "serializer/PositionToPairStringSerializer.h"
#include "repository/util/StringStreamWrapper.h"

namespace std {
    template<>
    struct hash <Position> {
        size_t operator()(const Position &position ) const {
            hash<std::string> sh;
            return sh(position.getTitle())^sh(position.getValue());
        }
    };
}


bool  positionRepositoryStreamTest_SavePosition()  {
    auto stream = std::make_shared<StringStreamWrapper>();
    PositionStreamRepository repository(stream, std::make_unique<PositionToPairStringSerializer>());
    Position pos("test", "value");
    repository.save(pos);
    repository.flush();

    return assertEq<std::string>("test::value", stream->str(), __FUNCTION__);
}


bool  positionRepositoryStreamTest_GetAllPositions()  {
    auto stream = std::make_shared<StringStreamWrapper>();
    stream->write("test::value\r\ntest2::value2\r\ntest3::value3");
    PositionStreamRepository repository(stream, std::make_unique<PositionToPairStringSerializer>());
    std::list<Position> list = repository.getAll();
    std::unordered_set<Position> ok{{"test", "value"}, {"test2", "value2"}, {"test3", "value3"}};
    std::unordered_set<Position> res(list.begin(), list.end());
    return assertEq(ok, res, __FUNCTION__);
}


bool  positionRepositoryStreamTest_FindPositionByTitle()  {
    auto stream = std::make_shared<StringStreamWrapper>();
    stream->write("test::value\r\ntest2::value2\r\ntest3::value3\r\ntest2::value4");
    PositionStreamRepository repository(stream, std::make_unique<PositionToPairStringSerializer>());
    std::list<Position> list = repository.findByTitle("test2");
    std::unordered_set<Position> ok{{"test2", "value2"}, {"test2", "value4"}};
    std::unordered_set<Position> res(list.begin(), list.end());
    return assertEq(ok, res, __FUNCTION__);
}


bool  positionRepositoryStreamTest_DeletePosition()  {
    auto stream = std::make_shared<StringStreamWrapper>();
    stream->write("test::value\r\ntest2::value2\r\ntest3::value3\r\ntest2::value2");
    PositionStreamRepository repository(stream, std::make_unique<PositionToPairStringSerializer>());
    Position pos("test2", "value2");
    repository.deletePosition(pos);
    repository.flush();
    return assertEq<std::string>("test::value\r\ntest3::value3", stream->str(), __FUNCTION__);
}

