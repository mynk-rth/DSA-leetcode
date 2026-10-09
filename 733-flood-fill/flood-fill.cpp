class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       
        int naya_color = color;
        int purana_color = image[sr][sc];

        if (purana_color == naya_color) {
            return image;
        }
        queue<pair<int, int>> q;
        q.push({sr, sc});

        image[sr][sc] = naya_color;

        vector<pair<int, int>> directions = {{-1, 0},{1, 0},{0, -1},{0, 1}};  // top bottom left right

        int m = image.size();
        int n = image[0].size();

        while (!q.empty()) {              // (1,1) (0,1) (1,0) (0,0) (0,2)
            auto [row_cord, col_cord] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row_cord + directions[i].first;   
                int nc = col_cord + directions[i].second;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == purana_color) {
                    image[nr][nc] = naya_color;
                    q.push({nr, nc});
                }
            }
        }

        return image;   // [[2,2,2],[2,2,0],[1,0,1]]
    }
};