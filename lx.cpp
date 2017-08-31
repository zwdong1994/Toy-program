
#include <iostream>
#include <set>
#define N 1000000
int h[N];
struct hillCouple
{
    int x;
    int y;
};

using namespace std;

int main()
{
    int n;
    set<struct hillCouple> st;
    while(cin>>n)
    {
        st.clear();
        for(int i=0;i<n;i++)
            cin>>h[i];
        for(int i=0;i<n;i++)
        {
            for(int j=(i+1)%n;j!=i;j=(j+1)%n)
            {
                struct hillCouple temp;
                if(j==(i+1)%n)
                {
                    temp.x=(i<j)?i:j;
                    temp.y=(i<j)?j:i;
                    st.insert(temp);
                    if(h[j]>h[i])
                        break;
                }
                else
                {
                    if(h[j]<h[(j-1)%n])
                        break;
                    temp.x=(i<j)?i:j;
                    temp.y=(i<j)?j:i;
                    st.insert(temp);
                }
            }
        }
        cout<<st.size()<<endl;
    }
    return 0;
}
