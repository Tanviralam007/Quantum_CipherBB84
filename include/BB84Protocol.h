#ifndef BB84PROTOCOL_H
#define BB84PROTOCOL_H

#include "../include/Alice.h"
#include "../include/Bob.h"
#include <vector>
#include <string> 

class  BB84Protocol{
    private:
        Alice alice;
        Bob bob;

    public:
        BB84Protocol();
        void run_protocol(int sequence_size);
        void outcome();
};


#endif // BB84PROTOCOL_H