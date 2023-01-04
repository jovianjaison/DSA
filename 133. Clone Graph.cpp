//BFS
//O(mn) Time
//O(m+n) Space
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return node;

        queue<Node*> q;
        unordered_map<Node*,Node*> copies;
        Node* head=new Node(node->val,{});
        copies[node]=head;
        q.push(node);

        while(!q.empty()){
            Node* curr=q.front();q.pop();

            for(Node* neighbor:curr->neighbors){
                if(copies.find(neighbor)==copies.end()){
                    copies[neighbor]= new Node(neighbor->val,{});
                    q.push(neighbor);
                }

                copies[curr]->neighbors.push_back(copies[neighbor]);
            }
        }

        return copies[node];
    }
};