#include "DuplicatesFinderReducer.h"
#include "stores/states/duplicates-finder/DuplicatesFinderState.h"
#include "stores/action-types/duplicates-finder/DuplicatesFinderActionTypes.h"
#include "services/duplicates-finder/data/duplicates-list/DuplicatesList.h"

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

            currentState->update([currentState] () {
                currentState->serviceRunning->set(true);
                currentState->hasError->set(false);
                currentState->error->set(Error());
            });

            break;
        }

        case (DuplicatesFinderActionTypes::FIND_DUPLICATES_FINISHED): {
            qDebug() << __PRETTY_FUNCTION__ << "->FIND_DUPLICATES_FINISHED";

            DuplicatesList duplicates;
            try {
                duplicates = std::any_cast<DuplicatesList>(action->payload().getDefault());
            } catch (const std::bad_any_cast&) {
                qDebug() << __PRETTY_FUNCTION__ << "->FIND_DUPLICATES_FINISHED->BAD_ANY_CAST";
            }

            currentState->update([currentState, duplicates] () {
                currentState->serviceRunning->set(false);
                currentState->duplicates->set(duplicates);
            });

            break;
        }

        case (DuplicatesFinderActionTypes::FIND_DUPLICATES_ERROR): {
            Error error;
            try {
                error = std::any_cast<Error>(action->payload().getDefault());
            } catch (const std::bad_any_cast&) {
                qDebug() << __PRETTY_FUNCTION__ << "->FIND_DUPLICATES_ERROR->BAD_ANY_CAST";
                error = Error(-1, "FIND_DUPLICATES_ERROR->BAD_ANY_CAST");
            }

            currentState->update([currentState, error] () {
                currentState->serviceRunning->set(false);
                currentState->hasError->set(true);
                currentState->error->set(error);
            });

            break;
        }

        default: {

        }
    }
}
