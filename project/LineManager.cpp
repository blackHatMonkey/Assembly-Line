/*
 * Name: Brian Smith
 * Seneca Student ID: 137105177
 * Seneca email: bsmith55@myseneca.ca
 * Date of completion: 12/22/2018
 *
 * I confirm that I am the only author of this file
 * and the content was created entirely by me.
 */

#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "LineManager.h"
#include "Utilities.h"

/**
 * @brief Construct a new Line Manager:: Line Manager object
 *
 * @param fileName Name of file to find the assembly line order.
 * @param tasks A vector of tasks.
 * @param orders A vector of customer orders.
 */
LineManager::LineManager(const std::string &fileName,
                         std::vector<Task *> &tasks,
                         std::vector<CustomerOrder> &orders) {

  // need to convert in order to store in class
  for (auto &order : orders) {
    ToBeFilled.push_front(std::move(order));
  }

  m_cntCustomerOrder = ToBeFilled.size();
  AssemblyLine = tasks;

  Utilities::setDelimiter('|');
  Utilities util;

  for (std::ifstream file(fileName); !file.eof();) {
    std::string task1, task2, line;
    auto more = true;
    auto pos = (size_t)0;

    std::getline(file, line);

    task1 = util.extractToken(line, pos, more);

    // capture the second task
    if (more) {
      task2 = util.extractToken(line, pos, more);

      Task *taskAddress11, *taskAddress2;

      // need to find pointers to link them
      for (auto &task : AssemblyLine) {
        if (task->getName() == task1) {
          taskAddress11 = task;
        } else if (task->getName() == task2) {
          taskAddress2 = task;
        }
      }
      // link the tasks to create the assembly line
      taskAddress11->setNextTask(*taskAddress2);
    }
  }
}

/**
 * @brief Run a single cycle of the assembly line.
 *
 * @param out An ostream object to print output.
 * @return true In case all the orders are completed.
 * @return false In case not all all the orders are completed.
 */
auto LineManager::run(std::ostream &out) -> bool {
  if (!ToBeFilled.empty()) {
    *(AssemblyLine.back()) += std::move(ToBeFilled.back());
    ToBeFilled.pop_back();
  }

  // fill all orders in each task
  for (auto &task : AssemblyLine) {
    task->runProcess(out);
  }

  // take out any of the compeleted orders from the line
  for (auto &task : AssemblyLine) {
    CustomerOrder co;
    if (task->getCompleted(co)) {
      if (co.getOrderFillState()) {
        Completed.push_front(std::move(co));
      } else {
        *task += std::move(co);
      }
    }
    task->moveTask();
  }

  return m_cntCustomerOrder == Completed.size();
}

/**
 * @brief Display completed orders.
 *
 * @param out an ostream object to output to.
 */
auto LineManager::displayCompleted(std::ostream &out) const -> void {
  for (const auto &order : Completed) {
    order.display(out);
  }
}

/**
 * @brief Validate each task on the assembly line.
 *
 */
auto LineManager::validateTasks() const -> void {
  for (const auto &task : AssemblyLine) {
    task->validate(std::cout);
  }
}