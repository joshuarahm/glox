#ifndef POINT3D_HPP_
#define POINT3D_HPP_

/* Include the base interface for
 * the Point class */
#include "glox/Plottable.hpp"

#warn "Deprecated: use glox.GloxPoint instead"

namespace graphics {

/* The type of the number this point
 * uses. The default value is double
 */
template <class NumType=double>

/* class that represents a point in OpenGL. Comes bundled
 * with some useful wrappers for OpenGL. THIS IS ONLY
 * a wapper class, VERY little logic exists here */
class Point3D {
public:
    /* Create a new Point with the three variables */
    inline Point3D( NumType x, NumType y, NumType z ) :
        x( x ), y( y ), z( z ) {}

    /* Creates a new point that is a copy of
     * the given point */
    inline Point3D( const Point3D<NumType>& point ) :
        x( point.x ), y( point.y ), z( point.z ) {}

    /* Creates a new point set to the origin */
    inline Point3D( ) :
        x(0),y(0),z(0) {}

    /* Copies another point */
    inline Point3D operator=( const Point3D<NumType>& point ) {
        this->x = point.x;
        this->y = point.y;
        this->z = point.z;

        return * this;
    }

    /* Returns the components of this
     * point */
    inline NumType getX() const { return x ; }
    inline NumType getY() const { return y ; }
    inline NumType getZ() const { return z ; }

    /* add two points together. Returns a new point
     * with the components added to eachother */;
    inline Point3D<NumType> operator+( const Point3D<NumType>& other ) const {
        return Point3D<NumType>( other.x + x, other.y + y, other.z + z );
    }

    /* Adds a point to itself */
    inline Point3D<NumType> operator+=( const Point3D<NumType>& other ) {
        /* add the componets */
        x += other.x;
        y += other.y;
        z += other.z;

        /* return this for chaining */
        return * this;
    }
    
    /* Implements a PointType plot() function.
     * This simply calls glVertex() on the components
     * of the point */
    inline void plot();

    inline void setZ( NumType z ) {
        this->z = z ;
    }

    inline void setY( NumType y ) {
        this->y = y ;
    }

    inline void setX( NumType x ) {
        this->x = x ;
    }

private:
    NumType x;
    NumType y;
    NumType z;
};

/* The type this vector is measured in */
template <class NumType>

/* Fine, I'll be a little more explicit about
 * the difference between a point and a vector! THIS
 * IS ONLY A WRAPPER TO GLNORMAL()*/
class Vector3D : public Point3D<NumType> {
public:

    /* A vector IS a point */
    inline Vector3D() :
        Point3D<NumType>() {};

    inline Vector3D( const Point3D<NumType>& point ) :
        Point3D<NumType>( point ) {}

    inline Vector3D( NumType x, NumType y, NumType z ) :
        Point3D<NumType>(x,y,z) {};

    /* Calls GL normal on this vector */
    inline void glNormal();
};

/* Point3D<double> is a pain to type oall
 * the time */
typedef Point3D<double> Point3;

/* SIMPLY call glVertex using the values in this
 * point. THIS is a convienience function */
template <>
inline void Point3D<int>::glVertex() {
    glVertex3i( this->getX(), this->getY(), this->getZ() );
}

template <>
inline void Point3D<float>::glVertex() {
    glVertex3f( this->getX(), this->getY(), this->getZ() );
}

template <>
inline void Point3D<short>::glVertex() {
    glVertex3s( this->getX(), this->getY(), this->getZ() );
}

template <class T>
inline void Point3D<T>::glVertex() {
    glVertex3d( this->getX(), this->getY(), this->getZ() );
}
template <>
inline void Vector3D<int>::glNormal() {
    glNormal3i( this->getX(), this->getY(), this->getZ() );
}

template <>
/* This function implies NOTHING about the structure
 * of the object attempting to normalize. THESE functions
 * simply are wrappers for glNormal to make it less painful
 * to use! */
inline void Vector3D<float>::glNormal() {
    glNormal3f( this->getX(), this->getY(), this->getZ() );
}

template <>
inline void Vector3D<short>::glNormal() {
    glNormal3s( this->getX(), this->getY(), this->getZ() );
}

template <class T>
inline void Vector3D<T>::glNormal() {
    glNormal3d( this->getX(), this->getY(), this->getZ() );
}

}

#endif
