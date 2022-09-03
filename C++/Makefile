CXX			= clang++
LANG		= -std=c++17
PICKY		= -Wall

ARCH		:= $(shell arch) # Ex: x86_64
UNAME_S     := $(shell uname -s) # Ex: Linux

OPTS		= -Ofast $(NATIVE) -DNDEBUG

REPORTING   = -Rpass=.*

CXXFLAGS	= $(OPTS) $(LANG) $(PICKY) $(INCLUDES) $(DEFS) $(PTHREAD)

SOURCES		= main.cpp

HEADERS		= $(SOURCES:.cpp=.hpp)
OBJECTS		= $(SOURCES:.cpp=.o)
TARGETS		= $(SOURCES:.cpp=.exe)
PCHS		= $(HEADERS:=.gch)

.PHONY: defreport optreport clean depend all

all		: $(TARGETS)

%.exe	: %.o
		  $(CXX) $(CXXFLAGS) $^ -o $@ $(LIB)

%.o 	: %.cpp
		  $(CXX) -c $(CXXFLAGS) $< -o $@

%.s 	: %.cpp
		  $(CXX) -S -fverbose-asm $(CXXFLAGS) $<

clean	:
		  /bin/rm -f $(TARGETS) $(OBJECTS) $(PCHS) a.out *~

depend: $(ALL_SRC)
	@ $(CXX) -MM $(LANG) $(INCLUDES) $(SOURCES) > makedep
	@ echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	@ echo '$$r makedep' >>eddep
	@ echo 'w' >>eddep
	@ cp Makefile Makefile.bak
	@ ed - Makefile < eddep
	@ /bin/rm eddep makedep
	@ echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	@ echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	@ echo '# see make depend above' >> Makefile


# The following 4 (yes 4) comment lines must be in all the subdirectory makefiles
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: main.cpp
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
