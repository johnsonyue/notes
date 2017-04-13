* 欧几里得：
	* gcd(a,b): 
		
			//递推关系
			定理：gcd(a,b) = gcd(b, a%b)
			证：记cd为common divisor，d为divisor
				只需证：cd(a, b) = cd(b, a%b)即可
				模除可以写成线性式：a = b*d+r
				设 c = cd(a, b),
				则 k1*c = k2*d*c+r 
				=> r = c*(k1-k2*d)
				所以，c|r，又c|a,c|b，
				所以cd(a,b)=cd(b,r)=cd(b,a%b)
			
			//状态转移（辗转相除法）
			pseudo code:
			def gcd(a,b):
				if b==0:
					return a
				else:
					return gcd(b,a%b)
				
 * e_gcd(a,b):
			
			定理：若 gcd(a, b)|c，则必有整数x, y，使a*x+b*y=c
			证：由辗转相除的过程，
				ai=bi*di+ri
				bi=ri*d(i-1)+r(i-1)
				=>r(i-1) = bi-(ai-bi*di)*d(i-1)
				=>r(i-1) = bi*(1+di*d(i-1))-ai
				即可以表示成xi*bi + yi*ai 的形式，
				所以，辗转相除最后，r(n)可以递推回a,b,
				即必有x*a+y*b=r(n)=gcd，
				又因为gcd|c，所以x,y只需扩大响应倍数即可。
			//递推关系表达式：
			ai=bi*di+ri
			bi=ri*d(i-1)+r(i-1)
			由定理：
			xi*bi+yi*ri=gcd, 
			
			由上述三个式子，就可以写出整数x,y的表达式
			使得x*ai+y*bi=gcd
			//这里很关键，要知道目标问题是什么
			//用xi,yi表示x,y即为递推关系
			
			
 * note:
	 * 递归需要明确三个问题：
		 * 问题是什么
		 * 终止条件是什么
		 * 状态转移是什么
	 * 找状态转移：
		 * 子问题看作已知
		 * 找到递推关系 （类似于方程中的等量关系）