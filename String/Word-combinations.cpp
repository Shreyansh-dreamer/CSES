#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

struct trieNode {
    trieNode *children[26];
    bool isEndOfWord;
    int size;
};

trieNode* getNode() {
    trieNode* newNode=new trieNode();
    newNode->isEndOfWord=false;
    newNode->size=0;

    for(int i=0;i<26;i++)
        newNode->children[i]=NULL;

    return newNode;
}

trieNode* root=getNode();

void insert(string word) {
    trieNode *crawler=root;

    for(int i=0;i<word.length();i++) {
        int index=word[i]-'a';

        if(!crawler->children[index])
            crawler->children[index]=getNode();

        crawler=crawler->children[index];
    }

    crawler->isEndOfWord=true;
    crawler->size=word.length();
}

string s;
vector<int> memo;

int dp(int i) {
    if(i==s.size())
        return 1;

    if(memo[i]!=-1)
        return memo[i];

    long long ans=0;
    trieNode *crawler=root;

    for(int j=i;j<s.size();j++) {
        int index=s[j]-'a';

        if(!crawler->children[index])
            break;

        crawler=crawler->children[index];

        if(crawler->isEndOfWord) {
            int len=crawler->size;
            ans=(ans+dp(i+len))%MOD;
        }
    }

    return memo[i]=ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>s;

    int k;
    cin>>k;

    for(int i=0;i<k;i++) {
        string word;
        cin>>word;
        insert(word);
    }

    memo.assign(s.size(),-1);

    cout<<dp(0)<<'\n';

    return 0;
}