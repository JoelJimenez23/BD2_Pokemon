#ifndef NODE_HPP
#define NODE_HPP

#define DISK_NULL (-1)
#define INITIAL_RECORD (0)
#include "utils.hpp"
#include <fstream>
#include <sstream>
#define DETACH (-2)
#define NO_DETACH (-3)

template<typename KeyType>
struct Node{
    KeyType key{};
    long data_pointer {DISK_NULL};

    long right {DISK_NULL};
    long left {DISK_NULL};
    long height {0};
    long next {DISK_NULL};

    explicit Node() = default;

    explicit Node(KeyType k, long physical_pos):data_pointer{physical_pos}{
        fun::copy(key,k);
    }

    Node &operator=(const Node &other){
        fun::copy(key,other.key);
        data_pointer = other.data_pointer;
        next = other.next;
        return *this;
    }
};

template<typename T>
std::ostream& operator<<( std::ostream& ofs, Node<T> &node ) {
    ofs.write( (char*)&node, sizeof(node) );
    return ofs;
}

template<typename T>
std::istream& operator>>( std::istream& ifs, Node<T> &node ){
    ifs.read( (char*)&node, sizeof(node) );
    return ifs;
}

#endif
