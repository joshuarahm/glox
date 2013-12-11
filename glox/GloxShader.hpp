#ifndef GLOXSHADER_HPP_
#define GLOXSHADER_HPP_

/*
 * Author: jrahm
 * created: 2013/12/09
 * GloxShader.hpp: <description>
 */


#include "glox/GloxCommon.hpp"
#include <string>

namespace glox {

class GloxShader {
public:
    inline GloxShader( GLenum type ) {
        this->type = type ; 
    }

    static inline const std::string& getMessage() {
        return message ;
    }

    inline GLenum getType() const {
        return type ;
    }

    inline unsigned int getId() const {
        return m_shader ;
    }

    int load( const char* filename ) ;

    ~GloxShader() ;
private:
    unsigned int m_shader ;
    GLenum type ;

    static int readFile( const char* filename, std::string& into ) ;
    static std::string message ;
} ;

}

#endif /* GLOXSHADER_HPP_ */
