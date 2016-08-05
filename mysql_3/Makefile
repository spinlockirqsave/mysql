CXX			= g++
SOURCES		= main.cpp Database.cpp GameActTypesDbQuery.cpp Utility.cpp
INCLUDES	= -I. -I/usr/include/mysql
LIBS		+= -L/usr/lib/x86_64-linux-gnu -lmysqlclient -pthread -lm
OBJECTS		= $(SOURCES:.cpp=.o)
TARGET		= executable

all: release

debug:	CXXFLAGS += -DDEBUG -g3 -O0 -Wall -std=c++11 -D_GNU_SOURCE -pthread 
debug:	$(SOURCES) $(TARGET)

release:	CXXFLAGS += -O3 -Wall -std=c++11 -D_GNU_SOURCE -pthread 
release:	$(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CXX) -o $(TARGET) $(OBJECTS) $(LIBS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) $<

.PHONY:
clean:
	rm -rf $(OBJECTS) $(TARGET)
