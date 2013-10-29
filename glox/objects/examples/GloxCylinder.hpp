#ifndef GLOXCYLINDER_HPP_
#define GLOXCYLINDER_HPP_

/*
 * Author: jrahm
 * created: 2013/10/24
 * GloxCylinder.hpp: <description>
 */

#include "glox/GloxObject.hpp"
#include "glox/GloxPointNormalTexture.hpp"

#include "glox/GloxTexture.hpp"
#include "glox/GloxQuadStrip.hpp"

#include "glox/GloxScopedTranslation.hpp"
#include "glox/GloxColor.hpp"

#include "glox/GloxPoint.hpp"

#ifndef COMPILING_CYLINDER
#warn "Do Not Use This Class, it is broken!"
#endif

namespace glox {

/* This is an example object that draws
 * a cylinder. This object supports lighting
 * and texturing */
class GloxCylinder : public GloxObject {
public:
    /* Creates a cylinder with the radius r and the height
     * h. th_res specifies the radial resolution of this
     * cylinder */
    GloxCylinder( const GloxPoint<float>& pos, float r, float h,
        float th_res=6, const GloxTexture* texture=NULL, bool normals=true, float rep=1, float repy=1 );

    /* Get the position of this
     * Cylinder */
    inline const GloxPoint<float>& getPosition() const {
        return m_position;
    }

    /* Sets the position of this Cylinder */
    inline void setPosition( const GloxPoint<float>& new_pos ) {
        m_position = new_pos;
    }

    inline void draw() const {
        if( m_texture ) {
            glEnable(GL_TEXTURE_2D);
            m_texture->bind();
        } else {
            glDisable(GL_TEXTURE_2D);
        }
        /* Color of the tree without a texture */
        static const GloxColor brown( 139, 69, 19 );
        /* Translate to the position of
         * this object */
        GloxScopedTranslation trans( m_position );

        /* Set the OpenGL state machine to
         * use brown as the color */
        m_body.plot();
        glDisable(GL_TEXTURE_2D);
    }

private:
    /* The position of this cylinder */
    GloxPoint<float> m_position;
    
    /* the cylinder is basically just a quad
     * strip. This object supports lighting,
     * so the components are PointNormals */
    GloxQuadStrip< GloxPointNormalTexture > m_body;

    /* the texture used for ths cylinder */
    const GloxTexture* m_texture;
};

};

#endif /* GLOXCYLINDER_HPP_ */
