/*
 * @lc app=leetcode id=812 lang=c
 *
 * [812] Largest Triangle Area
 */

//S=1/2[(x1y2-x2y1)+(x2y3-x3y2)+(x3y1-x1y3)]
double get_area(int *a, int *b, int *c) {
    return 0.5 * abs((a[0] * b[1] - b[0] * a[1]) +
                     (b[0] * c[1] - c[0] * b[1]) +
                     (c[0] * a[1] - a[0] * c[1]));
}

double largestTriangleArea(int **points, int pointsSize, int *pointsColSize) {
    double ans = 0;
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            for (int k = j + 1; k < pointsSize; k++) {
                double area = get_area(points[i], points[j], points[k]);
                printf("area = %lf\n", area);
                if (ans < area)
                    ans = area;
            }
        }
    }
    return ans;
}
