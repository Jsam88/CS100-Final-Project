//CS100 FINAL PROJECT
#ifndef _TASKMENU_HPP_
#define _TASKMENU_HPP_

#include "SetupTaskFiles.hpp"
#include "SubtaskSchedule.hpp"
#include "SubtaskSingularTask.hpp"
#include "OrderByDueDate.hpp"
#include "OrderByPriority.hpp"
#include "OrderByTaskType.hpp"
#include "OrderTasks.hpp"
#include "Task.hpp"


#include <iostream>
#include <string>
#include <vector>

using namespace std;
class SingularSubtask;
class ScheduleSubtask;

class Menu : public SetupTaskFiles   {
    private:
        vector<Task*> tasks;
        void printTasks(vector<Task*>& ListOfTasks, OrderTasks* orderType, string classification = "");
        void printByDueDate(vector<Task*>& ListOfTasks);
        void printByPriority(vector<Task*>& ListOfTasks);
        void printByClassification(vector<Task*>& ListOfTasks, string classification);
        
    public:
    int userNumber;
    void printTaskMenu();
    void printScheduleActions();
    int getUserNumber(){
        return userNumber;
    }


//===========================================================================

        void printTaskMenu() {
            cout << "Welcome to the Task Menu. What would you like to do?" << endl;
            cout << "-------------------------------------" << endl
                 << "a - View all schedules and tasks" << endl
                 << "b - Create a Schedule" << endl
                 << "c - Create a Task" << endl
                 << "d - Edit a Schedule" << endl
                 << "e - Edit a Task" << endl
                 << "f - Display by due date" << endl
                 << "g - Display by priority" << endl
                 << "h - Display by Classification" << endl
                 << "i - Delte all Schedules and Tasks" << endl
                 << "q - Exit Task Scheduler" << endl
                 << "-------------------------------------" << endl << endl
                 << "Choose an option: ";
                 TaskMenu();
        }

        void printScheduleActions() {                                       //Schedule is essentially a folder in this case
            cout << "What would you like to do with this schedule?" << endl
                 << "-------------------------------------" << endl
                 << "a - Rename Schedule Title" << endl
                 << "b - Set priority" << endl
                 << "c - Set Description" << endl
                 << "d - Set Due Date" << endl
                 << "e - Set Classification" << endl
                 << "f - Embed another Schedule" << endl
                 << "g - Delete this Schedule" << endl
                 << "q - Return to Task Scheduler" << endl
                 << "-------------------------------------" << endl << endl
                 << "Choose an option: ";
                 ScheduleActions();
        }

        void printTaskActions() {
            cout << "What would you like to do with this Task?" << endl
                 << "-------------------------------------" << endl
                 << "a - Rename Task Title" << endl
                 << "b - Set priority" << endl
                 << "c - Set Description" << endl
                 << "d - Set Due Date" << endl
                 << "e - Set Classification" << endl
                 << "f - Embed another Schedule" << endl
                 << "g - Delete this Task" << endl
                 << "q - Return to Task Scheduler" << endl
                 << "-------------------------------------" << endl << endl
                 << "Choose an option: ";
                 TaskActions();
        }
        
        
        void TaskMenu() {
            char input;
            string userInput = "";
            printTaskMenu();
            cin >> input;
            cout << endl;

            while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' && 
                   input != 'C' && input != 'd' && input != 'D' && input != 'e' && input != 'E' && 
                   input != 'f' && input != 'F' && input != 'g' && input != 'G' && input != 'h' &&
                   input != 'H' && input != 'q' && input != 'Q') {
                cout << "Error: Unknown input. Please Select a valid option: ";
                cin >> input;
                cout << endl;
            }

            if (input == 'a' || input == 'A') {             //INPUT A = VIEW SCHEDULE(S) DONE
                if ( tasks.empty() == true){
                    cout << "There are no Schedules." << endl;
                }

                else{
                    for(int l = 0; l < tasks.size(); l++) {
                        cout << l + 1 << ")" << endl;
                        tasks.at(l)->displayTask();
                        numberOfIndents = 1;
                        firstLayerDirectorySubtaskDisplayFlag = 0;
                    }
                }
                cout << endl;
                printTaskMenu();
            }

            else if (input == 'b' || input == 'B') {             //INPUT B = CREATE A SCHEDULE
                vector<Task*> listOfTasks;
                ScheduleSubtask* schedule = new ScheduleSubtask("", "", "", "", "", listOfTasks);
                tasks.push_back(schedule);

                cout << "Type in a Schedule title followed by ENTER:" << endl;
                string title;
                getline(cin, title);
                //setTaskTitle(title);
                tasks.at(tasks.size() - 1)->setTaskTitle(title);

                createSchedule(title);

                cout << "Type in the new schedules priority (high, medium, or low) followed by ENTER:" << endl;
                string priority;
                getline(cin, priority);
                tasks.at(tasks.size() - 1)->setTaskPriority(priority);

                cout << "Type in the new schedules description followed by ENTER:" << endl;
                string description;
                getline(cin, description);
                tasks.at(tasks.size() - 1)->setTaskDescription(description);

                cout << "Type in the new schedules due date (mm/dd/year) followed by ENTER:" << endl;
                string dueDate;
                getline(cin, dueDate);
                tasks.at(tasks.size() - 1)->setTaskDueDate(dueDate);

                cout << "Type in the new schedules task type followed by ENTER:" << endl;
                string taskType;
                getline(cin, taskType);
                tasks.at(tasks.size() - 1)->setTaskType(taskType);

                tasks.at(tasks.size() - 1)->saveTaskInformation();      //save the information
                importTasks();
                cout << endl;
                printTaskMenu();               //return to main menu
            }

            else if (input == 'c' || input == 'C') {        //INPUT C = CREATE A TASK
                SingularSubtask* singularTask = new SingularSubtask("", "", "", "", "");
                tasks.push_back(singularTask);

                cout << "Type in a task title followed by ENTER:" << endl;
                string title;
                getline(cin, title);
                //setTaskTitle(title);
                tasks.at(tasks.size() - 1)->setTaskTitle(title);

                createSchedule(title);

                cout << "Type in the new task priority (high, medium, or low) followed by ENTER:" << endl;
                string priority;
                getline(cin, priority);
                tasks.at(tasks.size() - 1)->setTaskPriority(priority);

                cout << "Type in the new task description followed by ENTER:" << endl;
                string description;
                getline(cin, description);
                tasks.at(tasks.size() - 1)->setTaskDescription(description);

                cout << "Type in the new task due date (mm/dd/year) followed by ENTER:" << endl;
                string dueDate;
                getline(cin, dueDate);
                tasks.at(tasks.size() - 1)->setTaskDueDate(dueDate);

                cout << "Type in the new task task type followed by ENTER:" << endl;
                string taskType;
                getline(cin, taskType);
                tasks.at(tasks.size() - 1)->setTaskType(taskType);

                tasks.at(tasks.size() - 1)->saveTaskInformation();      //save the information
                importTasks();
                cout << endl;
                printTaskMenu();               //return to main menu
            }

            else if (input == 'd' || input == 'D') {        //INPUT D = EDIT SCHEDULE
                if(tasks.empty() == true){
                    cout << "There are no schedules to edit." << endl;
                }

                else{
                    cout << "Which schedule would you like to edit? Please enter the corresponding number next to the Schedule";
                    for(int l = 0; l < tasks.size(); l++) {
                        cout << l + 1 << ")" << endl;
                        tasks.at(l)->displayTask();
                        numberOfIndents = 1;
                        firstLayerDirectorySubtaskDisplayFlag = 0;
                    }

                    cin >> userNumber;
                    while(!(cin >> userNumber) ||userNumber > tasks.size() || userNumber <= 0) { 
                        cout << "ERROR: Enter a valid number:" << endl;
                        cin >> userNumber;
                        cout << endl;
                    }
                    if(tasks.at(userNumber - 1)->checkTaskType() == "Schedule Task"){
                        cout << endl << tasks.at(userNumber - 1) << " - ";      //subtract 1 to get the right cell inside vector
                    }
                    else{
                        cout << "ERROR: Entered Invalid Schedule. Returning to main menu." << endl;
                        printTaskMenu();
                    }
                }
                    printScheduleActions(); 
            }

            else if (input == 'e' || input == 'E') {        //INPUT E = EDIT TASK NEEDS HELP
                if(tasks.empty() == true){
                    cout << "There are no tasks to edit." << endl;
                }

                else{
                    cout << "Which task would you like to edit? Please enter the corresponding number next to the task";
                    for(int l = 0; l < tasks.size(); l++) {
                        cout << l + 1 << ")" << endl;
                        tasks.at(l)->displayTask();
                        numberOfIndents = 1;
                        firstLayerDirectorySubtaskDisplayFlag = 0;
                    }

                    cin >> userNumber;
                    while(!(cin >> userNumber) || userNumber > tasks.size() || userNumber <= 0) {
                        cout << "ERROR: Enter a valid number:" << endl;
                        cin >> userNumber;
                        cout << endl;
                    }

                    if(tasks.at(userNumber - 1)->checkTaskType() == "Singular Task"){
                        cout << endl << tasks.at(userNumber - 1) << " - ";      //subtract 1 to get the right cell inside vector
                    }
                    else{
                        cout << "ERROR: Entered Invalid Task. Returning to main menu." << endl;
                        printTaskMenu();
                    }
                
                }
                    printTaskActions(); 
            }

            else if (input == 'F' || input == 'F') {        //INPUT F = DUE DATE DISPLAY
                printByDueDate(tasks);
            }

            else if (input == 'g' || input == 'G') {        //INPUT G = PRIORITY DISPLAY
                printByPriority(tasks);
            }

            else if (input == 'h' || input == 'H') {        //INPUT H = CLASSIFICATION DISPLAY
                string classificationType;
                cout << "Enter the classification (work, personal, or academic) you want displayed on top" << endl;
                cin >> classificationType;
                    if (!(classificationType == "work" || classificationType == "personal" || classificationType == "academic")) {
                        while (!(classificationType == "work" || classificationType == "personal" || classificationType == "academic")){
                            cout << "Enter a valid classification (work, personal, or academic): " << endl;
                            cin >> classificationType;
                        }
                    }

                printByClassification(tasks, classificationType);
            }
            else if (input == 'i' || input == 'I') {        //INPUT I = DELETE ALL SCHEDULES/TASKS
                for(int l = 0; l < tasks.size(); l++) {
                        delete tasks.at(l);
                    }
            }
            else if (input == 'q' || input == 'Q') {        //INPUT Q = QUIT PROGRAM
                cout << "See you later!" << endl;
                exit;
            }
        }

    };

        //================================================================================

// int getUserNumber();
// void printScheduleActions();        //CHECK IF THIS REDEFINES IT HERE
// void printTaskMenu();

void ScheduleActions(){
            char input;
            printScheduleActions();
            cin >> input;
            cout << endl;

            while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' && 
                   input != 'C' && input != 'd' && input != 'D' && input != 'e' && input != 'E' && 
                   input != 'f' && input != 'F' && input != 'g' && input != 'G' && input != 'q' && 
                   input != 'Q') {
                cout << "Error: Unknown input. Please Select a valid option: ";
                cin >> input;
                cout << endl;
            }

            if (input == 'a' || input == 'A') {        //INPUT A = RENAME SCHEDULE
            cout << "What would you like to rename your schedule to?";
                string rename;
                getline(cin, rename);
                tasks.at(getUserNumber() - 1)->setTaskTitle(rename);
                cout << "Your Schedule has been re-named to " << rename << '!' << endl;
                tasks->saveTaskInformation();
                importTasks();
                printScheduleActions();
            }

            else if (input == 'b' || input == 'B') {        //INPUT B = SET SCHEDULE PRIORITY
                string setPriority;
                getline(cin, setPriority);
                tasks.at(getUserNumber() - 1)->setTaskPriority(setPriority);
                cout << "Your Schedule has been re-prioritized to " << setPriority << '!' << endl;
                tasks->saveTaskInformation();
                importTasks();
                printScheduleActions();
            }

            else if (input == 'c' || input == 'C') {        //INPUT C = SET SCHEDULE DESCRIPTION
                string newDescription;
                getline(cin, newDescription);
                setTaskDescription(newDescription);
                tasks.at(getUserNumber() - 1)->setTaskDescription(newDescription);
                cout << "Your Schedule has been re-described to " << newDescription << '!' << endl;
                tasks->saveTaskInformation();
                importTasks();
                printScheduleActions();
            }

            else if (input == 'd' || input == 'D') {        //INPUT D = SET SCHEDULE DUE DATE
                string dueDate;
                getline(cin, dueDate);
                tasks.at(getUserNumber() - 1)->setTaskDueDate(dueDate);
                cout << "Your Schedule date has been changed to " << dueDate << '!' << endl;
                tasks->saveTaskInformation();
                importTasks();
                printScheduleActions();
            }
            
            else if (input == 'e' || input == 'E') {        //INPUT E = SET SCHEDULE CLASSIFICATION
                string setClassification;
                getline(cin, setClassification);
                tasks.at(getUserNumber() - 1)->setTaskClassification(setClassification);
                cout << "Your Schedule date has been changed to " << setClassification << '!' << endl;
                tasks->saveTaskInformation();
                importTasks();
                printScheduleActions();
            }

            else if (input == 'f' || input == 'f') {        //INPUT F = EMBED ANOTHER SCHEDULE
                // cout << "Type in a Schedule title followed by ENTER:" << endl;
                // string title;
                // getline(cin, title);
                // setTaskTitle(title);

                // createSchedule();

                // cout << "Type in the new schedules priority followed by ENTER:" << endl;
                // string priority;
                // getline(cin, priority);
                // setTaskPriority(priority);

                // cout << "Type in the new schedules description followed by ENTER:" << endl;
                // string description;
                // getline(cin, description);
                // setTaskDescription(description);

                // cout << "Type in the new schedules due date followed by ENTER:" << endl;
                // string dueDate;
                // getline(cin, dueDate);
                // setTaskDueDate(dueDate);

                // cout << "Type in the new schedules task type followed by ENTER:" << endl;
                // string taskType;
                // getline(cin, taskType);
                // setTaskType(taskType);

                // tasks->saveTaskInformation();      //save the information
                // importTasks();
                // cout << endl;
                // printTaskMenu();               //return to main menu
            }
            else if (input == 'g' || input == 'G') {        //INPUT G = DELETE THIS SCHEDULE
                tasks.erase(tasks.at(getUserNumber() - 1));
                cout << "Your Schedule has successfully been deleted!\n Returning to main menu..." << endl;
                tasks->saveTaskInformation();
                importTasks();
                printTaskMenu();
            }
            else if (input == 'q' || input == 'Q') {        //INPUT Q = QUIT PROGRAM
                cout << "Back to main menu!" << endl;
                printTaskMenu();
            }
        }

        //=================================================================================
        void printTaskActions();
        void TaskActions(){
            char input;
            printTaskActions();
            cin >> input;
            cout << endl;

            while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' && 
                   input != 'C' && input != 'd' && input != 'D' && input != 'e' && input != 'E' && 
                   input != 'f' && input != 'F' && input != 'g' && input != 'G' && input != 'q' && 
                   input != 'Q') {
                cout << "Error: Unknown input. Please Select a valid option: ";
                cin >> input;
                cout << endl;
            }

            if (input == 'a' || input == 'A') {        //INPUT A = RENAME TASK
            cout << "What would you like to rename your task to?";
                string rename;
                getline(cin, rename);
                tasks.at(getUserNumber() - 1)->setTaskTitle(rename);
                cout << "Your task has been re-named to " << rename << '!' << endl;
                tasks->saveTaskInformation();
                importTasks();
                printTaskActions();
            }

            else if (input == 'b' || input == 'B') {        //INPUT B = SET TASK PRIORITY
                string setPriority;
                getline(cin, setPriority);
                tasks.at(getUserNumber() - 1)->setTaskPriority(setPriority);
                cout << "Your task has been re-prioritized to " << setPriority << '!' << endl;
                tasks->saveTaskInformation();
                importTasks();
                printTaskActions();
            }

            else if (input == 'c' || input == 'C') {        //INPUT C = SET TASK DESCRIPTION
                string newDescription;
                getline(cin, newDescription);
                setTaskDescription(newDescription);
                tasks.at(getUserNumber() - 1)->setTaskDescription(newDescription);
                cout << "Your task has been re-described to " << newDescription << '!' << endl;
                tasks->saveTaskInformation();
                importTasks();
                printTaskActions();
            }

            else if (input == 'd' || input == 'D') {        //INPUT D = SET TASK DUE DATE
                string dueDate;
                getline(cin, dueDate);
                tasks.at(getUserNumber() - 1)->setTaskDueDate(dueDate);
                cout << "Your Task date has been changed to " << dueDate << '!' << endl;
                tasks->saveTaskInformation();
                importTasks();
                printTaskActions();
            }
            
            else if (input == 'e' || input == 'E') {        //INPUT E = SET TASK CLASSIFICATION
                string setClassification;
                getline(cin, setClassification);
                tasks.at(getUserNumber() - 1)->setTaskClassification(setClassification);
                cout << "Your Task date has been changed to " << setClassification << '!' << endl;
                tasks->saveTaskInformation();
                importTasks();
                printTaskActions();
            }

            else if (input == 'f' || input == 'F') {        //INPUT F = EMBED ANOTHER TASK
                // cout << "Type in a Task title followed by ENTER:" << endl;
                // string title;
                // getline(cin, title);
                // tasks.at(getUserNumber() - 1)->setTaskTitle(title);                                          //WE WANT TO FORMAT EVERYTHING LIKE THIS

                // cout << "Type in the new schedules priority followed by ENTER:" << endl;
                // string priority;
                // getline(cin, priority);
                // setTaskPriority(priority);

                // cout << "Type in the new schedules description followed by ENTER:" << endl;
                // string description;
                // getline(cin, description);
                // setTaskDescription(description);

                // cout << "Type in the new schedules due date followed by ENTER:" << endl;
                // string dueDate;
                // getline(cin, dueDate);
                // setTaskDueDate(dueDate);

                // cout << "Type in the new schedules task type followed by ENTER:" << endl;
                // string taskType;
                // getline(cin, taskType);
                // setTaskDescription(taskType);

                // saveTaskInformation();      //save the information

                // cout << endl;
                // printTaskMenu();            //return to main menu
            }

            else if (input == 'g' || input == 'G') {        //INPUT G = DELETE THIS TASK NEEDS HELP
                tasks.erase(tasks.at(getUserNumber() - 1));
                cout << "Your Schedule has successfully been deleted!\n Returning to main menu..." << endl;
                tasks->saveTaskInformation();
                importTasks();
                printTaskMenu();
            }

            else if (input == 'q' || input == 'Q') {        //INPUT Q = QUIT PROGRAM
                cout << "Main menu!" << endl;
                printTaskMenu();
            }
        }

        void printTasks(vector<Task*>& ListOfTasks, OrderTasks* orderType, string classification = "") {
            orderType->display(ListOfTasks, classification);
        }
        
        void printByDueDate(vector<Task*>& ListOfTasks) {
            OrderTasks* orderDueDate = new OrderByDueDate();
            printTasks(ListOfTasks, orderDueDate);
        }
        
        void printByPriority(vector<Task*>& ListOfTasks) {
            OrderTasks* orderPriority = new OrderByPriority();
            printTasks(ListOfTasks, orderPriority);
        }
        
        void printByClassification(vector<Task*>& ListOfTasks, string classification) {
            OrderTasks* orderTaskType = new OrderByTaskType();
            printTasks(ListOfTasks, orderTaskType, classification);
        }
#endif