#include "repository/util/FileStreamWrapper.h"
#include "repository/PositionStreamRepository.h"
#include "serializer/PositionToPairStringSerializer.h"
#include <string>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>
#include <regex>

constexpr int ERROR = -1;

std::vector<std::string> stringSplit(const std::string &str);
std::shared_ptr<StreamWrapper> streamInit(int argc, char *argv[]);
std::shared_ptr<PositionStreamRepository> repositoryStreamInit(const std::shared_ptr<StreamWrapper> &streamWrapper);
class App {
public:
    explicit App(std::shared_ptr<PositionRepository> repository);
    void run();
private:
    void findByTitle(std::vector<std::string> &command);
    void add(std::vector<std::string> &command);
    void remove(std::vector<std::string> &command);
    void all(std::vector<std::string> &command);

    std::shared_ptr<PositionRepository> rep;
};


int main(int argc, char *argv[]) {
    std::shared_ptr<StreamWrapper> stream = streamInit(argc, argv);
    if(!stream) {
        std::cout << "Invalid stream" << std::endl;
        return ERROR;
    }
    std::shared_ptr<PositionStreamRepository> rep = repositoryStreamInit(stream);
    App app(rep);
    app.run();
    rep->flush();
    return 0;
}




std::shared_ptr<StreamWrapper> streamInit(int argc, char *argv[]) {
    std::string filename("positions.txt");
    if(argc == 1) {
        std::cout << "using default file: " << filename << std::endl;
    } else {
        filename = argv[1];
        std::cout << "using file: " << filename << std::endl;
    }
    auto file = std::make_shared<FileStreamWrapper>(filename);
    if(!file->isOpen()) {
        std::cout << "error opening file" << std::endl;
        return std::shared_ptr<StreamWrapper>();
    }
    return file;
}

std::shared_ptr<PositionStreamRepository> repositoryStreamInit(const std::shared_ptr<StreamWrapper> &streamWrapper) {
    return std::make_shared<PositionStreamRepository>(streamWrapper,
            std::make_unique<PositionToPairStringSerializer>());
}


using menuHandler = void(*)(std::string&);


App::App(std::shared_ptr<PositionRepository> repository) {
    rep = repository;
}
void App::run()  {
    std::string command;
    std::cout << "> ";
    std::unordered_map<std::string, std::function<void(std::vector<std::string>&)>> h {
            {"find", std::bind(&App::findByTitle, this, std::placeholders::_1)},
            {"add", std::bind(&App::add, this, std::placeholders::_1)},
            {"remove", std::bind(&App::remove, this, std::placeholders::_1)},
            {"all", std::bind(&App::all, this, std::placeholders::_1)},
    };
    while(std::getline(std::cin, command, '\n')) {
        if(command == "exit") {
            return;
        }
        auto c = stringSplit(command);
        auto itr = h.find(c[0]);
        if(itr == h.end()) {
            std::cout << "command not found. Please repeat\n> " << std::endl;
            continue;
        }
        itr->second(c);
        std::cout << "> ";
    }
}

void App::all(std::vector<std::string> &command) {
    auto l = rep->getAll();
    for(const auto &el : l) {
        std::cout << el << "\n";
    }
    std::cout << std::flush;
}

void App::add(std::vector<std::string> &command) {
    if(command.size() != 3) {
        std::cout << "invalid arguments of command" << std::endl;
        return;
    }
    Position pos(command[1], command[2]);
    rep->save(pos);
}

void App::findByTitle(std::vector<std::string> &command) {
    if(command.size() != 2) {
        std::cout << "invalid arguments of command" << std::endl;
        return;
    }
    std::list<Position> r = rep->findByTitle(command[1]);
    for(const auto &el : r) {
        std::cout << el << "\n";
    }
        std::cout << std::flush;
}

void App::remove(std::vector<std::string> &command) {
    if(command.size() != 2) {
        std::cout << "invalid arguments of command" << std::endl;
        return;
    }
    std::list<Position> l = rep->findByTitle(command[1]);
    int index = 0;
    size_t positionsFoundedCount = l.size();
    if(positionsFoundedCount == 0) {
        std::cout << "not found" << std::endl;
        return;
    }
    std::cout << "-- founded " << positionsFoundedCount << "positions; \n"
              << "-- what positions to remove? Indicate numbers cross a space.\n";
    for(const auto &el : l) {
        std::cout << "-- [" << index << "] " << el << "\n";
        ++index;
    }
    std::cout << "--> "<< std::flush;
    std::string tmp;
    std::getline(std::cin, tmp, '\n');
    auto indexesStr = stringSplit(tmp);
    std::vector<int> indexes;
    try {
        for(const auto &el : indexesStr) {
            indexes.push_back(std::stoi(el));
        }
    } catch (std::invalid_argument &exp) {
        std::cout << "entered not an integer number" << std::endl;
        return;
    } catch(std::out_of_range &exp) {
        std::cout << "error" << std::endl;
        return;
    }
    std::sort(indexes.begin(), indexes.end());
    if(indexes.back() > positionsFoundedCount) {
        std::cout << "out of range" << std::endl;
        return;
    }
    index = 0;
    auto litr = l.begin();
    for(auto itr = indexes.begin(); itr != indexes.end(); ++itr) {
        while(index != *itr) {
            ++litr;
            ++index;
        }
        rep->deletePosition(*litr);
        ++litr;
        ++index;
    }

}


std::vector<std::string> stringSplit(const std::string &str) {
    std::regex re(" ");
    std::sregex_token_iterator begin(str.begin(), str.end(), re, -1), end;
    return {begin, end};
}