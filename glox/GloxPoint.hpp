#ifndef GLOXPOINT_HPP_
#define GLOXPOINT_HPP_

/*
 * Author: jrahm
 * created: 2013/10/22
 * GloxPoint.hpp: <description>
 */

#include "glox/GloxCommon.hpp"
#include "glox/GloxPlottable.hpp"

namespace glox {

/* Type that the GloxPoint holds,
 * defaults to an integer */
template <class NumT=int>

/* A point in 3D space. This class
 * implements Plottable which provides
 * the `plot` function which calles
 * glVertex on the components */
class GloxPoint : public Plottable {
public:
	/* Creates a new GloxPoint from the components
	 * specified */
	inline GloxPoint( const NumT& x=0, const NumT& y=0, const NumT& z=0 ):
		x(x), y(y), z(z) {}

	/* Copies the glox point other */
	inline GloxPoint( const GloxPoint<NumT>& other ) :
		x(other.x), y(other.y), z(other.z) {}

	/* Returns the X componet of this
	 * point */
	inline const NumT& getX() const {
		return x;
	}

	/* Returns the Y component of this
	 * point */
	inline const NumT& getY() const {
		return y;
	}

	/* Returns the Z component of this
	 * point */
	inline const NumT& getZ() const {
		return z;
	}

	/* Sets the X component of this
	 * point */
	inline void setX( const NumT& x ) {
		this->x = x;
	}

	/* Sets the Y component of this point */
	inline void setY( const NumT& x ) {
		this->x = x;
	}

	/* Sets the Z component of this
	 * point */
	inline void setZ( const NumT& x ) {
		this->x = x;
	}

	/* Copy the point `point` into this
	 * point */
	inline const GloxPoint<NumT>& operator=( const GloxPoint<NumT>& point ) {
		this->x = point.x;
		this->y = point.y;
		this->z = point.z;

		return * this;
	}

	/* Add the components of `point` to this */
	inline GloxPoint<NumT>& operator+=( const GloxPoint<NumT>& point ) {
		this->x += point.x;
		this->y += point.y;
		this->z += point.z;

		return * this;
	}

	/* Returns a new GloxPoint that is the sum
	 * of this and `point` */
	inline GloxPoint<NumT> operator+( const GloxPoint<NumT>& point ) const {
		GloxPoint<NumT> ret;
		ret += point;
		return ret;
	}

	/* Plot this point. This function depends on the
	 * number provided */
	inline void plot( );
private:
	NumT x;
	NumT y;
	NumT z;
};

/* Implementations of the plot functions for
 * different template arguments */
template <>
inline void GloxPoint<int>::plot() {
    glVertex3i( this->getX(), this->getY(), this->getZ() );
}
template <>
inline void GloxPoint<float>::plot() {
    glVertex3f( this->getX(), this->getY(), this->getZ() );
}
template <>
inline void GloxPoint<short>::plot() {
    glVertex3s( this->getX(), this->getY(), this->getZ() );
}
template <class T>
inline void GloxPoint<T>::plot() {
    glVertex3d( this->getX(), this->getY(), this->getZ() );
}

}

#endif /* GLOXPOINT_HPP_ */
