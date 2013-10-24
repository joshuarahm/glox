#include "glox/objects/examples/GloxCylinder.hpp"

namespace glox {

GloxCylinder::GloxCylinder( const GloxPoint<float>& pos, float r, float h, float th_res ) :
    m_position( pos ) {
    float th = 0;

    GloxPoint<> point;
    GloxNormal<> normal;

    for( ; th <= 360; th += th_res ) {
        point.setX( r * GloxCos( th ) );
        point.setZ( r * GloxSin( th ) );
        point.setY( 0 );

        normal.setX( point.getX() );
        normal.setY( 0 );
        normal.setZ( point.getZ() );

        /* Add the new PointNormal to the
         * body */
        m_body.addPoint( GloxPointNormal<>( point, normal ) );

        /* The upper portion of the
         * cylinder */
        point.setX( r * GloxCos( th ) );
        point.setZ( r * GloxSin( th ) );
        point.setY( h );

        // The normal remains the same

        m_body.addPoint( GloxPointNormal<>( point, normal ) );
    }
}

}
