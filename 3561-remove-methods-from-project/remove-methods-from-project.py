from collections import defaultdict


class Solution:

    def dfs(self, g, vis, source):

        vis[source] = True

        for neighbour in g[source]:

            if not vis[neighbour]:
                self.dfs(g, vis, neighbour)

    def remainingMethods(self, n, k, invocations):

        g = defaultdict(list)
        p = defaultdict(list)

        for a in invocations:

            s = a[0]
            d = a[1]

            g[s].append(d)
            p[d].append(s)

        vis = [False] * n
        ans = []

        self.dfs(g, vis, k)

        flag = False

        for i in range(n):

            if vis[i]:

                parents = p[i]

                for par in parents:

                    if not vis[par]:
                        flag = True
                        break

                if flag:
                    break

        if flag:

            for i in range(n):
                ans.append(i)

        else:

            for i in range(n):

                if not vis[i]:
                    ans.append(i)

        return ans