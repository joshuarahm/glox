#ifndef GLOXPERSPECTIVE_HPP_
#define GLOXPERSPECTIVE_HPP_

/*
 * Author: jrahm
 * created: 2013/10/24
 * GloxPerspective.hpp: <description>
 */

#include "glox/GloxRenderable.hpp"
#include "glox/GloxPoint.hpp"

namespace glox {

/* This is an interface which describes
 * what makes a camera perspective. The
 * render() function will render the world
 * from this perspective */
class GloxPerspective : public GloxRenderable {
public:
	/* Create a new Perspective at the location
	 * 'pos' */
	inline GloxPerspective( const GloxPoint<>& pos ) :
		m_position( pos ) {}

	/* set the position of the perspective */
	inline void setPosition( const GloxPoint<>& pos ) {
		m_position = pos;
	}

	/* Returns the position of the Perspective */
	inline const GloxPoint<>& getPosition() const {
		return m_position;
	}

	/* This is called everytime the display
	 * function is called */
	virtual void render() const = 0;

	/* This renders a projection. This
	 * should be called if parameters 
	 * change */
	virtual void project() const = 0;

private:
	GloxPoint<> m_position;
};

}

#endif /* GLOXPERSPECTIVE_HPP_ */
