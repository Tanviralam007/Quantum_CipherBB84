#include "../include/Bob.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Bob::Bob(){
    std::srand(std::time(0));
}

void Bob::received_encoded_qbits(const std::vector<std::string>& encoded_qbits){
    received_qbits = encoded_qbits;
}

void Bob::generate_measurement_basis(int size){
    measurement_basis.clear();
    for(int i = 0; i < size; i++){
        measurement_basis.push_back(std::rand() % 2);
    }
}

void Bob::measure_qbits(){
    measured_bits.clear();
    for(size_t i = 0; i < received_qbits.size(); i++){
        if(measurement_basis[i] == 0){
            // rectilinear basis
            if(received_qbits[i] == "|0>"){
                measured_bits.push_back(0);
            } else if(received_qbits[i] == "|1>"){
                measured_bits.push_back(1);
            }
        } else {
            // diagonal basis
            if(received_qbits[i] == "|+>"){
                measured_bits.push_back(0);
            } else if(received_qbits[i] == "|->"){
                measured_bits.push_back(1);
            }
        }
    }
}

void Bob::compare_results(const std::vector<int>& alice_basis_sequence){
    int matching_bits = 0;
    for(size_t i = 0; i < measurement_basis.size(); i++){
        if(measurement_basis[i] == alice_basis_sequence[i]){
            if(measured_bits[i] == alice_basis_sequence[i]){
                ++matching_bits;
            }
        }
    }
    std::cout << "Matching bits: " << matching_bits << " | " << measurement_basis.size() << std::endl;
}

std::vector<int>& Bob::get_measured_bits(){
    return measured_bits;
}

std::vector<int>& Bob::get_measurement_basis(){
    return measurement_basis;
}