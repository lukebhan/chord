//
// This serves as a node declaration for utilizing chord.
//

#ifndef CHORD_NODE_H
#define CHORD_NODE_H

#include <string>
#include <stdlib.h>
#include "Helpers.h"
#include "constants.h"
#include "Finger.h"

class Node {
private:
    std::string generateIP();
    std::string generateByte();
    long long int identifier;
    Finger* finger = new Finger[M];
    Node* predecessor;
    Node* successor;
    long long int start(int k);
    Helpers helpFunction;
public:
    Node();
    Node* find_successor(long long int id);
    Node* find_predecessor(long long int id);
    Node* closest_preceding_finger(long long int id);
    void join(Node* n_prime);
    void init_finger_table(Node* n_prime);
    void update_others();
    void update_finger_tables(Node* s, int i);
    long long int getIdentifier();
};

#endif //CHORD_NODE_H