Suppose you have a linked list like this:
+---+    +---+    +---+
| A | -> | B | -> | C |
+---+    +---+    +---+
  ↑
  |
  p

Here, each node contains some data (A, B, C) and a pointer (next) to the next node in the sequence.

p = p->next;:

The current situation is that p is pointing to node A.
When you execute p = p->next; it means you are updating p to point to the next node in the list.
After this operation, p points to node B:

+---+    +---+    +---+
| A | -> | B | -> | C |
+---+    +---+    +---+
         ↑
         |
         p


p->next = temp;

Let's assume you have a new node created with data 'X', and temp is pointing to this new node.
When you execute p->next = temp;, it means you are updating the "next" pointer of the node that p is pointing to.
After this operation, the structure becomes:

+---+    +---+    +---+    +---+
| A | -> | B | -> | X | -> | C |
+---+    +---+    +---+    +---+
                  ↑
                  |
                  p


p = p->next; moves the pointer p to the next node in the list.
p->next = temp; updates the "next" pointer of the node that p is pointing to, making it point to a new node (temp).

