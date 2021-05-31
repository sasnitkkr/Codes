/*
 in int a[n], return indices of two numbers such that to target.
 https://leetcode.com/problems/two-sum/
 Method 1 :-  O(n) 1 pass
 Method 2 :-  O(n) 2 pass
 
 Tip:-  Use umap, a, t
*/

/* Method 1 :- O(n) 1 pass */

        vector<int> twoSum(vector<int>& a, int t)
        {
          
          vector<int> op;

          unordered_map<int,int> umap;

          for(int i=0; i<a.size(); i++)
          {
              auto it = umap.find(t-a[i]);
              if(it!=umap.end())
              {
                  op.push_back(it->second); // it->second is umap[t-a[i]]
                  op.push_back(i);
                  break;
              }

              umap[a[i]] = i;
          }
          return op;
    }

/* Method 2 :-  O(n) 2 pass */

        vector<int> twoSum(vector<int>& a, int t) {
          vector<int> op;
          unordered_map<int, int> umap;

          for(int i=0; i<a.size(); i++)
          {
              umap[a[i]]=i;
          }
          for(int i=0; i<n; i++)
          {
              if(umap.find(t-a[i])!=umap.end() && umap[t-a[i]]!=i) /* Important to check for same index e.g. TC 2*/
              {
                  op.push_back(i);
                  op.push_back(umap[t-a[i]]);
                  break;
              }   
          }
          return op;
    }
