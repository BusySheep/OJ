#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Point {
	int x;
	int y;
	Point(int x, int y) : x(x), y(y) {}
};

bool operator==(Point const& a, Point const& b) {
	return a.x == b.x && a.y == b.y;
}

vector<vector<bool>> visited;
bool needVisit(Point point) {
	return point.x >= 0 && point.x < 8 && point.y >= 0 && point.y < 8 && !visited[point.y][point.x];
}

Point parsePosition(char const* position) {
	return Point(position[0] - 'a', position[1] - '1');
}

int solve(Point origin, Point destination) {
	static const int xDiff[8] = {-1, 1, -1, 1, -2, 2, -2, 2};
	static const int yDiff[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
	visited.assign(8, vector<bool>(8, false));
	int step = 0;
	queue<pair<Point, int>> q;
	q.push(make_pair(origin, 0));
	while (!q.empty()) {
		Point point = q.front().first;
		step = q.front().second;
		q.pop();
		visited[point.y][point.x] = true;
		if (point == destination) {
			break;
		}
		for (int i = 0; i < 8; ++i) {
			Point newPoint(point.x + xDiff[i], point.y + yDiff[i]);
			if (needVisit(newPoint)) {
				q.push(make_pair(newPoint, step + 1));
			}
		}
	}
	return step;
}

int main() {
	char pos1[3];
	char pos2[3];
	while (scanf("%s %s", pos1, pos2) != -1) {
		Point origin = parsePosition(pos1);
		Point destination = parsePosition(pos2);
		printf("To get from %s to %s takes %d knight moves.\n", pos1, pos2, solve(origin, destination));
	}
	return 0;
}