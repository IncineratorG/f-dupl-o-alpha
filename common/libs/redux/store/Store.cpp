#include "Store.h"

Store::Store(std::shared_ptr<Reducer> reducer, std::shared_ptr<State> state)
    : mReducer(reducer),
      mState(state)
{

}

std::shared_ptr<State> Store::state() const {
    return mState;
}

void Store::dispatch(const std::shared_ptr<Action> action) {
    mReducer->reduce(mState, action);
}
