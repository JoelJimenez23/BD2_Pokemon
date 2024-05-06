#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstring>
namespace fun{

template<typename T>
void copy( T &a, T& b ){
    std::memcpy( (char*)&a, (char*)&b, sizeof(T) );
}

template<typename T>
void copy( T &a, const T& b ){
    std::memcpy( (char*)&a, (char*)&b, sizeof(T) );
}

template<typename T>
void copy( T &a, char*& b ){
    std::memcpy( (char*)&a, b, sizeof(T) );
}

}


#endif // UTILS_HPP
