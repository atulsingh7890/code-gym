using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeGymCSharp
{
   public struct PriorityValue
   {
      public PriorityValue( int v, int i )
      {
         value = v;
         index = i;
      }
      public int value;
      public int index;
   }

   public class MyComparer : IComparer<PriorityValue>
   {
      public int Compare( PriorityValue a, PriorityValue b )
      {
         if( a.value < b.value ) return -1;
         if( a.value > b.value ) return +1;
         return a.index.CompareTo( b.index );
      }
   }


   public class Solution
   {
      public static void Main()
      {
         TotalCost( new int[] { 17, 12, 10, 2, 7, 2, 11, 20, 8 }, 3, 4 );
      }

      public long TotalCost( int[] costs, int k, int candidates )
      {
         PriorityQueue<int, PriorityValue> headWorkers = new( new MyComparer() );
         PriorityQueue<int, PriorityValue> tailWorkers = new( new MyComparer() );

         for( int i = 0; i < candidates; ++i )
         {
            headWorkers.Enqueue( costs[ i ], new PriorityValue( costs[ i ], i ) );
         }

         for( int i = Math.Max( candidates, costs.Length - candidates ); i < costs.Length; ++i )
         {
            tailWorkers.Enqueue( costs[ i ], new PriorityValue( costs[ i ], i ) );
         }

         long answer = 0;
         int nextHead = candidates;
         int nextTail = costs.Length - 1 - candidates;

         for( int i = 0; i < k; i++ )
         {
            if( tailWorkers.Count == 0 || !( headWorkers.Count == 0 ) && headWorkers.Peek() <= tailWorkers.Peek() )
            {
               answer += headWorkers.Dequeue();

               // Only refill the queue if there are workers outside the two queues.
               if( nextHead <= nextTail )
               {
                  headWorkers.Enqueue( costs[ nextHead ], new PriorityValue( costs[ nextHead ], nextHead ) );
                  nextHead++;
               }
            }

            else
            {
               answer += tailWorkers.Dequeue();

               // Only refill the queue if there are workers outside the two queues.
               if( nextHead <= nextTail )
               {
                  tailWorkers.Enqueue( costs[ nextTail ], new PriorityValue( costs[ nextTail ], nextTail ) );
                  nextTail--;
               }
            }
         }

         return answer;
      }
   }
}
