#### [LCP 07. 传递信息](https://leetcode-cn.com/problems/chuan-di-xin-xi/)

> - BFS
> - 执行用时：9 ms, 在所有 Java 提交中击败了15.22%的用户

```java
class Solution {
    public int numWays(int n, int[][] relation, int k) {
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for(int[] r : relation){
            Set<Integer> set = map.getOrDefault(r[0], new HashSet<>());
            set.add(r[1]);
            map.put(r[0], set);
        }
        Deque<Integer> queue = new ArrayDeque<>();
        queue.offer(0);
        while(!queue.isEmpty() && k-- > 0){
            int size = queue.size();
            for(int i = 0; i < size; i++){
                int num = queue.poll();
                Set<Integer> set = map.get(num);
                if(set == null){
                    continue;
                }
                for(Integer nextNum : set){
                    queue.offer(nextNum);
                }
            }
        }
        int ans = 0;
        while(!queue.isEmpty()){
            if(queue.poll() == n - 1){
                ans++;
            }
        }
        return ans;
    }
}
```

> - DFS
> - 执行用时：2 ms, 在所有 Java 提交中击败了42.69%的用户

```java
class Solution {
    private Map<Integer, Set<Integer>> map;
    private int n, k;
    private int ans = 0;
    public int numWays(int n, int[][] relation, int k) {
        map = new HashMap<>();
        for(int[] r : relation){
            Set<Integer> set = map.getOrDefault(r[0], new HashSet<>());
            set.add(r[1]);
            map.put(r[0], set);
        }
        this.n = n;
        this.k = k;
        dfs(0, 0);
        return ans;
    }
    private void dfs(int num, int step){
        if(step == k){
            if(num == n - 1){
                ans++;
            }
            return;
        }
        Set<Integer> set = map.get(num);
        if(set == null){
            return;
        }
        for(Integer nextNum : set){
            dfs(nextNum, step + 1);
        }
    }
}
```

> - DP
> - 执行用时：0 ms, 在所有 Java 提交中击败了100.00%的用户

```Jjava
class Solution {
    public int numWays(int n, int[][] relation, int k) {
        int[][] dp = new int[k + 1][n];
        dp[0][0] = 1;
        for(int i = 1; i <= k; i++){
            for(int[] r : relation){
                int num = r[0];
                int nextNum = r[1];
                dp[i][nextNum] += dp[i - 1][num];
            }
        }
        return dp[k][n - 1];
    }
}
```

