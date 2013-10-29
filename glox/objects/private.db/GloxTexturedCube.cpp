#include "glox/objects/GloxTexturedCube.hpp"
#include "glox/GloxScopedBegin.hpp"

namespace glox {

void GloxTexturedCube::update_top() {
    m_top.clear();

    GloxNormal<> normal( 0, 1, 0 );

    /* The points for the top */
    m_top.add( GloxPointNormalTexture( GloxPoint<>(-m_half, m_half,-m_half),
        normal, GloxPoint<>(0,0)) );

    m_top.add( GloxPointNormalTexture( GloxPoint<>( m_half, m_half,-m_half),
        normal, GloxPoint<>(m_top_tex.getXReps(),0)) );

    m_top.add( GloxPointNormalTexture( GloxPoint<>( m_half, m_half, m_half),
        normal, GloxPoint<>(m_top_tex.getXReps(),m_top_tex.getYReps())) );

    m_top.add( GloxPointNormalTexture( GloxPoint<>(-m_half, m_half, m_half),
        normal, GloxPoint<>(0,m_top_tex.getYReps())) );
}

void GloxTexturedCube::update_bottom() {
    m_bottom.clear();

    GloxNormal<> normal( 0, -1, 0 );

    /* The points for the top */
    m_bottom.add( GloxPointNormalTexture( GloxPoint<>(-m_half,-m_half, m_half),
        normal, GloxPoint<>(0,0)) );

    m_bottom.add( GloxPointNormalTexture( GloxPoint<>( m_half,-m_half, m_half),
        normal, GloxPoint<>(m_bottom_tex.getXReps(),0)) );

    m_bottom.add( GloxPointNormalTexture( GloxPoint<>( m_half,-m_half,-m_half),
        normal, GloxPoint<>(m_bottom_tex.getXReps(),m_bottom_tex.getYReps())) );

    m_bottom.add( GloxPointNormalTexture( GloxPoint<>(-m_half,-m_half,-m_half),
        normal, GloxPoint<>(0,m_bottom_tex.getYReps())) );
}

void GloxTexturedCube::update_front() {
    m_front.clear();

    GloxNormal<> normal( 0, 0, 1 );

    /* The points for the top */
    m_front.add( GloxPointNormalTexture( GloxPoint<>(-m_half, m_half, m_half),
        normal, GloxPoint<>(0,0)) );

    m_front.add( GloxPointNormalTexture( GloxPoint<>( m_half, m_half, m_half),
        normal, GloxPoint<>(m_front_tex.getXReps(),0)) );

    m_front.add( GloxPointNormalTexture( GloxPoint<>( m_half,-m_half, m_half),
        normal, GloxPoint<>(m_front_tex.getXReps(),m_front_tex.getYReps())) );

    m_front.add( GloxPointNormalTexture( GloxPoint<>(-m_half,-m_half, m_half),
        normal, GloxPoint<>(0,m_front_tex.getYReps())) );
}

void GloxTexturedCube::update_back() {
    m_back.clear();

    GloxNormal<> normal( 0, 0, -1 );

    /* The points for the back */
    m_back.add( GloxPointNormalTexture( GloxPoint<>(-m_half, m_half,-m_half),
        normal, GloxPoint<>(0,0)) );

    m_back.add( GloxPointNormalTexture( GloxPoint<>( m_half, m_half,-m_half),
        normal, GloxPoint<>(m_back_tex.getXReps(),0)) );

    m_back.add( GloxPointNormalTexture( GloxPoint<>( m_half,-m_half,-m_half),
        normal, GloxPoint<>(m_back_tex.getXReps(),m_front_tex.getYReps())) );

    m_back.add( GloxPointNormalTexture( GloxPoint<>(-m_half,-m_half,-m_half),
        normal, GloxPoint<>(0,m_back_tex.getYReps())) );
}

void GloxTexturedCube::update_right() {
    m_right.clear();

    GloxNormal<> normal( 1, 0, 0 );

    /* The points for the right */
    m_right.add( GloxPointNormalTexture( GloxPoint<>( m_half,-m_half, m_half),
        normal, GloxPoint<>(0,0)) );

    m_right.add( GloxPointNormalTexture( GloxPoint<>( m_half, m_half, m_half),
        normal, GloxPoint<>(m_right_tex.getXReps(),0)) );

    m_right.add( GloxPointNormalTexture( GloxPoint<>( m_half, m_half,-m_half),
        normal, GloxPoint<>(m_right_tex.getXReps(),m_front_tex.getYReps())) );

    m_right.add( GloxPointNormalTexture( GloxPoint<>( m_half,-m_half,-m_half),
        normal, GloxPoint<>(0,m_right_tex.getYReps())) );
}

void GloxTexturedCube::update_left() {
    m_left.clear();

    GloxNormal<> normal( -1, 0, 0 );

    /* The points for the left */
    m_left.add( GloxPointNormalTexture( GloxPoint<>(-m_half,-m_half, m_half),
        normal, GloxPoint<>(0,0)) );

    m_left.add( GloxPointNormalTexture( GloxPoint<>(-m_half, m_half, m_half),
        normal, GloxPoint<>(m_left_tex.getXReps(),0)) );

    m_left.add( GloxPointNormalTexture( GloxPoint<>(-m_half, m_half,-m_half),
        normal, GloxPoint<>(m_left_tex.getXReps(),m_front_tex.getYReps())) );

    m_left.add( GloxPointNormalTexture( GloxPoint<>(-m_half,-m_half,-m_half),
        normal, GloxPoint<>(0,m_left_tex.getYReps())) );
}

GloxTexturedCube::GloxTexturedCube( float size, const GloxColor& color,
    const GloxTextureRepeat& topTex ,
    const GloxTextureRepeat& botTex ,
    const GloxTextureRepeat& frontTex ,
    const GloxTextureRepeat& backTex  ,
    const GloxTextureRepeat& leftTex  ,
    const GloxTextureRepeat& rightTex ) :
    
    m_top_tex( topTex ) , m_bottom_tex( botTex ), m_front_tex( frontTex ),
    m_back_tex( backTex ), m_left_tex( leftTex ), m_right_tex( rightTex ),
    m_color( color ) {
    m_half = size / 2;

    update_top();
    update_bottom();
    update_front();
    update_back();
    update_left();
    update_right();
}

inline void GloxTexturedCube::plot_with( const _M_Square& face, const GloxTextureRepeat& tex ) const {
     if( tex.isNull() ) {
        glDisable( GL_TEXTURE_2D );
    } else {
        tex.getTexture()->bind();
        glEnable( GL_TEXTURE_2D );
    }

    glBegin( GL_QUADS );
    face.plot();
    glEnd();

    glDisable( GL_TEXTURE_2D );
}

void GloxTexturedCube::draw() const {
    /* Save current attributes for this scope */
    GloxScopedAttributes __sca( GL_CURRENT_BIT );
    //GloxScopedBegin __sbgn( GL_QUADS );

    /* The normal to use for plotting */
    GloxNormal<> normal(0,0,0);

    /* Render this color */
    m_color.render();

    plot_with(m_right, m_right_tex);
    plot_with(m_left, m_left_tex);
    plot_with(m_top, m_top_tex);
    plot_with(m_bottom, m_bottom_tex);
    plot_with(m_front, m_front_tex);
    plot_with(m_back, m_back_tex);
}

}
