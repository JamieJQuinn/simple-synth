BIN=synth
SRCS=synth.cpp filters.cpp waves.cpp utility.cpp
SFMLLIBS= -lsfml-graphics -lsfml-window -lsfml-system
LIBS=
CFLAGS=

all: $(BIN)

sfml: CFLAGS+=-DSFML_ENABLED
sfml: LIBS+= $(SFMLLIBS)
sfml: synth

synth: $(SRCS)
	g++ $(CFLAGS) -lm $(SRCS) $(LIBS) -o synth

.PHONY: clean

clean:
	rm $(BIN)
