//
// Created by nrx on 02.07.2020.
//

#ifndef ABSTRACT_POSITIONS_POSITION_H
#define ABSTRACT_POSITIONS_POSITION_H

#include <string>

class Position {
public:
    Position();
    Position(const std::string &title, const std::string &position);
    const std::string& getTitle() const;
    const std::string& getValue() const;
    void setTitle(const std::string &title);
    void setValue(const std::string &value);
private:
    std::string title;
    std::string value;

};


#endif //ABSTRACT_POSITIONS_POSITION_H
