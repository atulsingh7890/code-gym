////https://www.codechef.com/JUNE20B/problems/PRICECON
//
//
//#include <stdio.h>
//
//int main()
//{
//	int testcases = 0;
//	scanf("%d", &testcases);
//	while (testcases--)
//	{
//		int N = 0, K = 0;
//		scanf("%d %d", &N, &K);
//		long long lost = 0;
//		while (N--) {
//			int price = 0;
//			scanf("%d", &price);
//			lost += price > K ? price - K : 0;
//		}
//		printf("%lld\n", lost);
//	}
//}