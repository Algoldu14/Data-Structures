CC= g++
CFLAGS= -Wall -g

ejecutable: main.o CoreLogic.o Interface.o List.o ListNode.o Queue.o QueueNode.o Stack.o StackNode.o TreeNode.o Tree.o User.o
	$(CC) $(CFLAGS) -o ejecutable main.o User.o CoreLogic.o Interface.o List.o ListNode.o Queue.o QueueNode.o Stack.o StackNode.o TreeNode.o Tree.o

main.o: main.cpp Interface.hpp
	$(CC) $(CFLAGS) main.cpp

CoreLogic.o: CoreLogic.cpp CoreLogic.hpp User.hpp List.hpp Queue.hpp Stack.hpp Tree.hpp
	$(CC) $(CFLAGS) CoreLogic.cpp 			

Interface.o: Interface.cpp Interface.hpp CoreLogic.hpp
	$(CC) $(CFLAGS) Interface.cpp

User.o: User.cpp User.hpp
	$(CC) $(CFLAGS) User.cpp

Tree.o: Tree.cpp Tree.hpp User.hpp
	$(CC) $(CFLAGS) Treee.cpp

TreeNode.o: TreeNode.cpp TreeNode.hpp User.hpp
	$(CC) $(CFLAGS) TreeNode.cpp

List.o: List.cpp List.hpp User.hpp User.hpp
	$(CC) $(CFLAGS) List.cpp

ListNode.o: ListNode.cpp ListNode.hpp User.hpp
	$(CC) $(CFLAGS) ListNode.cpp

Queue.o: Queue.cpp Queue.hpp QueueNode.hpp User.hpp
	$(CC) $(CFLAGS) Queue.cpp

QueueNode.o: QueueNode.cpp QueueNode.hpp User.hpp
	$(CC) $(CFLAGS) QueueNode.cpp

Stack.o: Stack.cpp Stack.hpp StackNode.hpp User.hpp
	$(CC) $(CFLAGS) Stack.cpp

StackNode.o: StackNode.cpp StackNode.hpp User.hpp
	$(CC) $(CFLAGS) StackNode.cpp

.PHONY: clean
clean:
	rm -f *.o
	rm -f ejecutable
