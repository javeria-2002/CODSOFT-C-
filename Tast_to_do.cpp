#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    Task(string taskDescription) : description(taskDescription), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    string getDescription() const {
        return description;
    }

private:
    string description;
    bool completed;
};

class ToDoList {
public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getDescription() 
                 << " [" << (tasks[i].isCompleted() ? "Completed" : "Pending") << "]" << endl;
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks[index - 1].markCompleted();
    }

    void removeTask(size_t index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
    }

private:
    vector<Task> tasks;
};

void displayMenu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    ToDoList toDoList;
    int choice;
    string taskDescription;
    size_t taskNumber;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();  // To ignore the newline character left in the buffer

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            case 2:
                toDoList.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                toDoList.markTaskAsCompleted(taskNumber);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                toDoList.removeTask(taskNumber);
                break;
            case 5:
                cout << "Exiting To-Do List Manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
