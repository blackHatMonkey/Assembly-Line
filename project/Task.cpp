/*
 * Name: Brian Smith
 * Seneca Student ID: 137105177
 * Seneca email: bsmith55@myseneca.ca
 * Date of completion: 12/22/2018
 *
 * I confirm that I am the only author of this file
 * and the content was created entirely by me.
 */

#include <iostream>
#include <string>

#include "Task.h"

Task::Task(const std::string &line) : Item(line) {}

/**
 * @brief Run a single cycle of the assembly line for the current task.
 *
 * @param out An ostream object to output to.
 */
auto Task::runProcess(std::ostream &out) -> void {
  if (m_orders.size() && !m_orders.back().getOrderFillState()) {
    m_orders.back().fillItem(*this, out);
  }
}

/**
 * @brief Move last order to the next task.
 *
 * @return true In case the order is moved.
 * @return false In case the order is not moved.
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
 * @brief Set the next task in the assembly line.
 *
 * @param newTask The next task in line.
 */
auto Task::setNextTask(Task &newTask) -> void { m_pNextTask = &newTask; }

/**
 * @brief Remove the last order from the deque.
 *
 * @param order An object to move the last element to.
 * @return true In case the order is moved.
 * @return false In case the order is not moved.
 */
auto Task::getCompleted(CustomerOrder &order) -> bool {
  if (!m_orders.empty()) {
    order = std::move(m_orders.back());
    m_orders.pop_back();
    return true;
  } else {
    return false;
  }
}

/**
 * @brief Display name of item task is responsible for along with
 * the next time in line.
 *
 * @param out An ostream object to send output to.
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
 * @brief Add order to the task.
 *
 * @param order A customer order.
 * @return Task& Reference to the current instance.
 */
auto Task::operator+=(CustomerOrder &&order) -> Task & {
  m_orders.push_front(std::move(order));
  return *this;
}