#ifndef GLOXVIEWPORT_HPP_
#define GLOXVIEWPORT_HPP_

/*
 * Author: jrahm
 * created: 2013/10/24
 * GloxViewport.hpp: <description>
 */

#include "glox/GloxRenderable.hpp"

namespace glox {
	class GloxViewport : public GloxRenderable {
	public:	
		inline GloxViewport( int x=0, int y=0, int width=0, int height=0 ) :
			m_x( x ), m_y( y ), m_width( width ), m_height( height ) {}

		inline void render() const {
			glViewport( m_x, m_y, m_width, m_height );
		}

		inline void setX( int x ) { m_x = x ; }
		inline void setY( int y ) { m_y = y ; }

		inline void setWidth( int width ) { m_width = width; }
		inline void setHeight( int height ) { m_height = height; }

		inline double getAspectRatio() { return (double)m_width / (double)m_height ; }
	private:
		int m_x;
		int m_y;
		int m_width;
		int m_height;
	};
}

#endif /* GLOXVIEWPORT_HPP_ */
