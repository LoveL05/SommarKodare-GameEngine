OBJS = $(wildcard ./src/**/*.cpp) 

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -Iinclude -Iheaders

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -Llib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
# COMPILER_FLAGS = -w -Wl,-subsystem,windows
# $(COMPILER_FLAGS)

SDL_LIBS = sdl-config --libs

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32  -lSDL2main -lSDL2

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = GameEngine

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm -f $(OBJ_NAME).exe