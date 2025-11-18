# compiler to use
CXX = g++

# compiler flags
# -g: Adds debugging information
# -wall: Turns on most compiler warnings to help catch errors
# -std=c++11: Ensures support for C++ vectors
CXXFLAGS = -g -Wall -std=c++11

# the name of the final executable program
TARGET = lab13

# the source file(s)
SRCS = main.cpp

# object files (automatically derived from source files)
OBJS = $(SRCS:.cpp=.o)

# rule to link the object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean rule to remove generated files (run 'make clean')
clean:
	rm -f $(TARGET) $(OBJS)
