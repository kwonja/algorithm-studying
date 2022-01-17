#include <string>
#include <deque>
#include <algorithm>
#include <utility>

using namespace std;
deque<pair<int, int>> arr;
int check;
bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}
bool compare1(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}
int solution(vector<int> food_times, long long k) {
	int sum = 0;
	for (int i = 0; i < food_times.size(); i++)
	{
		arr.push_back(make_pair(food_times[i], i + 1));
		sum += food_times[i];
	}
	if (sum <= k)
	{
		return -1;
	}
	sort(arr.begin(), arr.end(), compare);
	sum = 0;
	while (1)
	{
		check = k - ((arr[0].first - sum)*arr.size());
		if (check >= 0)
		{
			k = k - ((arr[0].first - sum)*arr.size());
			sum += (arr[0].first - sum);
			arr.pop_front();
		}
		else
			break;
	}
	sort(arr.begin(), arr.end(), compare1);
	if (k == 0) return arr[0].second;
	else
		k = k % arr.size();
	return arr[k].second;

}
//정확성 부분에서는 맞았지만, 효율성부분에서 떨어진 코드
//sort를 두번하는 과정이나 k를 줄여나가는 방법에서 떨어진것 같다.


//2번째 시도
#include <string>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.first > b.first;
	}
};
int solution(vector<int> food_times, long long k) {
	int sum = 0; int check;
	priority_queue< pair<int, int>, vector<pair<int, int>>, cmp> pq;
	for (int i = 0; i < food_times.size(); i++)
	{
		pq.push(make_pair(food_times[i], i + 1));
		sum += food_times[i];
	}
	if (sum <= k)
	{
		return -1;
	}
	sum = 0;
	while (1)
	{
		check = k - ((pq.top().first - sum)*pq.size());
		if (check >= 0)
		{
			k = k - (pq.top().first - sum)*pq.size();
			sum += (pq.top().first - sum);
			pq.pop();
		}
		else
			break;
	}
	k = k % pq.size(); //여기서부터는 기존의 순서를 기억해야함->남아있는 것들
	vector<int> number;
	int n = pq.size();
	for (int i = 0; i < n; i++)
	{
		number.push_back(pq.top().second);
		pq.pop();
	}
	sort(number.begin(), number.end());
	return number[k];
}





//이 코드 역시 효율성 부분에서 떨어졌는데, k를 줄이는과정을 더 축소해야될것 같다.