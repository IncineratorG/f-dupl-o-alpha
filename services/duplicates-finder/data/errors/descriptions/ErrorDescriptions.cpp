#include "ErrorDescriptions.h"
#include "services/duplicates-finder/data/errors/Errors.h"

QString ErrorDescriptions::get(const int type) {
    switch (type) {
        case (Errors::UNKNOWN): {
            return "UNKNOWN_ERROR";
        }

        default: {
            return "";
        }
    }
}
