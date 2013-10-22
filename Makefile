CPPC?=g++
AR?=ar
CFLAGS= -Wall -Wextra -I.
LDFLAGS=
OBJECTS=obs/Tree.o obs/Sphere.o
all: setup $(OBJECTS)
	$(AR) -r libglcommon.a $(OBJECTS)


setup:
	mkdir -p obs/

clean:
	- rm -rf obs libglcommon.a
obs/Tree.o: ./graphics/objects/Tree.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

obs/Sphere.o: ./graphics/objects/Sphere.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

