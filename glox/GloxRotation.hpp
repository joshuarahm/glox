#ifndef GLOXROTATION_HPP_
#define GLOXROTATION_HPP_

/*
 * Author: jrahm
 * created: 2013/10/24
 * GloxRotation.hpp: <description>
 */

#include "glox/GloxCommon.hpp"

namespace glox {

class GloxRotation {
public:
	inline GloxRotation( double ang, double x, double y, double z ) :
		m_ang( ang ), m_x( x ), m_y( y ), m_z( z ) {}

	inline void render() const { glRotatef( m_ang, m_x, m_y, m_z ); }
	
	inline double getAngle() const { return m_ang; }
	inline double getX() const { return m_x; }
	inline double getY() const { return m_y; }
	inline double getZ() const { return m_z; }

	inline void setAngle( double ang ) { m_ang = ang ; }
	inline void setX( double x ) { m_x = x; }
	inline void setY( double y ) { m_y = y; }
	inline void setZ( double z ) { m_z = z; }
private:
	double m_ang;
	double m_x;
	double m_y;
	double m_z;
};

}

#endif /* GLOXROTATION_HPP_ */
