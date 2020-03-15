////商店中每种商品都有标价。例如，一朵花的价格是2元。一个花瓶的价格是5 元。为了吸引顾客，商店提供了一组优惠商品价。优惠商品是把一种或多种商品分成一组，并降价销售。例如，3朵花的价格不是6元而是5元。2 个花瓶加1 朵花的优惠价是10 元。试设计一个算法，计算出某一顾客所购商品应付的最少费用。
////
////对于给定欲购商品的价格和数量，以及优惠商品价，编程计算所购商品应付的最少费用。
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int B;            // 所购商品种类数
//	int C[5];         // 商品编码
//	int K[5] = { 0 }; // 购买该种商品总数
//	int P[5];         // 该商品正常单价
//	int Code[1000];   // 用于规范化商品编码
//
//	cin >> B;
//	if (B == 0)
//	{
//		cout << 0;
//		return 0;
//	}
//	for (int i = 0; i < B; ++i)
//	{
//		cin >> C[i] >> K[i] >> P[i];
//		Code[C[i]] = i;
//	}
//
//	int S;                          // 优惠商品组合数
//	cin >> S;
//	int J[100];                     // 某一优惠组合中商品的种类数
//	int discounts[100][1000][2];    // discount[i][j][0]描述第i个优惠组合中第j个商品的id，1描述个数。
//	int SPrice[100];                // 第i个组合商品的价格
//	for (int i = 0; i < S; ++i)
//	{
//		cin >> J[i];
//		for (int ii = 0; ii < J[i]; ++ii)
//		{
//			cin >> discounts[i][ii][0] >> discounts[i][ii][1];
//			discounts[i][ii][0] = Code[discounts[i][ii][0]];
//		}
//		cin >> SPrice[i];
//	}
//
//	int goods[5];        // goods[i]表示第i个商品的个数
//	int fgoods[5];       // fgoods[i]表示在递推式中goods[i]减去相应的数量后的数值
//	int curPrice = 0;    // 表示一定的goods比例下的当前价
//	int minPrice = 1000; // 表示一定的goods比例下的最小价，最后存到KP中
//
//	int KP[6][6][6][6][6] = { 0 };
//	// KP[goods[0]][goods[1]][goods[2]][goods[3]][goods[4]]表示给定各商品购买的个数对应的最低价格
//
//	/******************************************
//	递归公式：
//	对于每一个组合商品，假设其五个单品数量分别为是[a,b,c,d,e]（可以为0），则：
//	KP[g0][g1][g2][g3][g4] = min{ KP[g0-a][g1-b][g2-c][g3-d][g4-e] + discountPrice, (pay for each) }
//	也就是说，对每个组合商品，给定购买数量的最优解为去掉该组合后的最优解加上该组合的价格。
//	******************************************/
//
//	// I 计算单买的价格
//	for (goods[0] = 0; goods[0] <= K[0]; ++goods[0])
//	for (goods[1] = 0; goods[1] <= K[1]; ++goods[1])
//	for (goods[2] = 0; goods[2] <= K[2]; ++goods[2])
//	for (goods[3] = 0; goods[3] <= K[3]; ++goods[3])
//	for (goods[4] = 0; goods[4] <= K[4]; ++goods[4])
//	{
//		KP[goods[0]][goods[1]][goods[2]][goods[3]][goods[4]] =
//			goods[0] * P[0] +
//			goods[1] * P[1] +
//			goods[2] * P[2] +
//			goods[3] * P[3] +
//			goods[4] * P[4];
//	}
//
//	// II 计算优惠的价格
//	for (goods[0] = 0; goods[0] <= K[0]; ++goods[0])
//	for (goods[1] = 0; goods[1] <= K[1]; ++goods[1])
//	for (goods[2] = 0; goods[2] <= K[2]; ++goods[2])
//	for (goods[3] = 0; goods[3] <= K[3]; ++goods[3])
//	for (goods[4] = 0; goods[4] <= K[4]; ++goods[4])
//	{
//		/* 对于每一个商品数量组合 */
//		minPrice = KP[goods[0]][goods[1]][goods[2]][goods[3]][goods[4]];
//		for (int i = 0; i < S; ++i)
//		{   /* 对于第i个优惠 */
//
//			// 1. 复制数量信息备用
//			for (int j = 0; j < 5; ++j)
//				fgoods[j] = goods[j]; 
//
//			// 2. 判断第i个优惠能不能用，顺便更新fgoods
//			bool canUse = true;
//			for (int j = 0; j < J[i]; ++j)
//			{
//				// 相应的goods数减去优惠组合中包含的数量
//				fgoods[discounts[i][j][0]] = goods[discounts[i][j][0]] - discounts[i][j][1];
//				if (fgoods[discounts[i][j][0]] < 0)
//				{
//					canUse = false;
//					break;
//				}
//			}
//			if (!canUse)
//				continue;
//
//			// 3. 计算使用当前价格购买的价格，更新最小值
//			for (int j = 0; j < J[i]; ++j)
//			{
//				curPrice = KP[fgoods[0]][fgoods[1]][fgoods[2]][fgoods[3]][fgoods[4]] + SPrice[i];
//				if (curPrice < minPrice) minPrice = curPrice;
//			}
//
//			// 4. 更新KP
//			KP[goods[0]][goods[1]][goods[2]][goods[3]][goods[4]] = minPrice;
//		}
//	}
//
//	// III 输出结果
//	cout << KP[K[0]][K[1]][K[2]][K[3]][K[4]] << endl;
//	return 0;
//}
