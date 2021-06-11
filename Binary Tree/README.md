# Binary Trees

## Basic Terminology
```
1. Height :- Largest no of edges from root to leaf node. e.g height of root = 0
2. Level :- Level of root = 1
3. Diameter/Width :- Number of nodes in the longest path between two end nodes
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
  
4. Level Order - https://practice.geeksforgeeks.org/problems/level-order-traversal/1#
  a. Queue
  b. Recursion - level by level
  c. Reverse level order (level n, n-1, .... 3, 2, 1)
      p. https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1
            a. queue(simple) + stack
            b. From level-N to level-1
      q. https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118521/offering/1380977
            a. simple levelorder -> op in stack
  
5. Boundary - https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#
    Root Left Leaves Right (base cases-2) 
6. Zigzag - https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
    a. 2 stacks (LR RL)
    b. level wise
7. Spiral - https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1
   a. 2 stacks (RL LR)
   b. level wise
```
## Basic Problems
```
1. Height
2. Diameter
3. Replace Node with Depth
4. LCA of BT
```
