/*
 * Author: jrahm
 * created: 2013/10/24
 * GloxScopedTranslation.hpp: <description>
 */

#include "glox/GloxState.hpp"
#include "glox/GloxRotation.hpp"

namespace glox {

/* A translation that endures for
 * the current scope */
class GloxScopedRotation {
public:
	inline GloxScopedRotation( double angle, double x, double y, double z ) {
		GloxState::pushMatrix();
		GloxState::rotate( angle, x, y, z );
	}

	inline GloxScopedRotation( const GloxRotation& rotation ) {
		GloxState::pushMatrix();
		GloxState::rotate( rotation.getAngle(), rotation.getX(),
	      rotation.getY(), rotation.getZ() );
	}

	inline ~GloxScopedRotation( ) {
		GloxState::popMatrix();
	}
};

}
