#include <iostream>
#include <queue>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<int> nums;
        std::vector<std::vector<int>> in_neighbors(n, std::vector<int>());
        std::queue<int> exiting;
        for (int i = 0; i < n; ++i) {
            int jump; 
            std::cin >> jump;
            nums.push_back(jump);
            int next_position = i + jump;
            if (next_position < 0 || next_position >= n) {
                exiting.push(i);
            } else if (jump != 0) {
                in_neighbors[next_position].push_back(i);
            }
        }

        // Case 1 : 1 ends in finite number of steps
        // Suppose v vertices in such path
        // Count w other vertices that end in finite number of steps
        // Subtract out certain paths that come back to starting path that create cycle
        // Then the answer is v(v-1) / 2 + vw + (n-v)*(2n + 1) + (number of steps that lead out for first v vertices) - some values

        // Case 2:  1 results in a cycle
        // v vertices in this cycle
        // Count w vertices that end in finite number of steps
        // The answer is vw + (number of steps that lead out for first v vertices)

        std::vector<bool> visited(n, false);
        visited[0] = true;
        int starting_path = 0;
        bool game_finishes = false;
        long long num_vertices = 0;
        long long num_steps_that_lead_out_along_path = 0;
        std::vector<int> path;
        std::vector<int> index_in_path(n, 0);
        while (true) {
            int vertex = starting_path;
            path.push_back(vertex);
            index_in_path[vertex] = path.size() - 1;
            ++num_vertices;
            int num_leading_before = n - vertex;
            int num_leading_after = vertex + 1;
            num_steps_that_lead_out_along_path += num_leading_before + num_leading_after;
            int next = nums[vertex] + vertex;
            if (next < 0 || next >= n) {
                game_finishes = true;
                break;
            } else if (visited[next]) {
                break;
            } else {
                visited[next] = true;
                starting_path = next;
            }
        }

        int other_vertices_that_finish = 0;
        long long subtracted_value = 0;
        std::vector<bool> second_visited(n, false);
        std::vector<int> subtracted_value_map(n, -1);
        while (!exiting.empty()) {
            int vertex = exiting.front();
            exiting.pop();
            if (!visited[vertex]) {
                ++other_vertices_that_finish;
                int next = vertex + nums[vertex];
                if (next >= 0 && next < n) {
                    if (visited[next]) {
                        subtracted_value += path.size() - index_in_path[next];
                        subtracted_value_map[vertex] = path.size() - index_in_path[next];
                    } else if (subtracted_value_map[next] != -1) {
                        subtracted_value += subtracted_value_map[next];
                        subtracted_value_map[vertex] = subtracted_value_map[next];
                    }
                }
            }
            second_visited[vertex] = true;
            for (int neighbor : in_neighbors[vertex]) {
                if (!second_visited[neighbor]) {
                    exiting.push(neighbor);
                    second_visited[neighbor] = true;
                }
            }
        }

        long long answer = num_steps_that_lead_out_along_path + num_vertices * other_vertices_that_finish - subtracted_value;

        if (game_finishes) {
            long long along_path = num_vertices * (num_vertices - 1);
            answer += along_path / 2;
            long long outside_path = (n - num_vertices) * (2*n + 1);
            answer += outside_path;
        }

        std::cout << answer << '\n';
    }
}
