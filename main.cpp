#include <iostream>
//Read Json
#include <fstream>
#include "json.h"

using namespace std;
//출처: https://tmdahr1245.tistory.com/86 [tmdahr1245]
int main() {
  std::cout << "Hello World!\n";

 Json::Value root;
 Json::Reader reader;
/* 
 JSONCPP_STRING doc= "{\"integer_key\" :[1,2,3],\"string_key\" : [\"value1\",\"value2\",\"value3\"]}";
reader.parse(doc,root);//json >> root; 두 구문 모두 json을 파싱하는데 사용할 수 있다.
 */

 ifstream f_json("test.json", ifstream::binary);
 reader.parse(f_json,root);//json >> root; 두 구문 모두 json을 파싱하는데 사용할 수 있다.



//Json::Value 객체는 begin(), end() 둘다 정의되서 범위기반 for문도 사용 가능하다.
    std::cout << "===전체===!\n";
    for(auto& value:root)
        cout<<value<<endl;

    std::cout << "===string_key  문자열===!\n";
    JSONCPP_STRING str;
    for(auto& value:root["string_key"]){
        str = value.asString();
        
        cout<< str <<endl;//string으로 가져오기
    }
    std::cout << "===integer_key  숫자===!\n";
    for(auto& value:root["integer_key"])
        cout<<value.asInt()<<endl;//integer로 가져오기
        
    std::cout << "===string_key===!\n";
    cout<<root.get("string_key","UTF-8");//get 함수를 통해 value를 가져올수도 있다.


//    ofstream outFile("test.json", ios::out);
//    outFile << root;




}