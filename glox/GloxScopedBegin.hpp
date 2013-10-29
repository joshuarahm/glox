#ifndef GLOXSCOPEDBEGIN_HPP_
#define GLOXSCOPEDBEGIN_HPP_

/*
 * Author: jrahm
 * created: 2013/10/29
 * GloxScopedBegin.hpp: <description>
 */

#include "glox/GloxCommon.hpp"

namespace glox {

/* In keeping with the philosophy of Glox,
 * this class scopes a begin so GlEnd is
 * automatically called when leaving scope */
class GloxScopedBegin {
public:
    inline GloxScopedBegin( GLenum to_begin ) {
        glBegin( to_begin );
    }

    inline ~GloxScopedBegin( ) {
        glEnd();
    }
};

}

#endif /* GLOXSCOPEDBEGIN_HPP_ */
