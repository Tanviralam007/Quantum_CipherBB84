#ifndef ALICE_H
#define ALICE_H

#include <vector>
#include <string>
#include <cstdlib> // For rand() and srand() [random number generation]
#include <ctime> // For time() [time for seeding the random number generator]

class Alice{
    private:
        std::vector<int> bit_sequence;
        std::vector<int> basis_sequence;
        std::vector<std::string> encoded_qbits;
    
    public:
        Alice();

        void generate_bit_sequence(int size);
        void generate_basis_sequence();
        void encode_bits();

        void print_bit_sequence();
        void print_basis_sequence();
        void print_encoded_qbits();

        // getters
        std::vector<int> get_bit_sequence();
        std::vector<int> get_basis_sequence();
        std::vector<std::string> get_encoded_qbits();
};

#endif // ALICE_H