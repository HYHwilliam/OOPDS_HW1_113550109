#include "ToDoList.h"

int main()
{
    ToDoList* todoList = new ToDoList();
    string* choice = new string("0");

    while (true)
    {
        todoList->showMenu();
        cout << "Enter your choice: ";
        cin >> *choice;

        if (choice->length() != 1)
        {
            cout << "Invalid input. Please enter a single character." << endl;
            continue;
        }

        switch ((*choice)[0])
        {
            case '1':
                todoList->addTask();
                break;
            case '2':
                todoList->viewTasks();
                break;
            case '3':
                todoList->editTask(todoList);
                break;
            case '4':
                todoList->markTaskCompleted();
                break;
            case '5':
                todoList->deleteTask();
                break;
            case '6':
                cout << "Exiting program..." << endl;
                delete choice;
                delete todoList;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
