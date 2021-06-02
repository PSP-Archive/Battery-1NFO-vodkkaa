###########################################################################
###########################################################################
#                         DSXTEST by Julius Parishy                       #
#                              Makefile.psp                               #
###########################################################################
#                    Build with 'make -f Makefile.psp'                    #
###########################################################################
#                         Readme.now - Readme                             #
#                            Copying - GNU GPL License                    #
#                            Release - Release Notes                      #
###########################################################################
###########################################################################

# Target Name
TARGET = battery

# Source Files
OBJS = ./main.o

#Build as a prx
BUILD_PRX = 1

# Libraries
LIBS = -ldsx -lpspgum -lpspgu -lm -lpsppower

# Misc.
INCDIR = 
CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

	
