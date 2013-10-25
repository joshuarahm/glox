/*
 * Author: jrahm
 * created: 2013/10/24
 * GloxScopedTranslation.hpp: <description>
 */

#include "glox/GloxState.hpp"

namespace glox {

/* A translation that endures for
 * the current scope */
class GloxScopedRotation {
public:
	inline GloxScopedRotation( double angle, double x, double, y, double z ) {
		GloxState::pushMatrix();
		GloxState::rotate( ang, x, y, z );
	}

	inline ~GloxScopedRotation( ) {
		GloxState::popMatrix();
	}
};
