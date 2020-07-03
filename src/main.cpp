
#include "serializer/PositionToPairStringSerializer.h"
#include "repository/PositionStreamRepository.h"
#include <iostream>
#include <memory>
#include<sstream>
#include <fstream>

int main() {
    std::shared_ptr<std::fstream> file = std::make_shared<std::fstream>("test1.txt", std::ios::in | std::ios::out | std::ios::app);
    if(!file->is_open() ) {
        std::cout << "файл не удалось открыть!" << std::endl;
        return 0;
    }
    PositionStreamRepository rep(file, std::make_unique<PositionToPairStringSerializer>());
    Position pos("0000000", "00000000");
    Position pos2("0111110000", "11111111111111111111111");
    rep.save(pos);
    rep.save(pos2);
    rep.flush();
    file->close();
}