#ifndef SPHERE_HPP_
#define SPHERE_HPP_

/*
 * Author: jrahm
 * created: 2013/10/03
 * Sphere.hpp: <description>
 */

#include "glox/common/Common.hpp"

#include <cstdlib>

namespace graphics {

class Sphere : public Object3D {
public:
    Sphere( const Point3& point=Point3(0,0,0), float radius=1, Color(*color_func)( int th, int ph )=NULL );

    void draw( ) ;
private:
    inline void plot_point( size_t idx ) {
        if( colors ) {
            colors[idx].glColor();
        }
        points[idx].glVertex();
        points[idx].glNormal();
    }

    /* Originally this was just an array of points,
     * but since the glNormal has been broken out
     * this now has to be renamed */
    Vector3D<double>* points;
    Color * colors;
    size_t npoints;
    size_t pointsperband;
};

}

#endif /* SPHERE_HPP_ */
