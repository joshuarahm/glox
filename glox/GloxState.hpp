#ifndef GLOXSTATE_HPP_
#define GLOXSTATE_HPP_

/*
 * Author: jrahm
 * created: 2013/10/24
 * GloxState.hpp: <description>
 */

#include "glox/GloxCommon.hpp"

namespace glox {

class GloxState {
public:
    inline static void pushMatrix() { glPushMatrix(); }
    inline static void popMatrix()  { glPopMatrix(); }

    template <class T>
    inline static void translate( const GloxPoint<T>& point ) ;

    inline static void matrixMode( GLenum val ) { glMatrixMode( val ) ; }
    inline static void loadIdentity() { glLoadIdentity(); }

    inline static void clear( GLbitfield val ) {
        glClear(val);
    }

    inline static void enable( GLenum e ) {
        glEnable( e );
    }

    inline static void flush() {
        glFlush();
    }

    inline static void lightModel( GLenum key, int val ) {
        glLightModeli( key, val );
    }

    inline static void colorMaterial( GLenum key, GLenum val ) {
        glColorMaterial(key,val);
    }

	inline static void rotate( double ang, double x, double y, double z ) {
		glRotated( ang, x, y, z );
	}
};

template <>
/* Floats are a special case, so translate to
 * them like normal */
inline void GloxState::translate( const GloxPoint<float>& point ) {
    glTranslatef( point.getX(), point.getY(), point.getZ() );
}

template <class T>
/* Everything else should be implicity cast
 * to a double and send to glTranslated */
inline void GloxState::translate( const GloxPoint<T>& point ) {
    glTranslated( point.getX(), point.getY(), point.getZ() );
}

}

#endif /* GLOXSTATE_HPP_ */
