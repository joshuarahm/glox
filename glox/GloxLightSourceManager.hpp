#ifndef GLOXLIGHTSOURCEMANAGER_HPP_
#define GLOXLIGHTSOURCEMANAGER_HPP_

#define GLOX_MAX_NUM_LIGHTS 8

/*
 * Author: jrahm
 * created: 2013/10/23
 * GloxLightSourceManager.hpp: <description>
 */

#include "glox/GloxCommon.hpp"
#include "glox/GloxLightSource.hpp"
#include "glox/GloxRenderable.hpp"

namespace glox {

/* Since there are a finite number of light
 * sources in OpenGL, they must be managed
 * and allocated through this GloxLightSourceManager
 */
class GloxLightSourceManager : public GloxRenderable {
public:
    inline GloxLightSourceManager() {
        /* Initialize the arry of LightSources to
         * NULL */
        for( size_t i = 0; i < GLOX_MAX_NUM_LIGHTS; ++ i ) {
            m_sources[i] = NULL;
        }
    }

    /* Renders the lighting  for this GloxLightSourceManager.
     * This will render the scene with the lights in this
     * manager and only the lights in this manager */
    void render() ;

    /* Returns the light source with
     * the ID `id'. Valid ID's are
     * 0-7. An invalid id will return
     * NULL. */
    GloxLightSource* getLightSource( int id ) ;

private:
    /* The sources of light */
    GloxLightSource* m_sources[ GLOX_MAX_NUM_LIGHTS ];
};

}

#endif /* GLOXLIGHTSOURCEMANAGER_HPP_ */
