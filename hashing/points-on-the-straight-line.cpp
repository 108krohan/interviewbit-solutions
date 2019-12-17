/*

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :

(1, 1)
(2, 2)

Sample Output :

2

You will be given 2 arrays X and Y. Each point is represented by (X[i], Y[i])


*/

struct Line {
    int x0, y0, x1, y1;
};

bool isLie(const Line& line, int px, int py) {
    int64_t lx = line.x1 - line.x0;
    int64_t ly = line.y1 - line.y0;
    if(lx == 0) return line.x0 == px;
    if(ly == 0) return line.y0 == py;
    int64_t dx = (px - line.x0) * ly;
    int64_t dy = (py - line.y0) * lx;
    return dx == dy;
}

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    if(n <= 1) return n;
    
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            Line line = { A[i], B[i], A[j], B[j] };
            int cnt = 0;
            for(int k = 0; k < n; ++k) {
                if(isLie(line, A[k], B[k])) {
                    ++cnt;
                }
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
}

