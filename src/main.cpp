#include "../include/BB84Protocol.h"
#include <iostream> 

int main(int argc, char **argv){
    BB84Protocol protocol = BB84Protocol();
    protocol.run_protocol(10);
    protocol.outcome();

    
    return 0;
}