#include "glox/GloxShader.hpp"

#include <iostream>
#include <fstream>

#include <sstream>

using namespace glox ;
using namespace std ;

string GloxShader::message ;

int GloxShader::readFile( const char* filename, string& into ) {
    ifstream stream ;   
    stream.open( filename ) ;
    stringstream sstream ;

    std::string line ;

    if( ! stream ) {
        message = string( "Unable to open file ") + filename + " for read" ;
        return -1 ;
    }

    while ( ! stream.eof() ) {
        getline( stream, line ) ;
        sstream << line << "\n" ;
    }

    into = sstream.str();

    return 0 ;
}

int GloxShader::load( const char* filename) {
    std::string contents ;

    if( readFile( filename, contents ) < 0 ) {
        return -1 ;
    }

    m_shader = glCreateShader( this->type ) ;
    const char* source = contents.c_str();
    int len = contents.length();
    glShaderSource( m_shader, 1, & source, &len  ) ;
    glCompileShader( m_shader ) ;

    int result, length ;
	glGetShaderiv(m_shader, GL_COMPILE_STATUS, &result);
    if( result == GL_FALSE ) {
		char *log;

		glGetShaderiv(m_shader, GL_INFO_LOG_LENGTH, &length);
		log = new char[length];
		glGetShaderInfoLog(m_shader, length, &result, log);

		fprintf(stderr, "shaderCompileFromFile(): Unable to compile %s: %s\n", filename, log);
		free(log);

		glDeleteShader(m_shader);

        cerr << "Returning with error code -1" << endl ;
        return -1 ;
    }

    return 0 ;
}

GloxShader::~GloxShader() {
    glDeleteShader( m_shader ) ;
}
