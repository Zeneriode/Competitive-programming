//
// Created by User on 15.10.2023.
//

#include <bits/stdc++.h>
#include "Graph.h"


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
    #endif

    // Пару городов
    string msk = "Moscow";
    string piter = "Saint Petersburg";
    string kzn = "Kazan";
    string inno = "Innopolis";

    Graph<string, Road> g;

    g.add_vertex(msk);
    g.add_vertex(piter);
    g.add_vertex(kzn);
    g.add_vertex(inno);

    g.add_edge(msk, piter);
    g.add_edge(msk, kzn);
    g.add_edge(piter, kzn);
    g.add_edge(kzn, inno);

    g.edges()[0].length = 400;
    g.edges()[1].length = 680;
    g.edges()[2].length = 1200;
    g.edges()[3].length = 42;
    // Просто должно работать "Moscow Piter"
    for (string city : g.path(msk, piter)) {
        cout << city << " ";
    }
    cout << "\n";

    // Проверка, сможет ли метод вернуть больше одного города. "Moscow Kazan Innopolis"
    for (string city : g.path(msk, inno)) {
        cout << city << " ";
    }
    cout << "\n";

    // Проверка, сможет ли метод найти путь покороче. Правильный ответ: "Saint Petersburg Moscow Kazan"
    for (string city : g.path(piter, kzn)) {
        cout << city << " ";
    }
    cout << "\n";
}
