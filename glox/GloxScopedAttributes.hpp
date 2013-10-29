#ifndef GLOXSCOPEDATTRIBUTES_HPP_
#define GLOXSCOPEDATTRIBUTES_HPP_

/*
 * Author: jrahm
 * created: 2013/10/29
 * GloxScopedAttributes.hpp: <description>
 */

#include "glox/GloxCommon.hpp"

namespace glox {

/* A class, which on creation
 * will push the specified attributes
 * to the GL stack, and upon deletion
 * will restore those attributes
 *
 * NOTE: When using this class, one should
 * be wary of manually pushing and popping
 * attributes from the GL stack.
 */
class GloxScopedAttributes {
public:
    /* Push the attributes on the GL stack */
    inline GloxScopedAttributes( GLbitfield fields ) {
        glPushAttrib( fields );
    }

    /* Restore the attributes */
    inline ~GloxScopedAttributes( ) {
        glPopAttrib() ;
    }
};

}

#endif /* GLOXSCOPEDATTRIBUTES_HPP_ */
