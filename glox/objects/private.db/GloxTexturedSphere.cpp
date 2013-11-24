#include "glox/objects/GloxTexturedSphere.hpp"
#include "glox/GloxCommon.hpp"
#include "glox/GloxPoint.hpp"
#include "glox/GloxNormal.hpp"
#include "glox/GloxPointNormalTexture.hpp"
#include "glox/GloxScopedAttributes.hpp"

namespace glox {

static void m_vertex( float th, float ph ) {
    GloxPoint<> point = GloxPoint<>::fromSpherical( 1, th, ph );
    GloxNormal<> normal( point.getX(), point.getY(), point.getZ() );
    GloxPoint<> texPoint( th/360.0, ph/180.0 + 0.5 );
    
    GloxPointNormalTexture( point, normal, texPoint ).plot();
}

GloxTexturedSphere::GloxTexturedSphere( float radius, float res, const GloxTexture& texture ) {
    m_radius = radius;
    m_texture = texture;
    
    /* Generate the display list */
    m_disp_list = glGenLists( 1 );
    glNewList( m_disp_list, GL_COMPILE );

    float ph, th;
    for ( ph = -90 ; ph < 90 ; ph += res ) {
        GloxWith( GL_QUAD_STRIP, 
            for ( th = 0 ; th <= 360 ; th += res ) {
                m_vertex(th,ph);
                m_vertex(th,ph+res);
            }
        );
    }

    glEndList();
}

void GloxTexturedSphere::draw() const {
    glPushMatrix();
    GloxEnableFor( GL_TEXTURE_2D, 
        glScalef( m_radius, m_radius, m_radius );
        /* Bind the texture */
        m_texture.bind();

        /* Call the display list */
        glCallList( m_disp_list );
    );
    glPopMatrix();
}

}
