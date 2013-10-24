#ifndef GLOXCYLINDER_HPP_
#define GLOXCYLINDER_HPP_

/*
 * Author: jrahm
 * created: 2013/10/24
 * GloxCylinder.hpp: <description>
 */

#include "glox/GloxObject.hpp"
#include "glox/GloxPointNormal.hpp"

#include "glox/GloxTexture.hpp"
#include "glox/GloxQuadStrip.hpp"

#include "glox/GloxScopedTranslation.hpp"
#include "glox/GloxColor.hpp"

#include "glox/GloxPoint.hpp"

namespace glox {

/* This is an example object that draws
 * a cylinder. This object supports lighting
 * and texturing */
class GloxCylinder : public GloxObject {
public:
    /* Creates a cylinder with the radius r and the height
     * h. th_res specifies the radial resolution of this
     * cylinder */
    GloxCylinder( const GloxPoint<float>& pos, float r, float h, float th_res=6 );

    /* Sets the texture to pin to this
     * cylinder */
    void setTexture( const GloxTexture* texture );

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
        /* Color of the tree without a texture */
        static const GloxColor brown( 139, 69, 19 );
        /* Translate to the position of
         * this object */
        GloxScopedTranslation t( m_position );

        /* Set the OpenGL state machine to
         * use brown as the color */
        brown.render();
        m_body.plot();
    }

private:
    /* The position of this cylinder */
    GloxPoint<float> m_position;
    
    /* the cylinder is basically just a quad
     * strip. This object supports lighting,
     * so the components are PointNormals */
    GloxQuadStrip< GloxPointNormal<> > m_body;
};

};

#endif /* GLOXCYLINDER_HPP_ */
