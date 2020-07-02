#include <iostream>

bool positionRepositoryStreamTest_SavePosition();
bool positionRepositoryStreamTest_GetAllPositions();
bool positionRepositoryStreamTest_FindPositionByTitle();
bool positionRepositoryStreamTest_DeletePosition();


int testRun() {
    bool good = true;
    good &= positionRepositoryStreamTest_SavePosition();
    good &= positionRepositoryStreamTest_GetAllPositions();
    good &= positionRepositoryStreamTest_FindPositionByTitle();
    good &= positionRepositoryStreamTest_DeletePosition();


    if(!good) {
        std::cout << "Testing fail!" << std::endl;
        return -1;
    }
    return 0;
}


int main() {
    return testRun();
}
