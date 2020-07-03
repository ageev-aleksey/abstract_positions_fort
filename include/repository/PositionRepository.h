//
// Created by nrx on 02.07.2020.
//

#ifndef ABSTRACT_POSITIONS_POSITIONREPOSITORY_H
#define ABSTRACT_POSITIONS_POSITIONREPOSITORY_H

#include "entity/Position.h"
#include <list>

/**
 * \brief класс выполняющий работу с некоторым хранилищем, в котором расположены
 * сущности \see Position
 */
class PositionRepository {
public:
    /**
     * \brief сохранение сущности
     * @param position - сущность \see Position
     */
    virtual void save(const Position &position) = 0;
    /**
     * \brief поиск сущности по ключу
     * @param title - ключ сущности
     * @return
     */
    virtual std::list<Position> findByTitle(const std::string &title) = 0;
    /**
     * \brief метод для получения всех сущностей из хранилища
     * @return список всех сущностей
     */
    virtual std::list<Position> getAll() = 0;
    /**
     * \brief удаление сущности
     * @param position - экземпляр сущности, которую нужно удалить
     */
    virtual void deletePosition(const Position &position) = 0;
    virtual ~PositionRepository() = default;
};

#endif //ABSTRACT_POSITIONS_POSITIONREPOSITORY_H
