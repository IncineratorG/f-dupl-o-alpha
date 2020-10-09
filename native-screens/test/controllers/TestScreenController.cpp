#include "TestScreenController.h"
#include "stores/AppStore.h"
#include "stores/actions/test/TestActions.h"
#include "common/libs/redux/selector/Selector.h"

#include <QDebug>
#include <QString>

TestScreenController::TestScreenController()
    : prop1(new StateProp<int>()),
      prop2(new StateProp<int>()),
      prop3(new StateProp<int>())
{
    auto propsList = getProps();
    for (int i = 0; i < propsList.length(); ++i) {
        auto prop = propsList.at(i);
        prop->setPropId(i);
    }

    auto testState = AppStore::get()->testState;

    testState->select(Selector({testState->prop1->propId()}, [testState] () {
        qDebug() << __PRETTY_FUNCTION__ << testState->prop1->get();
    }));
}

void TestScreenController::test() {
    qDebug() << __PRETTY_FUNCTION__;

    AppStore::get()->dispatch(TestActions::firstTestAction());

//    auto appStore = AppStore::get();

//    Selector selector({1, 2, 3}, [] () {});
//    selector.propIds();

//    QMap<int, QList<Selector>> map;

//    QList<Selector> list = map.value(1, {});
//    list.append(selector);
//    map.insert(1, list);


//    QList<Selector> list1 = map.value(1, {});
//    list1.append(selector);
//    map.insert(1, list1);

//    QList<Selector> list2 = map.value(1, {});

//    qDebug() << __PRETTY_FUNCTION__ << list2.length();
}

QList<std::shared_ptr<StatePropLike>> TestScreenController::getProps() {
    return QList<std::shared_ptr<StatePropLike>>({
                                                     prop1,
                                                     prop2,
                                                     prop3
                                                 });
}
