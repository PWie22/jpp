
#ifndef PUNKT_HPP
#define PUNKT_HPP

template <typename T>
 class Punkt
 {
    public:
       Punkt( T argX, T argY, T argZ )
       : x(argX), y(argY), z(argZ)
       { }
 
       T x, y, z;
 };

#endif // PUNKT_HPP