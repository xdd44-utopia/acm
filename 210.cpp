#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const double eps=1e-10;
struct Point{
	double x,y;
	int id;
	Point(double x=0,double y=0,int id=0):x(x),y(y),id(id){}
};
typedef Point Vector;

bool cmp(Point a,Point b) {
	if (a.y == b.y && a.x < b.x) {
		return true;
	}
	else if (a.y < b.y) {
		return true;
	}
	return false;
}

Vector operator + (Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);}
Vector operator - (Vector A,Vector B){return Vector(A.x-B.x,A.y-B.y);}
Vector operator * (Vector A,double B){return Vector(A.x*B,A.y*B);}
Vector operator / (Vector A,double B){return Vector(A.x/B,A.y/B);}

int dcmp(double x){if(fabs(x)<eps)return 0;return (x>0)?1:-1;}
bool operator == (const Vector A,const Vector B){
	return dcmp(A.x-B.x)==0 && dcmp(A.y-B.y)==0;
}
double Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
double Length(Vector A){return sqrt(Dot(A,A));}
double Cross(Vector A,Vector B){return A.x*B.y-B.x*A.y;}

int ConvexHell(Point p[],int n,Point ch[]) {
	sort(p, p+n, cmp);
	int m=0;
	for(int i=0;i<n;i++){
		while(m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0){
			m--;
		}
		ch[m++]=p[i];
	}
	int k=m;
	for(int i=n-2;i>=0;i--){
		while(m>k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0){
			m--;
		}
		ch[m++]=p[i];
	}
	if(n>1)m--;
	return m;
}
int main(){
	freopen("/Users/xdd44/Documents/Code/210/210.in", "r", stdin);
	int caseNum;
	cin >> caseNum;
	cout << caseNum << endl;
	while (caseNum--) {
		int n;
		cin >> n;
		Point p[20],ch[20];
		for(int i=0;i<n;i++) {
			cin >> p[i].x >> p[i].y;
		}
		if (caseNum > 0) {
			int t;
			cin >> t;
		}
		int sum = ConvexHell(p, n, ch);
		cout << sum + 1 << endl;
		for(int i=0;i<sum;i++) {
			cout << ch[i].x << " " << ch[i].y << endl;
		}
		cout << ch[0].x << " " << ch[0].y << endl;
		if (caseNum > 0) {
			cout << -1 << endl;
		}
	}
	return 0;
}
