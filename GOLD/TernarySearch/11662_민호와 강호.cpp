#include <iostream>
#include <cmath>
#define X first
#define Y second
#define MAX 2*10e4
using namespace std;

typedef pair<double, double> pdd;

double findDist(pdd a, pdd b) {
    double xDiff = a.X - b.X, yDiff = a.Y - b.Y;
    double dist = sqrt(xDiff * xDiff + yDiff * yDiff);
    return dist;
}

int main() {
    cout << fixed;
    cout.precision(10);
    pdd aStart, aEnd, bStart, bEnd;
    cin >> aStart.X >> aStart.Y >> aEnd.X >> aEnd.Y;
    cin >> bStart.X >> bStart.Y >> bEnd.X >> bEnd.Y;

    double dist = MAX;
    double low = 0.0, high = 100.0;
    while (high - low >= 1e-6) {
        double p = (2 * low + high) / 3;
        double q = (low + 2 * high) / 3;
        pdd p1 = {aStart.X + (aEnd.X - aStart.X) * (p / 100), aStart.Y + (aEnd.Y - aStart.Y) * (p / 100)};
        pdd p2 = {bStart.X + (bEnd.X - bStart.X) * (p / 100), bStart.Y + (bEnd.Y - bStart.Y) * (p / 100)};
        pdd q1 = {aStart.X + (aEnd.X - aStart.X) * (q / 100), aStart.Y + (aEnd.Y - aStart.Y) * (q / 100)};
        pdd q2 = {bStart.X + (bEnd.X - bStart.X) * (q / 100), bStart.Y + (bEnd.Y - bStart.Y) * (q / 100)};
        double pDist = findDist(p1, p2);
        double qDist = findDist(q1, q2); 
        dist = min(dist, min(pDist, qDist));
        if (pDist <= qDist) {
            high = q;
        }
        else {
            low = p;
        }
    }

    cout << dist;
}