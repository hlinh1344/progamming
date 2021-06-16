

#include <time.h>
#include <fstream>
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Header.h"
#include "List.h"

int main()
{
	runProgram();
	system("pause");
	return 0;
}

void runProgram()
{
	List<Pet*>* list = nullptr;
	bool willExit = false;
	int select;
	do
	{
		system("cls");
		std::cout << "1.Enter all pet's properties from file.\n";
		std::cout << "2.Display information of all pet.\n";
		std::cout << "3.Show pet's (morning & afternoon) ration.\n";
		std::cout << "4.Calculate number of days until the next health check day.\n";
		std::cout << "5.Add a Pet to the List.\n";
		std::cout << "6.Remove a Pet from the List.\n";
		std::cout << "7.Exit.\n";
		std::cout << "------------------------------------------\n";
		std::cout << "Select a number : ";
		std::cin >> select;
		std::cout << "\n\n";

		switch (select)
		{
		case 1:
			createPetList(list);
			std::cout << "\n\n";
			system("pause");
			break;
		case 2:
			display(list);
			std::cout << "\n\n";
			system("pause");
			break;
		case 3:
			showRation(list);
			std::cout << "\n\n";
			system("pause");
			break;
		case 4:
			untilNextHealthCheck(list);
			std::cout << "\n\n";
			system("pause");
			break;
		case 5:
			addPet(list);
			std::cout << "\n\n";
			system("pause");
			break;
		case 6:
			removePet(list);
			std::cout << "\n\n";
			system("pause");
			break;
		case 7:
			exitProgram(willExit);
			std::cout << "\nBye!\n\n";
			system("pause");
			break;
		default:
			break;
		}
	} while (!willExit);
	delete list;
	list = nullptr;
}
void exitProgram(bool& willExit)
{
	willExit = true;
}

void display(List<Pet*>* list)
{
	if (list->isEmpty())
		std::cout << "\nNo element in the list!!\n";
	else
	{
		petInfoHeader();
		list->printList(std::cout);
	}

}

void untilNextHealthCheck(List<Pet*>* list)
{
	if (list->isEmpty())
		std::cout << "\nNo element in the list!!\n";
	else
	{
		petHealthCheckHeader();
		Node<Pet*>* current = list->getHead();
		int n = 1;
		while (current != nullptr)
		{
			std::cout << std::setw(3) << std::right;

			if (n < 10)
			{
				std::string ID;
				ID = "0" + std::to_string(n++);
				std::cout << ID;
			}
			else
			{
				std::string ID;
				ID = std::to_string(n++);
				std::cout << ID;
			}
			current->getData()->showPetHealCheckInfo();
			current = (current->getNext());
		}
	}
}

void createPetList(List<Pet*>*& list)
{
	delete list;
	list = nullptr;
	list = new  List<Pet*>;

	std::ifstream myFile("petInfo.txt");
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			Node<Pet*>* newNode = new Node<Pet*>();
			if (newNode == nullptr)
				std::cout << "\nCan't create new node!\n";
			else {
				char line[10] = {};
				myFile.getline(line, 100);
				if (line[0] == '1')
				{
					Dog* newPet = new Dog();
					myFile >> newPet;
					newPet->setID(getNewID(list));
					newNode->setData(newPet);

				}
				else if (line[0] == '2')
				{
					Cat* newPet = new Cat();
					myFile >> newPet;
					newPet->setID(getNewID(list));
					newNode->setData(newPet);
				}
				list->addTail(newNode);
			}
		}
		myFile.close();
		std::cout << "\nCreate the list of pet from file!\n";
	}
	else
	{
		std::cout << "\nCan't open file\n";
		list = nullptr;
	}
}

void showRation(List<Pet*>* list)
{
	if (list->isEmpty())
		std::cout << "\nNo element in the list!!\n";
	else
	{
		petRationHeader();
		// int n = 1;
		Node<Pet*>* current = list->getHead();
		while (current != nullptr)
		{
			int n = current->getData()->getID();
			std::cout << std::setw(3) << std::right;
			if (n < 10)
			{
				std::string ID;
				ID = "0" + std::to_string(n++);
				std::cout << ID;
			}
			else
			{
				std::string ID;
				ID = std::to_string(n++);
				std::cout << ID;
			}
			current->getData()->showPetRation();
			current = (current->getNext());
		}
	}
}

void addPet(List<Pet*>* list)
{
	int type;
	do
	{
		std::cout << "\nPress 1 or 2 to select the pet you want to add:";
		std::cout << "\n1. Dog\t\t2. Cat\n";
		std::cout << "\nYour selection: ";
		std::cin >> type;
		if ((type != 1) && (type != 2))
		{
			std::cout << "\n\nPlease choose again !\n";
		}
	} while ((type != 1) && (type != 2));

	Node<Pet*>* newNode = new Node<Pet*>();
	if (type == 1)
	{
		Pet* newPet = new Dog();
		newPet->setID(getNewID(list));
		newPet->addPet();
		newNode->setData(newPet);
	}
	else if (type == 2)
	{
		Pet* newPet = new Cat();
		newPet->setID(getNewID(list));
		newPet->addPet();
		newNode->setData(newPet);
	}
	list->addTail(newNode);
}

void removePet(List<Pet*>* list)
{
	int idRemove;
	int listSize = list->getSize();
	if (list->isEmpty())
		std::cout << "\nThe list is empty!!\n";
	else
	{
		std::cout << "\nEnter ID number of pet you want to remove : ";
		std::cin >> idRemove;
		Node<Pet*>* current = list->getHead();
		Node<Pet*>* previous = nullptr;
		while (current != nullptr)
		{
			if (idRemove == current->getData()->getID())
				break;
			previous = current;
			current = current->getNext();
		}
		if (current == nullptr)
			std::cout << "No Pet has ID = " << idRemove << " ! ";
		else {
			list->removeNode(previous, current);
			while (current != nullptr)
			{
				current->getData()->setID(current->getData()->getID() - 1);
				current = current->getNext();
			}
		}
	}
}

void petRationHeader()
{
	std::cout << std::setw(3) << std::right << "ID"
		<< std::setw(7) << std::right << "Type"
		<< std::setw(25) << std::right << "Morning ration"
		<< std::setw(25) << std::right << "Afternoon ration" << std::endl;
}

void petHealthCheckHeader()
{
	std::cout << std::setw(3) << std::right << "ID"
		<< std::setw(7) << std::right << "Type"
		<< std::setw(30) << std::right << "Recent health check day"
		<< std::setw(30) << std::right << "The next health check day"
		<< std::setw(25) << std::right << "Remaining days" << std::endl;
}

void petInfoHeader()
{
	std::cout << std::setw(3) << std::right << "ID"
		<< std::setw(7) << std::right << "Type"
		<< std::setw(10) << std::right << "Weight"
		<< std::setw(10) << std::right << "Length"
		<< std::setw(10) << std::right << "Height"
		<< std::setw(25) << std::right << "Breed"
		<< std::setw(25) << std::right << "Hair color" << std::endl;
}

int getNewID(List<Pet*>* list)
{
	if (list->isEmpty())
		return 1;
	return list->getTail()->getData()->getID() + 1;
}