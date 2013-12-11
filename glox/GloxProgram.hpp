#ifndef GLOXPROGRAM_HPP_
#define GLOXPROGRAM_HPP_

/*
 * Author: jrahm
 * created: 2013/12/09
 * GloxProgram.hpp: <description>
 */

#include "glox/GloxCommon.hpp"
#include "glox/GloxShader.hpp"
#include "glox/GloxVector3.hpp"
#include "glox/GloxVector4.hpp"
#include "glox/GloxPoint.hpp"

#include <vector>

namespace glox {

class GloxProgram {
public:
    GloxProgram( ) ; 

    unsigned int getId() {
        return id ;
    }

    int attachShader( const GloxShader& shader ) ;
    
    int attachShaderFromFile( const char* filename, GLenum type ) ;

    int getUniformLocation( const char* uniform ) ;

    inline void setUniformFloat( int uniform, float fl ) {
        glUniform1f( uniform, fl ) ;
    }

    inline void setUniformInteger( int uniform, float i ) {
        glUniform1f( uniform, i ) ;
    }

    template <class Vectorizable3>
    inline void setUniformVector3( int uniform, const Vectorizable3& point ) {
        glUniform3f( uniform, point.getX(), point.getY(), point.getZ() ) ;
    }

    template <class Vectorizable4>
    inline void setUniformVector4( int uniform, const Vectorizable4& point ) {
        float arr[4] ;
        point.toVector( arr, 4 ) ;
        glUniform4fv( uniform, 1, arr ) ;
    }

    template <class Vectorizable3>
    inline void setUniformVector3FromList( int uniform, const std::vector<Vectorizable3>& vecs ) {
        int len = vecs.size() * 3 ;
        float* arr = new float[len] ;

        for ( size_t i = 0; i < vecs.size() ; ++ i ) {
            vecs[i].toVector( arr + (i * 3), 3 ) ;
        }
    }

    template <class Vectorizable4>
    inline void setUniformVector4FromList( int uniform, const std::vector<Vectorizable4>& vecs ) {
        int len = vecs.size() * 4 ;
        float* arr = new float[len] ;

        for ( size_t i = 0; i < vecs.size() ; ++ i ) {
            vecs[i].toVector( arr + (i * 3), 3 ) ;
        }
    };
    
    void render() const ;

    int link();

    static void unloadPrograms() ;
private:

    unsigned int id ;
};

}

#endif /* GLOXPROGRAM_HPP_ */
