#ifndef TODO_H
#define TODO_H

#include <string>
#include <vector>

class Todo {
public:
    void addTask(const std::string& task);
    void deleteTask(int index);
    void markComplete(int index);
    void showTasks() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::vector<std::pair<std::string, bool>> tasks;
};

#endif
