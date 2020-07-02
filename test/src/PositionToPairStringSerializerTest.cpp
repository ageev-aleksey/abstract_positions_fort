#include "serializer/ParseErrorException.h"
#include "serializer/PositionToPairStringSerializer.h"
#include "asserts.h"

bool  positionToPairStringSerializer_Serialize()  {
    Position pos("test1", "value1");
    PositionToPairStringSerializer serializer;
    std::string res = serializer.serialize(pos);
    return assertEq<std::string>("test1:value1", res, __FUNCTION__);
}

bool  positionToPairStringSerializer_Deserialize()  {
    std::string str = "test1:value1";
    PositionToPairStringSerializer serializer;
    Position res = serializer.deserialize(str);
    return assertEq<Position>(Position("test1", "value1"), res, __FUNCTION__);
}

bool  positionToPairStringSerializer_DeserializeInvalidFormat()  {
    std::string str = "test1:value1:";
    PositionToPairStringSerializer serializer;
    try {
        Position res = serializer.deserialize(str);
    } catch (ParseErrorException &exp) {
        std::cout << "Test OK: " << __FUNCTION__ << std::endl;
        return true;
    }
    std::cout << "Test  ERROR: " << __FUNCTION__ <<  "\n"
              << "-- exception was not thrown" << std::endl;
    return false;
}
