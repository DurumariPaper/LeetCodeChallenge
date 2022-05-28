class Solution {
public:
    bool CheckOverlap(int rec1L, int rec1D, int rec1R, int rec1T, 
                  int rec2L, int rec2D, int rec2R, int rec2T)
    {
        return (min(rec1R, rec2R) > max(rec1L, rec2L) && min(rec1T, rec2T) > max(rec1D, rec2D));
    }

    int computeArea(int rec1L, int rec1D, int rec1R, int rec1T, 
                    int rec2L, int rec2D, int rec2R, int rec2T) 
    {

        int rec1Area = (rec1R - rec1L) * (rec1T - rec1D);
        int rec2Area = (rec2R - rec2L) * (rec2T - rec2D);

        bool f = CheckOverlap(rec1L, rec1D, rec1R, rec1T, 
                              rec2L, rec2D, rec2R, rec2T);

        if (!f) return rec1Area + rec2Area;

        int h = min(rec1T, rec2T) - max(rec1D, rec2D);
        int w = min(rec1R, rec2R) - max(rec1L, rec2L);

        return rec1Area + rec2Area - h * w;
    }
};