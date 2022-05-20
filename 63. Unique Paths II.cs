public class Solution {
    public int UniquePathsWithObstacles(int[][] obstacleGrid)
    {
      if(obstacleGrid.Length == 0)
      {
         return 0;
      }

      int[,] paths = new int[obstacleGrid.Length, obstacleGrid[0].Length];

      //first row
      foreach(int i in Enumerable.Range( 0, obstacleGrid[0].Length ))
      {
         if(obstacleGrid[0][i] == 0)
         {
            paths[0, i] = 1;
         }
         else
         {
            break;
         }
      }

      //first column
      foreach(int i in Enumerable.Range( 0, obstacleGrid.Length ))
      {
         if(obstacleGrid[i][0] == 0)
         {
            paths[i, 0] = 1;
         }
         else
         {
            break;
         }
      }

      foreach(int i in Enumerable.Range( 1, obstacleGrid.Length - 1))
      {
         foreach(int j in Enumerable.Range( 1, obstacleGrid[0].Length - 1))
         {
            if(obstacleGrid[i][j] == 0)
            {
               paths[i, j] = paths[i - 1, j] + paths[i, j - 1];
            }
         }
      }
      return paths[obstacleGrid.Length - 1, obstacleGrid[0].Length - 1];
   }
}
