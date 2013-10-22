#ifndef GLOXOBJECT_HPP_
#define GLOXOBJECT_HPP_

/*
 * Author: jrahm
 * created: 2013/10/22
 * GloxObject.hpp: <description>
 */

namespace glox {

/* Similar to Plottable, but more strict.
 * This object knows how to draw itself and that
 * is all.
 *
 * An object should be all-inclusive, that is,
 * unlike Plottable, GloxObject implies that
 * the Object itself will only depend on the
 * transformations of the OpenGL state machine
 */
class GloxObject {
public:
	/* Draws this object */
	virtual void draw() = 0;
};

}

#endif /* GLOXOBJECT_HPP_ */
