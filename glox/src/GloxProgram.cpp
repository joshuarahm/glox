#include "glox/GloxProgram.hpp"

#include <iostream>

using namespace glox ;
using namespace std ;

GloxProgram::GloxProgram( ) {   
    // cout << "Creating program2" << endl;
    this->id = glCreateProgram() ;
    // cout << "Done making program" << endl ;
}

int GloxProgram::attachShader( const GloxShader& shader ) {
    int shader_id = shader.getId() ;
    glAttachShader( this->id, shader_id ) ;
    return 0 ;
}

int GloxProgram::attachShaderFromFile( const char* filename, GLenum type ) {
    GloxShader shader( type ) ;
    int ret = shader.load( filename ) ;
    if( ! ret ) {
        return this->attachShader( shader );
    }
    return ret ;
}

int GloxProgram::getUniformLocation( const char* uniform ) {
    return glGetUniformLocation(this->id, uniform);
}

void GloxProgram::render() const {
    glUseProgram( this->id );
}

void setUniformVector3( int uniform, const std::vector< GloxVector3<> >& vec ) {
    int len = vec.size() * 3 ;
    float* arr = new float[len] ;

    for( size_t i = 0 ; i < vec.size() ; ++ i ) {
        arr[i * 3 + 0] = vec[i].get0();
        arr[i * 3 + 1] = vec[i].get1();
        arr[i * 3 + 2] = vec[i].get2();
    }

	glUniform3fv(uniform, vec.size(), arr);
}

void setUniformVector3( int uniform, const std::vector< GloxVector4<> >& vec ) {
    int len = vec.size() * 4 ;
    float* arr = new float[len] ;

    for( size_t i = 0 ; i < vec.size() ; ++ i ) {
        arr[i * 4 + 0] = vec[i].get0();
        arr[i * 4 + 1] = vec[i].get1();
        arr[i * 4 + 2] = vec[i].get2();
    }

	glUniform4fv(uniform, vec.size(), arr);
}

void GloxProgram::unloadPrograms() {
    glUseProgram( 0 ) ;
}

int GloxProgram::link() {
    int result ;
	glLinkProgram( id );
	glGetProgramiv( id , GL_LINK_STATUS, &result);

	if(result == GL_FALSE) {
		GLint length;
		char *log;

		/* get the program info log */
		glGetProgramiv( id , GL_INFO_LOG_LENGTH, &length);
		log = new char[length];
		glGetProgramInfoLog( id , length, &result, log);

		/* print an error message and the info log */
		fprintf(stderr, "Program linking failed: %s\n", log);
		free(log);

        return -1 ;
	}

    return 0 ;
}
