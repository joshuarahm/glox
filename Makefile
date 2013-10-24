CPPC?=g++
AR?=ar
CFLAGS= -Wall -Wextra -I.
LDFLAGS=
OBJECTS=obs/GloxLightSource.o obs/GloxLightSourceManager.o
BINARY=libglox.a
all: setup $(OBJECTS)
	$(AR) -r $(BINARY) $(OBJECTS)

setup:
	mkdir -p obs/

clean:
	- rm -rf obs $(BINARY)

obs/GloxLightSource.o: ./glox/private.db/GloxLightSource.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/GloxLightSourceManager.o: ./glox/private.db/GloxLightSourceManager.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

