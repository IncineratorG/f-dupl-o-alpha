#include "Errors.h"
#include "services/duplicates-finder/data/errors/codes/ErrorCodes.h"
#include "services/duplicates-finder/data/errors/descriptions/ErrorDescriptions.h"

Error Errors::get(const int type) {
    switch (type) {
        default: {
            return Error(
                        ErrorCodes::get(Errors::UNKNOWN),
                        ErrorDescriptions::get(Errors::UNKNOWN)
                   );
        }
    }
}
