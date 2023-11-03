#pragma once

#include <string>
#include <iostream>
#include <algorithm>

class Hex
{ 
public:
    Hex();
    Hex(const size_t n, unsigned char t = 0);
    Hex(const std::initializer_list<unsigned char>& t);
    Hex(const std::string& t);
    Hex(const Hex& other);
    Hex(Hex&& other) noexcept;      
    virtual ~Hex() noexcept;
    size_t get_size();
    unsigned char* get_array();
    std::string get_string_for_view();
    bool operator>(const Hex& other);
    bool operator<(const Hex& other);
    bool operator==(const Hex& other);
    Hex operator+(const Hex& other);
    Hex operator-(const Hex& other);
private:
    size_t _size;
    unsigned char *_array;
};
