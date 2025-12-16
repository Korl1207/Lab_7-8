#include "ProcessList.h"

#include <iostream>

bool ProcessList::insert(const PCB* newPCB) {
  ListNode* newList = new ListNode(newPCB, nullptr);
  ListNode* node = head;
  ListNode* prev = nullptr;
  while (node != nullptr && node->getProcessID() < newPCB->processID) {
    prev = node;
    node = node->getNext();
  }
  if (node != nullptr && node->getProcessID() == newPCB->processID) {
    return false;
  }
  if (prev != nullptr)
    prev->setNext(newList);
  else
    head = newList;
  if (node != nullptr) newList->setNext(node);
  return true;
}

bool ProcessList::remove(int pid) {
  ListNode* node = head;
  ListNode* prev = nullptr;
  while (node != nullptr && node->getProcessID() != pid) {
    prev = node;
    node = node->getNext();
  }
  if (node == nullptr) return false;
  if (prev != nullptr) {
    prev->setNext(node->getNext());
    delete node;
  }
  head = node->getNext();
  delete node;
  return true;
}

ProcessList::~ProcessList() {
  ListNode *tmp, *node = head;
  while (node != nullptr) {
    tmp = node->getNext();
    delete node;
    node = tmp;
  }
}

void ProcessList::printList() {
  ListNode* node = head;
  while (node != nullptr) {
    node->print();
    node = node->getNext();
  }
}