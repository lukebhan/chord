#include "Helpers.h"

#include <openssl/sha.h>
#include <math.h>


long long int Helpers::hash(std::string key) {
    // declare buffers and set mod_val
    unsigned char buffer[M];
    unsigned char resultHash [M];
    char finalHash[M];
    std::string hashStr = "";
    long long int mod_val = pow(2, M);

    std::copy(key.begin(), key.end(), buffer);
    SHA1(buffer, sizeof(buffer), resultHash);
    for(uint32_t i = 0; i < M/8; i++){
        // convert to decimal form
        sprintf(finalHash, "%d", resultHash[i]);
        hashStr += finalHash;
    }

    long long int res = stoll(hashStr) % mod_val;
    return res;
}