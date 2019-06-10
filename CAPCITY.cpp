#include<bits/stdc++.h>
using namespace std;

void dfs1(int s,vector<int>*graph,bool *visited,stack<int>&v)
{
    visited[s]=true;
    for(auto i:graph[s])
    {
        if(!visited[i])
        {
            dfs1(i,graph,visited,v);
        }
    }
    v.push(s);
}

void dfs2(vector<int>*graph, int start, unordered_set<int>*component, bool *visited)
{
    visited[start]=true;
    component->insert(start);
    for(int i=0;i<graph[start].size();i++)
    {
        int next=graph[start][i];
        if(!visited[next])
        {
            dfs2(graph,next,component,visited);
        }
    }
}

unordered_set<unordered_set<int>*>* getSCC(vector<int>*graph,vector<int>*graphT,int n)
{
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    stack<int>v;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs1(i,graph,visited,v);
        }
    }
    memset(visited,false,sizeof(visited));
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    while(!v.empty())
    {
        if(!visited[v.top()])
        {
            unordered_set<int>*component = new unordered_set<int>();
            dfs2(graphT,v.top(),component,visited);
            output->insert(component);
        }
        else
        {
            v.pop();
        }
    }
    return output;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
int c=1;
    while(c--)
    {
        int v,e;
        cin>>v;
        cin>>e;
        vector<int>graph[v+1];
        vector<int>graphT[v+1];
        for(int i=0;i<e;i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graphT[b].push_back(a);
        }
        unordered_set<unordered_set<int>*>*components = getSCC(graph,graphT,v);
        unordered_set<unordered_set<int>*>::iterator it=components->begin();
        // bool flag1=true;
        vector<int>vec;
        while (it != components->end()) {
            // bool flag=true;
            unordered_set<int>* component = *it;
            unordered_set<int>::iterator it2 = component->begin();
            int count=0;
            while (it2 != component->end()) {
                // int check=*it2;
                // cout<<*it2<<" ";
                count++;
                it2++;
            }
            if(count>1)
            {
                unordered_set<int>::iterator it3 = component->begin();
                while (it3 != component->end()) {
                    // cout<<*it3<<" ";
                    vec.push_back(*it3);
                    it3++;
                }
            }
            delete component;
            it++;
        }
        sort(vec.begin(),vec.end());
        cout<<vec.size()<<endl;
        for(auto j:vec)
            cout<<j<<" ";
        delete components;
    }
    return 0;
}

