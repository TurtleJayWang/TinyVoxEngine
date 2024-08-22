#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>
#include <algorithm>

#include "BitMask.hpp"

typedef unsigned long long IndexType;

template <size_t log2Size>
struct InternalNode
{
    BitMask<1 << (log2Size + log2Size + log2Size)> childMask;
    BitMask<1 << (log2Size + log2Size + log2Size)> leafMask;
    IndexType childIndices[1 << (log2Size + log2Size + log2Size)];
};

template <typename LeafT, size_t log2Size, size_t height>
class Tree
{
public:

    Tree();

    static size_t getSize() { return log2Size; }

    static size_t getHeight() { return height; }

private:

    std::vector<IndexType> childIndicesMap;

    std::vector<InternalNode> internalNodes;

    std::vector<LeafT> leafValues;

};

template <typename ValueT, typename TreeT>
class Grid
{
public:

    Grid();

    static size_t coord(size_t x, size_t y, size_t z);

private:
};
