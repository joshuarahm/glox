#ifndef OBJECT3D_HPP_
#define OBJECT3D_HPP_

namespace graphics {

class Object3D {
public:
    /* Creates a new Object3D given the initial
     * position of the object */
    inline Object3D( const Point3& pos ) :
        position( pos ) {}

    /* An object can draw itself */
    virtual void draw() = 0;

    /* All objects have a position */
    inline const Point3& getPosition() const { return position; }
    
    /* Need the ability to update the position of
     * the object */
    inline void setPosition( const Point3& npoint ) 
        { position = npoint; }
protected:
    Point3 position;
};

}

#endif
