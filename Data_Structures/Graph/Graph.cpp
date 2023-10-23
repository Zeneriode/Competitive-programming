//
// Created by User on 15.10.2023.
//

#include <bits/stdc++.h>
#include "Graph.h"

struct Road {
    string city1;
    string city2;
    int length;
    Road(string city1, string city2, int length) {
        this->city1 = city1;
        this->city2 = city2;
        this->length = length;
    }
    Road(string city1, string city2) {
        this->city1 = city1;
        this->city2 = city2;
        this->length = 1;
    }
};

int main() {
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
