#include "asserts.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include "repository/PositionStreamRepository.h"
#include "serializer/PositionToPairStringSerializer.h"


bool  positionRepositoryStreamTest_SavePosition()  {
    std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>();
    PositionStreamRepository repository(stream, std::make_unique<PositionToPairStringSerializer>());
    Position pos("test", "value");
    repository.save(pos);
    repository.flush();

    return assertEq<std::string>("test::value", stream->str(), __FUNCTION__);
    return true;
}


bool  positionRepositoryStreamTest_GetAllPositions()  {
    std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>();
    *stream << "test::value\r\ntest2::value2\r\ntest3::value3";
    PositionStreamRepository repository(stream, std::make_unique<PositionToPairStringSerializer>());
    std::list<Position> list = repository.getAll();

    //return assertEq<>()
    return true;
}


bool  positionRepositoryStreamTest_FindPositionByTitle()  {
    std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>();
    *stream << "test::value\r\ntest2::value2\r\ntest3::value3\r\ntest2::value4";
    PositionStreamRepository repository(stream, std::make_unique<PositionToPairStringSerializer>());
    std::list<Position> list = repository.findByTitle("test2");
    auto ptr = list.begin();
    return assertEq<size_t>(2, list.size(), __FUNCTION__) &&
            assertEq(Position("test2", "value2"), *(ptr++), __FUNCTION__) &&
            assertEq(Position("test2", "value4"), *(ptr++), __FUNCTION__);
}


bool  positionRepositoryStreamTest_DeletePosition()  {
    std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>();
    *stream << "test::value\r\ntest2::value2\r\ntest3::value3\r\ntest2::value2";
    PositionStreamRepository repository(stream, std::make_unique<PositionToPairStringSerializer>());
    Position pos("test2", "value2");
    repository.deletePosition(pos);
    repository.flush();
    return assertEq<std::string>("test::value\r\ntest3::value3", stream->str(), __FUNCTION__);
}

