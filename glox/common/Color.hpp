#ifndef COLOR_HPP_
#define COLOR_HPP_

#warn "This Color type is deprecated. Use glox/GloxColor"

namespace graphics {

inline uint8_t color_float_to_int( float i ) {
    return (uint8_t)(i * 255);
}

/* This is a color class, it is for
 * convinience */
class Color {
public:
    inline Color( uint32_t color ) :
        color( color ) {}

    inline Color() :
        color( 0x00FFFFFF ) {}

    // inline Color( uint8_t r, uint8_t g, uint8_t b ):
    //     color( (r<<16)|(g<<8)|b ) {}

    inline Color( float r, float g, float b ):
        color((color_float_to_int(r) << 16) |
              (color_float_to_int(g) << 8 ) |
               color_float_to_int(b) ) {}

    inline void glColor()
        { glColor3ub( getR(), getG(), getB() ); }

    inline uint8_t getR() { return (color & 0xFF0000) >> 16; }
    inline uint8_t getG() { return (color & 0x00FF00) >>  8; }
    inline uint8_t getB() { return (color & 0x0000FF) >>  0; }

private:
    uint32_t color;
};

}
#endif
