/*
 * @Author: Jack Thake 
 * @Date: 2020-10-29 14:13:47 
 * @Last Modified by: Jack Thake
 * @Last Modified time: 2020-10-29 14:32:02
*/

#ifndef __LIST_H__
#define __LIST_H__

namespace types {
  class linear_list {
  public:
    linear_list();
    ~linear_list();

    bool push_front(const int &to_push); /* adds one item to front of list */
    bool push_back(const int &to_push); /* adds one item to front of list */
    
    bool remove_item(const int &to_remove); /* removes a given item */
    
    void clear(void); /* clear list */
    bool unique(void); /* remove duplicates */
    inline bool is_empty(void) const { return !this->head; }; /* returns if the list is empty */
  private:
    struct node {
      int data;
      node *next;
    };
    
    node *head;
  };  
} // namespace types


#endif
