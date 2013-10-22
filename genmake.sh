#!/bin/bash

cnt=1

obs=()
src=()
for i in $(find . | egrep '.*\.c(pp|xx)?$') ; do
	# add this file to the list of
	# sources
	src+=($i)
	# add the resulting object file to
	# the objects
	obs+=("obs/`basename $i | sed 's/\.c\(pp\|xx\)\?$/.o/g'`")
	cnt=$[cnt + 1]
done

# open Makefile
exec 3<> Makefile

#insert some commands
echo 'CPPC?=g++'>&3
echo 'AR?=ar'>&3
echo "CFLAGS=$CFLAGS -Wall -Wextra -I.">&3
echo "LDFLAGS=$LDFLAGS">&3
echo 'OBJECTS='${obs[@]}>&3

echo -e 'all: setup $(OBJECTS)\n\t$(AR) -r libglcommon.a $(OBJECTS)\n'>&3
echo -e '\nsetup:\n\tmkdir -p obs/'>&3
echo -e '\nclean:\n\t- rm -rf obs libglcommon.a'>&3

for ((i=0;i<${#obs[@]};i++)) ; do
	echo -e "${obs[$i]}: ${src[$i]}\n\t"'$(CPPC) $(CFLAGS) -o $@ -c $<\n'>&3
done

# close Makefile
exec 3>&-
