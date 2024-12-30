
# CXXFLAGS is the Make variable which contains the options to give to the C++ compiler.

# We always start by choosing a language. Here we are coding in pre-23 C++. If your compiler support -std=c++23, use it instead.
CXXFLAGS += -std=c++2b

# Then we activate the minimum vital warnings, they are there to help us
CXXFLAGS += -pedantic -Wall -Wextra -g

# We enable some optimizations
CXXFLAGS += -O2

# Here you have a list of useful warnings for C++. You should never have any message at compile time that you don't understand.
CXXFLAGS += -Walloc-zero -Wcast-align -Wconversion -Wctad-maybe-unsupported -Wctor-dtor-privacy -Wdeprecated-copy-dtor -Wduplicated-branches -Wduplicated-cond -Wextra-semi -Wfloat-equal -Wformat-signedness -Wformat=2 -Winit-self -Wlogical-op -Wmismatched-tags -Wnoexcept -Wnon-virtual-dtor -Wnull-dereference -Wold-style-cast -Woverloaded-virtual -Wredundant-tags -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wuseless-cast -Wvolatile -Wzero-as-null-pointer-constant -fmax-errors=2

# Some of the flags above are not understood by all compilers. We ask to just ignore them without emiting an error.
CXXFLAGS += -Wno-unused-command-line-argument -Wno-unknown-warning-option

# Then we add the flags pkg-config says to use
CXXFLAGS += $(shell pkg-config allegro-5 allegro_primitives-5 allegro_font-5 --cflags | sed 's/-I/-isystem/g')

# And that's it for the compiler flags.

#####

# LDLIBS is the Make variable which contains the options to give to the linker.

# ifeq tests if two strings are equal.
# $(shell command) runs the command in a shell (default interpreter: sh) and is replaced by what the command displays
ifeq "$(shell uname)" "Darwin"
	LDFLAGS += -lstdc++
endif

# We add the flags pkg-config says to use
LDLIBS += $(shell pkg-config allegro-5 allegro_primitives-5 allegro_font-5 allegro_ttf-5 --libs) -lallegro_main

#####

# CXX is the default C++ compiler

# Recipes
.PHONY: default # Attention: cette recette ne fabrique pas la cible (pas de fichier "default" créé)
default: main# Par défaut, faire le

.PHONY: all
all: main

# Recette magique (voir Makefile précédent)
%: %.cpp
	${CXX} ${CXXFLAGS} $< -o $@ ${LDLIBS}

# make clean supprime les fichiers objets
.PHONY: clean
clean:
	rm -f *.o

# make mrclean supprime les exécutables
.PHONY: mrclean
mrclean: clean
	rm -f arkanoid
