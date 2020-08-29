//
// This serves as a node class for utilizing chord
//

#include "Node.h"
#include <openssl/sha.h>
#include <iostream>

#define successor finger[0].node

Node::Node() {
    identifier = helpFunction.hash(generateIP());
}

/*
 * Sets node IP address to be an IPV4
 */
std::string Node::generateIP() {
    std::string res;
    for(uint32_t i = 0; i < IPV4_SIZE/8; i++){
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
 * Return closest finger preceding id
 */
Node* Node::closest_preceding_finger(long long id) {
    for(int32_t i = M-1; i > -1; i--){
        if(finger[i].node->identifier > identifier && finger[i].node->identifier < id){
            return finger[i].node;
        }
    }
    return successor;
}

/*
 * Ask node n to find id's predecessor
 */
Node* Node::find_predecessor(long long id) {
    Node* n_prime = this;
    Node* prev;
    while(!(id > n_prime->identifier && id <= n_prime->successor->identifier)){
        n_prime = n_prime->closest_preceding_finger(id);
        if(prev == n_prime){
            return n_prime;
        }
        prev = n_prime;
    }
    return n_prime;
}

/*
 * Ask node n to find id's successor
 */
Node* Node::find_successor(long long id) {
    Node *n_prime = find_predecessor(id);
    return n_prime->successor;
}

/*
 * Let node n join the network
 */
void Node::join(Node* n_prime){
    if(n_prime != nullptr) {
        init_finger_table(n_prime);
        update_others();
    }
    // node is first node;
    else {
        for(uint32_t i = 0; i < M; i++){
            finger[i].node = this;
        }
        predecessor = this;
    }
}

/*
 * init finger table
 */
void Node::init_finger_table(Node *n_prime) {
    finger[0].node = n_prime->find_successor(n_prime->identifier);
    predecessor = successor->predecessor;
    successor->predecessor = this;
    for(uint32_t i = 0; i < M-1; i++){
        if((finger[i].node != nullptr && this->start(i+1) >= identifier) && (this->start(i+1) < finger[i].node->identifier)){
            finger[i+1].node = finger[i].node;
        }
        else {
            finger[i+1].node = n_prime->find_successor(this->start(i+1));
        }
    }
}

/*
 * returns n + 2^(k-1) mod 2^m
 */
long long int Node::start(int k){
    long long int power = pow(2, k-1);
    long long int modulo_val = pow(2, M);
    return (identifier + power) % modulo_val;
}

/*
 * update finger tables when n joins
 */
void Node::update_others() {
    for(uint32_t i = 0; i < M; i++){
        Node* p = find_predecessor(identifier-pow(2, i));
        p->update_finger_tables(this, i);
    }
}

/*
 * update the finger table for the current node at pos i with Node s
 */
void Node::update_finger_tables(Node *s, int i) {
    if(s->identifier >= identifier && s->identifier < finger[i].node->identifier){
        finger[i].node = s;
        Node* p = predecessor;
        p->update_finger_tables(s, i);
    }
}

/*
 * Returns node identity
 */
long long int Node::getIdentifier() {
    return identifier;
}