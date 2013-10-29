#include "glox/objects/GloxCube.hpp"
#include "glox/GloxScopedBegin.hpp"

namespace glox {

GloxCube::GloxCube( float size, const GloxColor& color ) :
    m_color( color ) {
    float half = size / 2;

    /* The points for the top */
    m_top.add( GloxPoint<> ( -half, half, half ) );
    m_top.add( GloxPoint<> (  half, half, half ) );
    m_top.add( GloxPoint<> (  half, half,-half ) );
    m_top.add( GloxPoint<> ( -half, half,-half ) );

    /* The points for the bottom */
    m_bottom.add( GloxPoint<> ( -half,-half, half ) );
    m_bottom.add( GloxPoint<> (  half,-half, half ) );
    m_bottom.add( GloxPoint<> (  half,-half,-half ) );
    m_bottom.add( GloxPoint<> ( -half,-half,-half ) );
    
    /* The points for the front */
    m_front.add( GloxPoint<> ( -half, half, half ) );
    m_front.add( GloxPoint<> (  half, half, half ) );
    m_front.add( GloxPoint<> (  half,-half, half ) );
    m_front.add( GloxPoint<> ( -half,-half, half ) );

    /* The points for the back */
    m_back.add( GloxPoint<> ( -half, half,-half ) );
    m_back.add( GloxPoint<> (  half, half,-half ) );
    m_back.add( GloxPoint<> (  half,-half,-half ) );
    m_back.add( GloxPoint<> ( -half,-half,-half ) );
    
    /* The points for the right */
    m_right.add( GloxPoint<> ( half, -half, half ) );
    m_right.add( GloxPoint<> ( half,  half, half ) );
    m_right.add( GloxPoint<> ( half,  half,-half ) );
    m_right.add( GloxPoint<> ( half, -half,-half ) );

    /* The points for the right */
    m_left.add( GloxPoint<> ( -half, -half, half ) );
    m_left.add( GloxPoint<> ( -half,  half, half ) );
    m_left.add( GloxPoint<> ( -half,  half,-half ) );
    m_left.add( GloxPoint<> ( -half, -half,-half ) );
}

void GloxCube::draw() const {
    /* Save current attributes for this scope */
    GloxScopedAttributes __sca( GL_CURRENT_BIT );
    GloxScopedBegin __sbgn( GL_QUADS );

    /* The normal to use for plotting */
    GloxNormal<> normal(0,0,0);

    /* Render this color */
    m_color.render();

    normal.setY( 1 );
    normal.plot();
    m_top.plot();

    normal.setY( -1 );
    normal.plot();
    m_bottom.plot();
    normal.setY( 0 );

    normal.setZ( 1 );
    normal.plot();
    m_front.plot();

    normal.setZ( -1 );
    normal.plot();
    m_back.plot();
    normal.setZ( 0 );
     
    normal.setX( 1 );
    normal.plot();
    m_right.plot();

    normal.setX( -1 );
    normal.plot();
    m_left.plot();
}

}
