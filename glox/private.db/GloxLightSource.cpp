#include "glox/GloxLightSource.hpp"
#include "glox/GloxDebug.hpp"
namespace glox {

void GloxLightSource::render() const {
	if( ! this->isEnabled() ) {
		GloxTrace( "GloxLightSource", "Light %d Disabled\n", index );
		return ;
	}

	for( M_lm_map_t::const_iterator itr = lightModelsAttrs.begin();
		/* Set all of the attributes in the map */
		itr != lightModelsAttrs.end() ; ++ itr ) {
		glLightModelf( (*itr).first, (*itr).second );
	}

	glEnable( m_light );

	/* Set the position of the light */
	float vec [4];

	this->ambient.toVector( vec, 4 );
	//GloxTrace( "GloxLightSource", "ambient: {%f, %f, %f, %f}\n", vec[0], vec[1], vec[2], vec[3] );
    glLightfv(m_light,GL_AMBIENT, vec);

	this->diffuse.toVector( vec, 4 );
	//GloxTrace( "GloxLightSource", "diffuse: %s\n", this->diffuse.toString().c_str() );
	//GloxTrace( "GloxLightSource", "diffuse: {%f, %f, %f, %f}\n", vec[0], vec[1], vec[2], vec[3] );
    glLightfv(m_light,GL_DIFFUSE ,vec);

	this->specular.toVector( vec, 4 );
	//GloxTrace( "GloxLightSource", "specular: {%f, %f, %f, %f}\n", vec[0], vec[1], vec[2], vec[3] );
    glLightfv(m_light,GL_SPECULAR,vec);


	/* enable this light */
	glEnable( this->m_light );
	this->m_pos.toVector( vec, 4 );

    glLightfv(m_light,GL_POSITION,vec);
}

}
