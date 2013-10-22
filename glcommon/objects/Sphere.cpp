#include "Sphere.hpp"
#include <math.h>

#include <cstdio>

using namespace graphics;

/* conv_point must now return a vector3d */
/* Convert a point from spherical to euclidian
 * coordinates */
static Vector3D<double> conv_point( double th, double ph, float r ) {
    float dx = r*dsin(th)*dcos(ph);
    float dy = r*dsin(ph);
    float dz = r*dcos(th)*dcos(ph);
    return Vector3D<double>( dx, dy, dz );
}

#define INIT_COLOR Color(dcos(th)*dcos(th) , dsin(ph)*dsin(ph) , dsin(th)*dsin(th))

Sphere::Sphere( const Point3& pos, float radius, Color(*color_func)( int th, int ph ) ) : Object3D( pos ) {
    static const int inc = 6; /* ball increment */
    int th,ph;
    size_t i = 0;
    
    /* The number of points in the ball */
    pointsperband = (180 / inc) + 1;
    npoints = pointsperband * pointsperband * 2;
    this->points = new Vector3D<double>[npoints];
    if( color_func ) {
        this->colors = new Color[npoints];
    } else {
        this->colors = NULL;
    }

    /* Cache the points. */
    for( ph = - 90; ph < 90; ph += inc ) {
        for( th = 0; th <= 360 ; th += (inc<<1) ) {
            if(color_func) {
                colors[i] = color_func( th, ph );
            }
            points[i++] = conv_point( th, ph, radius );

            if(color_func) {
                colors[i] = color_func( th, ph );
            }
            points[i++] = conv_point( th, ph+inc, radius );
        }
    }

}

void Sphere::draw() {
    /* TODO break this into a defined varaible */
    static const int   emission    =  0;
    static const float shinyvec[1] = {0};

    size_t i;
    size_t j;

    glPushMatrix();
    glTranslated( position.getX(), position.getY(), position.getZ() );
    float yellow[] = {1.0,1.0,0.0,1.0};
    float Emission[]  = {0.0,0.0,0.01*emission,1.0};

    glMaterialfv(GL_FRONT,GL_SHININESS,shinyvec);
    glMaterialfv(GL_FRONT,GL_SPECULAR,yellow);
    glMaterialfv(GL_FRONT,GL_EMISSION,Emission);

    for( i = 0; i < this->npoints; ) {
        /* Point, Color, & vertex */
        glBegin(GL_QUAD_STRIP);
        for( j = 0; j < pointsperband; ++ j ) {
            plot_point( i ++ );
            plot_point( i ++ );
        }
        glEnd();
    }

    glEnd();

    glPopMatrix();
}
