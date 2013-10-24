#ifndef GLOXPOINTNORMAL_HPP_
#define GLOXPOINTNORMAL_HPP_

/*
 * Author: jrahm
 * created: 2013/10/22
 * GloxPointNormal.hpp: <description>
 */

#include "glox/GloxPlottable.hpp"
#include "glox/GloxPoint.hpp"
#include "glox/GloxNormal.hpp"

namespace glox {

/* The number type used by both
 * the point and the normal to use */
template <class NumT=float>

/* A class that couples a point with a normal. This
 * is a useful wrapper over both a glVertex and glNormal
 * functions */
class GloxPointNormal : public GloxPlottable{
public:
	/* Creates a new point at the
	 * origin with no normal */
	GloxPointNormal( ) :
		m_point(), m_normal() {}

	/* Creates a new GloxPointNormal at the point `point`
	 * and with the normal `normal` */
	GloxPointNormal( const GloxPoint<NumT>& point, const GloxNormal<NumT>& normal ) :
		m_point( point ), m_normal( normal ) {}

	/* Plots a point and sets the
	 * normal for that point */
	inline void plot( ) const {
		m_normal.plot();
		m_point.plot();
	}

	inline void setPoint( const GloxPoint<NumT>& point ) {
		m_point = point;
	}

	inline void setNormal( const GloxNormal<NumT>& normal ) {
		m_normal = normal;
	}

	inline const GloxPoint<NumT>& getPoint () {
		return m_point;
	}

	inline const GloxNormal<NumT>& getNormal() {
		return m_normal;
	}
	
private:
	GloxPoint<NumT> m_point;
	GloxNormal<NumT> m_normal;
};

}

#endif /* GLOXPOINTNORMAL_HPP_ */
