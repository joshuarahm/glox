#ifndef GLOXLIGHT_HPP_
#define GLOXLIGHT_HPP_

/*
 * Author: jrahm
 * created: 2013/10/22
 * GloxLight.hpp: <description>
 */

#include "glox/GloxPoint.hpp"
#include "glox/GloxColor.hpp"
#include "glox/GloxRenderable.hpp"

#include <map>

namespace glox {

class GloxLightSource {
public:
	/* Create a new light source using the light_id
	 * that is to be used in OpenGl */
	inline GloxLightSource( GLenum light_id ) :
		m_light( light_id ) {}

    /* Sets the color of this light
     * source */;
    void setColor( const GloxColor& color );

	/* Sets the position of a point */
	void setPosition( const GloxPoint<>& position, bool directional=false ) {
		m_pos = position;
		this->directional = directional;
	}

	inline const GloxPointf& getPosition() { return m_pos ; }
	
	/* Sets whether this light is
	 * enabled or not */
	inline void setEnabled( bool enabled ) {
		this->enabled = enabled;
	}

	/* True if this light is enabled */
	inline bool isEnabled() const {
		return this->enabled;
	}

	inline void setAmbient( const GloxColor& color ) {
		this->ambient = color;
	}

	inline void setDiffuse( const GloxColor& color ) {
		this->diffuse = color;
	}

	inline void setSpecular( const GloxColor& color ) {
		this->specular = color;
	}

	inline void setLightModelAttribute( GLenum attr, float value ) {
		lightModelsAttrs[attr] = value;
	}

	inline void setLightModelAttribute( GLenum attr, const GloxColor& color ) {
		lightModelsAttrs_vectors[attr] = color;
	}

	/* Reder this light source */
	void render() const ;

private:
	typedef std::map<GLenum,float> M_lm_map_t;
	typedef std::map< GLenum,GloxColor >  M_lm_map_vec_t;

	GLenum m_light;

    GloxPoint<> m_pos;
	bool directional;
    
    /* The index of this light source */
    int index;
	bool enabled;

	/* Colors for different attributes */
	GloxColor ambient;
	GloxColor diffuse;
	GloxColor specular;

	M_lm_map_t lightModelsAttrs;
	M_lm_map_vec_t lightModelsAttrs_vectors;
};

}

#endif /* GLOXLIGHT_HPP_ */
