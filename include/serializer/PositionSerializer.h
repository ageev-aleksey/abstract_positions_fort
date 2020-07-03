#ifndef ABSTRACT_POSITIONS_POSITIONSERIALIZER_H
#define ABSTRACT_POSITIONS_POSITIONSERIALIZER_H

#include "entity/Position.h"
#include <list>

/**
 * интерфейс определяющий структуру класса, который релизует механизм
 * сериализации и десериализации сущности \see Position
 */
class PositionSerializer {
public:
    /**
     * \brief сериализаця списка сущностей
     * @param pos - список сущностей
     * @return строка с сериализованными данными
     */
    virtual std::string serialize(const std::list<Position> &pos) const = 0;
    /**
     * \brief десериализация сущностей из строки
     * @param strPosition - строка сущностями
     * @return списко сущностей
     */
    virtual std::list<Position> deserialize(const std::string &strPosition) const = 0;
};
#endif //ABSTRACT_POSITIONS_POSITIONSERIALIZER_H
