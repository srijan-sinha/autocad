IDIR =./include
INDIR =./lib
CC=g++
CFLAGS=-I$(IDIR) -I$(INDIR)
GTKFLAG = `pkg-config gtkmm-3.0 --cflags --libs`

ODIR =./bin
SDIR =./src
BDIR =./build

_DEPS = display.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = display.o main.o display.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))																																																																																																																																																																																																																																																																																																																																																																																																																																		

_BUILDS = main
BUILDS = $(patsubst %,$(BDIR)/%,$(_BUILDS))

MKDIR = mkdir -p

OUT_DIR = bin build

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(GTKFLAG)

all: directories $(BUILDS)

directories: 
	$(MKDIR) $(OUT_DIR)

$(BDIR)/main: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS) $(GTKFLAG) 
