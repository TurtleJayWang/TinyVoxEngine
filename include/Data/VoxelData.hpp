#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <bitset>

#include <memory>
#include <mem.h>

typedef unsigned long IdxT;

template <size_t Log2Size, typename ValueT>
class Node
{
public:

    Node(IdxT parentIdx, IdxT valueIdx);

    unsigned char* getBuffer();

    const static size_t size = Log2Size;

    IdxT parentIndex;

    IdxT thisIndex;

    IdxT childNodeIndex[1 << (Log2Size + Log2Size + Log2Size)];

    IdxT value;

    const static size_t bufferSizeInByte = sizeof(IdxT) + sizeof(IdxT) + sizeof(IdxT)
        + sizeof(IdxT) * (1 << (Log2Size + Log2Size + Log2Size)) // size of value indices
        + (1 << (Log2Size + Log2Size + Log2Size - 3)); // The total size of the masks

    std::bitset<1 << (Log2Size + Log2Size + Log2Size)> nodeMask;

    unsigned char buffer[bufferSizeInByte];

private:

};

template <
    typename ValueT, // The value type of the data the tree stores
    typename NodeT,  // The node type which the tree uses (specifies the size of each level)
    size_t height = 4U // The level of the tree, including root node
>
class UniformSizeTree
{
public:

    typedef std::shared_ptr<NodeT> NodePtr;

    class Traversor
    {
    public:
        Traversor(NodePtr n) : node(n) { }
        void descend(int index) { if (node->childMask[index]) node = node->childNodeIndex[index]; }
        void ascend() { node = node->parentIndex; }
        void createChild(size_t index) { node->childMask[index] = 1; }
        ValueT& get() { return _values[node->valueIndex]; }
    private:
        NodePtr node;
    };

    UniformSizeTree();

    Traversor getTraversor();

    void add(size_t level, int idxX, int idxY, int idxZ, ValueT value);

    void genBuffer(unsigned char* valueBuffer, size_t valueBufferSize, unsigned char* nodeBuffer, size_t nodeBufferSize);

    void freeBuffer(unsigned char* valueBuffer, unsigned char* nodeBuffer);

private:

    ValueT _backgroundValue;

    std::set<ValueT> _values; // Leaf values

    std::vector<NodePtr> _nodes; // Non-leaf nodes

};

template <typename ValueT, typename NodeT, size_t height = 4>
using Tree = UniformSizeTree<ValueT, NodeT, height>;

template <typename ValueT>
class Grid
{
public:

    Grid();

    ~Grid();

    std::shared_ptr<Tree<ValueT, Node<4>>> getTree() { return tree; }

private:

    std::shared_ptr<Tree<ValueT, Node<4, ValueT>>> tree;

};
