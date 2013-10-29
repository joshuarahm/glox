#include "glox/objects/examples/GloxCylinder.hpp"
#include "glox/GloxDebug.hpp"

namespace glox {

GloxCylinder::GloxCylinder( const GloxPoint<float>& pos, float r, float h, float th_res, const GloxTexture* texture, bool normals, float rep, float repy ) :
    m_position( pos ) {
    float th = 0;
    m_texture = texture;

    GloxPoint<> point;
    GloxNormal<> normal;
    GloxPoint<> texPoint;

    float texStep;

    /* The position in the texture */
    float texPos = 0;

    if( m_texture ) {
        /* We want the texture to map exactly
         * to the sphere */
        texStep = th_res / 360 * rep;
    }

    for( ; th <= 360; th += th_res, texPos += texStep ) {
        point.setX( r * GloxCos( th ) );
        point.setZ( r * GloxSin( th ) );
        point.setY( 0 );

		if( normals ) {
        	normal.setX( point.getX() );
        	normal.setY( 0 );
        	normal.setZ( point.getZ() );
		}

        texPoint.setX( texPos );
        texPoint.setY( repy );
        texPoint.setZ( 0 );

        /* Add the new PointNormal to the
         * body */
        m_body.addPoint( GloxPointNormalTexture( point, normal, texPoint ) );

        /* The upper portion of the
         * cylinder */
        point.setY( h );
		texPoint.setY( 0 );

        // The normal remains the same
        m_body.addPoint( GloxPointNormalTexture( point, normal, texPoint ) );
    }
}

}
