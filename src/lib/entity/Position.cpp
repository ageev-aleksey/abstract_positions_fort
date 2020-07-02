#include "entity/Position.h"
#include <iostream>

Position::Position() {

}


Position::Position(const std::string &title, const std::string &value): title(title), value(value)  {

}

const std::string &Position::getTitle() const {
    return title;
}

const std::string &Position::getValue() const {
    return value;
}

void Position::setTitle(const std::string &title) {
    this->title = title;
}

void Position::setValue(const std::string &value) {
    this->value = value;
}

bool Position::operator==(const Position &other) const {
    return (title == other.title) && (value == other.value);
}

bool Position::operator!=(const Position &other) const {
    return !(*this == other);
}



std::ostream& operator<<(std::ostream &stream, const Position &position) {
    stream << "Position(title=" << position.title << "; value=" << position.value << ")";
    return stream;
}