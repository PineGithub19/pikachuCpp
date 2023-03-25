#include "Header_File/logic.h"

vector<pair<int, int>> findPath(int _x, int _y, int x, int y) {
	// INIT Graph
	vector<vector<char>> graph(n_rows + 2, vector<char>(n_cols + 2, '0'));
	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++) {
			graph[i + 1][j + 1] = pokemons[i][j];
		}
	}
	
	pair<int, int> s = {_x + 1, _y + 1};
	pair<int, int> t = {x + 1, y + 1};
	
	// BFS
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	deque<pair<int, int>> dq;
	dq.push_back(t);
	
	vector<vector<pair<int, int>>> trace(graph.size(), vector<pair<int, int>>(graph[0].size(), make_pair(-1, -1)));
	
	trace[t.first][t.second] = make_pair(-2, -2);
	graph[t.first][t.second] = '0';
	graph[s.first][s.second] = '0';
	while(!dq.empty()) {
		auto u = dq.front();
		dq.pop_front();
		if (u == s)
			break;
		for (int k = 0; k < 4; k++) {
			int x1 = u.first + dx[k];
			int y1 = u.second + dy[k];
			while(x1 >= 0 && x1 < graph.size() && y1 >= 0 && y1 < graph[0].size() && graph[x1][y1] == '0') {
				if (trace[x1][y1].first == -1) {
					trace[x1][y1] = u;
					dq.push_back({x1, y1});
				}
				x1 += dx[k];
				y1 += dy[k];
			}
		}	
	}
	
	// trace back - Truy Vet
	vector<pair<int, int>> result;
	if (trace[s.first][s.second].first != -1) {
		while(s.first != -2) {
			result.push_back({s.first - 1, s.second - 1});
			s = trace[s.first][s.second];
		}
	}
	
	return result;
}

//	Kiem tra xem co duong noi giua 2 cap pokemon hay khong (khong qua 3 doan)
bool canConnect(int _x, int _y, int x, int y) {
	auto path = findPath(_x, _y, x, y);
	return path.size() >= 2 && path.size() <= 4;
}

// Kiem tra xem cap pokemon x, y co hop le voi cap pokemon _x, _y hay khong
bool selectPokemon(int x, int y) { 
	if (_x == -1 && _y == -1 || pokemons[x][y] != pokemons[_x][_y] || !canConnect(_x, _y, x, y))
		return false;
	return true;
} 


