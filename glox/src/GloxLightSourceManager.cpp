#include "glox/GloxLightSourceManager.hpp"
#include "glox/GloxState.hpp"
#include <iostream>

using namespace std;
namespace glox {

int light_source_gl[] = {
	GL_LIGHT0,
	GL_LIGHT1,
	GL_LIGHT2,
	GL_LIGHT2,
	GL_LIGHT3,
	GL_LIGHT4,
	GL_LIGHT5,
	GL_LIGHT6,
	GL_LIGHT7,
};

void GloxLightSourceManager::render() const {
    GloxState::enable( GL_NORMALIZE );
	GloxState::enable( GL_LIGHTING );
    GloxState::colorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
    GloxState::enable(GL_COLOR_MATERIAL);

	for ( size_t i = 0 ; i < GLOX_MAX_NUM_LIGHTS; ++ i ) {
		if( m_sources[i] && m_sources[i]->isEnabled() ) {
			m_sources[i]->render();
		}
	}
}

GloxLightSource* GloxLightSourceManager::getLightSource( int id ) {
	if( m_sources[id] ) {
		return m_sources[id];
	}

	GloxLightSource* lightSource = new GloxLightSource( light_source_gl[id] );
	m_sources[id] = lightSource;

	return lightSource;
}

}
