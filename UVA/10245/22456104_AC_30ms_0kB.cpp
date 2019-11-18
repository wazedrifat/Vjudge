#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair <int, int>
#define MX 100001
struct Point {
  double x, y;
};
 
bool cmp(Point a, Point b) {
  return a.x < b.x;
};
 
double dis(Point a, Point b) {
  return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
 
int main() {
  int n;
  while (scanf("%d", &n) && n) {
    Point p[10000];
	
    for (int i = 0; i < n; i++)
      scanf("%lf%lf", &p[i].x, &p[i].y);

    if (n == 1) {
      puts("INFINITY");
      continue;
    }
    
	sort(p, p + n, cmp);
    double min = dis(p[0], p[1]);
    
	for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n && (p[j].x - p[i].x)*(p[j].x - p[i].x) < min; j++)
        if (dis(p[j], p[i]) < min) 
			min = dis(p[j], p[i]);
    
	min = sqrt(min);
    
	if (min > 10000.0 || fabs(min - 10000.0) < 0.00001) 
		puts("INFINITY");
    else 
		printf("%.4lf\n", min);
  }
}