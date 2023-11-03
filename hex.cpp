#include "hex.hpp"

int to_dec(int a) {
    return (a>=65) ? a-55 : a-48;
}

int to_hex(int a) {
    return (a>9) ? a+55 : a+48;
}

Hex Hex::operator+(const Hex& other) {
    size_t rd = 0, maxlen, minlen;
    bool first = _size > other._size;
    maxlen = first ? _size : other._size;
    minlen = first ? other._size : _size;
    Hex result(maxlen, 0);
    for (size_t i = 0; i<minlen; ++i) {
        size_t sum = to_dec(_array[i])+to_dec(other._array[i])+rd;
        rd = sum / 16;
        result._array[i]=to_hex(sum%16);
    }
    size_t counter{minlen};
    while (counter<maxlen and rd>0) {
        size_t n = first ? to_dec(_array[counter]) : to_dec(other._array[counter]);
        size_t sum = n + rd;
        rd = sum/16;
        result._array[counter]=to_hex(sum%16);
        ++counter;
    }
    if (rd>0) {
        ++result._size;
        unsigned char* arr_upd = new unsigned char[_size];
        for (size_t i = 0; i<result._size-1; ++i)
            arr_upd[i] = result._array[i];
        arr_upd[result._size-1] = to_hex(rd);
        delete result._array;
        result._array = arr_upd;
    }
    return result;
}

Hex Hex::operator-(const Hex& other) {
    if (_size < other._size)
        throw std::invalid_argument("Minuend is smaller than subtrahend");
    Hex result(_size, 0);
    bool rd{false};
    for (size_t i = 0; i<_size; ++i) {
        long long n = to_dec(_array[i]);
        if (i<other._size) {
            n-=to_dec(other._array[i]);
        }
        if (rd) {
            --n;
            rd=false;
        }
        if (n<0) {
            n+=16;
            rd=true;
        }
        result._array[i]=to_hex(n);
    }
    if (rd)
        throw std::invalid_argument("Minuend is smaller than subtrahend");
    long long counter{-1};
    for (size_t i{_size-1}; i>0; --i) {
        if (to_dec(result._array[i])!=0) {
            break;
        } else {
            counter = i;
        }
    }
    if (counter!=-1) {
        result._size = counter;
        unsigned char* arr_upd = new unsigned char[_size];
        for (size_t i{}; i<result._size; ++i)
            arr_upd[i] = result._array[i];
        delete result._array;
        result._array = arr_upd;
    }
    return result;
}

bool Hex::operator>(const Hex& other) {
    if (_size > other._size)
        return true;
    if (_size < other._size)
        return false;
    for (size_t i{_size-1}; i>=0; --i) {
        if (_array[i]>other._array[i])
            return true;
        if (_array[i]<other._array[i])
            return false;
    }
    return false;
}

bool Hex::operator<(const Hex& other) {
    if (_size > other._size)
        return false;
    if (_size < other._size)
        return true;
    for (size_t i{_size-1}; i>=0; --i) {
        if (_array[i]>other._array[i])
            return false;
        if (_array[i]<other._array[i])
            return true;
    }
    return false;
}

bool Hex::operator==(const Hex& other) {
    if (_size != other._size)
        return false;
    for (size_t i = 0; i<_size; --i) {
        if (_array[i] != other._array[i])
            return false;
    }
    return true;
}
bool wrong_digit(int a) {
    if (a==0 or (a>=48 and a<=57) or (a>=65 and a<=70))
        return false;
    return true;
}

Hex::Hex() {
    _size = 0;
    _array = nullptr;
}

Hex::Hex(const size_t n, unsigned char t) {
    if (wrong_digit(t))
        throw std::invalid_argument("Input digit out of range");
    _size = n;
    _array = new unsigned char[_size];
    for (size_t i{}; i < _size; ++i)
        _array[i] = t;
}

Hex::Hex(const std::initializer_list<unsigned char>& t) {
    _array = new unsigned char[t.size()];
    _size = t.size();
    size_t i{_size-1};
    for (auto& c : t) {
        if (wrong_digit(c))
            throw std::invalid_argument("Input digit out of range");
        _array[i--] = c;
    }
}

Hex::Hex(const std::string& t) {
    _array = new unsigned char[t.size()];
    _size  = t.size();
    size_t i{_size-1};
    for(auto& c: t) {
        if (wrong_digit(c))
            throw std::invalid_argument("Input digit out of range");
        _array[i--] = c;
    }
}

Hex::Hex(const Hex& other) {
    _size  = other._size;
    _array = new unsigned char[_size];
    for(size_t i{}; i<other._size; ++i) 
        _array[i] = other._array[i];
}

Hex::Hex(Hex&& other) noexcept {
    _size = other._size;
    _array = other._array;
    other._size = 0;
    other._array = nullptr;
}

Hex::~Hex() noexcept {
  
    _size = 0;
    delete[] _array;
    _array = nullptr;
}

size_t Hex::get_size() {
    return _size;
}

unsigned char* Hex::get_array() {
    return _array;
}

std::string Hex::get_string_for_view() {
    std::string s = "";
    for (size_t i = 0; i < _size; i++) {
        s += _array[i];
        
    }
    std::reverse(s.begin(), s.end());
    return s;
}