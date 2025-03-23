#include "todo.h"
#include <iostream>

int main() {
    Todo todo;
    int choice;

    do {
        std::cout << "\n--- To-Do List ---\n";
        std::cout << "1. Add Task\n2. Delete Task\n3. Mark Complete\n4. Show Tasks\n5. Save to File\n6. Load from File\n0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::string task;
        int index;
        switch (choice) {
            case 1:
                std::cout << "Enter task: ";
                std::cin.ignore();
                std::getline(std::cin, task);
                todo.addTask(task);
                break;
            case 2:
                std::cout << "Enter task number to delete: ";
                std::cin >> index;
                todo.deleteTask(index - 1);
                break;
            case 3:
                std::cout << "Enter task number to mark complete: ";
                std::cin >> index;
                todo.markComplete(index - 1);
                break;
            case 4:
                todo.showTasks();
                break;
            case 5:
                todo.saveToFile("tasks.txt");
                break;
            case 6:
                todo.loadFromFile("tasks.txt");
                break;
            case 0:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid option!" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
