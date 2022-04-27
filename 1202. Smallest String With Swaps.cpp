

class Solution {
public:
   std::string smallestStringWithSwaps( std::string s, const  std::vector<std::vector<int>>& pairs ) {

      // we will use disjoint to form the connected paris 
      std::vector<int> parentArray( s.size(), -1 );



      for( auto p : pairs ) {
         joinParent( p[0], p[1], parentArray );
      }

      std::unordered_map<int, std::vector<int>> disjoint_sets;
      for( int i = 0; i < parentArray.size(); ++i ) {
         if( parentArray[i] != -1 ) {
            int parent = findParent( i, parentArray );
            auto it = disjoint_sets.find( parent );
            if( it == disjoint_sets.end() ) {
               disjoint_sets[parent] = std::vector<int>();
               disjoint_sets[parent].push_back( parent );
            }
            disjoint_sets[parent].push_back( i );
         }
      }

       std::string result = s;
      //fill the string now
      for(auto kv : disjoint_sets)
      {
          std::vector<char> chars;
          for(auto index : kv.second) {
              chars.push_back(s[index]);
          }
          std::sort(chars.begin(), chars.end());
          
          int k = 0;
          for(auto index : kv.second) {
              result[index] = chars[k++];
          }
      }

      return result;
   }
private:
   int findParent( int index, std::vector<int>& parent ) {
      while( parent[index] != -1 ) {
         return findParent( parent[index], parent );
      }
      return index;
   }

   void joinParent( int a, int b, std::vector<int>& parent ) {
      int parent_a = findParent( a, parent );
      int parent_b = findParent( b, parent );
      if( parent_a != parent_b ) {
         parent[parent_b] = parent_a;
      }
   }
};
