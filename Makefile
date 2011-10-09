#-*-Makefile-*-

CXX = clang++
CXXFLAGS = -O2 -g -Wall -fPIC -Werror
BIN = ./bin
LIB = ./lib
CP = cp
MKDIR = mkdir

# DDS Core 
SRCS = $(wildcard ./src/cpp/dds/core/*.cpp)
SRCS += $(wildcard ./src/cpp/dds/core/cond/*.cpp)
SRCS += $(wildcard ./src/cpp/dds/core/policy/*.cpp)
SRCS += $(wildcard ./src/cpp/dds/core/qos/*.cpp)
SRCS += $(wildcard ./src/cpp/dds/core/status/*.cpp)

SRCS += $(wildcard ./src/hpp/idds/*.cpp)
SRCS += $(wildcard ./src/hpp/idds/core/*.cpp)
SRCS += $(wildcard ./src/hpp/idds/core/policy/*.cpp)
SRCS += $(wildcard ./src/hpp/idds/domain/*.cpp)
SRCS += $(wildcard ./src/hpp/idds/pub/*.cpp)
SRCS += $(wildcard ./src/hpp/idds/qos/*.cpp)
SRCS += $(wildcard ./src/hpp/idds/sub/*.cpp)
SRCS += $(wildcard ./src/hpp/idds/topic/*.cpp)


# DDS Domain
SRCS += $(wildcard ./src/cpp/dds/domain/*.cpp)

# DDS Pub
SRCS += $(wildcard ./src/cpp/dds/core/pub/*.cpp)

OBJS = $(patsubst %.cpp,%.o,$(SRCS))

INCLUDE_DIRS = -I$(BOOST_HOME) -I./src/hpp

TARGET=libdds-psm-cxx.dylib

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -shared -o $(TARGET) $(OBJS)
	$(MKDIR) $(LIB)
	$(MKDIR) $(BIN)
	$(CP) $(TARGET) $(LIB)
$(OBJS): %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $(INCLUDE_DIRS) $< -o $@


test:
	make -C ./test
clean:
	$(RM) $(TARGET)
	$(RM) $(OBJS)
	$(RM) -Rf $(LIB) $(BIN)
	$(RM) *~	