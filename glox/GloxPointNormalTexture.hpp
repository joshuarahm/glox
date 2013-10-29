#ifndef GLOXPOINTNORMALTEXTURE_HPP_
#define GLOXPOINTNORMALTEXTURE_HPP_

/*
 * Author: jrahm
 * created: 2013/10/24
 * GloxPointNormalTexture.hpp: <description>
 */

#include "glox/GloxPlottable.hpp"
#include "glox/GloxPointNormal.hpp"
#include "glox/GloxTexture.hpp"
#include "glox/GloxPoint.hpp"

namespace glox {

/*
 * An aggregation of all of the following:
 * A point,
 * that points normal,
 * the mapping of a texture to
 * that point
 */
class GloxPointNormalTexture : public GloxPlottable {
public:
	inline GloxPointNormalTexture( const GloxPointNormal<>& pointNormal, const GloxPoint<>& texPoint ) :
		m_PointNormal( pointNormal ), m_TextureMap( texPoint ) {
	}
	
	inline GloxPointNormalTexture( const GloxPoint<>& point, const GloxNormal<>& normal, const GloxPoint<>& texPoint ) :
		m_PointNormal( point, normal ), m_TextureMap( texPoint ) {}

	inline void plot() const {
		glTexCoord2f( m_TextureMap.getX(), m_TextureMap.getY() );
		m_PointNormal.plot();
	}

	inline const GloxPointNormal<>& getPointNormal() const { return m_PointNormal; }
	inline const GloxPoint<>& getTexturePoint() const { return m_TextureMap; }

	inline GloxPointNormal<>& getPointNormal()  { return m_PointNormal; }
	inline GloxPoint<>& getTexturePoint()  { return m_TextureMap; }
private:
	GloxPointNormal<> m_PointNormal;
	GloxPoint<> m_TextureMap;     
};

}

#endif /* GLOXPOINTNORMALTEXTURE_HPP_ */
