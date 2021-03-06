#ifndef GLOXVECTOR3_HPP_
#define GLOXVECTOR3_HPP_

/*
 * Author: jrahm
 * created: 2013/10/29
 * GloxVector3.hpp: <description>
 */

#include "glox/GloxPoint.hpp"

#include <string>
#include <sstream>

#include <cmath>

namespace glox {
template <class NumT=float>

class GloxVector3 {
public:
    inline GloxVector3( const NumT& x=0, const NumT& y=0, const NumT& z=0 ) :
		x( x ), y( y ), z( z ) {}

	inline const NumT& get0() const { return x; }
	inline const NumT& get1() const { return y; }
	inline const NumT& get2() const { return z; }

	inline void set0( const NumT& x ) { this->x = x; }
	inline void set1( const NumT& y ) { this->y = y; }
	inline void set2( const NumT& z ) { this->z = z; }

	inline bool isZero() {
		return x == 0 && y == 0 && z == 0 ;
	}

	inline void operator+=(const GloxVector3& other ) {
		x += other.x;
		y += other.y;
		z += other.z;
	}

    inline void operator*=( NumT scalar ) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
    }

	inline GloxVector3<NumT> operator*( NumT scalar ) {
		GloxVector3 tmp = *this;
		tmp *= scalar;
		return tmp;
	}

	inline GloxVector3<NumT> cross( const GloxVector3<NumT>& v ) {
		return GloxVector3<NumT>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}

	inline double getMagnitude() const {
		return sqrt( x*x + y*y + z*z );
	}

	void normalize() {
		double mag = getMagnitude();
		x = x / mag;
		y = y / mag;
		z = z / mag;
	}

	inline GloxPoint<NumT> toPoint() {
		return GloxPoint<NumT>( x, y, z );
	}

    inline std::string toString() const {
        std::stringstream stream;
        stream << "( " << x << ", " << y << ", " << z <<  " )";
        return stream.str();
    }
private:
	NumT x;
	NumT y;
	NumT z;
};
}

#endif /* GLOXVECTOR3_HPP_ */
