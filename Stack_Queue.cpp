
#include <iostream>
#include <stdexcept>
#include "Stack.h" 
#include "Queue.h"
#include "TestFunctions.h"

int main() 
{
    TestStart();
    LinkedList<int>* container = nullptr;

    while (true) {
        std::cout << "Choose a data structure (1 - Stack, 2 - Queue, 0 - Exit): ";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 0:
            if (container) {
                delete container;
            }
            return 0;
        case 1:
            if (container) {
                delete container;
            }
            container = new Stack<int>();
            break;
        case 2:
            if (container) {
                delete container;
            }
            container = new Queue<int>();
            break;
        default:
            std::cout << "Invalid choice. Please choose again." << std::endl;
            continue;
        }

        while (true) {
            std::cout << "Choose an operation (1 - Push, 2 - Pop, 3 - GetFront, 4 - IsEmpty, 5 - Size, 6 - Print, 7 - Assignment, 0 - Back): \n";
            std::cin >> choice;

            switch (choice) {
            case 0:
                delete container;
                container = nullptr;
                break;
            case 1: {
                int value;
                std::cout << "Enter a value to push: ";
                std::cin >> value;
                container->Push(value);
                break;
            }
            case 2:
                try {
                    container->Pop();
                    std::cout << "Pop operation performed." << std::endl;
                }
                catch (const std::out_of_range& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            case 3: {
                try {
                    int front = container->GetFront();
                    std::cout << "Front element: " << front << std::endl;
                }
                catch (const std::out_of_range& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                bool isEmpty = container->IsEmpty();
                std::cout << "Is the container empty? " << (isEmpty ? "Yes" : "No") << std::endl;
                break;
            }
            case 5: {
                size_t size = container->Size();
                std::cout << "Size of the container: " << size << std::endl;
                break;
            }
            case 6: {
                std::cout << "Elements in the container: ";
                for (const int& item : *container) {
                    std::cout << item << " ";
                }
                std::cout << std::endl;
                break;
            }
            case 7: {
                LinkedList<int>* anotherContainer = new LinkedList<int>();
                *anotherContainer = *container;
                std::cout << "Assignment performed." << std::endl;
                delete anotherContainer;
                break;
            }
            default:
                std::cout << "Invalid choice. Please choose again." << std::endl;
                continue;
            }
            if (!container) {
                break;
            }
        }
    }

    return 0;
   
}
