CXX			= gcc
SOURCES		= main.c
INCLUDES	= -I. -I/usr/local/firstworks/include
LIBS		+= -L/usr/local/firstworks/lib -lsqlrclientwrapper -pthread -lm
OBJECTS		= $(SOURCES:.c=.o)
TARGET		= executable

all: $(SOURCES) $(TARGET)

debug:	CXXFLAGS += -DDEBUG -g3 -O0 -Wall -D_GNU_SOURCE -std=gnu99 -pthread 
debug:	$(SOURCES) $(TARGET)

release:	CXXFLAGS += -O3 -Wall -D_GNU_SOURCE -std=gnu99 -pthread 
release:	$(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CXX) -o $(TARGET) $(OBJECTS) $(LIBS)

.c.o:
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) $<

.PHONY:
clean:
	rm -rf $(OBJECTS) $(TARGET)
