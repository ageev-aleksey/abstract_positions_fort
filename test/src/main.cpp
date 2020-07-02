#include <iostream>

bool positionRepositoryStreamTest_SavePosition();
bool positionRepositoryStreamTest_GetAllPositions();
bool positionRepositoryStreamTest_FindPositionByTitle();
bool positionRepositoryStreamTest_DeletePosition();
bool positionToPairStringSerializer_Serialize();
bool positionToPairStringSerializer_Deserialize();


int testRun() {
    bool good = true;
    good &= positionRepositoryStreamTest_SavePosition();
    good &= positionRepositoryStreamTest_GetAllPositions();
    good &= positionRepositoryStreamTest_FindPositionByTitle();
    good &= positionRepositoryStreamTest_DeletePosition();
    good &= positionToPairStringSerializer_Serialize();
    good &= positionToPairStringSerializer_Deserialize();

    if(!good) {
        std::cout << "Testing fail!" << std::endl;
        return -1;
    }
    return 0;
}


int main() {
    return testRun();
}
