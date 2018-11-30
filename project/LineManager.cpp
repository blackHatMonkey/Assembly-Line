#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "LineManager.h"
#include "Utilities.h"

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
 * @brief
 *
 * @param out
 * @return true
 * @return false
 */
auto LineManager::run(std::ostream &out) -> bool {
  if (ToBeFilled.size()) {
    *(AssemblyLine.back()) += std::move(ToBeFilled.back());
    ToBeFilled.pop_back();
  }
  for (auto &task : AssemblyLine) {
    task->runProcess(out);
  }

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

  if (m_cntCustomerOrder == Completed.size()) {
    return true;
  } else {
    return false;
  }
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
 * @brief
 *
 */
auto LineManager::validateTasks() const -> void {
  for (auto task : AssemblyLine) {
    task->validate(std::cout);
  }
}