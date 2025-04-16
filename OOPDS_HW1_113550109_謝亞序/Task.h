#include "Basic_Task.h"

using namespace std;

class Task : public Basic_task
{
    private:
        string* description;
        string* dueDate;

    public:
        Task(const string& name, const string& category, const string& description, const string& dueDate)
            : Basic_task(name, category), description(new string(description)), dueDate(new string(dueDate)) {}

        ~Task()
        {
            delete description;
            delete dueDate;
        }

        const string* GetDescription() const
        {
            return description;
        }

        void SetDescription(const string* newDescription)
        {
            *description = *newDescription;
        }

        const string* GetDueDate() const
        {
            return dueDate;
        }

        void SetDueDate(const string* newDueDate)
        {
            *dueDate = *newDueDate;
        }

        void displayTask() const override
        {
            Basic_task::displayTask();
            cout << "Description: " << *description << "\nDue Date: " << *dueDate << endl;
        }
};

