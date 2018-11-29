/*
 * Name: Brian Smith
 * Seneca Student ID: 137105177
 * Seneca email: bsmith55@myseneca.ca
 * Date of completion: 12/23/2018
 *
 * I confirm that I am the only author of this file
 * and the content was created entirely by me.
 */

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <deque>
#include <iostream>
#include <string>
#include <vector>

#include "CustomerOrder.h"
#include "Task.h"

class LineManager {
public:
  LineManager(const std::string &fileName, std::vector<Task *> &tasks,
              std::vector<CustomerOrder> &orders);
  auto run(std::ostream &out) -> bool;
  auto displayCompleted(std::ostream &out) const -> void;
  auto validateTasks() const -> void;

private:
  std::vector<Task *> AssemblyLine;
  std::deque<CustomerOrder> ToBeFilled;
  std::deque<CustomerOrder> Completed;
  size_t m_cntCustomerOrder;
  int times = 0;
};

#endif