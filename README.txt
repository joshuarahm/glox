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
