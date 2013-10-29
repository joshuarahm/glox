LibGlox - GL Object eXtension
-----------------------------

LibGlox is an extension to OpenGL which wraps the
API in a friendlier, object-oriented framework which
abstracts away much of the OpenGL state machine to
make it harder to shoot yourself in the foot.

Much of library is inlined, which means that the performance
hit from the abstraction layer is minimal.

In order to build LibGlox, you must first generate the Makfile; this
is easy, just run ./genmake.sh from terminal then run make.

This will produce a static library to statically link against, unfortunately
as of now, there is no shared library :-( It should, however, be trivial to change
the makefile to build one.


Developer Stuff
---------------

There are 3 main types of "drawable" objects in Glox.

The first class is Plottable (GloxPlottable) objects. These
objects will simply and dumbly plot, they effect the OpenGL state
machine minimally; mostly restricted to points and normals.
However; plottable objects are very dependent
on the state of the state machine before they plot. Examples
of plottable objects are GloxPoint and GloxNormal.

The second class is Renderable (GloxRenderable) objects. These
objects will change the state of the GL state machine. Examples
of renderable objects are GloxPerspective and GloxColor.

Finally, the third class is full blown objects (GloxObjects) they are
similar to plottable, however they should not depend on the
original state of the StateMachine and ideally should restore
the StateMachine to the state it was in if possible
