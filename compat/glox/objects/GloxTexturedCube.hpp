#ifndef GLOXTEXTUREDCUBE_HPP_
#define GLOXTEXTUREDCUBE_HPP_

/*
 * Author: jrahm
 * created: 2013/10/28
 * GloxTexturedCube.hpp: This header contains the header for a cube class.
 * This cube class does not have textures. For a textured cube, use
 * GloxTexturedCube in GloxTexturedCube.hpp
 */

#include "glox/GloxCommon.hpp"
#include "glox/GloxNormal.hpp"
#include "glox/GloxPoint.hpp"
#include "glox/GloxObject.hpp"
#include "glox/GloxColor.hpp"
#include "glox/GloxPointCollection.hpp"
#include "glox/GloxScopedAttributes.hpp"
#include "glox/GloxTextureRepeat.hpp"
#include "glox/GloxPointNormalTexture.hpp"
#include "glox/GloxDebug.hpp"

namespace glox {

class GloxTexturedCube : public GloxObject {
public:
    /* Creates a new cube with the size
     * `size`. The size is the length of
     * each side of the cube */
    GloxTexturedCube( float size, const GloxColor& color,
        const GloxTextureRepeat& topTex = GloxTextureRepeat(NULL),
        const GloxTextureRepeat& botTex = GloxTextureRepeat(NULL),
        const GloxTextureRepeat& frontTex = GloxTextureRepeat(NULL),
        const GloxTextureRepeat& backTex  = GloxTextureRepeat(NULL),
        const GloxTextureRepeat& leftTex  = GloxTextureRepeat(NULL),
        const GloxTextureRepeat& rightTex = GloxTextureRepeat(NULL) );

    /* Draw this cube */
    void draw() const ;

    /* Sets the color of this cube */
    inline void setColor( const GloxColor& color ) {
        m_color = color;
    }

    /* Returns the color of this cube */
    inline const GloxColor& getColor() const {
        return m_color;
    }

    inline void setTopTexture( const GloxTextureRepeat& top_tex ) {
        m_top_tex = top_tex;
        update_top();
    }

    inline void setBottomTexture( const GloxTextureRepeat& tex ) {
        m_bottom_tex = tex;
        update_bottom();
    }

    inline void setFrontTexture( const GloxTextureRepeat& tex ) {
        m_front_tex = tex;
        update_front();
    }

    inline void setBackTexture( const GloxTextureRepeat& tex ) {
        m_back_tex = tex;
        update_back();
    }

    inline void setRightTexture( const GloxTextureRepeat& tex ) {
        m_right_tex = tex;
        update_right();
    }
    
    inline void setLeftTexture( const GloxTextureRepeat& tex ) {
        m_left_tex = tex;
        update_left();
    }
    
private:
    void update_top();
    void update_bottom();
    void update_front();
    void update_back();
    void update_right();
    void update_left();

    /* A typedef to make my life easier */
    typedef GloxPointCollection< GloxPointNormalTexture > _M_Square;

    inline void plot_with( const _M_Square& face, const GloxTextureRepeat& tex ) const;

    /* +/- y axis */
    _M_Square m_top;
    _M_Square m_bottom;
    
    /* -/+ z axis */
    _M_Square m_front;
    _M_Square m_back;

    /* -/+ x axis */
    _M_Square m_left;
    _M_Square m_right;

    /* The textures for the various faces of
     * the cube */
    GloxTextureRepeat m_top_tex;
    GloxTextureRepeat m_bottom_tex;
    GloxTextureRepeat m_front_tex;
    GloxTextureRepeat m_back_tex;
    GloxTextureRepeat m_left_tex;
    GloxTextureRepeat m_right_tex;

    /* The color of this cube */
    GloxColor m_color;


    float m_half;
};

}

#endif /* GLOXTEXTUREDCUBE_HPP_ */

