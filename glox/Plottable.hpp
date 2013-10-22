#ifndef PLOTTABLE_HPP_
#define PLOTTABLE_HPP_

/*
 * Author: jrahm
 * created: 2013/10/22
 * PointType.hpp: Holds the interface for al P
 */

namespace glox {

/* A plottable object is an object which
 * can plot itself */
class Plottable {
public:
    /* Plot this object on the
     * space */
    virtual void plot() = 0;
}

}

#endif /* PLOTTABLE_HPP_ */
