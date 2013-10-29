#ifndef GLOXTEXTUREREPEAT_HPP_
#define GLOXTEXTUREREPEAT_HPP_

/*
 * Author: jrahm
 * created: 2013/10/29
 * GloxTextureRepeat.hpp: <description>
 */

/* This class abstracts a teaxture that may repeat
 * several times */

#include "glox/GloxTexture.hpp"

namespace glox {

class GloxTextureRepeat {
public:
    inline GloxTextureRepeat( const GloxTexture* texture, float xreps=1.0f, float yreps=1.0 ):
        m_texture( texture ), m_xreps( xreps ), m_yreps( yreps ) {}

    inline const GloxTexture* getTexture() const {
        return m_texture ;
    }

    inline bool isNull() const {
        return m_texture == NULL;
    }

    inline float getXReps() const {
        return m_xreps;
    }

    inline float getYReps() const {
        return m_yreps;
    }

    inline void setYReps( float yreps)  {
        m_yreps = yreps;
    }

    inline void setXReps( float xreps )  {
        m_xreps = xreps;
    }
private:
    /* The texture this class
     * is repeating */
    const GloxTexture* m_texture;
    
    /* The number of times to repeat
     * this texture */
    float m_xreps;
    float m_yreps;
};

}


#endif /* GLOXTEXTUREREPEAT_HPP_ */
