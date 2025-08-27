class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0

        n, m = len(grid), len(grid[0])
        dirs = [(1, 1), (1, -1), (-1, -1), (-1, 1)]

        def inb(x, y):
            return 0 <= x < n and 0 <= y < m

        total_states = n * m * 4 * 2 * 2  # 16 * n * m
        memo = [-1] * total_states

        def state_index(i: int, j: int, d: int, turn: int, next_is_two: int) -> int:
            base = i * m + j
            return (((base << 2) + d) << 2) + (turn << 1) + next_is_two

        dirs_local = dirs
        grid_local = grid
        n_local, m_local = n, m

        def dfs(i: int, j: int, d: int, turn_used: int, next_is_two: int) -> int:
            idx = state_index(i, j, d, turn_used, next_is_two)
            v = memo[idx]
            if v != -1:
                return v

            best = 1
            expected = 2 if next_is_two else 0

            dx, dy = dirs_local[d]
            ni, nj = i + dx, j + dy
            if 0 <= ni < n_local and 0 <= nj < m_local and grid_local[ni][nj] == expected:
                cand = 1 + dfs(ni, nj, d, turn_used, 1 - next_is_two)
                if cand > best:
                    best = cand

            if turn_used == 0:
                nd = (d + 1) & 3
                tx, ty = i + dirs_local[nd][0], j + dirs_local[nd][1]
                if 0 <= tx < n_local and 0 <= ty < m_local and grid_local[tx][ty] == expected:
                    cand = 1 + dfs(tx, ty, nd, 1, 1 - next_is_two)
                    if cand > best:
                        best = cand

            memo[idx] = best
            return best

        ans = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] != 1:
                    continue
                for d in range(4):
                    dx, dy = dirs[d]
                    ni, nj = i + dx, j + dy
                    if not (0 <= ni < n and 0 <= nj < m and grid[ni][nj] == 2):
                        if ans < 1:
                            ans = 1
                        continue
                    val = dfs(i, j, d, 0, 1)
                    if val > ans:
                        ans = val

        return ans
