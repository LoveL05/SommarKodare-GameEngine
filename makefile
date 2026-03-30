OBJS = $(wildcard ./src/**/*.cpp)  $(wildcard ./src/*.cpp)

#CC specifies which compiler we're using
CC = g++

# Libraries
LIBSDL3 = libs/libSDL3.so

LIBS = $(LIBSDL3)
LIBS_DIR = libs

PLATFORM = $(OS)
PLATFORM_WINDOWS = Windows_NT

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -Iinclude -Iheaders -Iexternal

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = # -Llibs

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
# COMPILER_FLAGS = -w -Wl,-subsystem,windows
# $(COMPILER_FLAGS)

# SDL_LIBS = sdl-config --libs

#LINKER_FLAGS specifies the libraries we're linking against
# LINKER_FLAGS = -lSDL3
ifeq (PLATFORM, PLATFORM_WINDOWS)
	LINKER_FLAGS += -lmingw32
endif

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = GameEngine
ifeq (PLATFORM, Windows_NT)
	OBJ_NAME += .exe
endif

.PHONY: all clean SDL3 ${OBJ_NAME}

#This is the target that compiles our executable
all: $(OBJS) $(LIBSDL3) $(LIBS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) -o $(OBJ_NAME) $(LIBS)

$(LIBSDL3):
	if [ ! -d $(LIBS_DIR) ] ; then \
		mkdir $(LIBS_DIR); \
	fi 
	@echo "Entering SDL3 submodule..."
	@cd external/SDL3 ; \
		cmake -S . -B build ; \
		cmake --build build ; \
		cp build/libSDL3.so ../../libs/

clean:
	rm -f $(OBJ_NAME)