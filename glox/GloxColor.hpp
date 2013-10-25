#ifndef GLOXCOLOR_HPP_
#define GLOXCOLOR_HPP_

/*
 * Author: jrahm
 * created: 2013/10/23
 * GloxColor.hpp: <description>
 */

#include "glox/GloxCommon.hpp"
#include "glox/GloxRenderable.hpp"
#include "glox/GloxVectorizable.hpp"

#include <string>
#include <sstream>

namespace glox {

/* This is a color class, it is for
 * convinience */
class GloxColor : public GloxRenderable,GloxVectorizable<uint8_t>,GloxVectorizable<float> {
public:
    /* Creates a new color that is defined
     * from the float values for r, g, b. The 
     * default value is an opaque black color */
    inline GloxColor( uint8_t r=0, uint8_t g=0, uint8_t b=0, uint8_t a=255 ) :
        r( r ), g( g ), b( b ), a( a ) {}

    inline GloxColor( const GloxColor& color ) :
        r( color.r ), g( color.g ), b( color.b ), a( color.a ) {}

    

    /* Get the components of this
     * color */
    inline uint8_t getR() const { return r; } 
    inline uint8_t getG() const { return g; } 
    inline uint8_t getB() const { return b; } 
    inline uint8_t getA() const { return a; } 

    inline void render() const {
        if( a < 255 ) {
            glColor4ub( r, g, b, a );
        } else {
            glColor3ub( r, g, b );
        }
    }


    inline void scale( float   f ) { scale2( f ); }
    inline void scale( uint8_t f ) { scale2( f ); }

    virtual int toVector( float* arr, size_t len ) const {
        if( len < 3 ) return -1;
        arr[0] = r / 255.0;
        arr[1] = g / 255.0;
        arr[2] = b / 255.0;
        if( len > 3 ) {
            arr[3] = a / 255.0;
            return 4;
        }
        return 3;
    }
    
    virtual int toVector( uint8_t* arr, size_t len ) const {
        if( len < 3 ) return -1;
        arr[0] = r;
        arr[1] = g;
        arr[2] = b;
        if( len > 3 ) {
            arr[3] = a;
            return 4;
        }
        return 3;
    }

    inline GloxColor operator*( float value ) const {
        GloxColor ret( * this );
        ret.scale2( value );
        return ret;
    }

    inline std::string toString( ) const {
        char buf[ 32 ];
        snprintf( buf, 32, "( %d, %d, %d, %d )\n", r, g, b, a );
        return std::string( buf );
    }

    inline GloxColor operator*( int value ) const { return (*this) * ((float)value); }

private:
    template <class NumT>
    inline void scale2( NumT f ) {
        int r1 = (int)(f * r);
        int g1 = (int)(f * r);
        int b1 = (int)(f * r);
        int a1 = (int)(f * r);
        r = r1 & 0xFF;
        g = g1 & 0xFF;
        b = b1 & 0xFF;
        a = a1 & 0xFF;
    }

    uint8_t r; 
    uint8_t g; 
    uint8_t b; 
    uint8_t a; 
};

}

#endif /* GLOXCOLOR_HPP_ */
