#ifndef QUADSTRIP_HPP_
#define QUADSTRIP_HPP_

/*
 * Author: jrahm
 * created: 2013/10/22
 * QuadStrip.hpp: 
 */

#include "glox/GloxPointCollection.hpp"

namespace glox {

template <class PlottableT /* extends Plottable */>

/* This class represents a quad strip
 * for OpenGL. This will draw a collection
 * of points using GL_QUAD_STRIP
 * 
 * This class extends Plottable wich
 * means that it may be plotted, but
 * that it IS dependent on state
 * of the OpenGL machine */
class GloxQuadStrip : public Plottable {
public: 
	/* Creates a new GloxQuadStrip with the points
	 * given as a vector as it's initial points */
    inline QuadStrip( const std::vector< PlottableT >& points ) :
		points( points ) {}

	/* Creates a new GloxQuadStrip with the points
	 * given as a collection of points */
	inline QuadStrip( const GloxPointCollection<PlottableT>& collection ) :
		points( collection ) {}
	
	inline virtual void plot() {
		
	}
private:
    /* The points that make up this
     * quad strip */
    GloxPointCollection<PlottableT> points;
};

}
#endif /* QUADSTRIP_HPP_ */
