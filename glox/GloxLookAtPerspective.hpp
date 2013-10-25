#ifndef GLOXLOOKATPERSPECTIVE_HPP_
#define GLOXLOOKATPERSPECTIVE_HPP_

/*
 * Author: jrahm
 * created: 2013/10/24
 * GloxLookAtPerspective.hpp: <description>
 */

#include <GL/glu.h>

#include "glox/GloxPerspective.hpp"
#include "glox/GloxState.hpp"

namespace glox {

/* This is a projection which is a thin
 * layer around gluLookAt */
class GloxLookAtPerspective : public GloxPerspective {
public:
	inline GloxLookAtPerspective( const GloxPoint<>& pos=GloxPoint<>(),
		const GloxPoint<>& lookAt=GloxPoint<>(), const GloxPoint<>& upVec=GloxPoint<>( 0.0f, 1.0f, 0.0f ),
		double fov=50.0, double asp=1.8, double zn=0.1, double zfar=100.0) :
		GloxPerspective::GloxPerspective( pos ), m_LookAtPoint( lookAt ), m_UpVector( upVec ),
		m_FieldOfView( fov ), m_AspectRatio( asp ), m_ZNear( zn ), m_ZFar( zfar )
		{}

	inline virtual void project() const {
		GloxState::matrixMode(GL_PROJECTION);
		GloxState::loadIdentity();

		printf( "fov: %f, asp: %f, znear: %f, zfar: %f\n", m_FieldOfView, m_AspectRatio, m_ZNear, m_ZFar );
		gluPerspective( m_FieldOfView, m_AspectRatio, m_ZNear, m_ZFar );

		GloxState::matrixMode(GL_MODELVIEW);
		GloxState::loadIdentity();
	}
	
	inline virtual void render() const {
		printf(    "gluLookAt (%f, %f, %f) ( %f, %f, %f ), ( %f, %f, %f )\n",
				   getPosition().getX(), getPosition().getY(), getPosition().getZ(),
		           m_LookAtPoint.getX(), m_LookAtPoint.getY(), m_LookAtPoint.getZ(),
		           m_UpVector.getX()   , m_UpVector.getY()   , m_UpVector.getZ()    );
		gluLookAt( getPosition().getX(), getPosition().getY(), getPosition().getZ(),
		           m_LookAtPoint.getX(), m_LookAtPoint.getY(), m_LookAtPoint.getZ(),
		           m_UpVector.getX()   , m_UpVector.getY()   , m_UpVector.getZ()    );
	}

	inline void setLookAtPoint( const GloxPoint<>& point ) {
		m_LookAtPoint = point;
	}

	inline const GloxPoint<>& getLookAtPoint() {
		return m_LookAtPoint;
	}

	inline void setUpVector( const GloxPoint<>& point ) {
		m_UpVector = point;
	}

	inline const GloxPoint<>& getUpVector() {
		return m_UpVector;
	}

	double getFieldOfView() const  { return m_FieldOfView; }
	double getAspectRatio() const  { return m_AspectRatio; }
	double getZNear() const  { return m_ZNear; }
	double getZFar() const  { return m_ZFar; }

	void setFieldOfView( double fieldOfView) { m_FieldOfView = fieldOfView; }
	void setAspectRatio( double aspectRatio) { m_AspectRatio = aspectRatio; }
	void setZNear( double zNear) { m_ZNear = zNear; }
	void setZFar ( double zFar) { m_ZFar = zFar; }

private:
	GloxPoint<> m_LookAtPoint;
	GloxPoint<> m_UpVector;

	double m_FieldOfView;
	double m_AspectRatio;
	double m_ZNear;
	double m_ZFar;
};

}

#endif /* GLOXLOOKATPERSPECTIVE_HPP_ */
