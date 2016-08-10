#TARGET = test
TARGET = FractionTest


GNUSTEP_MAKEFILES = /usr/share/GNUstep/Makefiles
include $(GNUSTEP_MAKEFILES)/common.make
ADDITIONAL_FLAGS += -std=gnu11 -Wall -Werror
TOOL_NAME = $(TARGET)
#test_OBJC_FILES = test.m
#$(TARGET)_OBJC_FILES = $(TARGET).m
$(TARGET)_OBJC_FILES = $(TARGET).m Fraction.m
include $(GNUSTEP_MAKEFILES)/tool.make
