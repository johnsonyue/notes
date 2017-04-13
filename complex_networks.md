#[Wang Xiaofan book](books/network_science.pdf)
##organization:
 * Chp 2&3. graph theory, topology
 * Chp 8. scale-free network
 * Chp 4. degree corelation ?
 * Chp 5. betweeness, k-core ..

##Intro:
 * Complex network 2 properties:
	 * [small world](books/complex_network/smallworld.pdf),
	 * [scale free](books/complex_network/scalefree.pdf)


##Theory:
 * Topology:
	 * Networks' perspective:
		 * 只关注多少个节点，节点间连接
	 * Geometry Objects' perspective:
		 * 连续变形(allow skewing, but no cutting or wielding) 保持不变的性质

 * Graph:
	 * 网络的图表示：
		 * Network --(abstract)--> Graph
		 * Graph = V,E.  Each e in E, e[0], e[1] in V.
	 * Traceroute 路径拓扑图： 带权有向图，简单图（无重边和自环），用边表（三元组）
	 * Maintain Graph in Computer:
		 * Adjacency Matrix:
			 * 行列对换矩阵改变，但图的特征不变，因为：
			 * 矩阵论：正交变换不改变特征值
		 * Adjacency List && 三元组:
			 * 适合存稀疏矩阵

	 * Graph Properties of Interest:
		 * 共引 && 耦合 （Cocitation && Bioblographic Coupling）：
		 * 路径 && 连通性 && 树：
			 * [王义和]():
				 * 通道是顶点的序列（v0,v1...,vn），顶点可以重。
				 * 闭合性：通道v0=vn.
				 * 特殊通道：边不重为迹，点不重为路。
				 * 考虑图的连通性考虑路。
		 * G-S算法求稳定匹配：
		 * degree:
			 * 无向图：平均节点度=2*|E| / |V|
			 * 有向图：平均节点出／入度= |E| / |V|

* Complex Network:
	* Difference from Graph:
		* CN are much bigger in size. (经典力学vs统计力学，体现哲学上观点，量变到质变)
		* CN considers evolvement.

	* Density:
		* Rou = 2*|E| / ( |V| * (|V|-1) )
		* Rou = 平均节点度 / (|V|-1)
		* 密度随网络演变而变化：
			* |V|->infinite, |E|/|V|->C, 则Rou->0,变稀疏
			* |V|->infinite, |E|/|V|^2->C（每个节点都有一定比例直接连到其他节点）, 则Rou->C,变稠密
			* 通常网络演变时密度变化介于二者之间，即服从“稠密化幂律”：  
				|E|=|V|^alpha，1<alpha<2.