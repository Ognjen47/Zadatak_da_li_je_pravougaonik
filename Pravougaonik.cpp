#include <bits/stdc++.h>
using namespace std;

int kvadratRastojanja(int xi, int yi, int xj, int yj) {
    int dx = xi - xj;
    int dy = yi - yj;
    return dx * dx + dy * dy;
}
int skalarniProizvod(int ax, int ay, int bx, int by, int cx, int cy) { // skalarni proizvod vektora
    int ABx = bx - ax, ABy = by - ay;
    int BCx = cx - bx, BCy = cy - by;
    return ABx * BCx + ABy * BCy;
}


int main(){
    vector<pair<int, int>> tacke(4);
    for (int i = 0; i < 4; ++i) {
        cin >> tacke[i].first >> tacke[i].second;
    }
    sort(tacke.begin(), tacke.end()); // priprema za permutacije

    do {
        int x1 = tacke[0].first, y1 = tacke[0].second;
        int x2 = tacke[1].first, y2 = tacke[1].second;
        int x3 = tacke[2].first, y3 = tacke[2].second;
        int x4 = tacke[3].first, y4 = tacke[3].second;

        if (
            kvadratRastojanja(x1, y1, x2, y2) > 0 && //eliminise slusaj da su tacke iste
            kvadratRastojanja(x1, y1, x2, y2) == kvadratRastojanja(x3, y3, x4, y4) &&
            kvadratRastojanja(x2, y2, x3, y3) == kvadratRastojanja(x4, y4, x1, y1) &&
            kvadratRastojanja(x1, y1, x3, y3) == kvadratRastojanja(x2, y2, x4, y4) &&//dijagonale su jednake?

            skalarniProizvod(x1, y1, x2, y2, x3, y3) == 0 &&
            skalarniProizvod(x2, y2, x3, y3, x4, y4) == 0 &&
            skalarniProizvod(x3, y3, x4, y4, x1, y1) == 0
        ) {
            cout << "DA\n";
            return 0;
        }
    } while (next_permutation(tacke.begin(), tacke.end()));
      //isprobavamo sve moguce rasporede tacaka 


    cout << "NE\n";

    return 0;}
