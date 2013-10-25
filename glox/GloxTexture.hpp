#ifndef GLOXTEXTURE_HPP_
#define GLOXTEXTURE_HPP_

/*
 * Author: jrahm
 * created: 2013/10/22
 * GloxTexture.hpp: <description>
 */

#include "glox/GloxCommon.hpp"

namespace glox {

class GloxTexture {
public:
    GloxTexture( int id, int width, int height ) :
        m_id( id ), m_width( width ), m_height( height ) {}

    int getId() const { return m_id ; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    void bind() const { glBindTexture( GL_TEXTURE_2D, m_id ) ; }
private:
    int m_id;
    int m_width;
    int m_height;
};

}

#endif /* GLOXTEXTURE_HPP_ */
