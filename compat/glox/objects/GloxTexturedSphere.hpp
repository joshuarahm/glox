#ifndef GLOXTEXTUREDSPHERE_HPP_
#define GLOXTEXTUREDSPHERE_HPP_

/*
 * Author: jrahm
 * created: 2013/11/07
 * GloxTexturedSphere.hpp: <description>
 */

#include "glox/GloxTexture.hpp"
#include "glox/GloxObject.hpp"

namespace glox {

/* A sphere that has a texture mapped to it.
 * The texture is mapped using a mercader projection
 */
class GloxTexturedSphere : public GloxObject {
public:
    /* Create a new GloxTexturedSphere 
     * radius: the radius of the sphere
     * res: the resolution of the sphere. Should
     * be a factor of 360
     * */
    GloxTexturedSphere( float radius, float res, const GloxTexture& texture );

    /* Draw this sphere */
    void draw() const;

    /* Returns teh radius of the sphere */
    inline float getRadius() const { return m_radius; }

    /* Set the radius of this sphere */
    inline void setRadius( float radius ) { m_radius = radius; }

    /* Returns the texture */
    inline const GloxTexture& getTexture() const { return m_texture; }

private:
    /* The texture of the sphere */
    GloxTexture m_texture;

    /* The radius */
    float m_radius;
    
    /* The display list of this sphere */
    int m_disp_list;
};

}

#endif /* GLOXTEXTUREDSPHERE_HPP_ */
