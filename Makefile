CC= g++
CFLAGS= -Wall -g

ejecutable: main.o CoreLogic.o FO.o Interface.o List.o ListNode.o Queue.o QueueNode.o Stack.o StackNode.o
	$(CC) $(CFLAGS) -o ejecutable main.o CoreLogic.o FO.o Interface.o List.o ListNode.o Queue.o QueueNode.o Stack.o StackNode.o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

CoreLogic.o: CoreLogic.cpp CoreLogic.hpp User.hpp List.hpp Queue.hpp Stack.hpp Tree.hpp
	$(CC) $(CFLAGS) CoreLogic.cpp 			

Interface.o: Interface.cpp Interface.hpp CoreLogic.hpp
	$(CC) $(CFLAGS) Interface.cpp

User.o: User.cpp User.hpp
	$(CC) $(CFLAGS) User.cpp

List.o: List.cpp List.hpp User.hpp
	$(CC) $(CFLAGS) List.cpp

ListNode.o: ListNode.cpp ListNode.hpp
	$(CC) $(CFLAGS) ListNode.cpp

Queue.o: Queue.cpp Queue.hpp QueueNode.hpp
	$(CC) $(CFLAGS) Queue.cpp

QueueNode.o: QueueNode.cpp QueueNode.hpp
	$(CC) $(CFLAGS) QueueNode.cpp

Stack.o: Stack.cpp Stack.hpp StackNode.hpp
	$(CC) $(CFLAGS) Stack.cpp

StackNode.o: StackNode.cpp StackNode.hpp
	$(CC) $(CFLAGS) StackNode.cpp

.PHONY: clean
clean:
	rm -f *.o
	rm -f ejecutable