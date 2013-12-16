CPPC?=g++
AR?=ar
OPTFLAGS?=-g3 -ggdb
CFLAGS= -Wall -Wextra -Icompat -I. $(OPTFLAGS) -D DEBUG_LEVEL_TRACE -Islox -Iglox
LDFLAGS=
OBJECTS=obs/GloxCube.o obs/GloxFirstPersonPerspective.o obs/GloxTexturedCube.o obs/GloxShader.o obs/GloxCylinder.o obs/GloxProgram.o obs/GloxLightSource.o obs/GloxTexturedSphere.o obs/GloxLightSourceManager.o obs/GloxTextureFactory.o
BINARY=libglox.a
all: setup $(OBJECTS)
	$(AR) -r $(BINARY) $(OBJECTS)

setup:
	mkdir -p obs/

clean:
	- rm -rf obs $(BINARY)

obs/GloxCube.o: ./glox/src/GloxCube.cpp \
                            glox/GloxScopedBegin.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxFirstPersonPerspective.o: ./glox/src/GloxFirstPersonPerspective.cpp \
                            glox/GloxCommon.hpp \
                            glox/GloxFirstPersonPerspective.hpp \
                            glox/GloxState.hpp \
                            glox/GloxDebug.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxTexturedCube.o: ./glox/src/GloxTexturedCube.cpp \
                            glox/GloxScopedBegin.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxShader.o: ./glox/src/GloxShader.cpp \
                            glox/GloxShader.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxCylinder.o: ./glox/src/GloxCylinder.cpp \
                            glox/GloxDebug.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxProgram.o: ./glox/src/GloxProgram.cpp \
                            glox/GloxProgram.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxLightSource.o: ./glox/src/GloxLightSource.cpp \
                            glox/GloxDebug.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxTexturedSphere.o: ./glox/src/GloxTexturedSphere.cpp \
                            glox/GloxCommon.hpp \
                            glox/GloxPoint.hpp \
                            glox/GloxNormal.hpp \
                            glox/GloxPointNormalTexture.hpp \
                            glox/GloxScopedAttributes.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxLightSourceManager.o: ./glox/src/GloxLightSourceManager.cpp \
                            glox/GloxState.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxTextureFactory.o: ./glox/src/GloxTextureFactory.cpp \
                            glox/GloxTextureFactory.hpp \
                            glox/GloxTexture.hpp \
                            glox/GloxCommon.hpp \
                            glox/GloxDebug.hpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

