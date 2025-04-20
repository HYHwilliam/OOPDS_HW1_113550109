#include <iostream>
#include <string>

using namespace std;

class Basic_task
{
    protected:
        string* name;
        string* category;
        bool* completed;

    public:
        Basic_task(const string& name, const string& category, bool completed = false)
            : name(new string(name)), category(new string(category)), completed(new bool(completed)) {}

        virtual ~Basic_task()
        {
            delete name;
            delete category;
            delete completed;
        }

        const string* GetName() const
        {
            return name;
        }
        void SetName(const string* newName)
        {
            *name = *newName;
        }
        const string* GetCategory() const
        {
            return category;
        }
        void SetCategory(const string* newCategory)
        {
            *category = *newCategory;
        }
        const bool* GetCompleted() const
        {
            return completed;
        }

        virtual void displayTask() const
        {
            cout << "Task: " << *name << endl << "Category: " << *category
                 << endl << "Status: " << (*completed ? "Completed" : "Not Completed") << endl;
        }

        void markCompleted()
        {
            *completed = true;
        }
};
