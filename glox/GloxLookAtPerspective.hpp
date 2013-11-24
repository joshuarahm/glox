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
#include "glox/GloxStandardProjection.hpp"
#include "glox/GloxDebug.hpp"

namespace glox {

/* This is a projection which is a thin
 * layer around gluLookAt */
class GloxLookAtPerspective : public GloxStandardProjection {
public:
	inline GloxLookAtPerspective( const GloxPoint<>& pos=GloxPoint<>(),
		const GloxPoint<>& lookAt=GloxPoint<>(), const GloxPoint<>& upVec=GloxPoint<>( 0.0f, 1.0f, 0.0f ),
		float fov=50.0, float asp=1.8, float zn=0.1, float zfar=500.0) :
        GloxStandardProjection( pos, fov, asp, zn, zfar ),
		m_LookAtPoint( lookAt ), m_UpVector( upVec ) {}
	
	inline virtual void render() const {
//		GloxTrace( "GloxLookAtPerspective", "gluLookAt: %s %s %s\n",
//			getPosition().toString().c_str(), m_LookAtPoint.toString().c_str(),
//			m_UpVector.toString().c_str() );

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
};

}

#endif /* GLOXLOOKATPERSPECTIVE_HPP_ */
