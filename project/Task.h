/*
 * Name: Brian Smith
 * Seneca Student ID: 137105177
 * Seneca email: bsmith55@myseneca.ca
 * Date of completion: 12/22/2018
 *
 * I confirm that I am the only author of this file
 * and the content was created entirely by me.
 */

#ifndef TASK_H
#define TASK_H

#include <deque>
#include <string>

#include "CustomerOrder.h"
#include "Item.h"

class Task : public Item {
public:
  Task(const std::string &line);
  Task(const Task &) = delete;
  Task(Task &&) = delete;
  auto operator=(const Task &) -> Task & = delete;
  auto operator=(Task &&) -> Task & = delete;
  auto runProcess(std::ostream &out) -> void;
  auto moveTask() -> bool;
  auto setNextTask(Task &) -> void;
  auto getCompleted(CustomerOrder &) -> bool;
  auto validate(std::ostream &) const -> void;
  auto operator+=(CustomerOrder &&) -> Task &;

private:
  std::deque<CustomerOrder> m_orders;
  Task *m_pNextTask = nullptr;
};

#endif