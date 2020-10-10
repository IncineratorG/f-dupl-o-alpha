#include "DuplicatesFinderReducer.h"
#include "stores/states/duplicates-finder/DuplicatesFinderState.h"
#include "stores/action-types/duplicates-finder/DuplicatesFinderActionTypes.h"

#include <QDebug>

DuplicatesFinderReducer::DuplicatesFinderReducer() {

}

void DuplicatesFinderReducer::reduce(std::shared_ptr<State> state,
                                     std::shared_ptr<Action> action) {
    if (action->storeMark() != DuplicatesFinderActionTypes::STORE_MARK) {
        return;
    }

    auto currentState = std::dynamic_pointer_cast<DuplicatesFinderState>(state);

    switch (action->type()) {
        case (DuplicatesFinderActionTypes::FIND_DUPLICATES_BEGIN): {
            qDebug() << __PRETTY_FUNCTION__ << "->FIND_DUPLICATES_BEGIN";
            break;
        }

        case (DuplicatesFinderActionTypes::FIND_DUPLICATES_FINISHED): {
            qDebug() << __PRETTY_FUNCTION__ << "->FIND_DUPLICATES_FINISHED";
            break;
        }

        case (DuplicatesFinderActionTypes::FIND_DUPLICATES_ERROR): {
            qDebug() << __PRETTY_FUNCTION__ << "->FIND_DUPLICATES_ERROR";
            break;
        }

        default: {

        }
    }
}
