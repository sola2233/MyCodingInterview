CXX	= g++
AR = ar

PROJ_DIR = $(shell pwd)
INCLDIR += $(PROJ_DIR)/Utilities
LIBDIR = $(PROJ_DIR)/lib

# 搜索文件夹内的其余文件夹，向下递归编译
SRC_UTL 	= $(PROJ_DIR)/Utilities
SRC_01		= $(PROJ_DIR)/01_AssignmentOperator
SRC_03_01 	= $(PROJ_DIR)/03_01_DuplicationInArray
SRC_03_02 	= $(PROJ_DIR)/03_02_DuplicationInArrayNoEdit
SRC_04		= $(PROJ_DIR)/04_FindInPartiallySortedMatrix
SRC_05		= $(PROJ_DIR)/05_ReplaceSpaces
SRC_06		= $(PROJ_DIR)/06_PrintListInReversedOrder
SRC_07		= $(PROJ_DIR)/07_ConstructBinaryTree

SRC_OBJ += 	$(SRC_01)
# 看本层会不会用到
OBJS_UTL = $(SRC_UTL)/*.o
OBJS_06 = $(SRC_06)/*.o

.PHONY : all
all: $(SRC_UTL) $(SRC_06)
	make -C $(SRC_UTL)
	make -C $(SRC_01)
	make -C $(SRC_03_01)
	make -C $(SRC_03_02)
	make -C $(SRC_04)
	make -C $(SRC_05)
	make -C $(SRC_06)
	make -C $(SRC_07)

.PYTHON : clean
clean:
	make clean -C $(SRC_UTL)
	make clean -C $(SRC_01)
	make clean -C $(SRC_03_01)
	make clean -C $(SRC_03_02)
	make clean -C $(SRC_04)
	make clean -C $(SRC_05)
	make clean -C $(SRC_06)
	make clean -C $(SRC_07)
	$(RM) $(LIBDIR)/*.a 