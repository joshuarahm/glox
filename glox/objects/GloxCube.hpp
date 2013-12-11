#ifndef GLOXCUBE_HPP_
#define GLOXCUBE_HPP_

/*
 * Author: jrahm
 * created: 2013/10/28
 * GloxCube.hpp: This header contains the header for a cube class.
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

namespace glox {

class GloxCube : public GloxObject {
public:
    /* Creates a new cube with the size
     * `size`. The size is the length of
     * each side of the cube */
    GloxCube( float x, float y, float z, const GloxColor& color );

	inline GloxCube( const GloxCube& other ) {
		m_disp_list = other.m_disp_list ;
		m_color = other.m_color;
	}

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
    
private:
    int m_disp_list ;
    /* The color of this cube */
    GloxColor m_color;
};

}

#endif /* GLOXCUBE_HPP_ */

