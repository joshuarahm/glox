#ifndef GLOXSTANDARDPROJECTION_HPP_
#define GLOXSTANDARDPROJECTION_HPP_

/*
 * Author: jrahm
 * created: 2013/10/29
 * GloxStandardProjection.hpp: <description>
 */

#include <GL/glu.h>

#include "glox/GloxPerspective.hpp"
#include "glox/GloxState.hpp"

namespace glox {

class GloxStandardProjection : public GloxPerspective {
public:

inline GloxStandardProjection( const GloxPoint<>& pos,  float fov=50.0, float asp=1.8, float znear=0.1, float zfar=500.0 ) :
    GloxPerspective( pos ),
	m_FieldOfView( fov ), m_AspectRatio( asp ), m_ZNear( znear ), m_ZFar( zfar ) {
}

/* Set up the projection */
inline virtual void project() const {
	GloxState::matrixMode(GL_PROJECTION);
	GloxState::loadIdentity();

	gluPerspective( m_FieldOfView, m_AspectRatio, m_ZNear, m_ZFar );

	GloxState::matrixMode(GL_MODELVIEW);
	GloxState::loadIdentity();
}

/* This class only helps with
 * projections, it still needs to
 * have render implemented */
virtual void render() const = 0;

float getFieldOfView() const  { return m_FieldOfView; }
float getAspectRatio() const  { return m_AspectRatio; }
float getZNear() const  { return m_ZNear; }
float getZFar() const  { return m_ZFar; }

void setFieldOfView( float fieldOfView) { m_FieldOfView = fieldOfView; }
void setAspectRatio( float aspectRatio) { m_AspectRatio = aspectRatio; }
void setZNear( float zNear) { m_ZNear = zNear; }
void setZFar ( float zFar) { m_ZFar = zFar; }

private:
	float m_FieldOfView;
	float m_AspectRatio;
	float m_ZNear;
	float m_ZFar;
};

}

#endif /* GLOXSTANDARDPROJECTION_HPP_ */
