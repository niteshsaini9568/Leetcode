class Solution {
public:
    void DFS(
        int u,
        const vector<int>& present,
        const vector<int>& future,
        const vector<vector<int>>& adj,
        vector<vector<vector<int>>>& dp,
        int budget
    ) {
        // dp[u][0] -> parent NOT bought
        // dp[u][1] -> parent IS bought

        vector<pair<vector<int>, vector<int>>> childrenDP;

        for (int v : adj[u]) {
            DFS(v, present, future, adj, dp, budget);
            childrenDP.push_back({dp[v][0], dp[v][1]});
        }

        for (int parentBought = 0; parentBought <= 1; parentBought++) {

            int price  = parentBought ? present[u] / 2 : present[u];
            int profit = future[u] - price;

            vector<int> best(budget + 1, 0);

            // -------- Case 1: Do NOT buy u --------
            vector<int> noBuy(budget + 1, 0);

            for (auto& child : childrenDP) {
                vector<int> temp(budget + 1, 0);
                for (int used = 0; used <= budget; used++) {
                    for (int take = 0; used + take <= budget; take++) {
                        temp[used + take] =
                            max(temp[used + take], noBuy[used] + child.first[take]);
                    }
                }
                noBuy.swap(temp);
            }

            best = noBuy;

            // -------- Case 2: Buy u --------
            if (price <= budget) {
                vector<int> buy(budget + 1, 0);

                for (auto& child : childrenDP) {
                    vector<int> temp(budget + 1, 0);
                    for (int used = 0; used <= budget; used++) {
                        for (int take = 0; used + take <= budget; take++) {
                            temp[used + take] =
                                max(temp[used + take], buy[used] + child.second[take]);
                        }
                    }
                    buy.swap(temp);
                }

                for (int b = price; b <= budget; b++) {
                    best[b] = max(best[b], buy[b - price] + profit);
                }
            }

            dp[u][parentBought] = move(best);
        }
    }

    int maxProfit(
        int n,
        vector<int>& present,
        vector<int>& future,
        vector<vector<int>>& hierarchy,
        int budget
    ) {
        vector<vector<int>> adj(n);
        for (auto& h : hierarchy) {
            int u = h[0] - 1;
            int v = h[1] - 1;
            adj[u].push_back(v);
        }

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(budget + 1, 0))
        );

        DFS(0, present, future, adj, dp, budget);

        int ans = 0;
        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[0][0][b]);
        }
        return ans;
    }
};
