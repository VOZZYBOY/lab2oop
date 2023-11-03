#include "hex.hpp"

int main() {
    Hex test_subject_1 = Hex("ABEF");
    Hex test_subject_2 = Hex("7EA");
    std::cout << (test_subject_1 - test_subject_2).get_string_for_view() << '\n';
}