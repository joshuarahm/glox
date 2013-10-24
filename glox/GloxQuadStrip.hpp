#ifndef QUADSTRIP_HPP_
#define QUADSTRIP_HPP_

/*
 * Author: jrahm
 * created: 2013/10/22
 * QuadStrip.hpp: 
 */

#include <GL/gl.h>
#include <GL/glu.h>

#include "glox/GloxPointCollection.hpp"

namespace glox {

template <class PlottableT /* extends Plottable */ = GloxPoint<float> >

/* This class represents a quad strip
 * for OpenGL. This will draw a collection
 * of points using GL_QUAD_STRIP
 * 
 * This class extends Plottable wich
 * means that it may be plotted, but
 * that it IS dependent on state
 * of the OpenGL machine */
class GloxQuadStrip : public GloxPlottable {
public: 
    inline GloxQuadStrip() :
        points() {}
	/* Creates a new GloxQuadStrip with the points
	 * given as a vector as it's initial points */
    inline GloxQuadStrip( const std::vector< PlottableT >& points ) :
		points( points ) {}

	/* Creates a new GloxQuadStrip with the points
	 * given as a collection of points */
	inline GloxQuadStrip( const GloxPointCollection<PlottableT>& collection ) :
		points( collection ) {}
	
	/* Plots the points as a GL_QUAD_STRIP */
	inline virtual void plot() const {
		glBegin( GL_QUAD_STRIP );
		points.plot();
		glEnd();
	}

	/* Appends a point to the collection
	 * of points to plot */
	inline void addPoint( const PlottableT& point ) {
		points.add( point );
	}

private:
    /* The points that make up this
     * quad strip */
    GloxPointCollection<PlottableT> points;
};

}
#endif /* QUADSTRIP_HPP_ */
