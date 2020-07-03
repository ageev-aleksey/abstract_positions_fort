#include "serializer/ParseErrorException.h"
#include "serializer/PositionToPairStringSerializer.h"
#include "asserts.h"

bool  positionToPairStringSerializer_Serialize()  {
    Position pos("test1", "value1");
    PositionToPairStringSerializer serializer;
    std::string res = serializer.serialize(std::list{pos});
    return assertEq<std::string>("test1::value1", res, __FUNCTION__);
}

bool  positionToPairStringSerializer_Serialize2()  {
    std::list<Position> posl{{"test1", "value1"}, {"test2", "value2"}};
    PositionToPairStringSerializer serializer;
    std::string res = serializer.serialize(posl);
    return assertEq<std::string>("test1::value1\r\ntest2::value2", res, __FUNCTION__);
}

bool  positionToPairStringSerializer_Deserialize()  {
    std::string str = "test1::value1";
    PositionToPairStringSerializer serializer;
    std::list<Position> res = serializer.deserialize(str);
    return  assertEq<size_t>(1, res.size(), __FUNCTION__) &&
            assertEq<Position>(Position("test1", "value1"), *res.begin(), __FUNCTION__);
}

bool  positionToPairStringSerializer_Deserialize2()  {
    std::string str = "test1::value1\r\ntest2::value2";
    PositionToPairStringSerializer serializer;
    std::list<Position> res = serializer.deserialize(str);
    return  assertEq<size_t>(2, res.size(), __FUNCTION__) &&
            assertEq<Position>(Position("test1", "value1"), *res.begin(), __FUNCTION__) &&
            assertEq<Position>(Position("test2", "value2"), *(++res.begin()), __FUNCTION__);
}

bool  positionToPairStringSerializer_DeserializeInvalidFormat()  {
    std::string str = "test1::value1:";
    PositionToPairStringSerializer serializer;
    try {
        std::list<Position> res = serializer.deserialize(str);
    } catch (ParseErrorException &exp) {
        std::cout << "Test OK: " << __FUNCTION__ << std::endl;
        return true;
    }
    std::cout << "Test  ERROR: " << __FUNCTION__ <<  "\n"
              << "-- exception was not thrown" << std::endl;
    return false;
}
