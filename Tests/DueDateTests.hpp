#ifndef DUE_DATE_TESTS_HPP
#define DUE_DATE_TESTS_HPP
#include "../OrderTasks.hpp"
#include "../OrderByDueDate.hpp"
#include "../SubtaskSchedule.hpp"
#include <vector>
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

void printTasks(vector<Task*>& ListOfTasks, OrderTasks* orderType, string classification = "") {
	orderType->display(ListOfTasks, classification);
}

void test_printByDueDate(vector<Task*>& ListOfTasks) {  //copied from OrderTasks_Test.cpp
	OrderByDueDate* orderDueDate = new OrderByDueDate();
	printTasks(ListOfTasks, orderDueDate);
}

TEST(OrderByDueDateTest, OneTask){
    vector<Task*> ListOfTasks;
    
    Task* task1 = new Task();
	task1->setTaskTitle("Task 1");
	task1->setTaskDueDate(5, 18, 2021);
    ListOfTasks.push_back(task1);

    EXPECT_EQ(test_printByDueDate(ListOfTasks), "1. Title: Task 1 Due date: 5/18/2021\n");
}

#endif
