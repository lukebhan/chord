//
// Created by luke on 8/28/20.
//

#ifndef CHORD_HELPERS_H
#define CHORD_HELPERS_H

#include <string>
#include "constants.h"

struct Helpers {
    long long int hash(std::string key);
    Helpers() = default;
};


#endif //CHORD_HELPERS_H
