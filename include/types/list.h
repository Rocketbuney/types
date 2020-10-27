#ifndef __LIST_H__
#define __LIST_H__

#include <cstddef>

/* very basic linear linked list */
class  linear_list {
  public:
    linear_list();
    ~linear_list();

    bool add_item(const int &to_add); /* add item to the list */
    bool remove_item(const int &to_remove); /* remove item */
    void iterate(void *(*callback)(int)); /* iterate through all */
    
    inline size_t size(void) const { return this->length; }; /* get size */

  private:
    /* each node in the list */
    struct node {
      node *next;
      int data;
    };

    node *head; /* start of list */
    size_t length; /* list length */
};

#endif
