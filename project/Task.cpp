#include <deque>
#include <iostream>
#include <string>

#include "Task.h"

Task::Task(const std::string &line) : Item(line) {}

/**
 * @brief
 *
 * @param out
 */
auto Task::runProcess(std::ostream &out) -> void {

  if (m_orders.size() && !m_orders.back().getOrderFillState()) {
    m_orders.back().fillItem(*this, std::cout);
  }
}

/**
 * @brief
 *
 * @return true
 * @return false
 */
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

/**
 * @brief
 *
 * @param newTask
 */
auto Task::setNextTask(Task &newTask) -> void { m_pNextTask = &newTask; }

/**
 * @brief
 *
 * @param order
 * @return true
 * @return false
 */
auto Task::getCompleted(CustomerOrder &order) -> bool {
  if (m_orders.size()) {
    order = std::move(m_orders.back());
    m_orders.pop_back();
    return true;
  } else {
    return false;
  }
}

/**
 * @brief
 *
 * @param out
 */
auto Task::validate(std::ostream &out) -> void {
  out << getName() << " --> ";

  if (m_pNextTask) {
    out << m_pNextTask->getName();
  } else {
    out << "END OF LINE";
  }

  out << std::endl;
}

/**
 * @brief
 *
 * @param order
 * @return Task&
 */
auto Task::operator+=(CustomerOrder &&order) -> Task & {
  m_orders.push_front(std::move(order));
  return *this;
}