#include "StudentManagementSystem.h"

//Constructor
StudentManagementSystem::StudentManagementSystem(): root(nullptr), head(nullptr) {}

//Destructor to free memory
StudentManagementSystem::~StudentManagementSystem()
{
    clearTree(root);
    clearList();
}
