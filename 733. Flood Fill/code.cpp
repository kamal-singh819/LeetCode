class Solution {

  
  ////// VERY SIMPLE USING DFS-----------------------
  
  
  
  
  
  private:
    bool isValidPath(vector<vector<int>>& image, int i, int j, int n, int m, int &source){  //this function is to know the path we are moving is valid or not
        if(i>=0 && i<n && j>=0 && j<m && image[i][j] == source)
            return true;
        return false;    
    }  

    void dfs(vector<vector<int>>& image, int i, int j, int n, int m, int &color, int &source)  {
        image[i][j] = color;
        if(isValidPath(image, i+1, j, n, m, source))
            dfs(image, i+1, j, n, m, color, source);
        if(isValidPath(image, i-1, j, n, m, source))
            dfs(image, i-1, j, n, m, color, source);
        if(isValidPath(image, i, j+1, n, m, source))
            dfs(image, i, j+1, n, m, color, source);
        if(isValidPath(image, i, j-1, n, m, source))
            dfs(image, i, j-1, n, m, color, source);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int source = image[sr][sc];
        if(source == color) //if newcolor is same as source index color, then return image directly
            return image;

        int n = image.size();
        int m = image[0].size();    


        dfs(image, sr, sc, n, m, color, source); 
 

        return image;  
        
    }
};
