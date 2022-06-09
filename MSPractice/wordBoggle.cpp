
// WORD BOGGLE 2 
// VERY NICE QUESTION
// IMPLEMENTATION WITH TRIE
class Solution {
public:
    class Node{
        public:
            Node * child[26];
            bool isLeaf;
            Node() {
                for(int i=0;i<26;i++) {
                    child[i]=NULL;
                }
                isLeaf = false;
            }
    };
    int dx[8] = {-1, -1, -1, 0, +1, +1, +1, 0};
    int dy[8] = {-1, 0, +1, +1, +1, 0, -1, -1};
    set<string> ans;
    void insert(Node * root, string key) {
        for(auto x: key) {
            if(!root->child[x-'A'])
                root->child[x-'A'] = new Node();
            root = root->child[x-'A'];
        }
        root->isLeaf = true;
    }
    bool isSafe(int i, int j, vector<vector<char> >& board, vector<vector<int>> &vis) {
        return (i>=0 && i<board.size() && j>=0 && j<board[0].size() && !vis[i][j]);
    }
    
    void SearchWord(Node * root, vector<vector<char> >& board, int i, int j, vector<vector<int>> &vis, string str) {
        if(root->isLeaf){
            //cout<<"SW "<<i<<" "<<j<<"--->"<<str<<endl;
            ans.insert(str);
        }
        if(isSafe(i,j,board,vis)) {
            vis[i][j]=1;
            for(int k=0;k<26;k++) {
                if(root->child[k]) {
                    char next_ch = char(k) + 'A';
                    for(int pos=0;pos<8;pos++) {
                        int new_x = i + dx[pos];
                        int new_y = j + dy[pos];
                        if(isSafe(new_x, new_y, board, vis) && board[new_x][new_y]==next_ch) {
                            SearchWord(root->child[k], board, new_x, new_y, vis, str+next_ch);
                        }
                    }
                }
            }
            vis[i][j]=0;
        }
        
    }
    
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    Node * root = new Node();
	    for(auto x:dictionary) {
	        insert(root, x);
	    }
	    vector<vector<int>> vis(board.size(),(vector<int>(board[0].size(),false)));
	    string str = "";
	    for(int i=0;i<board.size();i++) {
	        for(int j=0;j<=board[0].size();j++) {
    	            char curr_ch = board[i][j];
                    if(root->child[curr_ch-'A']!=NULL) {
                        str += curr_ch;
                        SearchWord(root->child[curr_ch-'A'], board, i, j,vis, str);
                        str ="";
                        vis.resize(board.size(),(vector<int>(board[0].size(),false)));
                    }
	            }
        }
        vector<string> res;
        for(auto x:ans)
            res.push_back(x);
        return res;
	    
	}
};