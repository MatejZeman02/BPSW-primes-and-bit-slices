#https://gist.github.com/maxtruxa/4b3929e118914ccef057f8a05c614b0f
#linking was not working due to bad order of parameters for g++

# output binary dir
BINDIR := bin/
# output binary 
BIN := $(BINDIR)main

# relase version
# CPPFLAGS := -DNDEBUG -Wall -Wextra -pedantic -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -O3

# debug version
CPPFLAGS := -g -Wall -Wextra -pedantic -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable


# source files
SRCS := \
	main.cpp \
    IsPrime.cpp \
	BPSWTest.cpp \
	BitStatistics.cpp \
	Li.cpp \
	BitRange.cpp \
	PrimesRange.cpp \
	PrimesRangeService.cpp \
	SieveGenerator.cpp \
	GeneratorFunctionBitStatistics.cpp \
	GeneratorFunctionPrime.cpp \
	mpz_aprcl.c \
	SliceTBalance.cpp \
	GeneratorFunctionPrimeBPSW.cpp \
	GeneratorFunctionPrimeAPRCL.cpp \
	GeneratorFunctionPrimeMR.cpp \
	GeneratorFunctionPrimeLS.cpp \
	GeneratorFunctionPrimeLS_D.cpp \
	GeneratorFunctionPrimeLS_DHistogram.cpp \
	GeneratorFunctionPrimeCreator.cpp \
	GeneratorFunctionPrimeMR128.cpp \
	GeneratorFunctionPrimeBPSW128.cpp \
	GeneratorFunctionPrimeBPSW2.cpp

# files included in the tarball generated by 'make dist' (e.g. add LICENSE file)
DISTFILES := $(BIN)

# filename of the tar archive generated by 'make dist'
DISTOUTPUT := $(BIN).tar.gz

# intermediate directory for generated object files
OBJDIR := .o
# intermediate directory for generated dependency files
DEPDIR := .d

# object files, auto generated from source files
OBJS := $(patsubst %,$(OBJDIR)/%.o,$(basename $(SRCS)))
# dependency files, auto generated from source files
DEPS := $(patsubst %,$(DEPDIR)/%.d,$(basename $(SRCS)))

# compilers (at least gcc and clang) don't create the subdirectories automatically
$(shell mkdir -p $(dir $(OBJS)) >/dev/null)
$(shell mkdir -p $(dir $(DEPS)) >/dev/null)
$(shell mkdir -p $(dir $(BINDIR)) >/dev/null)

# C compiler
# ToDo Is this ok? check original configuration on internet
CC := gcc
# C++ compiler
CXX := g++
# linker
LD := g++
# tar
TAR := tar

# C flags
# ToDo these flags are applied to a c file
CFLAGS := -std=c18

# C++ flags
CXXFLAGS := -std=c++17
# C/C++ flags

# linker libs
LDLIBS := -lgmp -lstdc++fs

# linker flags
# static linking improves performance of Miller-Rabin test by ~2%
# it may be possible to staticaly link only gmp library by linking gmp.a just like ordinary .o file
LDFLAGS := -static

# flags required for dependency generation; passed to compilers
DEPFLAGS = -MT $@ -MD -MP -MF $(DEPDIR)/$*.Td

# compile C source files
COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@
# compile C++ source files
COMPILE.cc = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c -o $@

# link object files to binary
#LINK.o = $(LD) $(LDFLAGS) $(LDLIBS) -o $@

# precompile step
PRECOMPILE =
# postcompile step
POSTCOMPILE = mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d

all: $(BIN)
	@echo ============================================================================= OK ======================================================================

dist: $(DISTFILES)
	$(TAR) -cvzf $(DISTOUTPUT) $^

.PHONY: clean
clean:
	$(RM) -r $(OBJDIR) $(DEPDIR)

.PHONY: distclean
distclean: clean
	$(RM) $(BIN) $(DISTOUTPUT)

.PHONY: install
install:
	@echo no install tasks configured

.PHONY: uninstall
uninstall:
	@echo no uninstall tasks configured

.PHONY: check
check:
	@echo no tests configured

.PHONY: help
help:
	@echo available targets: all dist clean distclean install uninstall check

#linking in g++ requires specific order of parameters
$(BIN): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ $(LDLIBS) 

$(OBJDIR)/%.o: %.c
$(OBJDIR)/%.o: %.c $(DEPDIR)/%.d
	$(PRECOMPILE)
	$(COMPILE.c) $<
	$(POSTCOMPILE)

$(OBJDIR)/%.o: %.cpp
$(OBJDIR)/%.o: %.cpp $(DEPDIR)/%.d
	$(PRECOMPILE)
	$(COMPILE.cc) $<
	$(POSTCOMPILE)

$(OBJDIR)/%.o: %.cc
$(OBJDIR)/%.o: %.cc $(DEPDIR)/%.d
	$(PRECOMPILE)
	$(COMPILE.cc) $<
	$(POSTCOMPILE)

$(OBJDIR)/%.o: %.cxx
$(OBJDIR)/%.o: %.cxx $(DEPDIR)/%.d
	$(PRECOMPILE)
	$(COMPILE.cc) $<
	$(POSTCOMPILE)

.PRECIOUS: $(DEPDIR)/%.d
$(DEPDIR)/%.d: ;

-include $(DEPS) 