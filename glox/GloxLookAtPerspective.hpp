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
		const GloxPoint<>& lookAt=GloxPoint<>(), const GloxPoint<>& upVec=GloxPoint<>() ) :
		GloxPerspective::GloxPerspective( pos ), m_LookAtPoint( lookAt ), m_UpVector( upVec )
		{}

	inline virtual void project() const {
		GloxState::matrixMode(GL_PROJECTION);
		GloxState::loadIdentity();

		gluPerspective( m_FieldOfView, m_AspectRatio, m_ZNear, m_ZFar );

		GloxState::matrixMode(GL_MODELVIEW);
		GloxState::loadIdentity();
	}
	
	inline virtual void render() const {
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
private:
	GloxPoint<> m_LookAtPoint;
	GloxPoint<> m_UpVector;

	double m_FieldOfView;
	double m_AspectRatio;
	double m_ZNear;
	double m_ZFar;
}

}

#endif /* GLOXLOOKATPERSPECTIVE_HPP_ */
