#include "asserts.h"
#include<iostream>
#include <sstream>
#include <memory>
#include "repository/PositionStreamRepository.h"
#include "serializer/PositionToPairStringSerializer.h"


bool  positionRepositoryStreamTest_SavePosition()  {
    std::unique_ptr<std::iostream> stream = std::make_unique<std::stringstream>();
    std::stringstream *streamPtr = static_cast<std::stringstream*>(stream.get());
    PositionStreamRepository repository(std::move(stream), std::make_unique<PositionToPairStringSerializer>());
    Position pos("test", "value");
    repository.save(pos);
    return assertEq<std::string>("test:value", streamPtr->str(), __FUNCTION__);
}


bool  positionRepositoryStreamTest_GetAllPositions()  {
    std::unique_ptr<std::iostream> stream = std::make_unique<std::stringstream>();
    *stream << "test:value\ntest2:value2\ntest3:value3";
    std::stringstream *streamPtr = static_cast<std::stringstream*>(stream.get());
    PositionStreamRepository repository(std::move(stream), std::make_unique<PositionToPairStringSerializer>());
    std::list<Position> list = repository.getAll();
    auto ptr = list.begin();
    return assertEq<size_t>(3, list.size(), __FUNCTION__) &&
            assertEq(Position("test", "value"), *(ptr++), __FUNCTION__) &&
            assertEq(Position("test2", "value2"), *(ptr++), __FUNCTION__) &&
            assertEq(Position("test3", "value3"), *(ptr++), __FUNCTION__);
}


bool  positionRepositoryStreamTest_FindPositionByTitle()  {
    std::unique_ptr<std::iostream> stream = std::make_unique<std::stringstream>();
    *stream << "test:value\ntest2:value2\ntest3:value3\ntest2:value4";
    std::stringstream *streamPtr = static_cast<std::stringstream*>(stream.get());
    PositionStreamRepository repository(std::move(stream), std::make_unique<PositionToPairStringSerializer>());
    std::list<Position> list = repository.findByTitle("test2");
    auto ptr = list.begin();
    return assertEq<size_t>(2, list.size(), __FUNCTION__) &&
            assertEq(Position("test2", "value2"), *(ptr++), __FUNCTION__) &&
            assertEq(Position("test2", "value4"), *(ptr++), __FUNCTION__);
}


bool  positionRepositoryStreamTest_DeletePosition()  {
    std::unique_ptr<std::iostream> stream = std::make_unique<std::stringstream>();
    *stream << "test:value\ntest2:value2\ntest3:value3\ntest2:value2";
    std::stringstream *streamPtr = static_cast<std::stringstream*>(stream.get());
    PositionStreamRepository repository(std::move(stream), std::make_unique<PositionToPairStringSerializer>());
    Position pos("test2", "value2");
    repository.deletePosition(pos);
    return assertEq<std::string>("test:value\ntest3:value3", streamPtr->str(), __FUNCTION__);
}

