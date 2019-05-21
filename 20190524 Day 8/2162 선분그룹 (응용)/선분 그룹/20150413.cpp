#include <iostream>
using namespace std;

typedef struct POINT {
	double x;
	double y;

	// operator overloading
	bool operator > (const POINT &a) const {
		return ((x > a.x) || ((x == a.x) && (y > a.y)));
	}

	// operator overloading
	bool operator < (const POINT &a) const {
		return ((x < a.x) || ((x == a.x) && (y < a.y)));
	}

	// operator overloading
	bool operator <= (const POINT &a) const {
		return ((*this < a) || ((x == a.x) && (y == a.y)));
	}

} point;

struct line {
	point p1;
	point p2;
};

line input[3000];

// 삼각형의 넓이를 구하는 함수
int SignArea(point a, point b, point c) {
	double area = 0.5 * (a.x * b.y - a.y * b.x + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y);
#ifdef DEBUG
	// printf("넓이 : %f\n", area);
#endif
	if (area > 0) return 1;
	else if (area == 0) return 0;
	else return -1;
}

// 선분이 교차하는지를 확인하는 함수
double T(point a, point b, point c, point d) {
	return (SignArea(a, b, c) * SignArea(a, b, d));
}

// 선분이 교차하는지를 확인하는 함수
bool intersect(line l_one, line l_two) {
	point a = l_one.p1;
	point b = l_one.p2;
	point c = l_two.p1;
	point d = l_two.p2;


	if (T(a, b, c, d) == 0 && T(c, d, a, b) == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	else
		return T(a, b, c, d) <= 0 && T(c, d, a, b) <= 0;
}

// union-find 만들어보자
// 배열 하나만으로 해도 가능하며 이 경우 root는 첫번째

int union_find[3000]; // 자신의 부모가 누구인지를 나타내는 up-tree 배열

int find_set(int x) {
	if (union_find[x] == x) return x;
	find_set(union_find[x]);
}

void Union(int x, int y) {
	int a = find_set(x);
	int b = find_set(y);

	if (a < b) union_find[b] = a;
	else if (a > b) union_find[a] = b;
}

int main(void)
{
	// 입력받기
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	// 입력받으면서 Union_find group을 초기화
	for (int i = 0; i < N; i++) {
		cin >> input[i].p1.x >> input[i].p1.y
			>> input[i].p2.x >> input[i].p2.y;

		union_find[i] = i; // parent는 자기 자신
	}

	// 두 선분이 서로 교차하는지 판정
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (intersect(input[i], input[j])) {
				Union(i, j);
			}
		}
	}

	// Union_find에 데이터를 채웠으니 이제 결과값을 찍어보자
	int group_count = 0; // 그룹의 수
	int line_count[3000] = { 0, }; // 그룹들에 대한 선분의 개수
	int max_line = 0;    // 가장 크기가 큰 그룹에 속한 선분의 개수

	for (int i = 0; i < N; i++) {
		if (union_find[i] == i) {
			group_count++; // 루트 노드의 수 == 그룹의 수
		}

		line_count[find_set(i)]++; // 선분의 개수를 1 증가시킴

		// 가장 크기가 큰 그룹에 대한 선분의 개수 갱신
		if (line_count[find_set(i)] > max_line) {
			max_line = line_count[find_set(i)];
		}
	}

	cout << group_count << "\n" << max_line;
	return 0;
}