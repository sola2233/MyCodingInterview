# 搜集当前目录下的代码，将代码名转换为目标文件名（.o)
# wildcard 获取目录下的所有.cpp文件列表
# patsubst 将列表中的所有.cpp文件后缀替换成.o
UTL_OBJS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
UTL_LIBS = $(patsubst %.cpp, %.a, $(wildcard *.cpp))
# 加前缀函数
LIBS = $(addprefix lib, $(UTL_LIBS))

# 需要加一个隐式规则依赖所有的目标文件，不然只能生成一个目标文件
.PHONY : all
all : $(UTL_LIBS)

# $@  表示目标文件
# $^  表示所有的依赖文件
# $<  表示第一个依赖文件
# $?  表示比目标还要新的依赖文件列表
$(UTL_LIBS) : %.a : %.o
	@echo "正在创建lib$@"
	@$(AR) cr -o lib$@ $^
# 将静态库复制到lib下
	@mv lib$@ ../lib/

$(UTL_OBJS) : %.o : %.cpp
	@$(CXX) -c $(CFLAGS) $(CPPFLAGS) $^ -o $@

# 输出查看用
ECHO :
	@echo $(UTL_OBJS)
	@echo $(UTL_LIBS)
	@echo $(LIBS)

.PHONY : clean 
clean :
	-rm $(UTL_OBJS)
