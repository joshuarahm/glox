#ifndef GLOXTEXTUREFACTORY_HPP_
#define GLOXTEXTUREFACTORY_HPP_

/*
 * Author: jrahm
 * created: 2013/10/22
 * GloxTextureFactory.hpp: <description>
 */

#include <iostream>

namespace glox {

/* This is a static class that builds
 * texture objects. The textures can then
 * be pinned onto objects */
class GloxTextureFactory {
public:
    /* Creates a new texture from a bitmap
     * image. If there is an error, NULL is
     * returned */
	static GloxTexture* buildTextureFromBmp( std::istream& stream );

#ifndef NO_JPG_SUPPORT
	static GloxTexture* buildTextureFromJpg( std::istream& stream );
#endif

#ifndef NO_PNG_SUPPORT
	static GloxTexture* buildTextureFromPng( std::istream& stream );
#endif

}

}

#endif /* GLOXTEXTUREFACTORY_HPP_ */
