#include "../include/Alice.h"
#include <iostream>

// constructor: initializes the random seed for the random number generator
Alice::Alice(){
    // seed the random number generator with the current time
    std::srand(std::time(0));
}

void Alice::generate_bit_sequence(int size){
    bit_sequence.clear();
    for(int i = 0; i < size; i++){
        bit_sequence.push_back(std::rand() % 2);
    }
}

void Alice::generate_basis_sequence(){
    basis_sequence.clear();
    for(int i = 0; i < bit_sequence.size(); i++){
        basis_sequence.push_back(std::rand() % 2);
    }
}

void Alice::encode_bits(){
    encoded_qbits.clear();
    for(size_t i = 0; i < bit_sequence.size(); i++){
        // for rectilinear basis
        if(basis_sequence[i] == 0){
            // encode 0 as |0>
            if(bit_sequence[i] == 0){
                encoded_qbits.push_back("|0>");
            }
            // encode 1 as |1>
            else{
                encoded_qbits.push_back("|1>");
            }
        } else{
            // for diagonal basis
            // encode 0 as |+>
            if(bit_sequence[i] == 0){
                encoded_qbits.push_back("|+>");
            }
            // encode 1 as |->
            else{
                encoded_qbits.push_back("|->");
            }
        }
    }
}

void Alice::print_bit_sequence(){
    for(size_t i = 0; i < bit_sequence.size(); i++){
        std::cout << bit_sequence[i] << " ";
    }
    std::cout << std::endl;
}

void Alice::print_basis_sequence(){
    for(size_t i = 0; i < basis_sequence.size(); i++){
        std::cout << basis_sequence[i] << " ";
    }
    std::cout << std::endl;
}

void Alice::print_encoded_qbits(){
    for(size_t i = 0; i < encoded_qbits.size(); i++){
        std::cout << encoded_qbits[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int>& Alice::get_bit_sequence(){
    return bit_sequence;
}

std::vector<int>& Alice::get_basis_sequence(){
    return basis_sequence;
}

std::vector<std::string>& Alice::get_encoded_qbits(){
    return encoded_qbits;
}