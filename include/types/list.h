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

namespace types {
  /* holds one linear list, all connections are one way. */
  class linear_list {
    struct node; // forward declaration
  public:
    class iterator; // forward declaration
    linear_list();
    ~linear_list();

    bool push_front(void *);
    bool push_back(void *);
    
    bool remove(void *, bool (*compfn)(const void *, const void *)); /* removes  */
    bool unique(); /* remove all duplicates */

    bool clear(void);
    inline unsigned size(void) const { return this->len; }
    inline bool is_empty(void) const { return !this->head; };
    
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
    
    int remove_recurs(node * &current, void *, bool (*compfn)(const void *, const void *));
    
    unsigned len;
    node *head;
  };
} // namespace types


#endif
