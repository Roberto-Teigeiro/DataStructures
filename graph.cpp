#include <iostream>
#include <vector>
#include <stack>
#include <queue>

void cargarGrafo(int n, int m, std::vector<std::vector<int>> &matrizAdy, std::vector<std::vector<int>> &listaAdy) {
    matrizAdy.assign(n, std::vector<int>(n, 0));
    listaAdy.resize(n);

    std::cout << "Ingrese los arcos del grafo:" << std::endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cout << "Arco " << i + 1 << ": ";
        std::cin >> u >> v;

        matrizAdy[u][v] = 1;
        matrizAdy[v][u] = 1;

        listaAdy[u].push_back(v);
        listaAdy[v].push_back(u);
    }
}


void DFS(int nodoInicial, std::vector<std::vector<int>> &matrizAdy, std::vector<bool> &visitado) {
    std::cout << "Recorrido DFS: ";

    std::stack<int> pilaDFS;
    pilaDFS.push(nodoInicial);

    while (!pilaDFS.empty()) {
        int actual = pilaDFS.top();
        pilaDFS.pop();

        if (!visitado[actual]) {
            std::cout << actual << " ";
            visitado[actual] = true;

            for (int i = 0; i < matrizAdy[actual].size(); ++i) {
                if (matrizAdy[actual][i] && !visitado[i]) {
                    pilaDFS.push(i);
                }
            }
        }
    }

    std::cout << std::endl;
}
void BFS(int nodoInicial, std::vector<std::vector<int>> &listaAdy, std::vector<bool> &visitado) {
    std::cout << "Recorrido BFS: ";

    std::queue<int> colaBFS;
    colaBFS.push(nodoInicial);

    while (!colaBFS.empty()) {
        int actual = colaBFS.front();
        colaBFS.pop();

        if (!visitado[actual]) {
            std::cout << actual << " ";
            visitado[actual] = true;

            for (int i = 0; i < listaAdy[actual].size(); ++i) {
                if (!visitado[listaAdy[actual][i]]) {
                    colaBFS.push(listaAdy[actual][i]);
                }
            }
        }
    }

    std::cout << std::endl;
}

int main() {
    int n, m;
    std::cout << "Ingrese la cantidad de vértices y arcos: ";
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrizAdy;
    std::vector<std::vector<int>> listaAdy;

    cargarGrafo(n, m, matrizAdy, listaAdy);

    int nodoInicial;
    std::cout << "Ingrese el nodo inicial para DFS y BFS: ";
    std::cin >> nodoInicial;

    if (nodoInicial < 0 || nodoInicial >= n) {
        std::cout << "Nodo inicial no válido." << std::endl;
        return 1;
    }

    std::vector<bool> visitado(n, false);

    DFS(nodoInicial, matrizAdy, visitado);

    std::fill(visitado.begin(), visitado.end(), false);

    BFS(nodoInicial, listaAdy, visitado);

    return 0;
}