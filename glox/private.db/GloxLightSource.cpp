#include  "glox/GloxLightSource.hpp"

namespace glox {

static void conv_to_vec4( const GloxColor& color, float arr[4] ) {
	arr[0] = color.getR();
	arr[1] = color.getG();
	arr[2] = color.getB();
	arr[3] = color.getA();
}

void GloxLightSource::render() const {
	if( ! this->isEnabled() ) {
		return ;
	}

	for( M_lm_map_t::const_iterator itr = lightModelsAttrs.begin();
		/* Set all of the attributes in the map */
		itr != lightModelsAttrs.end() ; ++ itr ) {
		glLightModelf( (*itr).first, (*itr).second );
	}

	/* Set the position of the light */
	float vec [] = { (float)m_pos.getX(), (float)m_pos.getY(),
		(float)m_pos.getZ(), directional ? 0.0f : 1.0f };

	conv_to_vec4( this->ambient, vec );
    glLightfv(GL_LIGHT0,GL_AMBIENT, vec);

	conv_to_vec4( this->diffuse, vec );
    glLightfv(GL_LIGHT0,GL_DIFFUSE ,vec);

	conv_to_vec4( this->specular, vec );
    glLightfv(GL_LIGHT0,GL_SPECULAR,vec);

	/* enable this light */
	glEnable( this->m_light );
    glLightfv(GL_LIGHT0,GL_POSITION,vec);
}

}
