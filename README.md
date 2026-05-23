# 408 数据结构（C语言实现）

> 考研 408 数据结构核心代码实现，基于 C99 标准，CMake 构建。  
> 面向 408 考研复习，强调 **核心代码实现 + 时间复杂度分析 + 高频考点总结**。

---

## 目录

- [项目结构](#项目结构)
- [构建方式](#构建方式)
  - [依赖](#依赖)
  - [编译运行](#编译运行)
- [章节索引](#章节索引)
  - [第2章 线性表](#第2章-线性表)
  - [第3章 栈和队列](#第3章-栈和队列)
  - [第4章 串](#第4章-串)
  - [第5章 树与二叉树](#第5章-树与二叉树)
  - [第6章 图](#第6章-图)
  - [第7章 查找](#第7章-查找)
  - [第8章 排序](#第8章-排序)
- [代码规范](#代码规范)
- [参考](#参考)
- [TODO](#todo)

---

## 项目结构

```text
408-data-structures/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── include/
│   └── common.h
├── src/
│   ├── ch2_linear_list/
│   ├── ch3_stack_queue/
│   ├── ch4_string/
│   ├── ch5_tree/
│   ├── ch6_graph/
│   ├── ch7_search/
│   └── ch8_sort/
└── tests/
```

说明：

- `common.h`：统一定义 `Status`、`ElemType` 等公共类型
- `src/`：按照王道章节组织代码
- `tests/`：测试代码（可选）
- 每个模块独立编译运行

---

## 构建方式

### 依赖

要求：

- GCC / Clang（支持 C99）
- CMake >= 3.10

Ubuntu：

```bash
sudo apt update

sudo apt install build-essential cmake
```

Arch Linux：

```bash
sudo pacman -S gcc cmake make
```

---

### 编译运行

```bash
mkdir build

cd build

cmake ..

make -j$(nproc)
```

运行示例：

```bash
./bin/sqlist
./bin/linklist
./bin/sqstack
./bin/kmp
```

---

## 章节索引

---

## 第2章 线性表

| 文件名 | 内容 | 核心考点 | 时间复杂度 | 空间复杂度 | 王道页码 |
|--------|------|----------|------------|------------|----------|
| sqlist.c | 顺序表 | 插入、删除、查找 | O(n) | O(1) | Pxx |
| linklist.c | 单链表 | 头插法、尾插法、逆置 | O(n) | O(1) | Pxx |
| duallinklist.c | 双链表 | 插入、删除 | O(1) | O(1) | Pxx |
| circularlist.c | 循环链表 | 判空、尾节点处理 | - | - | Pxx |
| staticlinklist.c | 静态链表 | 游标实现 | - | - | Pxx |

### 高频算法

- 链表原地逆置
- 合并两个有序链表
- 删除重复元素
- 查找倒数第 K 个结点
- 快慢指针

---

## 第3章 栈和队列

| 文件名 | 内容 | 核心考点 | 王道页码 |
|--------|------|----------|----------|
| sqstack.c | 顺序栈 | 栈满判断 | Pxx |
| linkstack.c | 链栈 | 链式存储 | Pxx |
| sqqueue.c | 循环队列 | 队空/队满 | Pxx |
| linkqueue.c | 链队列 | 出队入队 | Pxx |

### 高频应用

- 括号匹配
- 表达式求值
- 中缀转后缀
- DFS（递归栈）
- BFS（队列）

---

## 第4章 串

| 文件名 | 内容 | 核心考点 | 王道页码 |
|--------|------|----------|----------|
| string.c | 顺序串 | 基本操作 | Pxx |
| kmp.c | KMP算法 | next数组、nextval数组 | Pxx |

### 高频算法

- BF算法
- KMP匹配
- next数组推导
- nextval优化

---

## 第5章 树与二叉树

| 文件名 | 内容 | 核心考点 | 时间复杂度 | 王道页码 |
|--------|------|----------|------------|----------|
| bitree.c | 二叉树 | 遍历 | O(n) | Pxx |
| threadtree.c | 线索二叉树 | 建线索 | O(n) | Pxx |
| bst.c | 二叉排序树 | 查找、插入、删除 | O(h) | Pxx |
| avltree.c | AVL树 | LL/RR/LR/RL旋转 | O(log n) | Pxx |
| huffman.c | 哈夫曼树 | WPL | O(nlogn) | Pxx |

### 高频内容

- 先序、中序、后序、层序遍历
- 递归与非递归实现
- BST删除
- AVL旋转
- 哈夫曼编码

---

## 第6章 图

| 文件名 | 内容 | 核心考点 | 时间复杂度 | 王道页码 |
|--------|------|----------|------------|----------|
| mgraph.c | 邻接矩阵 | 图存储 | - | Pxx |
| algraph.c | 邻接表 | 图存储 | - | Pxx |
| dfs_bfs.c | DFS/BFS | 遍历 | O(V+E) | Pxx |
| prim.c | Prim | 最小生成树 | O(V²) | Pxx |
| kruskal.c | Kruskal | 最小生成树 | O(ElogE) | Pxx |
| dijkstra.c | Dijkstra | 单源最短路 | O(V²) | Pxx |
| floyd.c | Floyd | 多源最短路 | O(V³) | Pxx |
| topo.c | 拓扑排序 | DAG | O(V+E) | Pxx |
| critical_path.c | 关键路径 | AOE网 | O(V+E) | Pxx |

### 高频内容

- DFS/BFS
- 最小生成树
- 最短路径
- 拓扑排序
- 关键路径

---

## 第7章 查找

| 文件名 | 内容 | 核心考点 | 平均查找长度 | 王道页码 |
|--------|------|----------|-------------|----------|
| seqsearch.c | 顺序查找 | 哨兵优化 | (n+1)/2 | Pxx |
| binsearch.c | 折半查找 | 判定树 | log₂(n+1)-1 | Pxx |
| bst.c | BST | 查找效率 | O(logn)~O(n) | Pxx |
| avltree.c | AVL | 平衡优化 | O(logn) | Pxx |
| hashtable.c | 哈希表 | 冲突处理 | - | Pxx |

### 高频内容

- 折半判定树
- AVL效率分析
- 哈希冲突处理
- ASL计算

---

## 第8章 排序

| 文件名 | 内容 | 时间复杂度 | 空间复杂度 | 稳定性 | 王道页码 |
|--------|------|------------|------------|--------|----------|
| insert_sort.c | 插入排序 | O(n²) | O(1) | ✓ | Pxx |
| shell_sort.c | 希尔排序 | O(n^1.3)~O(n²) | O(1) | ✗ | Pxx |
| bubble_sort.c | 冒泡排序 | O(n²) | O(1) | ✓ | Pxx |
| quick_sort.c | 快速排序 | O(nlogn)~O(n²) | O(logn) | ✗ | Pxx |
| select_sort.c | 选择排序 | O(n²) | O(1) | ✗ | Pxx |
| heap_sort.c | 堆排序 | O(nlogn) | O(1) | ✗ | Pxx |
| merge_sort.c | 归并排序 | O(nlogn) | O(n) | ✓ | Pxx |
| radix_sort.c | 基数排序 | O(d(n+r)) | O(r) | ✓ | Pxx |

### 高频考点

- 快排划分
- 建堆过程
- 堆调整
- 归并过程
- 稳定排序判断
- 时间复杂度比较

---

## 排序算法速记

| 算法 | 最好 | 平均 | 最坏 | 稳定 |
|------|------|------|------|------|
| 插入排序 | O(n) | O(n²) | O(n²) | ✓ |
| 冒泡排序 | O(n) | O(n²) | O(n²) | ✓ |
| 快速排序 | O(nlogn) | O(nlogn) | O(n²) | ✗ |
| 堆排序 | O(nlogn) | O(nlogn) | O(nlogn) | ✗ |
| 归并排序 | O(nlogn) | O(nlogn) | O(nlogn) | ✓ |

---

## 代码规范

统一规范：

- 使用 `Status` 返回状态

```c
typedef enum
{
    OK,
    ERROR,
    OVERFLOW
} Status;
```

基础类型：

```c
typedef int ElemType;
```

要求：

- 每个 `.c` 文件独立可编译
- 每个模块包含简单测试 `main()`
- 函数注释统一格式
- 核心算法补充复杂度分析

---

## 参考

- 《数据结构（C语言版）》严蔚敏
- 《王道408数据结构考研复习指导》
- 408统考考试大纲
- 历年408真题

---

## TODO

### Chapter 2

- [ ] 顺序表
- [ ] 单链表
- [ ] 双链表
- [ ] 循环链表

### Chapter 3

- [ ] 顺序栈
- [ ] 链栈
- [ ] 循环队列
- [ ] 表达式求值

### Chapter 4

- [ ] BF算法
- [ ] KMP
- [ ] next优化

### Chapter 5

- [ ] 二叉树
- [ ] BST
- [ ] AVL
- [ ] 哈夫曼树

### Chapter 6

- [ ] DFS/BFS
- [ ] Prim
- [ ] Kruskal
- [ ] Dijkstra
- [ ] Floyd

### Chapter 7

- [ ] 查找
- [ ] 哈希表

### Chapter 8

- [ ] 八大排序算法
- [ ] 排序复杂度分析
- [ ] 稳定性总结

---

## License

MIT License

---

⭐ 如果这个项目帮助到了你，欢迎 Star。