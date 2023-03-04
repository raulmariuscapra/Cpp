#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class vectorul
{
public:
    int n;
    std::vector<int> v;
    void initializare()
    {
        std::ifstream ifs;
        ifs.open("sortarebubblesortobiecte.in");
        ifs>>n;
        v.resize(n,0);
        for(int i=0;i<n;++i)
        {
            ifs>>v[i];
        }
        ifs.close();
    }
    std::vector<int> sortare()
    {
        int r;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n-i-1;++j)
            {
                if(v[j]>v[j+1])
                {
                    r=v[j];
                    v[j]=v[j+1];
                    v[j+1]=r;
                }
            }
        }
        return v;
    }
    void afisare()
    {
        for(int i=0;i<n;++i)
        {
            std::cout<<v[i]<<" ";
        }
        std::cout<<std::endl;
    }
};

int main()
{

    vectorul v1;
    v1.initializare();
    v1.afisare();
    v1.v=v1.sortare();
    v1.afisare();
    return 0;
}
