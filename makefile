out : header.h test.o inOrder.o postOrder.o insert.o sethiUllman.o
	g++ test.o inOrder.o postOrder.o insert.o sethiUllman.o -o out
test.o : header.h
inOrder.o : header.h
postOrder.o : header.h
insert.o : header.h
sethiUllman.o : header.h
