CXX = g++
CXXFLAGS = -std=c++11
OPTIMIZATION_FLAGS = -O2
SANITIZER_FLAGS = -fsanitize=address,undefined

SRCDIR = src
INCDIR = include

ALGORITHMS_DIR = $(SRCDIR)/algorithm
GRAPH_DIR = $(SRCDIR)/graph

SOURCES = $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(ALGORITHMS_DIR)/*.cpp) $(wildcard $(GRAPH_DIR)/*.cpp)
HEADERS = $(wildcard $(INCDIR)/*.hpp)

PROJECT_NAME = main
OBJDIR = obj
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

$(info $(SOURCES))

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OPTIMIZATION_FLAGS) $(SANITIZER_FLAGS) -I$(INCDIR) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(PROJECT_NAME) $(OBJDIR)
