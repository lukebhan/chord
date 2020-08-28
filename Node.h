//
// This serves as a node declaration for utilizing chord.
//

#ifndef CHORD_NODE_H
#define CHORD_NODE_H

#include <string>
#include <stdlib.h>

const int HASH_SIZE = 40;
const int IPV4_SIZE = 32;

class Node {
private:
    std::string generateIP();
    std::string generateByte();
    unsigned char ipAddress[IPV4_SIZE];
    unsigned char identifier[HASH_SIZE];
    unsigned char key[IPV4_SIZE];
    Node* finger[HASH_SIZE];
    Node* predecessor;
    Node* successor;
public:
    unsigned char* getIpAddress();
    unsigned char* getIdentifier();
    Node* find_successor(unsigned char* id);
    Node* find_predecessor(unsigned char* id);
    Node* closest_preceding_finger(unsigned char* id);
    Node();
};


#endif //CHORD_NODE_H
