#ifndef GLOXPOINTCOLLECTION_HPP_
#define GLOXPOINTCOLLECTION_HPP_

/*
 * Author: jrahm
 * created: 2013/10/22
 * GloxPointCollection.hpp: <description>
 */

#include "glox/GloxPlottable.hpp"
#include "glox/GloxPoint.hpp"
#include "glox/GloxDebug.hpp"

#include <vector>
#include <string>
#include <sstream>

namespace glox {

template < class PlottableT=GloxPoint<float> >

/* GloxPointCollection: a collection of Plottable that
 * may be plotted in bulk */
class GloxPointCollection : public GloxPlottable {
public:
	/* Shorter vector term */
	typedef std::vector< PlottableT > m_Vec_t;
	typedef typename m_Vec_t::iterator iterator;
	typedef typename m_Vec_t::const_iterator const_iterator;

	/* Constructs a new GloxPointCollection with
	 * no Points */
	inline GloxPointCollection( ) {
		// Nothing here for now
	}

	/* Creates a new GloxPointCollection with the
	 * initial starting points `points`
	 */
	inline GloxPointCollection( const m_Vec_t& points ) {
		this->points = points;
	}
	
	/* Iterate through the vector of Plottable
	 * and call their plot functions */
	virtual void plot() const {
        // GloxTrace( "GloxPointCollection", "plot(): this = %s\n", this->toString().c_str() );

		for( const_iterator itr = this->begin(); itr != this->end(); ++ itr ) {
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

    inline void clear() { 
        points.clear();
    }

	/* Returns an iterator for this
	 * GloxPointCollection */
	inline const_iterator begin() const {
		return points.begin();
	}

	/* Returns then end of the const_iterator */
	inline const_iterator end() const {
		return points.end();
	}

    inline std::string toString() const {
        std::stringstream stream;
        stream << "[ ";
		for( const_iterator itr = this->begin(); itr != this->end(); ++ itr ) {
			stream << (*itr).toString() << ", ";
		}
        stream << "]";
        return stream.str();
    }

private:

	/* The points to plot */
	m_Vec_t  points;
};

};

#endif /* GLOXPOINTCOLLECTION_HPP_ */
