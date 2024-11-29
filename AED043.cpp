#include <iostream>
#include <map>

using namespace std;

int main(){

    map<string, pair<int, int>> m;

    int N;
    cin >> N;

    //criar map com nome_filme e par(positivas,negativas)
    for(int i = 0; i < N; i++){
        string name;
        int a;
        cin >> name >> a;

        if(m.find(name) == m.end()){
            m[name] = make_pair(0, 0); //par(positivas,negativas) -> total = positivas + negativas
        }

        if(a >= 5){
            m[name].first++;
        } else {
            m[name].second++;
        }
    }

    //imprimir numero de entradas diferentes
    cout << m.size() << endl;

    //numero maximo de reviews totais e quntos filmes tiveram esse numero
    int max = 0;
    int count = 0;
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second.first + it->second.second > max){
            max = it->second.first + it->second.second;
            count = 1;
        } else if(it->second.first + it->second.second == max){
            count++;
        }
    }
    cout << max << " " << count << endl;

    //numero de filmes com mais positivas que negativas
    int pos = 0;
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second.first > it->second.second){
            pos++;
        }
    }
    cout << pos << endl;
    


    return 0;
}