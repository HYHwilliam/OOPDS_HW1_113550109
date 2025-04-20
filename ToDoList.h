#include <map>
#include <vector>
#include <algorithm>
#include "Task.h"

using namespace std;

class ToDoList
{
    private:
        map<int*, Task*> tasks;
        int* nextID;

    public:
        ToDoList() : nextID(new int(1)) {}

        ~ToDoList()
        {
            for (auto& pair : tasks)
            {
                delete pair.first;
                delete pair.second;
            }
            delete nextID;
        }

        void showMenu()
        {
            cout << "\n----------- To-Do List -----------\n";
            cout << "1. Add Task\n";
            cout << "2. View Tasks\n";
            cout << "3. Edit Task\n";
            cout << "4. Mark Task as Completed\n";
            cout << "5. Delete Task\n";
            cout << "6. Exit\n";
            cout << "----------------------------------\n";
        }

        bool isValidDate(const string* date)
        {
            if (date->length() != 10 || (*date)[4] != '-' || (*date)[7] != '-')
            {
                cout << "The format of DueDate is not correct." << endl;
                return false;
            }

            int* year = new int(0);
            int* month = new int(0);
            int* day = new int(0);
            int* i = new int(0);

            for (*i = 0; *i < 4; (*i)++)
            {
                if (!isdigit((*date)[*i]))
                {
                    cout << "The input of year is not correct." << endl;
                    delete i;
                    delete year;
                    delete month;
                    delete day;
                    return false;
                }
                *year = (*year) * 10 + ((*date)[*i] - '0');
            }


            for (*i = 5; *i < 7; (*i)++)
            {
                if (!isdigit((*date)[*i]))
                {
                    cout << "The input of month is not correct." << endl;
                    delete i;
                    delete year;
                    delete month;
                    delete day;
                    return false;
                }
                *month = (*month) * 10 + ((*date)[*i] - '0');
            }

            for (*i = 8; *i < 10; (*i)++)
            {
                if (!isdigit((*date)[*i]))
                {
                    cout << "The input of day is not correct." << endl;
                    delete i;
                    delete year;
                    delete month;
                    delete day;
                    return false;
                }
                *day = (*day) * 10 + ((*date)[*i] - '0');
            }
            delete i;

            if (*month < 1 || *month > 12 || *day < 1 || *day > 31)
            {
                cout << "Invalid Date." << endl;
                delete year;
                delete month;
                delete day;
                return false;
            }
            delete year;
            delete month;
            delete day;
            return true;
        }

        void addTask()
        {
            string* name = new string;
            string* category = new string;
            string* description = new string;
            string* dueDate = new string;

            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, *name);
            for (const auto& pair : tasks)
            {
                if (*(pair.second->GetName()) == *name)
                {
                    cout << "A task with this name already exists. Please enter a different name." << endl;
                    delete name;
                    delete category;
                    delete description;
                    delete dueDate;
                    return;
                }
            }
            cout << "Enter task category: ";
            getline(cin, *category);
            cout << "Enter task description: ";
            getline(cin, *description);

            while (true)
            {
                cout << "Enter task due date (YYYY-MM-DD): ";
                getline(cin, *dueDate);

                if (!isValidDate(dueDate))
                {
                    cout << "Please use the format YYYY-MM-DD and enter a valid date again." << endl;
                }
                else
                {
                    break;
                }
            }

            int* id = new int(*nextID);
            tasks[id] = new Task(*name, *category, *description, *dueDate);

            cout << "Task added successfully! ID: " << *id << endl;

            (*nextID)++;

            delete name;
            delete category;
            delete description;
            delete dueDate;
        }

        void viewTasks(bool* DisplayAll = new bool(false))
        {
            if (tasks.empty())
            {
                cout << "No tasks available." << endl;
                return;
            }
            if (*DisplayAll)
            {
                if (tasks.empty())
                {
                    cout << "You do not have any tasks." << endl;
                    return;
                }

                vector<pair<int*, Task*>> sortT(tasks.begin(), tasks.end());
                sort(sortT.begin(), sortT.end(),[](const pair<int*, Task*>& a, const pair<int*, Task*>& b)
                {
                    return *(a.first) < *(b.first);
                });

                for (const auto& pair : sortT)
                {
                    cout << "----------------------------------\n";
                    cout << "Task ID: " << *(pair.first) << "\n";
                    pair.second->displayTask();
                    cout << "----------------------------------\n";
                }

                return;
            }


            string* choice = new string("0");

            while(true)
            {
                cout << "\nWhich specific conditions would you like to display?\n";
                cout << "1. Display All(by ID)\n2. Name\n3. Completion status\n4. Category\n5. Due Date\n6. Exit\n";
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
                    {

                        if (tasks.empty())
                        {
                            cout << "You do not have any tasks." << endl;
                            break;
                        }

                        vector<pair<int*, Task*>> sortT(tasks.begin(), tasks.end());
                        sort(sortT.begin(), sortT.end(),[](const pair<int*, Task*>& a, const pair<int*, Task*>& b)
                        {
                            return *(a.first) < *(b.first);
                        });

                        for (const auto& pair : sortT)
                        {
                            cout << "----------------------------------\n";
                            cout << "Task ID: " << *(pair.first) << "\n";
                            pair.second->displayTask();
                            cout << "----------------------------------\n";
                        }

                        break;

                    }

                    case '2':
                    {
                        string* nameInput = new string;
                        cout << "Enter name: ";
                        cin.ignore();
                        getline(cin, *nameInput);

                        int* counter = new int(0);
                        for (const auto& pair : tasks)
                        {
                            if (*(pair.second->GetName()) == *nameInput)
                            {
                                (*counter)++;
                                cout << "----------------------------------\n" << "Task ID: " << *(pair.first) << endl;
                                pair.second->displayTask();
                                cout << "----------------------------------" << endl;
                            }
                        }
                        if (*counter == 0)
                        {
                            cout << "The Name does not exist." << endl;
                        }
                        delete counter;
                        delete nameInput;
                        break;
                    }

                    case '3':
                    {
                        bool* isCompleted = new bool;
                        cout << "Enter completion status (1 for Completed, 0 for Not Completed): ";
                        cin >> *isCompleted;

                        int* counter = new int(0);
                        for (const auto& pair : tasks)
                        {
                            if (*(pair.second->GetCompleted()) == *isCompleted)
                            {
                                (*counter)++;
                                cout << "----------------------------------\n" << "Task ID: " << *(pair.first) << endl;
                                pair.second->displayTask();
                                cout << "----------------------------------" << endl;
                            }
                        }
                        if (*counter == 0 && *isCompleted)
                        {
                            cout << "No Task is completed." << endl;
                        }
                        else if (*counter == 0 && !(*isCompleted))
                        {
                            cout << "All Tasks are completed." << endl;
                        }
                        delete counter;
                        delete isCompleted;
                        break;
                    }

                    case '4':
                    {
                        string* categoryInput = new string;
                        cout << "Enter category: ";
                        cin.ignore();
                        getline(cin, *categoryInput);

                        int* counter = new int(0);
                        for (const auto& pair : tasks)
                        {
                            if (*(pair.second->GetCategory()) == *categoryInput)
                            {
                                (*counter)++;
                                cout << "----------------------------------\n" << "Task ID: " << *(pair.first) << endl;
                                pair.second->displayTask();
                                cout << "----------------------------------" <<endl;
                            }
                        }
                        if (*counter == 0)
                        {
                            cout << "No such Category." << endl;
                        }
                        delete counter;
                        delete categoryInput;
                        break;
                    }

                    case '5':
                    {
                        if (tasks.empty())
                        {
                            cout << "You do not have any tasks." << endl;
                            break;
                        }

                        vector<pair<int*, Task*>> Tsort(tasks.begin(), tasks.end());
                        sort(Tsort.begin(), Tsort.end(), [](const pair<int*, Task*>& a, const pair<int*, Task*>& b)
                        {
                            return *(a.second->GetDueDate()) < *(b.second->GetDueDate());
                        });

                        for (const auto& pair : Tsort)
                        {
                            cout << "----------------------------------\n" << "Task ID: " << *(pair.first) << endl;
                            pair.second->displayTask();
                            cout << "----------------------------------" << endl;
                        }
                        break;
                    }

                    case '6':
                    {
                        cout << "Exiting view mode.\n" << endl;
                        cout << "----------------------------------\n";
                        delete choice;
                        return;
                    }
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            }
        }


        void editTask(ToDoList* tlist)
        {
            if (tasks.empty())
            {
                cout << "No tasks available." << endl;
                return;
            }
            cout << "Enter task ID or name to edit: ";
            string* input = new string;
            cin.ignore();
            getline(cin, *input);

            try
            {
                int* idInput = new int(stoi(*input));
                for (auto it = tasks.begin(); it != tasks.end(); ++it)
                {
                    if (*(it->first) == *idInput)
                    {
                        modifyAttributes(it->second, tlist);
                        delete idInput;
                        delete input;
                        return;
                    }
                }
                cout << "Invalid task ID." << endl;
                delete idInput;
                delete input;
                return;
            }
            catch (invalid_argument& e)
            {
                for (auto it = tasks.begin(); it != tasks.end(); ++it)
                {
                    if (*(it->second->GetName()) == *input)
                    {
                        modifyAttributes(it->second, tlist);
                        delete input;
                        return;
                    }
                }
                cout << "No task found with name \"" << *input << "\"." << endl;
            }
            delete input;
        }

        void modifyAttributes(Task* task, ToDoList* tlist)
        {
            string* newValue = new string;
            string* choice = new string("0");

            while (true)
            {
                *choice = "0";
                cout << "\nWhich attribute would you like to edit?\n";
                cout << "1. Name\n2. Category\n3. Description\n4. Due Date\n5. Exit Editing\n";
                cout << "Enter your choice: ";
                cin >> *choice;
                if (choice->length() != 1)
                {
                    cout << "Invalid input. Please enter a single character." << endl;
                    continue;
                }
                bool* displayall = nullptr;
                switch ((*choice)[0])
                {
                    case '1':
                        cout << "Enter new name: ";
                        cin.ignore();
                        getline(cin, *newValue);
                        task->SetName(newValue);
                        break;
                    case '2':
                        cout << "Enter new category: ";
                        cin.ignore();
                        getline(cin, *newValue);
                        task->SetCategory(newValue);
                        break;
                    case '3':
                        cout << "Enter new description: ";
                        cin.ignore();
                        getline(cin, *newValue);
                        task->SetDescription(newValue);
                        break;
                    case '4':
                        cout << "Enter new due date (YYYY-MM-DD): ";
                        cin.ignore();
                        getline(cin, *newValue);
                        task->SetDueDate(newValue);
                        break;
                    case '5':
                        cout << "Exiting edit mode.\n" << endl;
                        cout << "----------------------------------\n";
                        delete newValue;
                        delete choice;
                        displayall = new bool(true);
                        tlist->viewTasks(displayall);
                        delete displayall;
                        return;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                cout << "Task updated successfully!" << endl;
            }
        }

        void markTaskCompleted()
        {
            if (tasks.empty())
            {
                cout << "No tasks available." << endl;
                return;
            }
            cout << "Enter task ID or name to mark as completed: ";
            string* input = new string;
            cin.ignore();
            getline(cin, *input);

            try
            {
                int* idInput = new int(stoi(*input));
                for (auto it = tasks.begin(); it != tasks.end(); ++it)
                {
                    if (*(it->first) == *idInput)
                    {
                        cout << "Task \"" << *(it->second->GetName()) << "\" marked as completed!" << endl;
                        it->second->markCompleted();
                        delete idInput;
                        delete input;
                        return;
                    }
                }
                cout << "Invalid task ID." << endl;
                delete idInput;
                delete input;
                return;
            }
            catch (invalid_argument& e)
            {
                for (auto it = tasks.begin(); it != tasks.end(); ++it)
                {
                    if (*(it->second->GetName()) == *input)
                    {
                        cout << "Task \"" << *(it->second->GetName()) << "\" marked as completed!" << endl;
                        it->second->markCompleted();
                        delete input;
                        return;
                    }
                }
                cout << "No task found with name \"" << *input << "\"." << endl;
            }
            delete input;
        }


        void deleteTask()
        {
            if (tasks.empty())
            {
                cout << "No tasks available." << endl;
                return;
            }
            cout << "Enter task ID or name to delete: ";
            string* input = new string;
            cin.ignore();
            getline(cin, *input);

            try
            {
                int* idInput = new int(stoi(*input));
                for (auto it = tasks.begin(); it != tasks.end(); ++it)
                {
                    if (*(it->first) == *idInput)
                    {
                        cout << "Task \"" << *(it->second->GetName()) << "\" deleted successfully!" << endl;
                        delete it->first;
                        delete it->second;
                        tasks.erase(it);
                        delete idInput;
                        delete input;
                        return;
                    }
                }
                cout << "Invalid task ID." << endl;
                delete idInput;
                delete input;
                return;
            }
            catch (invalid_argument& e)
            {
                for (auto it = tasks.begin(); it != tasks.end(); ++it)
                {
                    if (*(it->second->GetName()) == *input)
                    {
                        cout << "Task \"" << *(it->second->GetName()) << "\" deleted successfully!" << endl;
                        delete it->first;
                        delete it->second;
                        tasks.erase(it);
                        delete input;
                        return;
                    }
                }
                cout << "No task found with name \"" << *input << "\"." << endl;
            }
            delete input;
        }

} ;

