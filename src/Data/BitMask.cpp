#include <Data/BitMask.hpp>

template <size_t Size>
BitMask<Size>::BitMask()
{
    _byteSize = Size >> 3 + 1;
    bits = (unsigned char*) malloc(_byteSize);
    unset();
}

template <size_t Size>
BitMask<Size>::~BitMask()
{
    free(bits);
}

template <size_t Size>
void BitMask<Size>::set()
{
    for (int i = 0; i < _byteSize; i++) bits[i] = 1;
}

template <size_t Size>
void BitMask<Size>::unset()
{
    for (int i = 0; i < _byteSize; i++) bits[i] = 0;
}

template <size_t Size>
unsigned char* BitMask<Size>::data() { return bits; }

template <size_t Size>
size_t BitMask<Size>::size() { return Size; }

template <size_t Size>
bool BitMask<Size>::operator[](size_t idx)
{
    return (bits[idx >> 3] | (idx & 0b111));
}

template <size_t Size>
BitMask<Size> operator|(const BitMask<Size>& bitset, size_t num)
{
    BitMask<Size> result;
    for (int i = 0; i < std::min(bitset._byteSize, 8); i++)
        result.bits[i] = bitset.bits[i] | ((num & (0xff << (i << 3))) >> (i << 3));
    return result;
}

template <size_t Size>
BitMask<Size> operator|(const BitMask<Size>& bitset1, const BitMask<Size>& bitset2)
{
    for (int i = 0; i < bitset1._byteSize; i++)
        bitset1.bits[i] |= bitset2.bits[i];
}

template <size_t bits>
BitMask<bits> operator|(size_t num, const BitMask<bits>& bitset)
{
    return (bitset | num)
}

template <size_t Size>
BitMask<Size> operator&(const BitMask<Size>& bitset, size_t num)
{
    BitMask<Size> result;
    for (int i = 0; i < std::min(bitset._byteSize, 8); i++)
        result.bits[i] = bitset.bits[i] & ((num & (0xff << (i << 3))) >> (i << 3));
    return result;
}

template <size_t Size>
BitMask<Size> operator&(const BitMask<Size>& bitset1, const BitMask<Size>& bitset2)
{
    size_t n = (bitset.size() >> 3) + 1;
    for (int i = 0; i < n; i++)
        bitset1.bits[i] &= bitset2.bits[i];
}

template <size_t bits>
BitMask<bits> operator&(size_t num, const BitMask<bits>& bitset)
{
    return (bitset & num);
}
