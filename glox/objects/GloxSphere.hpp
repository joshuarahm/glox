#ifndef GLOXSPHERE_HPP_
#define GLOXSPHERE_HPP_

/*
 * Author: jrahm
 * created: 2013/10/22
 * GloxSphere.hpp: Better implemenation of
 * the Sphere.hpp
 */

#include "glox/GloxObject"

class GloxSphere : public GloxObject {
public:
	GloxSphere( float radius, float res=2 );

	void setTexture( const GloxTexture* texture );
}

#endif /* GLOXSPHERE_HPP_ */
