#include "DuplicatesFinderReducer.h"
#include "stores/states/duplicates-finder/DuplicatesFinderState.h"
#include "stores/action-types/duplicates-finder/DuplicatesFinderActionTypes.h"

DuplicatesFinderReducer::DuplicatesFinderReducer() {

}

void DuplicatesFinderReducer::reduce(std::shared_ptr<State> state,
                                     std::shared_ptr<Action> action) {
    if (action->storeMark() != DuplicatesFinderActionTypes::STORE_MARK) {
        return;
    }

    auto currentState = std::dynamic_pointer_cast<DuplicatesFinderState>(state);
}
