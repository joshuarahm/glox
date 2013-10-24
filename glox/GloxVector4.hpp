#ifndef GLOXVECTOR4_HPP_
#define GLOXVECTOR4_HPP_

/*
 * Author: jrahm
 * created: 2013/10/23
 * GloxVector4.hpp: <description>
 */

template <class NumT>

class GloxVector4 {
public:
	inline GloxVector4( const NumT& x, const NumT& y, const NumT& z, const NumT& w ) :
		x( x ), y( y ), z( z ), w( w ) {}

	inline const NumT& getX() const { return x; }
	inline const NumT& getY() const { return y; }
	inline const NumT& getZ() const { return z; }
	inline const NumT& getW() const { return w; }

	inline void setX( const NumT& x ) { this->x = x; }
	inline void setY( const NumT& x ) { this->y = y; }
	inline void setZ( const NumT& x ) { this->z = z; }
	inline void setW( const NumT& x ) { this->w = w; }
private:
	NumT x;
	NumT y;
	NumT z;
	NumT w;
};

#endif /* GLOXVECTOR4_HPP_ */
