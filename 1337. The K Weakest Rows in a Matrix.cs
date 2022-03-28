class RowInfo
{
   public RowInfo(int rowNumber, int rowStrongness)
   {
      this.RowNumber = rowNumber;
      this.RowStrongness = rowStrongness;
   }
   public int RowNumber { get; set; }
   public int RowStrongness { get; set; }
}

class StrengthComparer : IComparer<RowInfo>
{
   public int Compare(RowInfo a, RowInfo b)
   {
      if (a.RowStrongness > b.RowStrongness)
         return -1;
      else if (a.RowStrongness == b.RowStrongness)
         return a.RowNumber > b.RowNumber ? -1 : 1;
      else
         return 1;
   }
}

public class Solution
{
   public int[] KWeakestRows(int[][] mat, int k)
   {

      PriorityQueue<RowInfo, RowInfo> pq = new PriorityQueue<RowInfo, RowInfo>(new StrengthComparer());

      for (int i = 0; i < mat.Length; ++i)
      {
         RowInfo currentRowInfo = new RowInfo(i, mat[i].Sum());
         if (pq.Count < k)
         {
            pq.Enqueue(currentRowInfo, currentRowInfo);
         }
         else
         {
            // see if Max Heap has potential element to expunge
            if (pq.Peek().RowStrongness > currentRowInfo.RowStrongness)
            {
               pq.Dequeue();
               pq.Enqueue(currentRowInfo, currentRowInfo);
            }
         }
      }

      int[] kWeakestRows = new int[k];
      int j = kWeakestRows.Length - 1;
      while (pq.Count != 0)
      {
         kWeakestRows[j--] = pq.Peek().RowNumber;
         pq.Dequeue();
      }

      return kWeakestRows;
   }
}
