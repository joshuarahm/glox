#ifndef GLOXVECTORIZABLE_HPP_
#define GLOXVECTORIZABLE_HPP_

/*
 * Author: jrahm
 * created: 2013/10/24
 * GloxVectorizable.hpp: This class is an interface for types
 * that may be considered vectors and therefore can do
 * some simple operations.
 */

#include "glox/GloxCommon.hpp"

namespace glox {

template <class NumT=float>
class GloxVectorizable {
public:
	/* All vectors must be able to be multiplied
	 * by a scalar */
	virtual void scale( NumT amt ) = 0;
	inline GloxVectorizable<NumT>& operator*=( NumT amt ) { scale( amt ); };

	/* Creates a primitive vector and returns
	 * the number of elements stored */
	virtual int toVector( NumT* arr, size_t len ) const = 0;
};

}



#endif /* GLOXVECTORIZABLE_HPP_ */
