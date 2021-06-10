# Binary Trees

## Basic Terminology
```
1. Height :- Largest no of edges from root to leaf node. e.g height of root = 0
2. Level :- Level of root = 1
```

## Input
```
1. Use Stack (level wise)
```
## Traversals
```
1. Preorder (Root L R)
    a. Recursive
    b. Stack ( push Root, R, L)
  
2. Inorder (L Root R)
  a. Recursive
  b. Stack (Special)
 
3. Postorder
  a. Recursive
  b. One Stack (Special)
  c. Two Stack (Special)
  
4. Level Order Traversal
  a. Queue
  b. Recursion - level by level
  c. Reverse level order (level n, n-1, .... 3, 2, 1)
      p. https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1
      q. https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118521/offering/1380977
  
5. Boundary Traversal
    https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#
6. Zigzag Traversal
```
