#include "glox/GloxCommon.hpp"
#include "glox/GloxFirstPersonPerspective.hpp"
#include "glox/GloxState.hpp"
#include "glox/GloxDebug.hpp"

#include <GL/glu.h>

namespace glox {

void GloxFirstPersonPerspective::render() const {
    /* The point we are going to look at in first
     * person mode */
    GloxPoint<> lookat = GloxPoint<>::fromSpherical( 1.0f, m_yaw, m_pitch );

    /* translate the lookat to this
     * position */
    const GloxPoint<>& pos = this->getPosition();
    GloxPoint<> upvec = GloxPoint<>::fromSpherical( 1.0f, GloxSin(m_roll) * m_yaw, GloxCos(m_roll) * m_pitch + 90 );
    lookat += pos;

    GloxTrace( "GloxFirstPersonPerspective", "gluLookAt %s %s %s\n", pos.toString().c_str(), lookat.toString().c_str(), upvec.toString().c_str() ); 
    GloxTrace( "GloxFirstPersonPerspective", "(%f, %f, %f)\n", m_roll, m_pitch, m_yaw ); 
    /* Deal with roll */

    gluLookAt( pos.getX(), pos.getY(), pos.getZ(),
               lookat.getX(), lookat.getY(), lookat.getZ(),
               0, 1, 0 );

}

}
