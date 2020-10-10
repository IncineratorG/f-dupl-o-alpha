#include "SystemState.h"

SystemState::SystemState() {
    qmlFilePrefix = std::make_shared<StateProp<QString>>("file:///");

    initState();
}

QList<std::shared_ptr<StatePropLike>> SystemState::stateProps() const {
    QList<std::shared_ptr<StatePropLike>> props({
                                                    qmlFilePrefix
                                                });

    return props;
}
