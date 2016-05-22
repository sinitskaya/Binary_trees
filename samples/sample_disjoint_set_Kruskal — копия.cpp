#include "disjoint_set.h"
#include "graph.h"
#include "queue.h"

int main()
{
	try{
	setlocale(0,"");
	//Graph g1(6,10);
	int r1 = -1;
	cout << "Пользовательский ввод - 0"<< endl << "Пример - 1"<< endl;
	cin >> r1;
	Graph g1(8);
	if (r1 == 0)
	{
		Graph g2(1,1,1);
		g1 = g2;
	}
	if (r1 == 1)
	{
		Graph g2(8);
		//g2.Print();
		g2.edge[0][1] = 2;
		g2.edge[0][2] = 1;
		g2.edge[0][3] = 0;
		g2.edge[0][4] = 5;
		g2.edge[0][5] = -1;
		g2.edge[0][6] = -1;
		g2.edge[0][7] = -1;

		g2.edge[1][2] = 2;
		g2.edge[1][3] = -1;
		g2.edge[1][4] = 2;
		g2.edge[1][5] = 3;
		g2.edge[1][6] = -1;
		g2.edge[1][7] = -1;

		g2.edge[2][3] = -1;
		g2.edge[2][4] = 4;
		g2.edge[2][5] = -1;
		g2.edge[2][6] = -1;
		g2.edge[2][7] = -1;

		g2.edge[3][4] = 3;
		g2.edge[3][5] = -1;
		g2.edge[3][6] = 8;
		g2.edge[3][7] = -1;

		g2.edge[4][5] = 1;
		g2.edge[4][6] = -1;
		g2.edge[4][7] = 4;

		g2.edge[5][6] = 7;
		g2.edge[5][7] = 2;

		g2.edge[6][7] = 5;
		
		for(int i=0; i<g2.gsize; i++)
			for(int j=0; j<g2.gsize; j++)
				g2.edge[j][i] = g2.edge[i][j];
		//g2.Print();
		g1 = g2;
	}

	/*for(int i=0; i<g1.gsize; i++)
		for(int j=0; j<g1.gsize; j++)
			g1.edge[j][i] = g1.edge[i][j];*/
	cout << "Матрица смежности:" << endl;
	g1.Print();//
	cout << endl;
	/////////////////////////////////((size*size)/2)
	int size = g1.gsize; //n={12,76,98};
	int s = ((size*size));

	Node **v = new Node*[s];
	for(int i=0; i<s; i++)
		v[i] = new Node(-1);

	cout << "Список ребер: ";
	int k = 0;
	for(int i=0; i<g1.gsize; i++)
		for(int j=0; j<i; j++)
			if ( (j!=i) && (g1.edge[i][j]!=-1) )
			{
				v[k]->e.key = g1.edge[i][j];
				v[k]->e.v1 = i;
				v[k]->e.v2 = j;
				//cout << g1.edge[i][j] << " " << "= " << v[k]->e.key << "k= "<< k<< endl;
				k++;
			}
	cout << endl;
	
	BSearchTree_Queue q(k, v[0]);
	int f=0;
	for(int i=1; i<k; i++)
		//if(n[i].ves!=-1) учли тут (g1.edge[i][j]!=-1)
		{
			q.Insert(v[i]);
			f++;
		}
	q.SetQsize(k);
	int kol = k;
	q.print2();			//вывод списка ребер

	Edge *newn = new Edge[k];					 //миним ост дер
	for(int i=0; i<k; i++)
	{
		newn[i].v1 = -1;
		newn[i].v2 = -1;
		newn[i].key = -1;
	}

	Disjoint_set d(size); //0 до 7
	for( int i=0; i<=g1.gsize-1; i++)
		d.CreateSingleton(i);
	
	int t = 0, l = 0;
//	cout << "v1: " << bv.v1 << "v2: " << bv.v2 << "ves: " << bv.ves;
	while( (!q.IsEmpty()) && (l<kol-1) ) //&& (t<size-1)
	{
		Edge bv = q.Top();
		int r = d.FindSubset(bv.v1); f = d.FindSubset(bv.v2);
		//cout << "d.FindSubset(bv.v1): " << r << "  d.FindSubset(bv.v2): " << f << endl;
		if(r!=f)
		{
			d.Union( d.FindSubset(bv.v1), d.FindSubset(bv.v2) );
			newn[t].v1 = bv.v1;
			newn[t].v2 = bv.v2;
			newn[t].key = bv.key;
			t++;
		}
		l++;
		//cout << q.GetQsize()<< endl;
		q.Pop();
		//q.print2();
	} cout << endl;
	cout << "Минимальное остовное дерево: " << endl; 
	for(int i=0; i<t; i++)
		cout << "v1: " << newn[i].v1 << "  v2: " << newn[i].v2 << "  ves: " << newn[i].key << endl;

	delete [] newn;
	system("pause");
	}

	catch(exception &e)
	{
		cout << e.what() << endl;
		system("pause");
		return 0;
	}
	return 0;
}