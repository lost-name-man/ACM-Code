#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>

// It's common in competitive programming, but 'using namespace std;' is often discouraged in larger projects.
// Consider std:: prefix or using specific names like std::cout, std::vector, etc.
using namespace std;

// Using long long for int by default can sometimes be slower if not needed.
// Here, state values and counts fit in int. Max state is 2^20.
// #define int long long // Reconsider if this is strictly necessary for this problem.
// For competitive programming, it's a common safety net.

#define INF 1e18 // Not used
#define endl '\n'
#define MOD (int)(1000000007) // Not used

int n_grid, m_grid, k_fish; // Renamed to avoid conflict with std::n, std::m if they exist
long long target_state = 0; // Use long long for states if k is large, though int is fine for k=10 (2^20)

vector<pair<int, int>> bomb_candidate_locs;
pair<int, int> steps[5] = { {0,0}, {1,0},{0,1},{-1,0},{0,-1} }; // Added {0,0} for bomb center
int fish_loc_to_id[1003][1003] = { 0 }; // Stores (fish_idx + 1) for fish at (row, col)
long long initial_fish_counts[11]; // Stores initial a_i for fish_idx

// Stores coordinates of each fish type
// Useful if you need to iterate fish types directly, though not strictly used in this BFS structure's next_state calc
// pair<int, int> fish_actual_coords[11];


// Function to add potential bomb locations.
// A bomb is useful if it hits a fish. If a bomb at (br, bc) hits fish at (fr, fc),
// then |fr-br| + |fc-bc| <= 1.
// This means (br, bc) must be (fr, fc) or one of its 4 Manhattan neighbors.
void add_potential_bomb_sites_for_fish(int r, int c) {
    for(int i = 0; i < 5; ++i) { // Iterate through the fish cell itself and its 4 neighbors
        int nr = r + steps[i].first;
        int nc = c + steps[i].second;
        if (nr >= 1 && nr <= n_grid && nc >= 1 && nc <= m_grid) {
            bomb_candidate_locs.push_back({nr, nc});
        }
    }
}

void solve() {
    cin >> n_grid >> m_grid >> k_fish;

    target_state = 0;
    bomb_candidate_locs.clear(); // Clear for multiple test cases if any (not in this problem)
    memset(fish_loc_to_id, 0, sizeof(fish_loc_to_id));
    // memset(fish_actual_coords, 0, sizeof(fish_actual_coords)); // If used
    memset(initial_fish_counts, 0, sizeof(initial_fish_counts));


    for (int i = 0; i < k_fish; i++) {
        int r, c, num_fish;
        cin >> r >> c >> num_fish;
        // fish_actual_coords[i] = {r, c}; // If needed
        initial_fish_counts[i] = num_fish;
        // Each fish type `i` (0 to k_fish-1) needs `num_fish` items.
        // We use 2 bits for each fish type. Max num_fish is 3 (binary 11).
        // State: ... [fish_k-1 count] [fish_k-2 count] ... [fish_1 count] [fish_0 count]
        target_state |= ( (long long)num_fish << (i * 2) );
        add_potential_bomb_sites_for_fish(r, c);
        fish_loc_to_id[r][c] = i + 1; // Store 1-based fish index
    }

    // Critical fix: Sort and then unique to remove ALL duplicates
    sort(bomb_candidate_locs.begin(), bomb_candidate_locs.end());
    bomb_candidate_locs.erase(unique(bomb_candidate_locs.begin(), bomb_candidate_locs.end()), bomb_candidate_locs.end());

    queue<pair<long long, int>> q; // {current_state, num_bombs}
    // Using unordered_map for visited states can be faster than a large array if states are sparse,
    // but for up to 2^20 states, a vector/array is often better if memory allows.
    // Max state value is (1 << (2*k_fish)) - 1. For k_fish=10, this is 2^20 - 1.
    vector<int> min_bombs_to_reach_state(1 << (2 * k_fish), -1);


    q.push({0, 0}); // Initial state: 0 fish caught, 0 bombs used
    min_bombs_to_reach_state[0] = 0;

    long long final_ans = -1; // Should be int

    while (!q.empty()) {
        long long current_state = q.front().first;
        int num_bombs_used = q.front().second;
        q.pop();

        if (current_state == target_state) {
            final_ans = num_bombs_used;
            break;
        }

        // Try dropping a bomb at each candidate location
        for (const auto& bomb_loc : bomb_candidate_locs) {
            int bomb_r = bomb_loc.first;
            int bomb_c = bomb_loc.second;
            long long next_state = current_state;

            // Check 5 cells affected by the bomb: bomb_loc itself and its 4 neighbors
            for (int i = 0; i < 5; ++i) {
                int affected_r = bomb_r + steps[i].first;
                int affected_c = bomb_c + steps[i].second;

                if (affected_r >= 1 && affected_r <= n_grid &&
                    affected_c >= 1 && affected_c <= m_grid &&
                    fish_loc_to_id[affected_r][affected_c] != 0) {
                    
                    int fish_idx = fish_loc_to_id[affected_r][affected_c] - 1; // 0-based fish index

                    long long current_caught_for_this_fish = (current_state >> (fish_idx * 2)) & 3; // Get 2 bits for this fish
                    long long target_for_this_fish = (target_state >> (fish_idx * 2)) & 3; // initial_fish_counts[fish_idx]

                    if (current_caught_for_this_fish < target_for_this_fish) {
                        // Increment count for this fish in next_state
                        // This works because (state | (1 << bit)) increments if bit is 0,
                        // and (state | (2 << bit)) increments if LSB is 1 and MSB is 0.
                        // A simpler way is to clear and set:
                        // next_state &= ~(3LL << (fish_idx * 2)); // Clear the 2 bits
                        // next_state |= ((current_caught_for_this_fish + 1) << (fish_idx * 2)); // Set new count
                        // However, your original logic of `next_state += (1LL << (fish_idx * 2))`
                        // inside the loop effectively does this for one increment,
                        // because the bits for different fish_idx are independent.
                        // Let's stick to a clear update:
                        long long old_field_val = (next_state >> (fish_idx * 2)) & 3;
                        if (old_field_val < target_for_this_fish) { // Check against next_state's current count for this fish
                             next_state = (next_state & ~(3LL << (fish_idx * 2))) | ((old_field_val + 1) << (fish_idx * 2));
                        }
                    }
                }
            }

            if (next_state != current_state) { // If the bomb had an effect
                if (min_bombs_to_reach_state[next_state] == -1) { // If not visited or found a shorter path (not possible in BFS)
                    min_bombs_to_reach_state[next_state] = num_bombs_used + 1;
                    q.push({next_state, num_bombs_used + 1});
                }
            }
        }
    }
    cout << final_ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false); // Use false, not 0
    std::cin.tie(nullptr); // Use nullptr, not 0

    // The problem seems to imply a single test case based on structure.
    // If there were multiple test cases, global variables would need careful resetting.
    int T = 1;
    // cin >> T; // Uncomment if multiple test cases
    while (T--) {
        solve();
    }
    return 0;
}

