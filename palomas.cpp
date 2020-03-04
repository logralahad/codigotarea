#include <iostream>

using namespace std;

int main(){

    int ini, fin, res;
    cin >> ini >> fin;

    if(ini > fin){
        fin += 12;
    }

    res = fin - ini;

    if( res % 4 == 0 || ini == fin){
        cout << "Palomitas grandes";
    }

    else if( res % 2 == 1 ){
        cout << "Nada";
    }
    else{
        cout << "Palomitas medianas";
    }

return 0;
}
