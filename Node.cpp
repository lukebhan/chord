//
// This serves as a node class for utilizing chord
//

#include "Node.h"
#include <openssl/sha.h>
#include <iostream>>
#include <cstring>

const uint seed = 15;

Node::Node() {
    std::string address = generateIP();
    unsigned char hash[40];
    std::copy(address.begin(), address.end(), ipAddress);
    SHA1(hash, sizeof(hash), hash);
    std::strcpy((char*)identifier, (char*)hash);
}

/*
 * Returns node's private IP Variable
 */
unsigned char* Node::getIpAddress() {
    return ipAddress;
}

/*
 * Return node's identifier
 */
unsigned char* Node::getIdentifier() {
    return identifier;
}

/*
 * Sets node IP address to be an IPV4
 */
std::string Node::generateIP() {
    std::string res;
    for(uint32_t i = 0; i < 4; i++){
        res += generateByte();
    }
    return res;
}

/*
 * Generates an 8 bit number as unsigned char
 */
std::string Node::generateByte() {
    return std::to_string(rand() % 255 + 1);
}

/*
 * Returns closest finger preceding id
 */
Node* Node::closest_preceding_finger(unsigned char* id) {
    for(int i = HASH_SIZE-1; i > -1; i--){
        if(memcmp(finger[i]->getIdentifier(), identifier, 40) > 0 && std::memcmp(finger[i]->getIdentifier(), id, 40) < 0){
            return finger[i];
        }
    }
    return this;
}

Node* Node::find_predecessor(unsigned char *id) {
    Node* n_prime = this;
    while(!(std::memcmp(n_prime->getIdentifier(), id, 40) < 0 && std::memcmp(n_prime->successor->getIdentifier(), id, 40) > 0)){
        n_prime = n_prime->closest_preceding_finger(id);
    }
}

Node* Node::find_successor(unsigned char *id) {
    Node* n_prime = find_predecessor(id);
    return n_prime->successor;
}