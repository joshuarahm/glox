#ifndef GLOXCOMMON_HPP_
#define GLOXCOMMON_HPP_

#include <inttypes.h>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <cstdlib>

/* Include the OpenGL stuff */
#include <GL/gl.h>

/*
 * Author: jrahm
 * created: 2013/10/23
 * GloxCommon.hpp: <description>
 */

namespace glox {
    #define GloxWith( en, code ) \
        { glBegin( en ) ; \
            code  ;\
          glEnd(); }

    #define GloxEnableFor( en, code ) \
        { glEnable( en ) ; code ; glDisable( en ); }

    #define GloxDisableFor( en, code ) \
        { glDisable( en ) ; code ; glEnable( en ) ; }

    #define GloxWithTranslation( point, code ) \
        { \
            glox::GloxState::pushMatrix(); \
            glox::GloxState::translate( (point) ); \
            code; \
            glox::GloxState::popMatrix(); \
        }
    #define GloxScale( amt, code ) \
        { \
            glox::GloxState::pushMatrix(); \
            glScalef( amt,amt,amt ); \
            code; \
            glox::GloxState::popMatrix(); \
        }

    typedef long long Glox64;
    typedef unsigned long long Glox64u;
    typedef int Glox32;
    typedef unsigned int Glox32u;
    typedef unsigned char Glox8u;
    typedef signed char Glox8;
    typedef unsigned short Glox16u;
    typedef signed short Glox16;

    inline double GloxCos( double th ) {
        return cos(3.1415927/180*(th));
    }

    inline double GloxSin( double th ) {
        return sin(3.1415927/180*(th));
    }

};

#endif /* GLOXCOMMON_HPP_ */
