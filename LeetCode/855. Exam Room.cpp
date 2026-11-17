// 自己一开始用vector<bool>记录，没注意数据大小爆了,其实只需要记录座位下标

class ExamRoom {
private:
    int n;
    set<int> seated;

public:
    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        // 还没人坐，坐 0
        if (seated.empty()) {
            seated.insert(0);
            return 0;
        }

        int bestPos = -1;
        int bestDist = -1;

        // 1. 左边界：考虑坐 0
        int first = *seated.begin();
        if (first > bestDist) {
            bestDist = first;
            bestPos = 0;
        }

        // 2. 中间区间
        int prev = first;
        for (auto it = next(seated.begin()); it != seated.end(); ++it) {
            int cur = *it;
            int dist = (cur - prev) / 2;
            int pos = prev + dist;

            if (dist > bestDist) {
                bestDist = dist;
                bestPos = pos;
            }
            prev = cur;
        }

        // 3. 右边界：考虑坐 n - 1
        int last = *seated.rbegin();
        int dist = (n - 1) - last;
        int pos = n - 1;

        if (dist > bestDist) {
            bestDist = dist;
            bestPos = pos;
        }

        seated.insert(bestPos);
        return bestPos;
    }
    
    void leave(int p) {
        seated.erase(p);
    }
};

// 最佳答案，维护间隙而不是下标

// 表示"一个空隙"（一段连续的空位）
// 用 1-indexed 坐标，座位 1..n，另加两个哨兵：0 = 左墙，n+1 = 右墙
struct Gap {
    int dist;         // 如果坐进这个空隙，离最近的人的距离（越大越优先）
    int seat;         // 这个空隙里应该坐的座位号
    int lhsBarrier;   // 左边界：左边最近的那个"已坐的人"或左墙 0
    int rhsBarrier;   // 右边界：右边最近的那个"已坐的人"或右墙 n+1

    // 关键：把"优先级"编码进比较运算符
    // set 默认按 operator< 升序排，begin() 是"最小"元素
    // 这里定义：dist 大的算"更小"（排前面）
    //          dist 相同时，lhsBarrier 小的算"更小"（更靠左的排前面）
    // 效果：*gaps.begin() 直接就是"最优的那个空隙"
    bool operator<(const Gap& other) const {
        return (this->dist > other.dist)
            || ((this->dist == other.dist) && this->lhsBarrier < other.lhsBarrier);
    }
};

class ExamRoom {
public:
    // 初始化：
    //   occupied 一开始放两个哨兵 {0, n+1}，代表左右两堵墙
    //   整个教室就是一个大空隙 [0, n+1]，插入 gaps
    ExamRoom(int n) : n(n), occupied{ 0, n+1 } {
        gaps.insert({
            n,          // dist：一个人都没有，坐 1 号离右墙 n+1 距离是 n（坐 1 号，最近的是 n+1，距离 n）
            1,          // seat：第一个坐 1 号（对应原始 0-indexed 的 0 号）
            0,          // lhsBarrier：左墙
            n + 1       // rhsBarrier：右墙
        });
    };

    int seat() {
        // 1. 从 set 里直接取出"最优空隙"（dist 最大，dist 相同取最靠左）
        Gap bestGap = *gaps.begin();
        gaps.erase(gaps.begin());   // 这个空隙马上要被坐掉，先删掉
        int seat = bestGap.seat;    // 新来的人坐这里

        // 2. 原来的大空隙 [lhsBarrier, rhsBarrier] 被 seat 劈成两半：
        //    左半 [lhsBarrier, seat]，右半 [seat, rhsBarrier]
        Gap lGap = getGap(bestGap.lhsBarrier, seat);
        Gap rGap = getGap(seat, bestGap.rhsBarrier);

        // 3. 只有"中间真的还有空位"才把新空隙插回 set
        //    lhsBarrier + 1 < rhsBarrier 意思是两个边界之间至少隔了一个座位
        //    （如果 lhsBarrier+1 == rhsBarrier，说明中间没空位了，不用插）
        if (lGap.lhsBarrier + 1 < lGap.rhsBarrier) {
            gaps.insert(lGap);
        }
        if (rGap.lhsBarrier + 1 < rGap.rhsBarrier) {
            gaps.insert(rGap);
        }

        // 4. 把这个座位标记为"已坐"
        occupied.insert(seat);

        // 5. 内部是 1-indexed，转回题目要求的 0-indexed
        return seat - 1;
    }

    void leave(int p) {
        // 题目传入 0-indexed，转成内部的 1-indexed
        p += 1;

        // 找到 p 在已坐集合里的位置，拿到左右邻居
        auto it = occupied.find(p);
        int newLhs = *prev(it);   // 左边最近的已坐人（或左墙 0）
        int newRhs = *next(it);   // 右边最近的已坐人（或右墙 n+1）

        // 把 p 从已坐集合删掉
        occupied.erase(it);

        // p 走了，原来的两个小空隙 [newLhs, p] 和 [p, newRhs] 消失
        // 合并成一个大空隙 [newLhs, newRhs]
        // 注意：getGap 是纯函数，同样的 (l, r) 参数算出的 Gap 完全一样，
        //      所以这里 erase 能精确匹配 set 里存的那个对象
        gaps.erase(getGap(newLhs, p));
        gaps.erase(getGap(p, newRhs));
        Gap nGap = getGap(newLhs, newRhs);
        gaps.insert(nGap);
    }

private:
    set<Gap> gaps;        // 所有当前"空隙"，按 operator< 排好序，begin() 即最优
    int n;                // 座位总数（原始题目规模）
    set<int> occupied;    // 已坐的人的座位号（1-indexed，含哨兵 0 和 n+1）

    // 根据左右边界 (l, r) 算出这段空隙"应该坐哪、离最近的人多远"
    // l、r 是已坐的人（或墙），中间全是空位
    Gap getGap(int l, int r) {
        Gap gap;
        int dist, seat;

        if (l == 0) {
            // 左边界是墙 → 只能贴着左墙坐 1 号
            seat = 1;
            dist = r - seat;               // 最近的人是 r，距离 r - 1
        }
        else if (r == n + 1) {
            // 右边界是墙 → 只能贴着右墙坐 n 号
            seat = n;
            dist = seat - l;               // 最近的人是 l，距离 n - l
        }
        else {
            // 两边都是人 → 坐中点
            seat = (l + r) / 2;            // 整除，天然靠左，符合"距离相同选小座位"
            dist = min(seat - l, r - seat);// 到左右两边最近的人的距离取小的
        }

        gap.dist = dist;
        gap.seat = seat;
        gap.lhsBarrier = l;
        gap.rhsBarrier = r;

        // ⚠️ 这行是调试残留，正常不该走到 seat == -1，
        //    建议删掉，不然会污染输出 / 拖慢速度
        if (gap.seat == -1) {
            cout << l << " " << r << "\n";
        }
        return gap;
    }
};