#include "ListNode.h"

ListNode::ListNode() : data(PCB()), next(nullptr) {};

ListNode::ListNode(const PCB* newPCB, ListNode* next)
    : data(PCB(newPCB)), next(next) {}

ListNode::ListNode(int processID, std::string& processName,
                   PCB::Status processStatus, int commandCounter,
                   ListNode* next)
    : data(PCB(processID, processName, processStatus, commandCounter)),
      next(next) {}

void ListNode::setRegister(int ind, int val) {
  if (0 <= ind && ind < CPUREGISTERSIZE) {
    data.cpuRegisters[ind] = val;
    return;
  }
  throw std::out_of_range("Значение индекса выходит за пределы регистров");
}