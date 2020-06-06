//// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3344/
//
//#include <vector>
//
//class Solution {
//
//	enum class GRAPH_PROCESSING_STATUS {
//		NODE_NOT_YET_PROCESSED,
//		NODE_IN_TRANSIT_PROCESS,
//		NODE_FULLY_PROCESSED
//	};
//
//	bool IsCyclePresent(int node_id) {
//		// Mark the graph_node as node in transit of processing
//		graph_node_processing_status[node_id] = GRAPH_PROCESSING_STATUS::NODE_IN_TRANSIT_PROCESS;
//
//		bool cycle_status = false;
//
//		for (auto& neighbour : adjacency_list[node_id]) {
//			if (GRAPH_PROCESSING_STATUS::NODE_IN_TRANSIT_PROCESS == graph_node_processing_status[neighbour]) {
//				// We reach the back node
//				cycle_status =  true;
//				break;
//			}
//
//			if (GRAPH_PROCESSING_STATUS::NODE_NOT_YET_PROCESSED == graph_node_processing_status[neighbour] && IsCyclePresent(neighbour)) {
//				cycle_status =  true;
//				break;
//			}
//		}
//
//		// Mark the current node id as processed fully
//		graph_node_processing_status[node_id] = GRAPH_PROCESSING_STATUS::NODE_FULLY_PROCESSED;
//
//		return cycle_status;
//	}
//
//
//	std::vector<std::vector<int>> adjacency_list;
//	std::vector<GRAPH_PROCESSING_STATUS> graph_node_processing_status;
//
//public:
//	bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
//
//		adjacency_list.resize(numCourses, std::vector<int>());
//
//		for (auto& edge : prerequisites) {
//			adjacency_list[edge[0]].push_back(edge[1]);
//		}
//
//		graph_node_processing_status.resize(numCourses, GRAPH_PROCESSING_STATUS::NODE_NOT_YET_PROCESSED);
//
//		bool can_finish = true;
//
//		for (int current_course = 0; current_course < numCourses; ++current_course) {
//			if ((GRAPH_PROCESSING_STATUS::NODE_NOT_YET_PROCESSED == graph_node_processing_status[current_course])
//				&& (IsCyclePresent(current_course))) {
//				can_finish = false;
//				break;
//			}
//		}
//		return can_finish;
//	}
//};
//
//int main() {
//	Solution s;
//	s.canFinish(2, { {0,1} });
//}