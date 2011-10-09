#-*-Makefile-*-

CXX = clang++
CXXFLAGS = -O2 -g -Wall -fPIC -Werror
LDFLAGS = -L../lib -ldds-psm-cxx

CP = cp

BIN = ../bin


SRCS = $(wildcard ./dds/driver.cpp)
SRCS += $(wildcard ./dds/core/test/*.cpp)
SRCS += $(wildcard ./dds/core/test/*.cpp)
SRCS += $(wildcard ./dds/domain/test/*.cpp)
SRCS += $(wildcard ./dds/pub/test/*.cpp)
SRCS += $(wildcard ./dds/sub/test/*.cpp)
SRCS += $(wildcard ./dds/topic/test/*.cpp)

OBJS = $(patsubst %.cpp,%.o,$(SRCS))

INCLUDE_DIRS = -I$(BOOST_HOME) -I../src/hpp -I./

TARGET = testdriver

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS)
	$(CP) $(TARGET) ../bin


$(OBJS): %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $(INCLUDE_DIRS) $< -o $@


test:
	make -C ./test
clean:
	$(RM) $(TARGET)
	$(RM) $(OBJS)
	$(RM) *~	