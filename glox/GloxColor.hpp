#ifndef GLOXCOLOR_HPP_
#define GLOXCOLOR_HPP_

/*
 * Author: jrahm
 * created: 2013/10/23
 * GloxColor.hpp: <description>
 */

#include "GloxCommon.hpp"

namespace glox {

/* This is a color class, it is for
 * convinience */
class GloxColor {
public:
    /* Creates a new color that is defined
     * from the float values for r, g, b. The 
     * default value is an opaque black color */
    inline GloxColor( uint8_t r=0, uint8_t g=0, uint8_t b=0, uint8_t a=255 ) :
        r( r ), g( g ), b( b ), a( a ) {}

    

    /* Get the components of this
     * color */
    inline uint8_t getR() const { return r; } 
    inline uint8_t getG() const { return g; } 
    inline uint8_t getB() const { return b; } 
    inline uint8_t getA() const { return a; } 

private:
    uint8_t r; 
    uint8_t g; 
    uint8_t b; 
    uint8_t a; 
};

}

#endif /* GLOXCOLOR_HPP_ */
