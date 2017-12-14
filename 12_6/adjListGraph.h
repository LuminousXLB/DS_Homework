template <class TypeOfVer, class TypeOfEdge>
class adjListGraph : public graph<TypeOfEdge> {
 public:
  adjListGraph(int vSize, const TypeOfVer d[]);
  bool insert(int u, int v, TypeOfEdge w);
  bool remove(int u, int v);
  bool exist(int u, int v) const;
  void dfs() const;
  void bfs() const;
  void EulerCircuit(TypeOfVer start);
  void topSort() const;
  ~adjListGraph();

 private:
  struct edgeNode {     //邻接表中存储边的结点类
    int end;            //边终节点编号
    TypeOfEdge weight;  //边的权值
    edgeNode *next;
    edgeNode(int e, TypeOfEdge w, edgeNode *n = NULL) {
      end = e;
      weight = w;
      next = n;
    }  // e表示边的终节点
  };
  struct verNode {   //保存顶点的数据元素类型
    TypeOfVer ver;   //顶点值
    edgeNode *head;  //对应单链表的头指针(edgeNode类型)
    verNode(edgeNode *h = NULL) { head = h; }
  };
  struct EulerNode {
    int NodeNum;      //节点号
    EulerNode *next;  //指向结点在回上的后继
    EulerNode(int ver) {
      NodeNum = ver;
      next = NULL;
    }
  };
  verNode *verList;  //指向顶点表数组的指针

  void dfs(int start, bool p[]) const;
  EulerNode *EulerCircuit(int start, EulerNode *&end);
  verNode *clone() const;
};

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::adjListGraph(int vSize,
                                                  const TypeOfVer d[]) {
  //产生只有节点的图，边表均为空
  Vers = vSize;
  Edges = 0;                                             // 0条边
  verList = new verNode[vSize];                          //申请边表空间
  for (int i = 0; i < Vers; ++i) verList[i].ver = d[i];  //赋节点号
}

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::~adjListGraph() {
  int i;
  edgeNode *p;
  for (i = 0; i < Vers; ++i)
    while ((p = verList[i].head) != NULL) {
      verList[i].head = p->next;
      delete p;
    }
  delete[] verList;
}

template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::insert(int u, int v, TypeOfEdge w) {
  //没有判断边是否存在，书上说检查并不重要，可能允许重边
  verList[u].head = new edgeNode(v, w, verList[u].head);
  //注意上面这一行：
  // 1. 申请一个新的边节点，且其后继= verList[u].head
  // 2. verList[u].head指向新的边
  //这样做可以保证插入为常量时间
  ++Edges;
  return true;
}

template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::remove(int u, int v) {
  edgeNode *p = verList[u].head, *q;
  if (p == NULL) return false;  //结点u没有相连的边，返回
  if (p->end == v) {  //单链表中的第一个结点就是被删除的边
    verList[u].head = p->next;  //标准的链表删除操作
    delete p;
    --Edges;
    return true;
  }
  while (p->next != NULL && p->next->end != v) p = p->next;
  if (p->next == NULL) return false;  //没有找到被删除的边
  q = p->next;
  p->next = q->next;
  delete q;
  --Edges;  //找到，删除
  return true;
}

template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::exist(int u, int v) const {
  edgeNode *p = verList[u].head;                 // p指向u的边表
  while (p != NULL && p->end != v) p = p->next;  //在u的边表查找有没有到v的边
  if (p == NULL)
    return false;
  else
    return true;
}

// public dfs

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs(int start, bool visited[]) const {
  edgeNode *p = verList[start].head;   // p指向邻接表节点表的start
  cout << verList[start].ver << ‘\t’;  //打印start节点
  visited[start] = true;               //把起始点标志为已访问
  while (p != NULL) {                  //避免重复访问
    if (visited[p->end] == false) dfs(p->end, visited);
    //如果p没被访问过，则以p为起始点进行递归dfs
    p = p->next;
  }
}

// private dfs
template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs(int start, bool visited[]) const {
  edgeNode *p = verList[start].head;   // p指向邻接表节点表的start
  cout << verList[start].ver << ‘\t’;  //打印start节点
  visited[start] = true;               //把起始点标志为已访问
  while (p != NULL) {                  //避免重复访问
    if (visited[p->end] == false) dfs(p->end, visited);
    //如果p没被访问过，则以p为起始点进行递归dfs
    p = p->next;
  }
}

// bfs
//基于邻接表
template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::bfs() const {
  bool *visited = new bool[Vers];  //记录节点是否被访问过
  int currentNode;
  linkQueue<int> q;  //用队列记住当前访问节点的后继节点
  edgeNode *p;
  for (int i = 0; i < Vers; ++i) visited[i] = false;  //初始态均未访问
  cout << "当前图的广度优先遍历序列为：" << endl;

  for (i = 0; i < Vers; ++i) {         //考虑当前节点i
    if (visited[i] == true) continue;  //节点已访问，跳下一节点
    q.enQueue(i);           //将节点i入队，产生以i为根的树
    while (!q.isEmpty()) {  //(q非空)遍历从i开始所有能遍历节点
      currentNode = q.deQueue();                   //出队队首为当前节点
      if (visited[currentNode] == true) continue;  //已访，下一循环
      cout << verList[currentNode].ver << ‘\t’;    //打印当前节点
      visited[currentNode] = true;    //当前节点标志为已访问
      p = verList[currentNode].head;  // p指向当前节点的边表
      while (p != NULL) {             //如果边表不空
        if (visited[p->end] == false) q.enQueue(p->end);
        p = p->next;  //如果边表中的节点没有访问，则入队
      }
    }  //当已经遍历完从i开始所有能遍历的节点，跳出while
    cout << endl;
  }
}

// private
template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::EulerNode *
adjListGraph<TypeOfVer, TypeOfEdge>::EulerCircuit(int start, EulerNode *&end) {
  //采用类DFS搜索，‘类’表示不完全一样
  //因为这里没有对访问节点做标记，允许一个回的头尾重合，允许一个节点被访问多次
  EulerNode *beg;
  int nextNode;
  beg = end = new EulerNode(
      start);  //初始回的起始指针和终了指针节指向同一个存储start的链表单元

  while (verList[start].head != NULL) {
    nextNode = verList[start].head->end;  // start边表下一节点
    remove(start, nextNode);              //删除已经被访问的边
    remove(nextNode, start);              //删除已经被访问的边
    start = nextNode;  //将nextNode作为新的起始节点继续寻路
    end->next = new EulerNode(start);  //将新节点加入回中
    end = end->next;                   // end指向新加入节点
  }
  return beg;
  //返回指向一个回(链表)的指针
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::EulerCircuit(TypeOfVer start) {
  //指定起始节点start
  EulerNode *beg, *end, *p, *q, *tb, *te;  // beg, end欧拉回起始点
  int numOfDegree;
  edgeNode *r;                      //用于指向某个边表
  verNode *tmp;                     //用于临时保存图
  for (int i = 0; i < Vers; ++i) {  //通过节点度检查欧拉回的存在性
    numOfDegree = 0;
    r = verList[i].head;
    while (r != NULL) {
      ++numOfDegree;
      r = r->next;
    }
    if (numOfDegree == 0 || numOfDegree % 2)  //度为0或奇数
    {
      cout << "不存在欧拉回路" << endl;
      return;
    }
  }

  //寻找起始结点的编号i
  for (i = 0; i < Vers; ++i)
    if (verList[i].ver == start) break;  //找到则跳出循环
  if (i == Vers)  //未找到起始节点，因为0<start<Vers
  {
    cout << "起始结点不存在" << endl;
    return;
  }
  //创建一份邻接表的拷贝以便恢复邻接表
  tmp = clone();  //因为私有函数中有删除边的行为
  //寻找从i出发的路径，
  //路径的起点和终点地址分别是beg和end
  beg = EulerCircuit(i, end);  //返回从i=start开始的一条回路
  while (true) {               //上面的EulerCircuit是找出第一条回路
    p = beg;                   //让p指向当前寻找到的回路
    while (p->next != NULL)    //回路中是否有顶点的边未被访问
      if (verList[p->next->NodeNum].head != NULL)
        break;
      else
        p = p->next;  //红字表示该顶点有未访问边，否则p后移
    if (p->next == NULL) break;  //回中所有顶点的边都被访问了
    q = p->next;  //有未访问边：q指向含尚未访问边的节点
    tb = EulerCircuit(q->NodeNum, te);  //找以tb起始以te终了回
    te->next = q->next;                 //和原来的回连接起来
    p->next = tb;                       //
    delete q;
  }
  //恢复原图
  delete[] verList;
  verList = tmp;
  //显示得到的欧拉回路
  cout << "欧拉回路是：" << endl;
  while (beg != NULL) {  //打印欧拉回
    cout << verList[beg->NodeNum].ver << '\t';
    p = beg;
    beg = beg->next;
    delete p;
  }
  cout << endl;
}

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::verNode *
adjListGraph<TypeOfVer, TypeOfEdge>::clone() const {
  verNode *tmp = new verNode[Vers];  //把邻接表保存在tmp中
  edgeNode *p;
  for (int i = 0; i < Vers; ++i) {
    tmp[i].ver = verList[i].ver;
    p = verList[i].head;
    while (p != NULL) {
      tmp[i].head = new edgeNode(p->end, p->weight, tmp[i].head);
      p = p->next;
    }
  }
  return tmp;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::topSort() const {
  linkQueue<int> q;
  edgeNode *p;
  int current, *inDegree = new int[Vers];  //用于记录节点入度
  for (int i = 0; i < Vers; ++i) inDegree[i] = 0;
  for (i = 0; i < Vers; ++i) {  //遍历每个节点对应的边表
    for (p = verList[i].head; p != NULL; p = p->next)
      ++inDegree[p->end];  //边表中记录的每个节点入度加1
  }
  for (i = 0; i < Vers; ++i)
    if (inDegree[i] == 0) q.enQueue(i);  //所有入度为0的节点入队
  cout << "拓扑排序为：" << endl;
  while (!q.isEmpty()) {    //如果队列不为空则循环
    current = q.deQueue();  //出队最前面的元素
    cout << verList[current].ver << '\t';
    for (p = verList[current].head; p != NULL; p = p->next)
      if (--inDegree[p->end] == 0)  //出队节点的后继入度减1
        q.enQueue(p->end);          //入度为0的节点入队
  }
  cout << endl;
}
