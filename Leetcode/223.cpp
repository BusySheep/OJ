class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long area1 = long(C - A) * (D - B);
        long area2 = long(G - E) * (H - F);
        long innerTop = min(D, H);
        long innerBottom = max(B, F);
        long innerLeft = max(A, E);
        long innerRight = min(C, G);
        long overlap = 0;
        long overHeight = innerTop - innerBottom;
        long overWidth = innerRight - innerLeft;
        if (overHeight > 0 && overWidth > 0) overlap = overHeight * overWidth;
        return area1 + area2 - overlap;
    }
};