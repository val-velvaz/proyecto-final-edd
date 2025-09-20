# --- CONFIGURACIÓN DEL COMPILADOR ---
CXX = g++.exe

# --- CONFIGURACIÓN DEL PROYECTO ---
TARGET = output\search.exe
DEBUG_TARGET = output\Cirugias_debug.exe

# --- BANDERAS (FLAGS) DE COMPILACIÓN Y ENLACE ---
CXXFLAGS = -std=c++14 -Iinclude -I/ucrt64/include/SFML -DSFML_STATIC -m64
LDFLAGS = -L/ucrt64/lib -static-libgcc -static-libstdc++ -m64
LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lfreetype -lopengl32 -lwinmm -lgdi32 -lucrt

# --- BANDERAS (FLAGS) DE DEPURACIÓN ---
DEBUG_CXXFLAGS = $(CXXFLAGS) -g -O0

# --- BÚSQUEDA AUTOMÁTICA DE ARCHIVOS ---
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
DEBUG_OBJECTS = $(SOURCES:.cpp=.o.debug)

# --- REGLAS DE MAKEFILE ---
all: $(TARGET)

debug: $(DEBUG_TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS) $(LIBS)

$(DEBUG_TARGET): $(DEBUG_OBJECTS)
	$(CXX) $(DEBUG_OBJECTS) -o $(DEBUG_TARGET) $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o.debug: %.cpp
	$(CXX) $(DEBUG_CXXFLAGS) -c $< -o $@

# --- REGLAS ADICIONALES ---
clean:
	rm -f src/*.o src/*.o.debug $(TARGET) $(DEBUG_TARGET)

run: all
	.\$(TARGET)

run-debug: debug
	.\$(DEBUG_TARGET)