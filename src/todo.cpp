#include "todo.h"
#include <iostream>
#include <fstream>

void Todo::addTask(const std::string& task) {
    tasks.push_back({task, false});
}

void Todo::deleteTask(int index) {
    if (index < 0 || index >= tasks.size()) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    tasks.erase(tasks.begin() + index);
}

void Todo::markComplete(int index) {
    if (index < 0 || index >= tasks.size()) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    tasks[index].second = true;
}

void Todo::showTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks available." << std::endl;
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].first;
        if (tasks[i].second) std::cout << " [DONE]";
        std::cout << std::endl;
    }
}

void Todo::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    for (const auto& task : tasks) {
        outFile << task.first << "," << task.second << "\n";
    }
    outFile.close();
}

void Todo::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "No saved file found." << std::endl;
        return;
    }
    tasks.clear();
    std::string task;
    bool status;
    while (inFile >> task >> status) {
        tasks.push_back({task, status});
    }
    inFile.close();
}
