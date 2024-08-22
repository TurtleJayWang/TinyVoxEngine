#include <Data/VoxelData.hpp>

template <size_t Log2Size, typename ValueT>
Node<Log2Size, ValueT>::Node(IdxT parentIdx, IdxT valueIdx) : parentIndex(parentIdx), valueIndex(valueIdx) {}

template <size_t Log2Size, typename ValueT>
unsigned char* Node<Log2Size, ValueT>::getBuffer()
{
    size_t offset = 0;

    unsigned char* parentIdxBuf = (unsigned char*) &parentIndex;
    memcpy(buffer + offset, parentIdxBuf, sizeof(IdxT));
    offset += sizeof(IdxT);

    unsigned char* thisIndex = (unsigned char*) &thisIndex;
    memcpy(buffer + offset, thisIdxBuf, sizeof(IdxT));
    offset += sizeof(IdxT);

    unsigned char* valueIdxBuf  = (unsigned char*) &valueIndex; 
    memcpy(buffer + offset, valueIdxBuf, sizeof(IdxT));
    offset += sizeof(IdxT);

    unsigned char* childNodeIdxBuf = (unsigned char*) childNodeIndex; 
    memcpy(buffer + offset, childNodeIdxBuf, sizeof(IdxT * (1 << (Log2Size + Log2Size + Log2Size))));
    offset += sizeof(IdxT * (1 << (Log2Size + Log2Size + Log2Size)));

    for (int i = 0; i < nodeMask.size() / 8; i++)
    {
        unsigned char tempUChar = nodeMask[8 * i + 0] << 0
            | nodeMask[8 * i + 1] << 1
            | nodeMask[8 * i + 2] << 2
            | nodeMask[8 * i + 3] << 3
            | nodeMask[8 * i + 4] << 4
            | nodeMask[8 * i + 5] << 5
            | nodeMask[8 * i + 6] << 6
            | nodeMask[8 * i + 7] << 7;
        offset += i
        memcpy(buffer + offset, &tempUChar);
    }

    return buffer;
}

template <typename ValueT, typename NodeT, size_t height>
UniformSizeTree<ValueT, NodeT, height>::UniformSizeTree()
{
    _nodes.push_back(std::make_shared<NodeT>(0, 0));
}

template <typename ValueT, typename NodeT, size_t height>
UniformSizeTree<ValueT, NodeT, height>::Traversor UniformSizeTree<ValueT, NodeT, height>::getTraversor()
{
    return Traversor(_nodes[0]);
}
