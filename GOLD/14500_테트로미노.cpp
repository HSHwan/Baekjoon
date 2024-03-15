#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int width, length, maxSum = 0;
vector<vector<int>> paperNums;
vector<vector<pair<int, int>>> middleTypes = \
{{{-1 , -1}, {-1, 0}, {-1, 1}}, {{-1, -1}, {0, -1}, {1, -1}}, \
{{-1, 1}, {0, 1}, {1, 1}}, {{1, -1}, {1, 0}, {1, 1}}, \
{{0, -1}, {-1, 0}, {0, 1}}, {{0, -1}, {1, 0}, {0, 1}}, \
{{0, -1}, {-1, 0}, {1, 0}}, {{-1, 0}, {1, 0}, {0, 1}}};

vector<vector<pair<int, int>>> twoLinesTypes = \
{{{-1 , -1}, {-1, 0}, {0, 1}}, {{-1, -1}, {0, -1}, {1, 0}}, \
{{-1, 1}, {-1, 0}, {0, -1}}, {{-1, 1}, {0, 1}, {1, 0}}, \
{{1, -1}, {0, -1}, {-1, 0}}, {{1, -1}, {1, 0}, {0, 1}}, \
{{1, 1}, {1, 0}, {0, -1}}, {{1, 1}, {0, 1}, {-1, 0}}};

void input(){
    cin >> width >> length;
    vector<vector<int>>(width, vector<int>(length)).swap(paperNums);

    FOR(i, width){
        FOR(j, length){
            cin >> paperNums[i][j];
        }
    }
}

void oneLine(){
    /*

    ****

    */

    if (width >= 4){
        FOR (i, length){
            int xLine = paperNums[0][i] + paperNums[1][i] + paperNums[2][i] + paperNums[3][i];
            maxSum = max(maxSum, xLine);
            for (int j = 4; j < width; j++){
                xLine += paperNums[j][i];
                xLine -= paperNums[j - 4][i];
                maxSum = max(maxSum, xLine);
            }
        }
    }

    if (length < 4)
        return;
    FOR (i, width){
        int yLine = paperNums[i][0] + paperNums[i][1] + paperNums[i][2] + paperNums[i][3];
        maxSum = max(maxSum, yLine);
        for (int j = 4; j < length; j++){
            yLine += paperNums[i][j];
            yLine -= paperNums[i][j - 4];
            maxSum = max(maxSum, yLine);
        }
    }
}

void oneLineSideOneDot(){
    /*

    ***
    *
    
    */

    int oneLineSideDot;
    if (length >= 3 && width >= 2){
        FOR (i, length - 2){
            oneLineSideDot = paperNums[0][i] + paperNums[0][i + 1] + paperNums[0][i + 2];
            maxSum = max(maxSum, oneLineSideDot + paperNums[1][i]);
            maxSum = max(maxSum, oneLineSideDot + paperNums[1][i + 2]);

            oneLineSideDot = paperNums[width - 1][i] + paperNums[width - 1][i + 1] + paperNums[width - 1][i + 2];
            maxSum = max(maxSum, oneLineSideDot + paperNums[width - 2][i]);
            maxSum = max(maxSum, oneLineSideDot + paperNums[width - 2][i + 2]);
        }

        for (int i = 1; i < width - 1; i++){
            FOR (j, length - 2){
                oneLineSideDot = paperNums[i][j] + paperNums[i][j + 1] + paperNums[i][j + 2];
                maxSum = max(maxSum, oneLineSideDot + paperNums[i - 1][j]);
                maxSum = max(maxSum, oneLineSideDot + paperNums[i - 1][j + 2]);
                maxSum = max(maxSum, oneLineSideDot + paperNums[i + 1][j]);
                maxSum = max(maxSum, oneLineSideDot + paperNums[i + 1][j + 2]);
            }
        }
    }

    if (width < 3)
        return;
    FOR (i, width - 2){
        oneLineSideDot = paperNums[i][0] + paperNums[i + 1][0] + paperNums[i + 2][0];
        maxSum = max(maxSum, oneLineSideDot + paperNums[i][1]);
        maxSum = max(maxSum, oneLineSideDot + paperNums[i + 2][1]);

        oneLineSideDot = paperNums[i][length - 1] + paperNums[i + 1][length - 1] + paperNums[i + 2][length - 1];
        maxSum = max(maxSum, oneLineSideDot + paperNums[i][length - 2]);
        maxSum = max(maxSum, oneLineSideDot + paperNums[i + 2][length - 2]);
    }

    for (int i = 1; i < length - 1; i++){
        FOR (j, width - 2){
            oneLineSideDot = paperNums[j][i] + paperNums[j + 1][i] + paperNums[j + 2][i];
            maxSum = max(maxSum, oneLineSideDot + paperNums[j][i - 1]);
            maxSum = max(maxSum, oneLineSideDot + paperNums[j + 2][i - 1]);
            maxSum = max(maxSum, oneLineSideDot + paperNums[j][i + 1]);
            maxSum = max(maxSum, oneLineSideDot + paperNums[j + 2][i + 1]);
        }
    }
}

void oneLineMiddleOneDot(){
    /*

    ***
     *

    */

    int oneLineMiddleOneDot;

    if (length >= 3 && width == 2){
        FOR (i, length - 2){
            oneLineMiddleOneDot = paperNums[0][i] + paperNums[0][i + 1] + paperNums[0][i + 2] + paperNums[1][i + 1];
            maxSum = max(maxSum, oneLineMiddleOneDot);
        }
    }
    else if (width >= 3 && length == 2){
        FOR (i, width - 2){
            oneLineMiddleOneDot = paperNums[i][0] + paperNums[i + 1][0] + paperNums[i + 2][0] + paperNums[i + 1][1];
            maxSum = max(maxSum, oneLineMiddleOneDot);
        }
    }
    else if (width < 3 || length < 3)
        return;

    for (int i = 1; i < width - 1; i++){
        for (int j = 1; j < length - 1; j++){
            FOR (k, 8){
                oneLineMiddleOneDot = paperNums[i][j];
                oneLineMiddleOneDot += paperNums[i + middleTypes[k][0].X][j + middleTypes[k][0].Y];
                oneLineMiddleOneDot += paperNums[i + middleTypes[k][1].X][j + middleTypes[k][1].Y];
                oneLineMiddleOneDot += paperNums[i + middleTypes[k][2].X][j + middleTypes[k][2].Y];
                maxSum = max(maxSum, oneLineMiddleOneDot);
            }
        }
    }
}

void twoLines(){
    /*

    **
     **

    */

    int twoLines;
    if (length >= 3 && width == 2){
        FOR (i, length - 2){
            twoLines = paperNums[0][i + 1] + paperNums[1][i + 1];
            maxSum = max(maxSum, twoLines + paperNums[0][i] + paperNums[1][i + 2]);
            maxSum = max(maxSum, twoLines + paperNums[1][i] + paperNums[0][i + 2]);
        }
    }
    else if (width >= 3 && length == 2){
        FOR (i, width - 2){
            twoLines = paperNums[i + 1][0] + paperNums[i + 1][1];
            maxSum = max(maxSum, twoLines + paperNums[i][0] + paperNums[i + 2][1]);
            maxSum = max(maxSum, twoLines + paperNums[i][1] + paperNums[i + 2][0]);
        }
    }
    else if (width < 3 || length < 3)
        return;

    for (int i = 1; i < width - 1; i++){
        for (int j = 1; j < length - 1; j++){
            FOR (k, 8){
                twoLines = paperNums[i][j];
                twoLines += paperNums[i + middleTypes[k][0].X][j + middleTypes[k][0].Y];
                twoLines += paperNums[i + middleTypes[k][1].X][j + middleTypes[k][1].Y];
                twoLines += paperNums[i + middleTypes[k][2].X][j + middleTypes[k][2].Y];
                maxSum = max(maxSum, twoLines);
            }
        }
    }
}

void twoXtwoBox(){
    /*
    
    **
    **
    
    */

    int twoXtwoBox;

    for (int i = 0; i < width - 1; i++){
        for (int j = 0; j < length - 1; j++){
            twoXtwoBox = paperNums[i][j] + paperNums[i][j + 1] + paperNums[i + 1][j] + paperNums[i + 1][j + 1];
            maxSum = max(maxSum, twoXtwoBox);            
        }
    }
}

void solve(){
    oneLine();
    oneLineSideOneDot();
    oneLineMiddleOneDot();
    twoLines();
    twoXtwoBox();
}

void output(){
    cout << maxSum;
}

int main(){
    input ();
    solve ();
    output();
}