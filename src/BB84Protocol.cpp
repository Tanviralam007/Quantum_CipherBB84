#include "../include/BB84Protocol.h"
#include <iostream>

BB84Protocol::BB84Protocol(){
    alice = Alice();
    bob = Bob();
}

void BB84Protocol::run_protocol(int sequence_size){
    alice.generate_bit_sequence(sequence_size);
    alice.generate_basis_sequence();
    alice.encode_bits();

    bob.generate_measurement_basis(sequence_size);
    bob.received_encoded_qbits(alice.get_encoded_qbits());
    bob.measure_qbits();

    bob.compare_results(alice.get_basis_sequence());
}

void BB84Protocol::outcome(){
    std::cout << "Alice's bit sequence:   "; alice.print_bit_sequence();
    std::cout << "Alice's basis sequence: "; alice.print_basis_sequence();
    std::cout << "Alice's encoded qbits:  "; alice.print_encoded_qbits();

    std::cout << std::endl;

    std::cout <<"Bob's measurement basis: ";
    for(int basis : bob.get_measurement_basis()){
        std::cout << basis << " ";
    }
    std::cout << std::endl;

    std::cout << "Bob's measured bits:     ";
    for(int bit : bob.get_measured_bits()){
        std::cout << bit << " ";
    }
    std::cout << std::endl;
}