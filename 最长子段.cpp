#include<iostream>
#include<ctime>
#include<algorithm>
#include<vector>
#include<random>
#include<cstdlib>
using namespace std;

//��������Ӷβ�����
vector<int> getRandomvec(int num)
{
	default_random_engine e(time(NULL));
	uniform_real_distribution<double> u(-50, 50);
	vector<int> vec;
	for (int i = 0; i < num; i++)
	{
		vec.push_back(u(e));
	}//�����ʼ���Ӵ�
	//sort(vec.begin(), vec.end());
	cout << "��Щ�������Ϊ��" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << vec[i]<<'\t';
	}
	return vec;
}
int maxsumpart(vector<int> a, int left, int right)
{
	int sum;
	if (left == right)
	{sum = a[left] > 0 ? a[left] : 0;//�ݹ���ֹ�򷵻�
	return sum;
}
	int mid = (left + right) / 2;
	int maxleft = maxsumpart(a, left, mid);//���
	int maxright = maxsumpart(a, mid + 1, right);//�Ҷ�
	int left_tmp = 0;
	int max1=0;
	int max2 = 0;
	int right_tmp = 0;
	for (int i = mid; i >= left; --i)
	{
		left_tmp += a[i];
		if (left_tmp > max1)
			max1 = left_tmp;
	}
	for (int i = mid+1; i <right; ++i)//������
	{
		right_tmp += a[i];
		if (right_tmp > max2)
			max1 = right_tmp;
	}
	 sum = max1 + max2;
	if (sum < maxleft)
		sum = maxleft;
	if (sum < maxright)
		sum = maxright;
	return sum;
 }
int main()
{
	vector<int>a;
	a=getRandomvec(10);
	cout << endl;
	//int a[] = { -1,2,3,6,-7,8,6,9,-12 };
	cout << maxsumpart(a, 0, 9);
	return 0;
}