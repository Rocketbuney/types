#include <types.h>


/* clears all dynamic memory O(N) */
template <typename T>
linear_list<T>::~linear_list() {
  while (this->head) {
    node *temp = this->head;
    this->head = head->next;

    --this->length;
    delete temp;
  }
}


/* adds an item to the list O(1) */
template <typename T>
bool linear_list<T>::add_item(const T &to_add) {
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
template <typename T>
bool linear_list<T>::remove_item(const T &to_remove) {
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
template <typename T>
void linear_list<T>::iterate(void *(*callback)(T)) {
  node *current = this->head;
  while (current) {
    callback(current->data);
  }
}

