INCLDIR = -I../Utilities
LIBDIR = -L../lib
LIB = -lBinaryTree
CUR_OBJS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

main : ${CUR_OBJS}
	$(CXX) -o main ${CUR_OBJS} $(INCLDIR) $(LIBDIR) $(LIB)

$(CUR_OBJS) : %.o : %.cpp
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $^ -o $@

.PHONY : clean 
clean :
	-rm main $(CUR_OBJS)