#include <iostream>

struct Box{
    int volume;
};

int main(){
    Box* mybox = new Box; //Box* mybox is a pointer allocated in the Stack waiting for a location. Whilst new Box is the location allocated on the Heap.
    mybox->volume = 100;
    std::cout<<mybox->volume<<std::endl;

    return 0;
}
