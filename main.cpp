#include <iostream>
#include "src/Node.h"

int main() {
    // Simple chord example
    Node j;
    j.join(nullptr);
    std::cout << j.getIdentifier() << std::endl;
    for(uint32_t i = 0; i < 20; i++){
        Node k;
        k.join(&j);
    }
    Node* m = j.find_predecessor(j.getIdentifier()+1);
    std::cout << m->getIdentifier() << std::endl;
    return 0;
}
