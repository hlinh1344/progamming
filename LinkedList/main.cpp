#include "node.h"
#include "list.h"
#include "source.h"

int main() {
	runProgram();
	system("pause");
	return 0;
}

void runProgram() {
    List list;
	bool willExit = false;
	int select;
	do {
        system("cls");
        std::cout << "1.Create a list.\n";
        std::cout << "2.Display the list.\n";
        std::cout << "3.Sum all elements in the list.\n";
        std::cout << "4.Count the number of all elements in the list.\n";
        std::cout << "5.Count the number of even elements in the list.\n";
        std::cout << "6.Print positive elements in the list.\n";
        std::cout << "7.Add an element to the beginning of the list.\n";
        std::cout << "8.Add an element to the end of the list.\n";
        std::cout << "9.Add an element to the middle of the list.\n";
        std::cout << "10.Remove the first element of the list.\n";
        std::cout << "11.Remove the last element of the list.\n";
        std::cout << "12.Remove all elements with value 'k'of the list.\n";
        std::cout << "13.Exit.\n";
        std::cout << "------------------------------------------\n";
        std::cout << "Select a number : ";
        std::cin >> select;
        std::cout << "\n\n";

        switch (select)
        {
        case 1:
            createList(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 2:
            displayList(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 3:

            std::cout << "\n\n";
            system("pause");
            break;
        case 4:

            std::cout << "\n\n";
            system("pause");
            break;
        case 5:

            std::cout << "\n\n";
            system("pause");
            break;
        case 6:

            std::cout << "\n\n";
            system("pause");
            break;
        case 7:
            addFirst(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 8:
            addLast(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 9:

            std::cout << "\n\n";
            system("pause");
            break;
        case 10:

            std::cout << "\n\n";
            system("pause");
            break;
        case 11:

            std::cout << "\n\n";
            system("pause");
            break;
        case 12:

            std::cout << "\n\n";
            system("pause");
            break;
        case 13:
            exitProgram(willExit);
            std::cout << "\nBye!\n\n";
            system("pause");
            break;
        default:
            break;
        }
	} while (!willExit);

}

bool exitProgram(bool& willExit) {
    willExit = true;
    return willExit;
}



void addFirst(List &list) {
    std::cout << "data : ";
    int data;
    std::cin >> data;
    list.addHead(Node::getNewNode(data));
}

void displayList(const List &list) {
    list.display();
}

void createList(List& list) {
    std::cout << "Number of elements of the list : ";
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << i + 1<< ".";
        addLast(list);
    }
}

void addLast(List& list) {
    std::cout << "data : ";
    int data;
    std::cin >> data;
    list.addTail(Node::getNewNode(data));
}