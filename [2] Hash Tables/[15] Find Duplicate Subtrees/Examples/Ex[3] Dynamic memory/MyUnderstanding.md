From This Example i understood a very crucial concept of Heap vs Stack.
When I used Box* mybox = new Box; This means that we have created a pointer in the stack called mybox which points to a Box allocated in the Heap.
We must use Heap because Stack is very low in memory, Usually a few megabites (Stack Overflow). The heap is very large and needs to be managed manually.

So when we create a Variable in Heap, we must manually destroy it by "delete".

