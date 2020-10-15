#include "ErrorCodes.h"
#include "services/duplicates-finder/data/errors/Errors.h"

int ErrorCodes::get(const int type) {
    switch (type) {
        case (Errors::UNKNOWN): {
            return 1;
        }

        default: {
            return -1;
        }
    }
}
