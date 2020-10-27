#include <types/types.h>


/* initializes the list O(N) */
linear_list::linear_list() {
  this->head = NULL;
  this->length = 0;
}


/* clears all dynamic memory O(N) */
linear_list::~linear_list() {
  while (this->head) {
    node *temp = this->head;
    this->head = head->next;

    --this->length;
    delete temp;
  }
}


/* adds an item to the list O(1) */
bool linear_list::add_item(const int &to_add) {
  node *temp = this->head;

  this->head = new node;
  if (!this->head) {
    this->head = temp;
    return false;
  }

  this->head->next = temp;
  this->head->data = to_add;
  ++this->length;

  return true;
}


/* remove item from the lsit, inefficent O(N) */
bool linear_list::remove_item(const int &to_remove) {
  node *current = this->head, *previous = this->head;
  while (current) {
    if (current->data == to_remove) {
      if (this->head == current) {
        this->head = current->next;
      } else {
        previous->next = current->next;
      }

      --this->length;
      delete current;
      return true;
    }
  }

  return false;
}


/* iterate through the list O(N) */
void linear_list::iterate(void *(*callback)(int)) {
  node *current = this->head;
  while (current) {
    callback(current->data);
  }
}
