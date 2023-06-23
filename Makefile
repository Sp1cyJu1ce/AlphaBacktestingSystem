CXX = g++
CXXFLAGS = -Wall -std=c++11

# List all the .cpp files with the correct path
SOURCES = src/dataProcessing.cpp src/MomentumStrategy.cpp src/Portfolio.cpp src/Metrics.cpp src/Backtester.cpp src/main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = backtester

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)