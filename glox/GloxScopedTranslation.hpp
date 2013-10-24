#ifndef GLOXSCOPEDTRANSLATION_HPP_
#define GLOXSCOPEDTRANSLATION_HPP_

/*
 * Author: jrahm
 * created: 2013/10/24
 * GloxScopedTranslation.hpp: <description>
 */

#include "glox/GloxPoint.hpp"
#include "glox/GloxState.hpp"

namespace glox {

/* A translation that endures for
 * the current scope */
class GloxScopedTranslation {
public:
	inline GloxScopedTranslation( const GloxPoint<>& point ) {
		GloxState::pushMatrix();
		GloxState::translate( point );
	}

	inline ~GloxScopedTranslation( ) {
		GloxState::popMatrix();
	}
};

}

#endif /* GLOXSCOPEDTRANSLATION_HPP_ */
