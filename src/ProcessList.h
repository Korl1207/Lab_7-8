// ProcessList.h
#ifndef PROCESSLIST_H
#define PROCESSLIST_H

#include "ListNode.h"

class ProcessList {
  ListNode* head;

 public:
  ProcessList() : head(nullptr) {};
  ~ProcessList();
  bool insert(const PCB* newPCB);
  bool remove(int pid);

  void printList();
};

#endif  // PROCESSLIST_H