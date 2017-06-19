#include "evaluatables.h"

#include "utils/system_utils.h"

using namespace std;

/*****************************************************************
                           Evaluatable
*****************************************************************/

void Evaluatable::disableCaching() {
    // We only disable caching if it is done in maps as the
    // space for vectors is already reserved and thus not growing.
    if (cachingType == MAP) {
        cachingType = DISABLED_MAP;
    }

    //Alex : removing Kleene things
    //->start
    /*
    if (kleeneCachingType == MAP) {
        kleeneCachingType = DISABLED_MAP;
    }
    */
    //Alex->end
}
