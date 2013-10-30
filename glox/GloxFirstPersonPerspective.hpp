#ifndef GLOXFIRSTPERSONPERSPECTIVE_HPP_
#define GLOXFIRSTPERSONPERSPECTIVE_HPP_

/*
 * Author: jrahm
 * created: 2013/10/29
 * GloxFirstPersonPerspective.hpp: <description>
 */

#include "glox/GloxPerspective.hpp"
#include "glox/GloxPoint.hpp"
#include "glox/GloxStandardProjection.hpp"
#include "glox/GloxVector3.hpp"

namespace glox {

class GloxFirstPersonPerspective : public GloxStandardProjection {
public:
    inline GloxFirstPersonPerspective(
        const GloxPoint<>& pos=GloxPoint<>(),
        float roll=0, float pitch=0, float yaw=0,
        float fov=50.0, float asp=1.8, float znear=0.1, float zfar=500.0 ) :
        GloxStandardProjection( pos, fov, asp, znear, zfar ),
        m_yaw( yaw ), m_pitch( pitch ), m_roll( roll ) {}

    inline void setYaw( float yaw ) {
        m_yaw = yaw;
    }

    inline void setPitch( float pitch ) {
        m_pitch = pitch;
    }

    inline void setRoll( float roll ) {
        m_roll = roll;
    }

    inline float getYaw()   const { return m_yaw; }
    inline float getPitch() const { return m_pitch; }
    inline float getRoll()  const { return m_roll; }

    /* adds a vector of rotations, expressed in
     * terms or roll, pitch and yaw */
    inline void addRotationVector( const GloxVector3<float>& vec ) {
        m_roll += vec.get0();
        m_pitch += GloxCos( m_roll )*vec.get1() + GloxSin( m_roll )*vec.get2();
        m_yaw += GloxSin( m_roll )*vec.get1() + GloxCos( m_roll ) * vec.get2();
    }

    virtual void render() const;

    inline GloxPoint<> forward( float rad ) {
        return GloxPoint<>::fromSpherical( rad, m_yaw, m_pitch ) + this->getPosition();
    }
private:
    /* Rotations */
    float m_yaw;   /* Horizontal rotation */
    float m_pitch; /* Up or down */
    float m_roll;
};

}

#endif /* GLOXFIRSTPERSONPERSPECTIVE_HPP_ */
