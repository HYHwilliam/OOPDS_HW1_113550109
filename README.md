# OOPDS_HW1_113550109
## My ToDoList
----------------------
# How to use
## Adding a new task
1. Select the "Add Task" option from the main menu. (option 1)
2. Enter the required details:
   - Name: The title of the task.
   - Category: The category or group to which the task belongs.
   - Description: A detailed description of the task.
   - Due Date: The deadline for the task in the YYYY-MM-DD format.
  (- Completion Status: You do not need to input, it will set as not completed as default.)
3. Confirm the task creation, and the task will be added to your list.

## Viewing tasks
1. Select the "View Tasks" option from the main menu. (option 2)
2. Choose from the following filtering options :
   - 1: Display All (by ID): View all tasks sorted by their IDs.
   - 2: By Name: Enter a name to display tasks that match the input.
   - 3: By Completion Status: Filtered by completed or not completed tasks.
   - 4: By Category: Enter a category to display tasks that belong to it.
   - 5: By Due Date: View all tasks sorted by their due dates.
   - 6: Exit: Leave the task view.

3. The application will display the tasks according to your selected filtering condition

## 3. Edit a Specific Task
1. Select the "Edit Task" option from the main menu. (option 3)
2. Enter the Task ID to select the task you wish to modify.
3. Choose the attribute you want to change:
   - 1: Name: Update the task title.
   - 2: Category: Update the task category.
   - 3: Description: Update the task description.
   - 4: Due Date: Change the deadline for the task.
   - 5: Exit: Leave edit mode without making further changes.

4. Provide the new value for the selected attribute.
5. Your task will be updated immediately.
6. Once you exit the "Edit Task" mode, the application will display all tasks for a quick review.

## 4. Mark Task as Completed:
1. Select the "Mark Task as Completed" option from the main menu to mark a task as done. (option 4)
2. Enter the Task ID of the task or the Task Name to update its completion status.
3. Sort Tasks by Due Date:- The "Due Date" filter automatically arranges tasks chronologically.

## 5. Delete a Task
1. Select the "Delete Task" option from the main menu. (option 5)
2. Enter the Task ID of the task or the Task Name you want to delete.
3. The task will be removed from your list.

## 6. Exit the ToDoList:
1. Select the "Exit" option from the main menu. (option 6)
2. Exit!!

# Some other function in my program 
## 1. about showMenu function:
Will display the menu:
     1: Add Task: Allows users to create a new task by entering details such as name, category, description, and due date.
     2: View Tasks: Displays all tasks with filtering options, including sorting by name, category, completion status, and due date.
     3: Edit Task: Enables users to modify attributes of an existing task, such as updating its name, category, description, or due date.
     4: Mark Task as Completed: Allows users to mark a specific task as completed.
     5: Delete Task: Permanently removes a task from the list based on the selected task ID or name.
     6: Exit: Closes the application and ends the session.

## 2. The isValidDate function:
The function is designed to:
   - Check format: Ensures the input follows the expected YYYY-MM-DD pattern.
   - Extract values: Verifies the year, month, and day as numeric values.
   - Prevent invalid dates: Ensures month and day values are within a valid range. (Month is 1-12, Day is 1-31) 

## 3. The modifyAttributes function: 
User selects an attribute to edit from the following options:
     - 1: Name → Change the task title.
     - 2: Category → Update the task classification.
     - 3: Description → Modify task details.
     - 4: Due Date → Set a new deadline (YYYY-MM-DD format).
     - 5: Exit Editing → Stop editing and display all tasks.
The respective attribute is updated for the selected task.

# About Handling invalid user input:
1. Input Validation:
   - Ensures that user inputs match the expected format (e.g., YYYY-MM-DD for dates).
   - Restricts menu selection to valid options (e.g., out-of-range number).

2. Will Displays clear error messages when user inputs are invalid, to let user understand what mistake they made.

3. Retry Mechanism:
   - Retry: Clears the input and lets users re-enter valid data without crashing the program.
























