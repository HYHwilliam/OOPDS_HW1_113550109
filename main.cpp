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
            {
                string* input = new string("0");
                int counter = 0;

                while (counter < 3)
                {
                    cout << "Exiting program... Are you sure? (y/n): ";
                    cin >> *input;
                    if (input->length() != 1)
                    {
                        cout << "Invalid input. Please enter a single character." << endl;
                        continue;
                    }
                    if (((*input)[0] != 'y' && (*input)[0] != 'Y' && ((*input)[0] != 'n' && (*input)[0] != 'N')))
                    {
                        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                        continue;
                    }

                    if ((*input)[0] == 'y' || (*input)[0] == 'Y')
                    {
                        counter++;
                        switch (counter)
                        {
                            case 1:
                                cout << "You sure? Have you completed all your tasks? You lazy guy!!" << endl;
                                break;
                            case 2:
                                cout << "Nah. Face yourself. You see see you, that's not good!" << endl;
                                break;
                            case 3:
                            {
                                cout << "You are the freeloader! Fine, I'll let you exit." << endl;
                                cout << "Program is now closing. You best return here soon!" << endl;
                                delete choice;
                                delete todoList;
                                delete input;
                                return 0;
                            }

                        }

                    }
                    else if ((*input)[0] == 'n' || (*input)[0] == 'N')
                    {
                        cout << "That's great! Keep working hard and conquer your tasks!" << endl;
                        delete input;
                        break;
                    }
                }
                break;
            }

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
