#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(void) {
	double capacity;
	double dest;
	double avgD;
	int n;
	scanf("%lf%lf%lf%d", &capacity, &dest, &avgD, &n);
	vector<pair<double, double>> stations;
	for (int i = 0; i < n; i++) {
		double price, distance;
		scanf("%lf%lf", &price, &distance);
		stations.push_back(make_pair(distance, price));
	}
	sort(stations.begin(), stations.end());
	double gas = 0;
	double price = 0;
	double distanceAnswer = -1;
	if (stations.size() == 0 || stations[0].first != 0) {
		distanceAnswer = 0;
		goto PRINT;
	}
	for (int i = 0; i < n; ) {
		double maxDistance = capacity * avgD;
		const double& nowDistance = stations[i].first;
		const double& perPrice = stations[i].second;
		int j;
		int minJ = -1;
		for (j = i + 1; j < n && stations[j].first <= nowDistance + maxDistance; j++) {
			if (minJ == -1 || stations[j].second < stations[minJ].second) {
				minJ = j;
			}
			if (stations[j].second < perPrice) {
				break;
			}
		}
		if (j < n && stations[j].first <= nowDistance + maxDistance) {
			//加到能开到J为止
			double dis = stations[j].first - nowDistance;
			price += (dis / avgD - gas) * perPrice;
			//开到j
			i = j;
			gas = 0;
		}
		else if (j < n) {
			if (minJ != -1) {
				//能开到的范围内没有更便宜的油且能开到的范围内有加油站
				if (nowDistance + maxDistance > dest) {
					//如果在此处加完油之后能直接到达终点
					price += (dest - nowDistance) / avgD * perPrice;
					break;
				}
				//加满
				price += (capacity - gas) * perPrice;
				gas = capacity;
				//开到minJ加油站
				i = minJ;
				gas -= (stations[minJ].first - nowDistance) / avgD;
			}
			else {
				//能开到的范围内没有加油站，且还没有到达最后一个加油站，也就是还没有到达终点
				//加满
				price += (capacity - gas) * perPrice;
				gas = capacity;
				//开完油
				distanceAnswer = nowDistance + gas * avgD;
				break;
			}
		}
		else {
			//即stations[j].first > nowDistance + maxDistance
			//能开到的范围内没有更便宜的油
			//且剩下的所有加油站都在能开到的范围内
			if (minJ != -1) {
				//还有剩下的加油站
				if (nowDistance + maxDistance > dest) {
					//如果在此处加完油之后能直接到达终点
					price += (dest - nowDistance) / avgD * perPrice;
					break;
				}
				//加满
				price += (capacity - gas) * perPrice;
				gas = capacity;
				//开到minJ加油站
				i = minJ;
				gas -= (stations[minJ].first - nowDistance) / avgD;
			}
			else {
				//没有剩下的加油站了
				//于是只要尽力开到终点
				if (maxDistance + nowDistance < dest) {//开不到终点
					price += (capacity - gas) * perPrice;
					distanceAnswer = maxDistance + nowDistance;
				}
				else {
					price += (dest - nowDistance) / avgD * perPrice;
				}
				break;
			}
		}
	}
	PRINT:
	if (distanceAnswer >= 0) {
		printf("The maximum travel distance = %.2f\n", distanceAnswer);
	}
	else {
		printf("%.2f\n", price);
	}
	system("pause");
	return 0;
}
