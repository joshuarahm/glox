CPPC?=g++
AR?=ar
OPTFLAGS?=-g3 -ggdb
CFLAGS= -Wall -Wextra -I. $(OPTFLAGS) -D DEBUG_LEVEL_TRACE -Islox -Iglox
LDFLAGS=
OBJECTS=obs/GloxCylinder.o obs/GloxCube.o obs/GloxTexturedCube.o obs/GloxTexturedSphere.o obs/GloxFirstPersonPerspective.o obs/GloxShader.o obs/GloxProgram.o obs/GloxLightSource.o obs/GloxLightSourceManager.o obs/GloxTextureFactory.o
BINARY=libglox.a
all: setup $(OBJECTS)
	$(AR) -r $(BINARY) $(OBJECTS)

setup:
	mkdir -p obs/

clean:
	- rm -rf obs $(BINARY)

obs/GloxCylinder.o: ./glox/objects/examples/private.db/GloxCylinder.cpp \
                            glox/objects/examples/GloxCylinder.hpp \
                            glox/GloxDebug.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxCube.o: ./glox/objects/private.db/GloxCube.cpp \
                            glox/objects/GloxCube.hpp \
                            glox/GloxScopedBegin.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxTexturedCube.o: ./glox/objects/private.db/GloxTexturedCube.cpp \
                            glox/objects/GloxTexturedCube.hpp \
                            glox/GloxScopedBegin.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxTexturedSphere.o: ./glox/objects/private.db/GloxTexturedSphere.cpp \
                            glox/objects/GloxTexturedSphere.hpp \
                            glox/GloxCommon.hpp \
                            glox/GloxPoint.hpp \
                            glox/GloxNormal.hpp \
                            glox/GloxPointNormalTexture.hpp \
                            glox/GloxScopedAttributes.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxFirstPersonPerspective.o: ./glox/private.db/GloxFirstPersonPerspective.cpp \
                            glox/GloxCommon.hpp \
                            glox/GloxFirstPersonPerspective.hpp \
                            glox/GloxState.hpp \
                            glox/GloxDebug.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxShader.o: ./glox/private.db/GloxShader.cpp \
                            glox/GloxShader.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxProgram.o: ./glox/private.db/GloxProgram.cpp \
                            glox/GloxProgram.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxLightSource.o: ./glox/private.db/GloxLightSource.cpp \
                            glox/GloxLightSource.hpp \
                            glox/GloxDebug.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxLightSourceManager.o: ./glox/private.db/GloxLightSourceManager.cpp \
                            glox/GloxLightSourceManager.hpp \
                            glox/GloxState.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxTextureFactory.o: ./glox/private.db/GloxTextureFactory.cpp \
                            glox/GloxTextureFactory.hpp \
                            glox/GloxTexture.hpp \
                            glox/GloxCommon.hpp \
                            glox/GloxDebug.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

