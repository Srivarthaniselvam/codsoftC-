#include <iostream>
#include <vector>

using namespace std;

class Task {
public:
    string title;
    string description;
    bool completed;

    Task(string title, string description, bool completed = false)
        : title(title), description(description), completed(completed) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    void viewTasks() {
        cout << "\nTask List:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].title << " - " << tasks[i].description;
            cout << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
        }
    }

    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task '" << tasks[index].title << "' marked as completed!" << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            cout << "Task removed successfully." << endl;
        } else {
            cout << "Invalid index." << endl;
        }
    }
};

void runToDoList() {
    ToDoList todoList;

    cout << "Welcome to To-Do List Application!" << endl;
    cout << "..............Start the Task List Application............" << endl;

    while (true) {
        cout << "\nTo-Do List Application" << endl;
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\nType 'exit' to Exit" << endl;

        string choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "1") {
            string title, description;
            cout << "Task Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Task Description: ";
            getline(cin, description);
            todoList.addTask(Task(title, description));
            cout << "Task added successfully!" << endl;
        } else if (choice == "2") {
            todoList.viewTasks();
        } else if (choice == "3") {
            todoList.viewTasks();
            int index;
            cout << "Enter the index of the task to mark as completed: ";
            cin >> index;
            todoList.markTaskAsCompleted(index - 1);
        } else if (choice == "4") {
            todoList.viewTasks();
            int index;
            cout << "Enter index of the task to remove: ";
            cin >> index;
            todoList.removeTask(index - 1);
            cout << "Task removed successfully!" << endl;
        } else if (choice == "exit") {
            cout << "Closing To-Do List Application..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
}

int main() {
    runToDoList();
    return 0;
}
