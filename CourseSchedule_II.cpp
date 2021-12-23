class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> & prerequisites) {
        std::vector<std::unordered_set<int>> dependentOn(numCourses);
        std::vector<std::unordered_set<int>> dependenciesOf(numCourses);
        for (auto prerequisite : prerequisites) {
            dependentOn[prerequisite[0]].insert(prerequisite[1]);
            dependenciesOf[prerequisite[1]].insert(prerequisite[0]);
        }

        std::vector<std::pair<int, int>> degreeCount;
        for (int i = 0; i < dependentOn.size(); ++i) {
            degreeCount.push_back({ i, dependentOn[i].size() });
        }

        std::sort(degreeCount.begin(), degreeCount.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second;
            });

        std::vector<int> result;
        bool solution_exists = true;

        std::queue<int> node_to_process_order;
        for (int i = 0; i < degreeCount.size(); ++i) {
            if (degreeCount[i].second == 0)
                node_to_process_order.push(degreeCount[i].first);
            else
                break;
        }

        while (!node_to_process_order.empty()) {
            int currentCourseNumber = node_to_process_order.front();
            node_to_process_order.pop();
            if (dependentOn[currentCourseNumber].size() == 0) {
                // course which has no dependency
                result.push_back(currentCourseNumber);
                // remove this course's all dependency from dependenciesOf
                for (auto courseDependentOnThisCourse : dependenciesOf[currentCourseNumber]) {
                    dependentOn[courseDependentOnThisCourse].erase(currentCourseNumber);
                    if (dependentOn[courseDependentOnThisCourse].size() == 0) {
                        node_to_process_order.push(courseDependentOnThisCourse);
                    }
                }
            }
        }        

        return result.size() == numCourses ? result : std::vector<int>();
    }
};
