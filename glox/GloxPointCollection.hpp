#ifndef GLOXPOINTCOLLECTION_HPP_
#define GLOXPOINTCOLLECTION_HPP_

/*
 * Author: jrahm
 * created: 2013/10/22
 * GloxPointCollection.hpp: <description>
 */

#include "glox/Plottable.hpp"

namespace glox {

template <class PlottableT=GloxPoint>

/* GloxPointCollection: a collection of Plottable that
 * may be plotted in bulk */
class GloxPointCollection : public Plottable {
public:
	typedef m_Vec_t::iterator iterator;

	/* Constructs a new GloxPointCollection with
	 * no Points */
	inline GloxPointCollection( ) {
		// Nothing here for now
	}

	/* Creates a new GloxPointCollection with the
	 * initial starting points `points`
	 */
	inline GloxPointCollection( const m_Vec_t& points ) {
		this.points = points;
	}
	
	/* Iterate through the vector of Plottable
	 * and call their plot functions */
	virtual void plot() {
		for( iterator itr = this->begin(); itr != this->end(); ++ itr ) {
			(*itr).plot();
		}
	}

	/* Appends a point to this collection */
	virtual void add( const PlottableT& point ) {
		this->points.push_back( point );
	}

	/* Returns an iterator for this
	 * GloxPointCollection */
	inline iterator begin() {
		return points.begin();
	}

	/* Returns then end of the iterator */
	inline iterator end() {
		return points.end();
	}

private:
	/* Shorter vector term */
	typedef std::vector< PlottableT > m_Vec_t

	/* The points to plot */
	m_Vec_t  points;
}

};

#endif /* GLOXPOINTCOLLECTION_HPP_ */
