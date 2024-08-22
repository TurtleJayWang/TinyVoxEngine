#pragma once

#include <iostream>
#include <cstring>

template <size_t Size>
class BitMask
{
public:

    BitMask();

    ~BitMask();

    unsigned char* data();

    size_t size();

    void set();

    void unset();

    bool operator[](size_t idx);

    friend BitMask<Size> operator|(const BitMask<Size>& BitMask, size_t num);

    friend BitMask<Size> operator|(const BitMask<Size>& bitset1, const BitMask<Size>& bitset2);

    friend BitMask<bits> operator|(size_t num, const BitMask<bits>& BitMask);

    friend BitMask<Size> operator&(const BitMask<Size>& BitMask, size_t num);

    friend BitMask<Size> operator&(const BitMask<Size>& bitset1, const BitMask<Size>& bitset2);

    friend BitMask<bits> operator&(size_t num, const BitMask<bits>& BitMask);

private:

    unsigned char* bits;

    size_t _byteSize;

};
