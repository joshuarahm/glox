#ifndef GLOXVECTOR4_HPP_
#define GLOXVECTOR4_HPP_

/*
 * Author: jrahm
 * created: 2013/10/23
 * GloxVector4.hpp: <description>
 */

#include <string>
#include <sstream>

namespace glox {
template <class NumT=float>

class GloxVector4 {
public:
	inline GloxVector4( const NumT& x=0, const NumT& y=0, const NumT& z=0, const NumT& w=0 ) :
		x( x ), y( y ), z( z ), w( w ) {}

	inline const NumT& getX() const { return x; }
	inline const NumT& getY() const { return y; }
	inline const NumT& getZ() const { return z; }
	inline const NumT& getW() const { return w; }

	inline const NumT& get0() const { return x; }
	inline const NumT& get1() const { return y; }
	inline const NumT& get2() const { return z; }
	inline const NumT& get3() const { return w; }

	inline void setX( const NumT& x ) { this->x = x; }
	inline void setY( const NumT& y ) { this->y = y; }
	inline void setZ( const NumT& z ) { this->z = z; }
	inline void setW( const NumT& w ) { this->w = w; }

	inline bool isZero() {
		return x == 0 && y == 0 && z == 0 && w == 0 ;
	}

	inline void operator+=(const GloxVector4& other ) {
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
	}

    inline std::string toString() const {
        std::stringstream stream;
        stream << "( " << x << ", " << y << ", " << z << ", " << w << " )";
        return stream.str();
    }
private:
	NumT x;
	NumT y;
	NumT z;
	NumT w;
};
}

#endif /* GLOXVECTOR4_HPP_ */
