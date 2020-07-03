//
// Created by nrx on 02.07.2020.
//

#ifndef ABSTRACT_POSITIONS_POSITION_H
#define ABSTRACT_POSITIONS_POSITION_H

#include <string>

/**
 * \brief Сущность описывающая хранимые записи
 *
 */
class Position {
public:
    Position();
    /**
     *\brief конструктор сущности "Запись"
     * @param title - ключ записи
     * @param position - значение записи
     */
    Position(const std::string &title, const std::string &value);
    /**
     *\brief getter ключа записи
     * @return возвращает ключ записи (title)
     */
    const std::string& getTitle() const;
    /**
     *\brief getter значение записи
     * @return возвращает значение записи (value)
     */
    const std::string& getValue() const;
    /**
     * \brief setter ключа записи
     * @param title - ключ записи
     */
    void setTitle(const std::string &title);
    /**
     * \brief setter значение записи
     * @param value - значение записи
     */
    void setValue(const std::string &value);

    bool operator==(const Position &other) const;
    bool operator!=(const Position &other) const;
    /**
     * \brief оператор вывода в формате Position(title=<ключ>; value=<значение>)
     */
    friend std::ostream& operator<<(std::ostream &stream, const Position &position);
private:
    std::string title;
    std::string value;
};

std::ostream& operator<<(std::ostream &stream, const Position &position);
#endif //ABSTRACT_POSITIONS_POSITION_H
