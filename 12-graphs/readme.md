# Граф
Граф наричаме наредена двойка `G = (V, E)`, където `V` e непразно множество от върхове, а `E` e множество от ребра.

### Дефиниции
| Термин | Дефиниция |
| --- | --- |
| `Примка в граф` | Ребро от типа `{v, v}` |
| `Път в граф` | Редица от върхове `(v_1, v_2, ..., v_n)` за които е в сила `{v_i, v_{i+1}}` е елемент на `E`. |
| `Цикъл в граф` | Път `p` за който `v_1 = v_n` се нарича цикъл. |
| `Прост път` | Път `p` e прост ако всички елементи в редицата са уникални. |
| `Дължина на път` | Дължината на пътя е броя на ребрата в него. |
| `Силно свързани върхове` | В ориентиран граф казваме, че върхове `u`, `v` са силно свързани, ако съществува път от `u` до `v` и от `v` до `u` |

### Видове графи
#### Ориентиран граф
Ориентиран граф е граф, в който ръбовете имат посока, което означава, че връзките между върховете са еднопосочни. Това го прави подходящ за моделиране на зависимости и йерархии.

![Ориентиран граф](https://upload.wikimedia.org/wikipedia/commons/a/a2/Directed.svg)

#### Неориентиран граф
Неориентиран граф е граф, в който ръбовете нямат посока. Това означава, че връзките между върховете са двупосочни, което го прави удобен за моделиране на взаимоотношения.

![Неориентиран граф](https://en.wiktionary.org/wiki/undirected_graph#/media/File:Undirected.svg)

#### Цикличен граф
Цикличен граф съдържа поне един цикъл, което означава, че има път в графа, който започва и завършва в един и същ връх.

![Цикличен граф](https://upload.wikimedia.org/wikipedia/commons/2/26/Simple_cycle_graph.svg)

#### Ацикличен граф
Ацикличен граф е граф, който не съдържа цикли.

![Ацикличен граф](https://upload.wikimedia.org/wikipedia/commons/f/f7/Binary_tree.svg)

#### Свързан граф
Свързан граф е граф, в който съществува път между всяка двойка върхове. Това гарантира, че всички върхове са свързани помежду си.

![Свързан граф](https://upload.wikimedia.org/wikipedia/commons/c/cf/Complete_graph_K5.svg)

#### Претеглен (тегловен) граф
Претеглен граф е граф, в който всеки ръб има асоциирана стойност (тегло), което може да представлява разстояние, цена или друга характеристика.

![Претеглен граф](https://upload.wikimedia.org/wikipedia/commons/5/58/Weighted_Graph.svg)

#### Пълен граф
Пълен граф е граф, в който всеки връх е свързан с всички останали върхове чрез ръбове.

![Пълен граф](https://upload.wikimedia.org/wikipedia/commons/a/a9/Petersen-graph-factors.svg)


### Операции
| Операция | Описание |
| --- | --- |
| **`adjacent(G, x, y):`** | Проверява дали съществува ръб между върховете `x` и `y`. |
| **`neighbors(G, x):`** | Връща списък с всички върхове `y`, за които съществува ръб от `x` до `y`. |
| **`add_vertex(G, x):`** | Добавя върха `x`, ако все още не е в графа. |
| **`remove_vertex(G, x):`** | Премахва върха `x`, ако е в графа. |
| **`add_edge(G, x, y, z):`** | Добавя ръб `z` между `x` и `y`, ако ръбът още не съществува. |
| **`remove_edge(G, x, y):`** | Премахва ръба между `x` и `y`, ако съществува. |
| **`get_vertex_value(G, x):`** | Връща стойността, асоциирана с върха `x`. |
| **`set_vertex_value(G, x, v):`** | Променя стойността, асоциирана с върха `x`, на `v`. |

Структурите, които асоциират стойности с ръбовете, често предлагат и тези допълнителни операции:
| Операция | Описание |
| --- | --- |
| **`get_edge_value(G, x, y):`** | Връща стойността, асоциирана с ръба `(x, y)`. |
| **`set_edge_value(G, x, y, v):`** | Променя стойността, асоциирана с ръба `(x, y)`, на `v`. |

### Представяне
#### Списък на съседите (Adjacency List)
![adjacency-list](https://raw.githubusercontent.com/stoychoX/Data-structures-and-algorithms/main/Seminar11/media/weighted-list.png)

Всеки връх съдържа списък със съседните върхове.

```c++
class AdjacencyListGraph {
private:
    std::unordered_map<int, std::unordered_set<int>> adj_list;

public:
    void add_vertex(int vertex) {
        adj_list[vertex]; // Създава празен списък съседи за нов връх.
    }

    void add_edge(int u, int v) {
        if (adj_list.find(u) == adj_list.end() || adj_list.find(v) == adj_list.end())
            throw std::invalid_argument("Vertex does not exist!");

        adj_list[u].insert(v);
        adj_list[v].insert(u); // За неориентиран граф.
    }

    void remove_vertex(int vertex) {
        if (adj_list.find(vertex) != adj_list.end()) {
            for (int neighbor : adj_list[vertex]) 
                adj_list[neighbor].erase(vertex);
   
            adj_list.erase(vertex);
        }
    }

    void remove_edge(int u, int v) {
        if (adj_list[u].count(v)) adj_list[u].erase(v);
        if (adj_list[v].count(u)) adj_list[v].erase(u);
    }

    bool are_adjacent(int u, int v) {
        return adj_list[u].count(v) > 0;
    }

    const std::unordered_set<int>& neighbors(int vertex) const {
        return adj_list.at(vertex);
    }
};
```

#### Матрица на съседство (Adjacency Matrix)
![adjacency-matrix](https://raw.githubusercontent.com/stoychoX/Data-structures-and-algorithms/refs/heads/main/Seminar11/media/matrix.png)

Двумерна матрица, в която редовете представят изходни върхове, а колоните – целеви върхове.

```c++
class AdjacencyMatrixGraph {
private:
    std::vector<std::vector<int>> matrix;
    int size;

public:
    AdjacencyMatrixGraph(int n) : size(n), matrix(n, std::vector<int>(n, 0)) {}

    void add_edge(int u, int v) { // Може да добавим и тегло при weighted graph
        if (u >= size || v >= size) 
            throw std::out_of_range("Invalid vertex index!");   

        matrix[u][v] = 1;
        matrix[v][u] = 1; // За неориентиран граф.
    }

    void remove_edge(int u, int v) {
        if (u >= size || v >= size) 
            throw std::out_of_range("Invalid vertex index!");

        matrix[u][v] = 0;
        matrix[v][u] = 0;
    }

    bool are_adjacent(int u, int v) {
        if (u >= size || v >= size) 
            throw std::out_of_range("Invalid vertex index!");

        return matrix[u][v] == 1;
    }
};
```
#### Матрица на инцидентност (Incidence Matrix)
![graph](https://raw.githubusercontent.com/stoychoX/Data-structures-and-algorithms/main/Seminar11/media/incidence-matrix.png)
![incidence-matrix](https://raw.githubusercontent.com/stoychoX/Data-structures-and-algorithms/main/Seminar11/media/1.png)

- Двумерна матрица, в която редовете представят върховете, а колоните – ръбовете.
- Елементите показват кои върхове се свързват от кой ръб.

```c++
class IncidenceMatrixGraph {
private:
    std::vector<std::vector<int>> incidence_matrix;
    int vertex_count;
    int edge_count;

public:
    IncidenceMatrixGraph(int vertices, int edges)
        : vertex_count(vertices), edge_count(edges),
          incidence_matrix(vertices, std::vector<int>(edges, 0)) {}

    void add_edge(int edge_id, int u, int v) {
        if (edge_id >= edge_count || u >= vertex_count || v >= vertex_count) 
            throw std::out_of_range("Invalid vertex or edge index!");

        incidence_matrix[u][edge_id] = 1;
        incidence_matrix[v][edge_id] = 1; // За неориентиран граф.
    }

    void remove_edge(int edge_id) {
        if (edge_id >= edge_count) 
            throw std::out_of_range("Invalid edge index!");

        for (int i = 0; i < vertex_count; ++i) 
            incidence_matrix[i][edge_id] = 0;

    }

    bool is_edge_incident(int edge_id, int vertex) {
        if (edge_id >= edge_count || vertex >= vertex_count) 
            throw std::out_of_range("Invalid vertex or edge index!");

        return incidence_matrix[vertex][edge_id] == 1;
    }
};
```

### Сложност на операциите

| Операция                                   | Adjacency List | Adjacency Matrix | Incidence Matrix |
|-------------------------------------------|--------------------|----------------------|-------------------------|
| **Съхранение на граф**                        | `O(|V| + |E|)` | `O(|V|^2)`       | `O(|V|.|E|)`  |
| **Добавяне на връх**                          | `O(1)`         | `O(|V|^2)`       | `O(|V|.|E|)`  |
| **Добавяне на ръб**                           | `O(1)`         | `O(1)`           | `O(|V|.|E|)`  |
| **Премахване на връх**                        | `O(|E|)`       | `O(|V|^2)`       | `O(|V|.|E|)`  |
| **Премахване на ръб**                         | `O(|V|)`       | `O(1)`           | `O(|V|.|E|)`  |
| **Проверка за съседство (`x, y`)**        | `O(|V|)`       | `O(1)`           | `O(|E|)`            |

### Забележки

- **Списък на съседите:** Подходящ за разредени графи (sparse graphs).
- **Матрица на съседство:** Предпочитан за плътни графи (dense graphs), където `|E| ~ |V|^2`.
- **Матрица на инцидентност:** тъй като добавянето и премахването на върхове и ръбове е скъпо, e подходящ за специфични случаи, например когато основният фокус е върху ръбовете, например при задачи за намиране на пътища, които свързват определени върхове.


### Обхождане
#### Търсене в дълбочинa (depth-first-search)
![dfs](https://skilled.dev/images/dfs.gif)
```c++
void dfs(int vertex, const Graph& graph, std::unordered_set<int>& visited) {
    visited.insert(vertex);

    for (int neighbor : graph.neighbors(vertex)) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, graph, visited);
        }
    }
}

void dfs(const Graph& graph, int start) {
    std::unordered_set<int> visited;
    dfs(start, graph, visited);
}
```

#### Търсене в широчина (breadth-first-search)
![bfs](https://skilled.dev/images/bfs.gif)
```c++
void bfs(const Graph& graph, int start) {
    std::unordered_set<int> visited;
    std::queue<int> q;

    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph.neighbors(current)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}
```

#### Алгоритъм на Дейкстра
Алгоритъмът на Дейкстра се използва за намиране на най-краткия път от един връх до всички други върхове в граф с положителни тежести на ръбовете. Това е [алчен](https://en.wikipedia.org/wiki/Greedy_algorithm) алгоритъм, който постепенно изгражда оптималните решения за всички върхове.

1. Започваме от изходния връх и задаваме разстоянието му да бъде 0.
2. За всеки друг връх задаваме разстоянието му да бъде безкрайност (∞).
3. Поставяме всички върхове в приоритетна опашка, като започваме с изходния връх.
4. Докато има върхове в опашката:
    1. Изваждаме връха с най-малко разстояние от опашката.
    2. Обновяваме разстоянията на съседните върхове, като проверяваме дали новото разстояние през текущия връх е по-малко от старото разстояние.
    3. Ако е по-малко, обновяваме разстоянието на съседния връх.
5. Когато всички върхове са посетени, разстоянията ще съдържат най-кратките пътища от началния връх до всички останали върхове.

![dijkstra](https://upload.wikimedia.org/wikipedia/commons/5/57/Dijkstra_Animation.gif)

```c++
void dijkstra(const Graph& graph, int start) {
    // Приоритетна опашка със стойности <цена, връх>
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    
    // Тук ще пазим дистанциите от началния връх до всеки друг
    std::unordered_map<int, int> dist;

    // Тук ще пазим посетените върхове
    std::unordered_set<int> visited;

    // Инициализация на разстоянията
    for (const auto& vertex : graph.neighbors(start))
        dist[vertex.first] = INT_MAX;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Ако е посетен този връх, няма да го обработваме пак
        if (visited.find(u) != visited.end()) {
            continue;
        }

        visited.insert(u);

        // Обновяване на разстоянията на съседите
        for (const auto& neighbor : graph.neighbors(u)) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (visited.find(v) == visited.end() && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}
```

### Задачи
#### 1
Даден е насочен граф с тегловни ръбове. Намерете най-краткия път от даден изходен връх `source` до целевия връх `destination`.

#### 2
Даден е насочен граф. Напишете функция, която проверява дали има цикъл в него.

#### 3
Даден е граф, може да е ориентиран или неориентиран, и два върха. Напишете функция, която връща списък от всички пътища между тях.

#### 4
Даден е неориентиран граф. Трябва да проверите дали графът е свързан, т.е. дали има път между всяка двойка върхове.

#### 5
Даден е неориентиран граф. Напишете функция, която връща броя на компонентите на свързаност в графа, т.е. броя на групите от върхове, които са свързани помежду си.

#### 6
Даден е неориентиран граф и два върха. Трябва да намерите колко различни пътища съществуват между тях, които имат точно определена дължина (брой на ръбовете).

#### 7
Даден е неориентиран ацикличен граф. Трябва да намерите най-дългия път между два върха в графа.

