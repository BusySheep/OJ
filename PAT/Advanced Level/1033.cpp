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
			//�ӵ��ܿ���JΪֹ
			double dis = stations[j].first - nowDistance;
			price += (dis / avgD - gas) * perPrice;
			//����j
			i = j;
			gas = 0;
		}
		else if (j < n) {
			if (minJ != -1) {
				//�ܿ����ķ�Χ��û�и����˵������ܿ����ķ�Χ���м���վ
				if (nowDistance + maxDistance > dest) {
					//����ڴ˴�������֮����ֱ�ӵ����յ�
					price += (dest - nowDistance) / avgD * perPrice;
					break;
				}
				//����
				price += (capacity - gas) * perPrice;
				gas = capacity;
				//����minJ����վ
				i = minJ;
				gas -= (stations[minJ].first - nowDistance) / avgD;
			}
			else {
				//�ܿ����ķ�Χ��û�м���վ���һ�û�е������һ������վ��Ҳ���ǻ�û�е����յ�
				//����
				price += (capacity - gas) * perPrice;
				gas = capacity;
				//������
				distanceAnswer = nowDistance + gas * avgD;
				break;
			}
		}
		else {
			//��stations[j].first > nowDistance + maxDistance
			//�ܿ����ķ�Χ��û�и����˵���
			//��ʣ�µ����м���վ�����ܿ����ķ�Χ��
			if (minJ != -1) {
				//����ʣ�µļ���վ
				if (nowDistance + maxDistance > dest) {
					//����ڴ˴�������֮����ֱ�ӵ����յ�
					price += (dest - nowDistance) / avgD * perPrice;
					break;
				}
				//����
				price += (capacity - gas) * perPrice;
				gas = capacity;
				//����minJ����վ
				i = minJ;
				gas -= (stations[minJ].first - nowDistance) / avgD;
			}
			else {
				//û��ʣ�µļ���վ��
				//����ֻҪ���������յ�
				if (maxDistance + nowDistance < dest) {//�������յ�
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
