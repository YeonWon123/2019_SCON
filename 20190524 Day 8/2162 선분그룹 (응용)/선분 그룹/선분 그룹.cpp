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

// �ﰢ���� ���̸� ���ϴ� �Լ�
int SignArea(point a, point b, point c) {
	double area = 0.5 * (a.x * b.y - a.y * b.x + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y);
#ifdef DEBUG
	// printf("���� : %f\n", area);
#endif
	if (area > 0) return 1;
	else if (area == 0) return 0;
	else return -1;
}

// ������ �����ϴ����� Ȯ���ϴ� �Լ�
double T(point a, point b, point c, point d) {
	return (SignArea(a, b, c) * SignArea(a, b, d));
}

// ������ �����ϴ����� Ȯ���ϴ� �Լ�
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

// union-find ������
// �迭 �ϳ������� �ص� �����ϸ� �� ��� root�� ù��°

int union_find[3000]; // �ڽ��� �θ� ���������� ��Ÿ���� up-tree �迭

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
	// �Է¹ޱ�
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	// �Է¹����鼭 Union_find group�� �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		cin >> input[i].p1.x >> input[i].p1.y
			>> input[i].p2.x >> input[i].p2.y;

		union_find[i] = i; // parent�� �ڱ� �ڽ�
	}

	// �� ������ ���� �����ϴ��� ����
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (intersect(input[i], input[j])) {
				Union(i, j);
			}
		}
	}

	// Union_find�� �����͸� ä������ ���� ������� ����
	int group_count = 0; // �׷��� ��
	int line_count[3000] = { 0, }; // �׷�鿡 ���� ������ ����
	int max_line = 0;    // ���� ũ�Ⱑ ū �׷쿡 ���� ������ ����

	for (int i = 0; i < N; i++) {
		if (union_find[i] == i) {
			group_count++; // ��Ʈ ����� �� == �׷��� ��
		}

		line_count[find_set(i)]++; // ������ ������ 1 ������Ŵ

		// ���� ũ�Ⱑ ū �׷쿡 ���� ������ ���� ����
		if (line_count[find_set(i)] > max_line) {
			max_line = line_count[find_set(i)];
		}
	}

	cout << group_count << "\n" << max_line;
	return 0;
}