//
// Created by luke on 8/28/20.
//

#ifndef CHORD_FINGER_H
#define CHORD_FINGER_H

#include <utility>
#include <math.h>
#include "Node.h"

class Node;

class Finger {
public:
    std::pair<long long int, long long int> interval;
    Node* node;
    Finger() = default;
};
#endif //CHORD_FINGER_H
