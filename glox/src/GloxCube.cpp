#include "glox/objects/GloxCube.hpp"
#include "glox/GloxScopedBegin.hpp"

namespace glox {

GloxCube::GloxCube( float x, float y, float z, const GloxColor& color ) :
    m_color( color ) {
    float halfx = x / 2;
    float halfy = y / 2;
    float halfz = z / 2;

    m_disp_list = glGenLists( 1 );
    GloxNormal<> normal(0,0,0);
    glNewList( m_disp_list, GL_COMPILE );
    /* The points for the top */
    normal.setY( 1 );
    normal.plot();
    GloxPoint<> ( -halfx, halfy, halfz ).plot();
    GloxPoint<> (  halfx, halfy, halfz ).plot();
    GloxPoint<> (  halfx, halfy,-halfz ).plot();
    GloxPoint<> ( -halfx, halfy,-halfz ).plot();

    /* The points for the bottom */
    normal.setY( -1 );
    normal.plot();
    GloxPoint<> ( -halfx,-halfy, halfz ).plot();
    GloxPoint<> (  halfx,-halfy, halfz ).plot();
    GloxPoint<> (  halfx,-halfy,-halfz ).plot();
    GloxPoint<> ( -halfx,-halfy,-halfz ).plot();
    normal.setY( 0 ) ;
    
    /* The points for the front */
    normal.setZ( 1 );
    normal.plot();
    GloxPoint<> ( -halfx, halfy, halfz ).plot();
    GloxPoint<> (  halfx, halfy, halfz ).plot();
    GloxPoint<> (  halfx,-halfy, halfz ).plot();
    GloxPoint<> ( -halfx,-halfy, halfz ).plot();

    /* The points for the back */
    normal.setZ( -1 );
    normal.plot();
    GloxPoint<> ( -halfx, halfy,-halfz ).plot();
    GloxPoint<> (  halfx, halfy,-halfz ).plot();
    GloxPoint<> (  halfx,-halfy,-halfz ).plot();
    GloxPoint<> ( -halfx,-halfy,-halfz ).plot();
    normal.setZ( 0 );
    
    /* The points for the right */
    normal.setX( 1 );
    normal.plot();
    GloxPoint<> ( halfx, -halfy, halfz ).plot();
    GloxPoint<> ( halfx,  halfy, halfz ).plot();
    GloxPoint<> ( halfx,  halfy,-halfz ).plot();
    GloxPoint<> ( halfx, -halfy,-halfz ).plot();

    /* The points for the right */
    normal.setX( -1 );
    normal.plot();
    GloxPoint<> ( -halfx, -halfy, halfz ).plot();
    GloxPoint<> ( -halfx,  halfy, halfz ).plot();
    GloxPoint<> ( -halfx,  halfy,-halfz ).plot();
    GloxPoint<> ( -halfx, -halfy,-halfz ).plot();

    glEndList();
}

void GloxCube::draw() const {
    /* Save current attributes for this scope */
    GloxScopedAttributes __sca( GL_CURRENT_BIT );
    GloxScopedBegin __sbgn( GL_QUADS );

    /* The normal to use for plotting */
    GloxNormal<> normal(0,0,0);

    /* Render this color */
    m_color.render();

    glCallList( m_disp_list );
}

}
