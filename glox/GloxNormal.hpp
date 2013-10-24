#ifndef GLOXNORMAL_HPP_
#define GLOXNORMAL_HPP_

/*
 * Author: jrahm
 * created: 2013/10/22
 * GloxNormal.hpp: <description>
 */

#include "glox/GloxPlottable.hpp"

namespace glox {

/* Type that the GloxNormal holds,
 * defaults to an integer */
template <class NumT=float>

/* A normal in 3D space. This class
 * implements Plottable which provides
 * the `plot` function which calles
 * glVertex on the components */
class GloxNormal : public GloxPlottable {
public:
	/* Creates a new GloxNormal from the components
	 * specified */
	inline GloxNormal( const NumT& x=0, const NumT& y=0, const NumT& z=0 ):
		x(x), y(y), z(z) {}

	/* Copies the glox normal other */
	inline GloxNormal( const GloxNormal<NumT>& other ) :
		x(other.x), y(other.y), z(other.z) {}

	/* Returns the X componet of this
	 * normal */
	inline const NumT& getX() const {
		return x;
	}

	/* Returns the Y component of this
	 * normal */
	inline const NumT& getY() const {
		return y;
	}

	/* Returns the Z component of this
	 * normal */
	inline const NumT& getZ() const {
		return z;
	}

	/* Sets the X component of this
	 * normal */
	inline void setX( const NumT& x ) {
		this->x = x;
	}

	/* Sets the Y component of this normal */
	inline void setY( const NumT& x ) {
		this->x = x;
	}

	/* Sets the Z component of this
	 * normal */
	inline void setZ( const NumT& x ) {
		this->x = x;
	}

	/* Copy the normal `normal` into this
	 * normal */
	inline const GloxNormal<NumT>& operator=( const GloxNormal<NumT>& normal ) {
		this->x = normal.x;
		this->y = normal.y;
		this->z = normal.z;

		return * this;
	}

	/* Add the components of `normal` to this */
	inline GloxNormal<NumT>& operator+=( const GloxNormal<NumT>& normal ) {
		this->x += normal.x;
		this->y += normal.y;
		this->z += normal.z;

		return * this;
	}

	/* Returns a new GloxNormal that is the sum
	 * of this and `normal` */
	inline GloxNormal<NumT> operator+( const GloxNormal<NumT>& normal ) const {
		GloxNormal<NumT> ret;
		ret += normal;
		return ret;
	}

	/* Plot this normal. This function depends on the
	 * number provided */
	inline void plot( ) const;
private:
	NumT x;
	NumT y;
	NumT z;
};

/* Implementations of the plot functions for
 * different template arguments */
template <>
inline void GloxNormal<int>::plot() const {
    glNormal3i( this->getX(), this->getY(), this->getZ() );
}
template <>
inline void GloxNormal<float>::plot() const {
    glNormal3f( this->getX(), this->getY(), this->getZ() );
}
template <>
inline void GloxNormal<short>::plot() const {
    glNormal3s( this->getX(), this->getY(), this->getZ() );
}
template <class T>
inline void GloxNormal<T>::plot() const {
    glNormal3d( this->getX(), this->getY(), this->getZ() );
}

}
#endif /* GLOXNORMAL_HPP_ */
