#ifndef __LIST_H__
#define __LIST_H__

#include <cstddef>

/* very basic linear linked list */
template <typename T>
class linear_list {
  public:
    ~linear_list();

    bool add_item(const T &to_add); /* add item to the list */
    bool remove_item(const T &to_remove); /* remove item */
    void iterate(void *(*callback)(T)); /* iterate through all */
    
    inline size_t size() const { return this->size; }; /* get size */

  private:
    /* each node in the list */
    struct node {
      node *next;
      T data;
    };

    node *head = NULL; /* start of list */
    size_t length = NULL; /* list length */
};

#endif
