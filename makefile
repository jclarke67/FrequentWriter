writer:	List.o writer.o
	c++ -o writer List.o writer.o 

List.o: List.h List.cc
	c++ -g -c List.cc

writer.o: writer.cc
	c++ -g -c writer.cc

clean: 
	rm -r *.o writer
