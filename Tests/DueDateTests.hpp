#ifndef DUE_DATE_TESTS_HPP
#define DUE_DATE_TESTS_HPP
#include "../OrderTasks.hpp"
#include "../OrderByDueDate.hpp"
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
	task1->setTitle("Task 1");
	task1->setDueDate(5, 18, 2021);
    ListOfTasks.push_back(task1);

    EXPECT_EQ(test_printByDueDate(ListOfTasks), "1. Title: Task 1 Due date: 5/18/2021\n");
}

TEST(OrderByDueDateTest, NormalEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setDueDate(5, 18, 2021);
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setDueDate(4, 18, 2021);
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByDueDate(ListOfTasks), "1. Title: Task 2 Due date: 4/18/2021\n 2. Title: Task 1 Due date: 5/18/2021\n");
}

TEST(OrderByDueDateTest, OneDateEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setDueDate(4, 18, 2021);
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByDueDate(ListOfTasks), "1. Title: Task 2 Due date: 4/18/2021\n 2. Title: Task 1\n");
}

TEST(OrderByDueDateTest, NoDateEntry2){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByDueDate(ListOfTasks), "1. Title: Task 1\n 2. Title: Task 2\n");
}

TEST(OrderByDueDateTest, SameDateEntry){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setDueDate(5, 18, 2021);
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setDueDate(5, 18, 2021);
    ListOfTasks.push_back(task2);
    
    EXPECT_EQ(test_printByDueDate(ListOfTasks), "1. Title: Task 1 Due date: 5/18/2021\n 2. Title: Task 2 Due date: 5/18/2021\n");
}

TEST(OrderByDueDateTest, SameDateEntry2){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setDueDate(5, 18, 2021);
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setDueDate(5, 18, 2021);
    ListOfTasks.push_back(task2);
    
    Task* task3 = new Task();
    task3->setTitle("Task 3");
    task3->setDueDate(5, 18, 2021);
    ListOfTasks.push_back(task3);

    EXPECT_EQ(test_printByDueDate(ListOfTasks), "1. Title: Task 1 Due date: 5/18/2021\n 2. Title: Task 2 Due date: 5/18/2021\n 3. Title: Task 3 Due date: 5/18/2021\n");
}

TEST(OrderByDueDateTest, LotsOfDates){
    vector<Task*> ListOfTasks;

    Task* task1 = new Task();
	task1->setTitle("Task 1");
	task1->setDueDate(1, 1, 2021);
    ListOfTasks.push_back(task1);

    Task* task2 = new Task();
    task2->setTitle("Task 2");
    task2->setDueDate(1, 2, 2021);
    ListOfTasks.push_back(task2);
    
    Task* task3 = new Task();
    task3->setTitle("Task 3");
    task3->setDueDate(1, 3, 2021);
    ListOfTasks.push_back(task3);

    Task* task4 = new Task();
    task4->setTitle("Task 4");
    task4->setDueDate(1, 4, 2021);
    ListOfTasks.push_back(task4);

    Task* task5 = new Task();
    task5->setTitle("Task 5");
    task5->setDueDate(1, 5, 2021);
    ListOfTasks.push_back(task5);

    Task* task6 = new Task();
    task6->setTitle("Task 6");
    task6->setDueDate(1, 6, 2021);
    ListOfTasks.push_back(task6);
    
    Task* task7 = new Task();
    task7->setTitle("Task 7");
    task7->setDueDate(1, 7, 2021);
    ListOfTasks.push_back(task7);

    Task* task8 = new Task();
    task8->setTitle("Task 8");
    task8->setDueDate(1, 8, 2021);
    ListOfTasks.push_back(task8);

    EXPECT_EQ(test_printByDueDate(ListOfTasks), "1. Title: Task 1, Due date: 1/1/2021\n" +
                                                "2. Title: Task 2, Due date: 1/2/2021\n" +
                                                "3. Title: Task 3, Due date: 1/3/2021\n" +
                                                "4. Title: Task 4, Due date: 1/4/2021\n" +
                                                "5. Title: Task 5, Due date: 1/5/2021\n" +
                                                "6. Title: Task 6, Due date: 1/6/2021\n" +
                                                "7. Title: Task 7, Due date: 1/7/2021\n" +
                                                "8. Title: Task 8, Due date: 1/8/2021\n");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#endif