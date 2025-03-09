#ifndef BOB_H
#define BOB_H

#include <iostream>
#include <vector>
#include <string>

class Bob {
    private:
        std::vector<std::string> received_qbits;
        std::vector<int> measurement_basis;
        std::vector<int> measured_bits;

    public:
        Bob();

        void received_encoded_qbits(const std::vector<std::string>& encoded_qbits);
        void generate_measurement_basis(int size);
        void measure_qbits();
        void compare_results(const std::vector<int>& alice_basis_sequence);

        // getters
        std::vector<int>& get_measured_bits();
        std::vector<int>& get_measurement_basis();
};

#endif // BOB_H