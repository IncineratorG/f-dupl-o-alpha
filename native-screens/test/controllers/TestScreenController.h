#ifndef TESTSCREENCONTROLLER_H
#define TESTSCREENCONTROLLER_H

#include "common/libs/redux/prop/StatePropLike.h"
#include "common/libs/redux/prop/StateProp.h"

#include <QObject>
#include <QList>

#include <memory>

class TestScreenController : public QObject
{
    Q_OBJECT

public:
    std::shared_ptr<StateProp<int>> prop1;
    std::shared_ptr<StateProp<int>> prop2;
    std::shared_ptr<StateProp<int>> prop3;

    TestScreenController();

    Q_INVOKABLE void test();

private:
    QList<std::shared_ptr<StatePropLike>> getProps();
};

#endif // TESTSCREENCONTROLLER_H
