#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask(string desc) {
    Task newTask = {desc, false};
    tasks.push_back(newTask);
    cout << "✅ Task added!\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "📭 No tasks found.\n";
        return;
    }

    cout << "\n📝 Your Tasks:\n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "✔" : " ") << "] "
             << tasks[i].description << "\n";
    }
}

void markCompleted(int index) {
    if (index < 1 || index > tasks.size()) {
        cout << "❌ Invalid task number!\n";
        return;
    }

    tasks[index - 1].completed = true;
    cout << "✅ Task marked as completed!\n";
}

void deleteTask(int index) {
    if (index < 1 || index > tasks.size()) {
        cout << "❌ Invalid task number!\n";
        return;
    }

    tasks.erase(tasks.begin() + index - 1);
    cout << "🗑️ Task removed.\n";
}

int main() {
    int choice;
    string desc;
    int index;

    cout << "📋 Welcome to the To-Do List Manager\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, desc);
                addTask(desc);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> index;
                markCompleted(index);
                break;
            case 4:
                cout << "Enter task number to delete: ";
                cin >> index;
                deleteTask(index);
                break;
            case 5:
                cout << "👋 Exiting... Goodbye!\n";
                break;
            default:
                cout << "❗ Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}