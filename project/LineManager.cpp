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
  for (auto &order : orders) {
    ToBeFilled.push_front(std::move(order));
  }

  m_cntCustomerOrder = ToBeFilled.size();

  AssemblyLine = tasks;

  Utilities::setDelimiter('|');

  std::ifstream file(fileName);
  auto more = true;
  auto pos = (size_t)0;

  std::string section;
  std::string t1, t2;
  std::string line;
  Utilities util;

  while (!file.eof()) {
    more = true;
    Task *tp1 = nullptr;
    Task *tp2 = nullptr;
    t1 = "";
    t2 = "";
    std::getline(file, line);

    t1 = util.extractToken(line, pos, more);

    if (more) {
      t2 = util.extractToken(line, pos, more);

      for (auto &task : AssemblyLine) {
        if (task->getName() == t1) {
          tp1 = task;
        } else if (task->getName() == t2) {
          tp2 = task;
        }
      }
      tp1->setNextTask(*tp2);
    }
  }
}

auto LineManager::run(std::ostream &out) -> bool {
  if (ToBeFilled.size()) {
    // auto temp = std::move(ToBeFilled.back());
    if (times < 4) {
      *(AssemblyLine.back()) += std::move(ToBeFilled.back());
      ToBeFilled.pop_back();
      times++;
    }
  }
  for (auto &task : AssemblyLine) {
    // out << "RUNNING:" << task->getName() << std::endl;
    task->runProcess(out);
  }
  out << "---------------" << std::endl;

  for (auto &task : AssemblyLine) {
    // out << "SECOND LOOP" << std::endl;
    CustomerOrder co;
    if (task->getCompleted(co)) {
      if (co.getOrderFillState()) {
        // out << "COMPLETED ORDER" << std::endl;
        // co.display(out);
        Completed.push_front(std::move(co));
      } else {
        // out << "NOT COMPLETED" << std::endl;
        *task += std::move(co);
      }
      // continue;
    }

    task->moveTask();
  }

  if (4 == Completed.size()) {
    return true;
  } else {
    return false;
  }
}

auto LineManager::displayCompleted(std::ostream &out) const -> void {
  for (auto &order : Completed) {
    order.display(out);
  }
}

auto LineManager::validateTasks() const -> void {
  for (auto task : AssemblyLine) {
    task->validate(std::cout);
  }
}