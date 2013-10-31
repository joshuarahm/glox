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
    GloxTexture( unsigned int id=0 ) :
        m_id( id ) {}

    unsigned int getId() const { return m_id ; }
    void bind() const { glBindTexture( GL_TEXTURE_2D, m_id ) ; }

    void setId( unsigned int id ) { m_id = id; } 
private:
    unsigned int m_id;
};

}

#endif /* GLOXTEXTURE_HPP_ */
