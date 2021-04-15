/* LIST.h
 *   by Jack Thake
 *
 * Created:
 *   4/7/2021, 5:34:29 PM
 * Last edited:
 *   4/15/2021, 12:20:06 PM
 * Auto updated?
 *   Yes
 *
 * Description:
 *   Declaration for linear list class
**/

#ifndef __LIST_H__
#define __LIST_H__

#include <iterator>

namespace types {
  class linear_list {
    struct node; // forward declaration
  public:
    class iterator; // forward declaration
    linear_list();
    ~linear_list();

    bool push_front(void *);
    bool push_back(void *);

    bool clear(void);
    inline bool is_empty(void) { return !this->head; };
    
    iterator begin();
    iterator end();
    
    class iterator {
    public:
      iterator();
      iterator(const node *);
      
      iterator &operator=(const node *);
      iterator &operator++(); /* prefix */
      iterator &operator++(int); /* postfix */
      bool operator!=(const iterator &);
      void *operator*();
    private:
      const node *current_node;
    };
  private:
    struct node {
      void *data;
      node *next;
    };
    
    node *head;
  };
} // namespace types


#endif
