// ListNode.h
#ifndef LISTNODE_H
#define LISTNODE_H

#include "PCB.h"
using namespace nsPCB;

class ListNode {
  PCB data;
  ListNode* next;

 public:
  ListNode();
  ListNode(const PCB* newPCB, ListNode* next);
  ListNode(int processID, std::string& processName, PCB::Status processStatus,
           int commandCounter, ListNode* next);

  ListNode* getNext() { return next; }
  int getProcessID() const { return data.processID; }
  std::string getProcessName() const { return data.processName; }
  PCB::Status getProcessStatus() const { return data.processStatus; }
  int getCommandCounter() const { return data.commandCounter; }
  int getRegister(int ind) {
    if (0 <= ind && ind < CPUREGISTERSIZE) return data.cpuRegisters[ind];
    throw std::out_of_range("Значение индекса выходит за пределы регистров");
  }

  void setProcessID(int id) { data.processID = id; }
  void setProcessName(std::string name) { data.processName = name; }
  void setProcessStatus(PCB::Status st) { data.processStatus = st; }
  void setCommandCounter(int cc) { data.commandCounter = cc; }
  void setRegister(int ind, int val);
  void setNext(ListNode* newNext) { next = newNext; }
  void print() { data.print(); }
};

#endif  // LISTNODE_H