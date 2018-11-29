#include <deque>
#include <iostream>
#include <string>

#include "Task.h"

Task::Task(const std::string &line) : Item(line) {}

auto Task::runProcess(std::ostream &out) -> void {
  // TODO remove this
  // if (m_orders.size()) {
  //   m_orders.back().display(out);
  // }
  out << getName() << ":" << m_orders.size() << std::endl;
  if (m_orders.size() && !m_orders.back().getOrderFillState()) {
    m_orders.back().fillItem(*this, std::cout);
    // out << "========================" << std::endl;
    // for (auto &task : m_orders) {
    //   // out << "RUNNING:" << task->getName() << std::endl;
    //   task.display(out);
    // }
    // out << "========================" << std::endl;
  }
}

auto Task::moveTask() -> bool {
  if (m_orders.size() && m_orders.back().getItemFillState(getName()) &&
      m_pNextTask) {
    m_pNextTask->m_orders.push_front(std::move(m_orders.back()));
    m_orders.pop_back();
    return true;
  } else {
    return false;
  }
}

auto Task::setNextTask(Task &newTask) -> void { m_pNextTask = &newTask; }

auto Task::getCompleted(CustomerOrder &order) -> bool {
  if (m_orders.size()) {
    order = std::move(m_orders.back());
    m_orders.pop_back();
    return true;
  } else {
    return false;
  }
}

auto Task::validate(std::ostream &out) -> void {
  out << getName() << " --> ";

  if (m_pNextTask) {
    out << m_pNextTask->getName();
  } else {
    out << "END OF LINE";
  }

  out << std::endl;
}

auto Task::operator+=(CustomerOrder &&order) -> Task & {
  m_orders.push_front(std::move(order));
  return *this;
}