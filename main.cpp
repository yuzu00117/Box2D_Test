//// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
////
//
//#include <iostream>
//#include<stdio.h>
//#include<vector>
//#include"test.h"
//#include"sub.h"
//#include"main.h"
//#include"include/box2d/box2d.h"
//
//
//
//using namespace std;
//////ファイルの垣根を超えたグローバル変数 どこか一つで extern無しで定義する必要がある
//extern int Global_number;
//
//
//int main()
//{
//    //ワールドの設定をしてる
//    b2World* world = new b2World(b2Vec2(0.0f, 40.0f));
//    
//    //Main_test_class main_test[5];
//
//    //std::cout << "Hello World!\n";
//
//    //test(main_test[0]);
//
//    //std::cout << Global_number;
//
//    //sub();
//    //std::cout << Global_number;
//
//    //int number;
//   
//
//    //cout << "\n要素数を入力してください：";
//    //cin>>number;
//
//    //vector<int> vec(number);
//
//
//    //for (int i = 0; i < number; i++)
//    //{
//    //    cout << i << "番目の値を入力してください:";
//    //    cin >> vec[i];
//    //}
//
//    //for (int i = 0; i < number; i++)
//    //{
//    //    cout << "\n" << i <<"番目の値:"<<vec[i];
//    //}
//
//
//    //std::cout <<"\n main.cpp" << main_test[0].Get_number();
//
//    //std::cout << "\n pointer" << main_test[0].Get_pointer();
//
//
//
//    //int x = 10;
//    //int y = 30;
//
//    //int* pX = &x;
//    //int* pY = &y;
//
//
//    //std::cout <<"\n" << x << "\n";
//    //std::cout << y<<"\n";
//
//
//    //Scart(&x, &y);//参照渡しくそ便利だわさ
//
//  
//    //std::cout << *pX << "\n";
//    //std::cout << *pY << "\n";
//
//    std::cin.seekg(0);
//    std::cin.get();
//}
//
//
//// コンストラクタの初期化リストを使った実装
//Main_test_class::Main_test_class() : number(0),value(0) {//ここで初期化子リストを使ってメンバ変数を初期化しておる
//    // 初期化リストで number を 0 に初期化
//}
//
//Main_test_class::~Main_test_class() {
//    // リソース解放が必要であればここに記述
//}
//
//// セッター関数の定義
//void Main_test_class::Set_number(int Number) {
//    number = Number;
//
//}
//
//
//// ゲッター関数の定義 (const 修飾子追加)
//int Main_test_class::Get_number() const {
//    return number;
//}
//
//
//sub_test_class::sub_test_class() 
//{
//
//}
//
//
//
//// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
//// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー
//
//// 作業を開始するためのヒント: 
////    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
////   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
////   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
////   4. エラー一覧ウィンドウを使用してエラーを表示します
////   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
////   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します

#include"include/box2d/box2d.h"
#include <iostream>

#

int main() {
    // Worldの重力を設定（下方向に9.8m/s^2）
    b2Vec2 gravity(0.0f, -9.8f);
    b2World world(gravity);

    // 地面（静的なオブジェクト）を作成
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    // 動的なボディ（物体）を作成
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    b2Body* body = world.CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    // シミュレーションステップ
    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    for (int i = 0; i < 60; ++i) {
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        std::cout << "Step " << i << ": (" << position.x << ", " << position.y << "), angle: " << angle << std::endl;
    }

    return 0;
}
