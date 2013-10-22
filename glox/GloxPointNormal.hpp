#ifndef GLOXPOINTNORMAL_HPP_
#define GLOXPOINTNORMAL_HPP_

/*
 * Author: jrahm
 * created: 2013/10/22
 * GloxPointNormal.hpp: <description>
 */

#include "glox/Plottable.hpp"
#include "glox/GloxPoint.hpp"

namespace glox {

/* The number type used by both
 * the point and the normal to use */
template <class NumT>

/* A class that couples a point with a normal. This
 * is a useful wrapper over both a glVertex and glNormal
 * functions */
class GloxPointNormal : public Plottable{
public:
	/* Creates a new point at the
	 * origin with no normal */
	GloxPointNormal( ) :
		m_point(), m_normal() {}

	/* Creates a new GloxPointNormal at the point `point`
	 * and with the normal `normal` */
	GloxPointNormal( const GloxPoint& point, const GloxNormal& normal ) :
		m_point( point ), m_normal( normal ) {}

	/* Plots a point and sets the
	 * normal for that point */
	inline void plot( ) {
		m_normal.plot();
		m_point.plot();
	}

	inline void setPoint( const GloxPoint& point ) {
		m_point = point;
	}

	inline void setNormal( const GloxNormal& normal ) {
		m_normal = normal;
	}

	inline const GloxPoint& getPoint () {
		return m_point;
	}

	inline const GloxNormal& getNormal() {
		return m_normal;
	}
	
private:
	GloxPoint m_point;
	GloxNormal m_normal;
}

}

#endif /* GLOXPOINTNORMAL_HPP_ */
