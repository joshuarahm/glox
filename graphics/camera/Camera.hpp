#ifndef CAMERA_HPP_
#define CAMERA_HPP_

/*
 * Author: jrahm
 * created: 2013/10/10
 * Camera.hpp: <description>
 */

#include "GraphicsCommon.hpp"

namespace graphics {

class Camera {
public:
    inline Camera( const Point3& pos, double th, double ph ) :
        pos(pos), th( th ), ph( ph ){}
    /* Change open gl to reflect the position of
     * the camera */
    inline void perspective() {
        float dx, dy, dz;
        dz = this->pos.getZ() + dsin( this->ph ) * dcos( this->th );
        dx = this->pos.getX() + dsin( this->ph ) * dsin( this->th );
        dy = this->pos.getY() + dcos( this->ph );
    
        //printf( "[(%d,%d) (%f,%f,%f) (%f,%f,%f) (%f,%f,%f)]\n", this->th, this->phi,
        //  this->x, this->y, this->z, dx, dy, dz, 0.0, 1.0, 0.0 );
        gluLookAt( this->pos.getX(), this->pos.getY(), this->pos.getZ(), dx,dy,dz, 0,1,0 );
    }

    inline void forward( double amt ) {
        double x = this->pos.getX();
        double z = this->pos.getZ();

        this->pos.setZ(z + amt * dcos( this->th ));
        this->pos.setX(x + amt * dsin( this->th ));
    }

    inline void setTheta( double th ) {
        this->th = th;
    }

    inline void setPhi( double ph ) {
        this->ph = ph;
    }

    inline void incrementTheta( double dth ) {
        this->th -= dth;
		this->th = fmod(this->th,360);
    }

    inline void incrementPhi( double dph ) {
        this->ph -= dph;
		this->ph = fmod(this->ph,360);
    }

    inline void update( ) {
        incrementTheta( dth );
        incrementPhi( dph );
        forward( velocity );
    }

    inline void setPosition( const Point3& pos ) {
        this->pos = pos ;
    }

    inline double getTheta() const {
        return th;
    }

    inline double getPhi() const {
        return ph;
    }

    /* Todo, make this vector */
    inline void setVelocity( double veloc ) {
        velocity = veloc;
    }

    inline void setDTheta( double dth ) {
        this->dth = dth;
    }

    inline void setDPhi( double dphi ) {
        this->dph = dphi;
    }

    inline double getVelocity( double veloc ) const {
        return veloc;
    }

    inline double getDTheta( double dth ) const {
        return dth;
    }

    inline double getDPhi( double dphi ) const {
        return dphi;
    }

    inline const Point3& getPosition() const {
        return pos;
    }
private:
    Point3 pos;
    double th;
    double ph;

    double dth;
    double dph;
    double velocity;
};

}

#endif /* CAMERA_HPP_ */
