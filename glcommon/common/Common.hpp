#ifndef GRAPHICSCOMMON_HPP_
#define GRAPHICSCOMMON_HPP_

/*
 * Author: jrahm
 * created: 2013/10/03
 * GraphicsCommon.hpp: <description>
 */

#include <math.h>
#include <inttypes.h>

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cstdio>

/* use degrees instead of radians */
#define dcos(th) cos(3.1415927/180*(th))
#define dsin(th) sin(3.1415927/180*(th))

/* Include the header file that contains specific
 * headers for different types of glVertex */
#include "Point3D.hpp"

/* Include a class for color */
#include "Color.hpp"

/* Include the base class for all objects */
#include "Object3D.hpp"

/*
 * standard namespace for
 * graphics */
namespace graphics {

inline void setLightPosition( const Point3& point ) {
    /* Create a vector from the point */
    float vec[] = {(float)point.getX(),(float)point.getY(),(float)point.getZ(), 1.0};

    /* set the light position to that point */
    glLightfv(GL_LIGHT0,GL_POSITION,vec);
}

inline Color getCurrentColor( ) {
    float currentColor[4];
    glGetFloatv(GL_CURRENT_COLOR,currentColor);
    return Color( currentColor[0], currentColor[1], currentColor[2] );
}

template <class NumType>
/* This structure must have been overlooked,
 * It is a point paired with it's normal. This
 * is what I use for objects that are NOT spherical!
 */
struct PointNormal {
    /* Create the PointNormal from a Point and its
     * Normal. */
    inline PointNormal( const Point3D<NumType>& point,
        const Vector3D<NumType>& normal ) :
        point( point ), normal( normal ) {}

    /* The point and the normal */
    Point3D<NumType> point;
    Vector3D<NumType> normal;

    /* Call glNormal for the normal and
     * glVertex for the point. THIS is a
     * convience function! */
    inline void glVertexNormal( ) {
        normal.glNormal();
        point.glVertex();
    }
};

typedef PointNormal<double> PointNormalD;

struct Translation {
    inline Translation( double rotx=0,
        double roty=0, double rotz=0, double ang=0,
        double dx=0, double dy=0, double dz=0 ) :

    rotx( rotx ), roty( roty ),rotz( rotz ),
    ang( ang ), dx(dx), dy(dy), dz(dz) {}

    inline void glTranslate( ) {
        glTranslated( dx, dy, dz );
        glRotated( rotx, roty, rotz, ang );
    }

    inline void print() {
        printf("rotx = %f\n", rotx);
        printf("roty = %f\n", roty);
        printf("rotz = %f\n", rotz);
        printf("ang = %f\n", ang);
    
        printf("dx = %f\n", dx);
        printf("dy = %f\n", dy);
        printf("dz = %f\n", dz);
    }

    double rotx;
    double roty;
    double rotz;
    double ang;

    double dx;
    double dy;
    double dz;
};

}
#endif /* GRAPHICSCOMMON_HPP_ */
