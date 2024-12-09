#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Tasks {
public:
	string description;
	bool completion;
	Tasks(string desc) : description(desc), completion(false) {}
	
};

class todoItems {
private: 
	vector <Tasks> item;

public:

	//adds a task to the lists of to-do list.
	void addItem(const string itemDesc) {
		item.emplace_back(itemDesc);
		cout << "Task'" << itemDesc << "' has been added successfully\n";
	}

	//marks a completed task as 'completed'.
	void iscompleted(int itemNumber) {
		if (itemNumber > 0 && itemNumber <= item.size()) {
			item[itemNumber - 1].completion = true;
			cout << "Task " << itemNumber << " is completed.\n";
		}
		else {
			cout << "\n Invalid item number. Please try again.\n";
		}
	}

	//display all available tasks and indicate whether they are completed or still ongoing
	void viewAllTasks() const{
		int counter = 0;
		if (item.empty()) {
			cout << "\n You have no tasks to complete.\n";
			cout << "Your to-do list is empty.\n";
			return;
		}
		else {
			cout << "\n Your To-Do List \n";
			for (int i = 0; i < item.size(); i++) {
				cout << counter + 1 << ". " << item[i].description << " - " << (item[i].completion ? "Completed" : "Ongoing") << endl;
			}
		}
		cout << "\n";
	}

};

void displayMenu();


int main() {

	todoItems task;
	int choice;


	do {
		displayMenu();
		cout << "Enter your choice to select (1-4): ";
		cin >> choice;
		cin.ignore();

		switch (choice){	
			case 1: {
				cout << "Enter the Task to add to the to-do list: ";
				string itemDesc;
				getline(cin, itemDesc);
				task.addItem(itemDesc);
				break;
				}
			case 2: {
				int itemNumber;
				cout << "Enter task number to mark it 'completed': ";
				cin >> itemNumber;
				task.iscompleted(itemNumber);
				break;
			}
			case 3: {
				cout << "\n To-do List\n";
				task.viewAllTasks();
				break;
			}
			case 4: {
				cout << "Exiting. Goodbye!";
				break;
			}
			default:
				cout << "Invalid entry. Please try again!\n";
				break;
		}

	} while (choice != 4);

	system("pause>0");
	return 0;
}

//Dispaly the menu of the app.
void displayMenu() {
	cout << "\nTo Do List\n";
	cout << "\n";

	cout << "Menu\n";
	cout << "1. Add Task\n";
	cout << "2. Mark Task As Completed\n";
	cout << "3. View All Tasks\n";
	cout << "4. Exit\n";
	
}
