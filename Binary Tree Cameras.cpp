class Solution {
    
    enum State {
        MONITORED,
        NOT_MONITORED,
        CAMERA_PLACED
    };
    
    /*
        1. (NOT_MONITORED, NOT_MONITORED) --> CAMERA_PLACED 
        2. (NOT_MONITORED, *)  --> CAMERA PLACED
        3. (*, NOT_MONITORED)  --> CAMERA PLACED
        4. (CAMERA_PLACED, (MONITORED/CAMERA_PLACED))  ---> MONITORED
        
    
    */
    
    std::pair<State,int> cameraCover(TreeNode* root) {
        
        if(root == nullptr) {
            return {MONITORED, 0};
        }
        
        if(root->left == nullptr && root->right == nullptr) {
            return {NOT_MONITORED,0};
        }
        
        auto [left_state, cameras_in_left] = cameraCover(root->left);
        auto [right_state, cameras_in_right] = cameraCover(root->right);
        
        int cameras = 0;
        State current_state = MONITORED;
        
        if(left_state == NOT_MONITORED || right_state == NOT_MONITORED) {
            cameras++;
            current_state = CAMERA_PLACED;
        } else if(left_state == MONITORED && right_state == MONITORED) {           
            current_state = NOT_MONITORED;            
        } else {
            current_state = MONITORED;
        }
        
        return {current_state, cameras + cameras_in_left + cameras_in_right};
    }
public:
    int minCameraCover(TreeNode* root) {
        if (root == nullptr)
            return 0;

        auto [state, cameras] = cameraCover(root);
        
        return state == NOT_MONITORED ? cameras + 1 : cameras;
    }
};
