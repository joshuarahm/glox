#include "glox/GloxTextureFactory.hpp"
#include "glox/GloxTexture.hpp"
#include "glox/GloxCommon.hpp"

#include "glox/GloxDebug.hpp"

#include <sstream>
#include <GL/glu.h>

#define BMP_MAGIC_LE 0x4D42
#define BMP_MAGIC_BE 0x424D

using namespace std;

namespace glox {

static void revendian(void* x,const int n) {
   int k;
   char* ch = (char*)x;
   for (k=0;k<n/2;k++)
   {
      char tmp = ch[k];
      ch[k] = ch[n-1-k];
      ch[n-1-k] = tmp;
   }
}

std::string error_str;

const std::string& GloxTextureFactory::getErrorMessage() {
	return error_str;
}

GloxTexture* GloxTextureFactory::textureFromBitmap( std::istream& stream ) {
   	unsigned int   texture;   
	unsigned short magic;
   	unsigned int   dx,dy,size;
   	unsigned short nbp,bpp;   
   	unsigned char* image;     
   	unsigned int   k;         
   	int            max;       

	stream.read( (char*)&magic, 2 );

	if( magic != BMP_MAGIC_LE && magic != BMP_MAGIC_BE ) {
		error_str = "Bad magic number for bitmap\n";
		return NULL;
	}

	stream.seekg( 16, stream.cur );
	stream.read( (char*)&dx, 4 );
	stream.read( (char*)&dy, 4 );
	stream.read( (char*)&nbp, 2 );
	stream.read( (char*)&bpp, 2 );
	stream.read( (char*)&k, 4 );

	GloxTrace( "GloxTextureFactory", "dx = %d, dy = %d, nbp = %d, bpp = %d, k = %d\n",
		dx, dy, nbp, bpp, k );

	if( magic == BMP_MAGIC_BE ) {
		revendian( &dx,  sizeof( dx )  );
		revendian( &dy,  sizeof( dy )  );
		revendian( &nbp, sizeof( nbp ) );
		revendian( &bpp, sizeof( bpp ) );
		revendian( &k,   sizeof( k )   );
	}

	glGetIntegerv( GL_MAX_TEXTURE_SIZE, &max );

	stringstream error;

   	if ( dx  < 1 || dx > (unsigned int)max) {
   		error << "Image width " << dx << " out of range 1-" << max << "\n";
		error_str = error.str();
		return NULL;
	}
   	if ( dy  < 1 || dy > (unsigned int)max) {
		error << "Image height " << dy << " out of range 1-" << max << "\n";
		error_str = error.str();
		return NULL;
	}
   	if ( nbp != 1) {
   		error << "Bit planes is not 1: " << nbp << "\n";
		error_str = error.str();
		return NULL;
	}
   	if ( bpp != 24) {
   		error << "Bits per pixel is not 24: " << bpp << "\n";
		error_str = error.str();
		return NULL;
	}
   	if ( k != 0) {
   		error_str = "Compressed files not supported\n";
		return NULL;
	}

	size = 3 * dx * dy;
	image = new uint8_t[size];

	if( ! image ) {
		error_str = "Not enough memory for image\n";
		return NULL;
	}

	stream.seekg( 20, stream.cur );
	stream.read( (char*)image, size );
	for( k = 0; k < size; k += 3 ) {
		uint8_t temp = image[k];
		image[k] = image[k+2];
		image[k+2] = temp;
	}

   	int err = glGetError();
   	if (err){
   		error_str = std::string((char*)gluErrorString(err));
		delete[] image;
		return NULL;
	}

	glGenTextures( 1, &texture );
	glBindTexture( GL_TEXTURE_2D, texture );
	glTexImage2D( GL_TEXTURE_2D, 0, 3, dx, dy, 0, GL_RGB, GL_UNSIGNED_BYTE, image );

	err = glGetError();
	if( err ) {
   		error_str = std::string((char*)gluErrorString(err));
		delete[] image;
		return NULL;
	}

   	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    GloxDebug( "GloxTextureFactory", "Loaded Texture. First pixel: (%d, %d, %d)\n",
        image[0], image[1], image[2] );

	delete[] image;
	
	return new GloxTexture( texture );
}

};
